#pragma once

#include <Windows.h>

class GameWindow {
public:
  GameWindow();
  ~GameWindow();

  int Set(LPWSTR windowName);

  BYTE* Capture();

  inline LONG width() { return width_; }
  inline LONG height() { return height_; }
private:
  LONG width_;
  LONG height_;

  HWND windowHandle_;
  HDC windowDC_;

  HDC bitmapDC_;
  HBITMAP bitmapDIB_;
  BITMAPINFO bitmapInfo_;
  BYTE* bitmapData_;
};