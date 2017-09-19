#include "game_window.h"

#include <string>

BOOL CALLBACK EnumWindowProc(HWND hwnd, LPARAM lparam);

GameWindow::GameWindow() :
  width_(0),
  height_(0),
  windowHandle_(NULL),
  windowDC_(NULL),
  bitmapDC_(NULL),
  bitmapDIB_(NULL),
  bitmapInfo_(BITMAPINFO()),
  bitmapData_(NULL) {
}

GameWindow::~GameWindow() {
  if (windowDC_ != NULL) {
    ReleaseDC(windowHandle_, windowDC_);
    windowDC_ = NULL;
  }
  windowHandle_ = NULL;

  if (bitmapDC_ != NULL) {
    DeleteDC(bitmapDC_);
    bitmapDC_ = NULL;
  }
  if (bitmapDIB_ != NULL) {
    DeleteObject(bitmapDIB_);
    bitmapDIB_ = NULL;
  }
  bitmapData_ = NULL;
}

int GameWindow::Set(LPWSTR windowName) {
  // Find game window
  if (wcscmp(windowName, TEXT("")) == 0) {
    // [W] Window name is empty
    return -1;
  }
  EnumWindows(EnumWindowProc, reinterpret_cast<LPARAM>(&windowName));
  windowHandle_ = FindWindow(NULL, windowName);
  if (windowHandle_ == NULL) {
    // [E] Unable to find window
    return -2;
  }

  // Get device context for game window
  windowDC_ = GetDC(windowHandle_);
  if (windowDC_ == NULL) {
    // [E] Unable to get device context for game window
    return -3;
  }

  // Get device context for bitmap
  bitmapDC_ = CreateCompatibleDC(windowDC_);
  if (bitmapDC_ == NULL) {
    // [E] Unable to create device context for bitmap
    return -4;
  }

  // Set bitmap header
  bitmapInfo_.bmiHeader.biSize = sizeof(bitmapInfo_.bmiHeader);
  bitmapInfo_.bmiHeader.biPlanes = 1;
  bitmapInfo_.bmiHeader.biBitCount = 24;
  bitmapInfo_.bmiHeader.biCompression = BI_RGB;
  bitmapInfo_.bmiHeader.biClrUsed = 0;
  bitmapInfo_.bmiHeader.biClrImportant = 0;
  bitmapInfo_.bmiHeader.biXPelsPerMeter = 0;
  bitmapInfo_.bmiHeader.biYPelsPerMeter = 0;

  SetForegroundWindow(windowHandle_);

  return 0;
}

BYTE* GameWindow::Capture() {
  // Get game window dimensions
  RECT screenRect;
  LONG width;
  LONG height;
  GetClientRect(windowHandle_, &screenRect);
  width = screenRect.right - screenRect.left;
  height = screenRect.bottom - screenRect.top;

  // Check if window dimensions have changed
  if (width_ != width || height_ != height) {
    // Store new dimensions
    width_ = width;
    height_ = height;

    // Update bitmap header
    bitmapInfo_.bmiHeader.biWidth = width_;
    bitmapInfo_.bmiHeader.biHeight = height_;
    bitmapInfo_.bmiHeader.biSizeImage = 3 * width_ * height_;

    // Create bitmap
    bitmapDIB_ = CreateDIBSection(
      bitmapDC_,
      &bitmapInfo_,
      DIB_RGB_COLORS,
      (void**)(&bitmapData_),
      NULL,
      NULL
    );
    if (bitmapDIB_ == NULL) {
      // [W] Unable to create bitmap
      return NULL;
    }
    SelectObject(bitmapDC_, bitmapDIB_);
  }

  // Transfer bit-block
  if (BitBlt(
    bitmapDC_,
    0, 0,
    width_, height_,
    windowDC_,
    0, 0,
    SRCCOPY) == 0
    ) {
    // "[W] Unable to capture window
    return NULL;
  }

  return bitmapData_;
}

BOOL CALLBACK EnumWindowProc(HWND hwnd, LPARAM lparam) {
  // Get window title
  LPWSTR buffer = new TCHAR[255];
  memset(buffer, 0, 255);
  int length = GetWindowText(hwnd, buffer, 255);
  std::wstring title(buffer);

  // Compare title
  LPWSTR* param = reinterpret_cast<LPWSTR*>(lparam);
  if (length && title.find(*param) != std::string::npos) {
    return FALSE; // Since window has been found, stop enumeration by returning FALSE
  }

  delete buffer;

  return TRUE;
}