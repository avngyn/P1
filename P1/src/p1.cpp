#ifdef _DEBUG
#undef _DEBUG
#include <Python.h>
#define _DEBUG
#pragma comment (lib, "lib/opencv_world320d.lib")
#else
#include <Python.h>
#pragma comment (lib, "lib/opencv_world320.lib")
#endif

#include <Windows.h>

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include "game_window.h"
#include "keyboard.h"


static PyObject* Initialize(PyObject* self, PyObject* args);
static PyObject* Capture(PyObject* self, PyObject* args);
static PyObject* KeyPress(PyObject* self, PyObject* args);
static PyObject* KeyRelease(PyObject* self, PyObject* args);
static PyObject* GetKey(PyObject* self, PyObject* args);

static PyMethodDef P1_methods[] = {
  { "Initialize", Initialize, METH_VARARGS, "Initialize" },
  { "Capture", Capture, METH_VARARGS, "Capture frame" },
  { "KeyPress", KeyPress, METH_VARARGS, "Press key" },
  { "KeyRelease", KeyRelease, METH_VARARGS, "Release key" },
  { "GetKey", GetKey, METH_VARARGS, "Get key" },
  { NULL, NULL, 0, NULL }
};

static struct PyModuleDef P1_module = {
  PyModuleDef_HEAD_INIT,
  "p1",
  NULL,
  -1,
  P1_methods
};

GameWindow* kGameWindow = NULL;
int kFrameWidth = 0;
int kFrameHeight = 0;
bool kEnableView = false;

static PyObject* Initialize(PyObject* self, PyObject* args) {
  // Arguments
  const char* name;
  if (!PyArg_ParseTuple(args, "siii", &name, &kFrameWidth, &kFrameHeight, &kEnableView)) {
    return NULL;
  }

  // Check arguments
  if (name == NULL) {
    return NULL;
  }
  if (kFrameWidth == 0) {
    return NULL;
  }
  if (kFrameHeight == 0) {
    return NULL;
  }

  // Convert name to LPWSTR
  wchar_t wname[256];
  mbstowcs(wname, name, strlen(name) + 1);

  // Instantiate game window
  if (kGameWindow != NULL) {
    delete kGameWindow;
    kGameWindow = NULL;
  }
  kGameWindow = new GameWindow();

  // Set game window
  int status = kGameWindow->Set(wname);

  // Return
  return PyLong_FromLong(status);
}

static PyObject* Capture(PyObject* self, PyObject* args) {
  // Capture window
  BYTE* frameData = kGameWindow->Capture();

  // Orient frame
  cv::Mat frameImage(kFrameHeight, kFrameWidth, cv::DataType<unsigned char>::type);
  cv::Mat tempImage;
  cv::resize(
    cv::Mat(kGameWindow->height(), kGameWindow->width(), CV_8UC3, frameData),
    tempImage,
    frameImage.size(),
    0,
    0,
    CV_INTER_LINEAR
  );
  cv::flip(tempImage, frameImage, 0);

  // Convert color space to gray
  cv::cvtColor(frameImage, tempImage, CV_RGB2GRAY, 1);

  // Display frame
  if (kEnableView) {
    cv::imshow("View", tempImage);
    cv::waitKey(1);
  }

  // Return
  return PyByteArray_FromStringAndSize(reinterpret_cast<const char*>(tempImage.data), tempImage.total());
}

static PyObject* KeyPress(PyObject* self, PyObject* args) {
  // Arguments
  int key;
  if (!PyArg_ParseTuple(args, "i", &key)) {
    return NULL;
  }

  // Press key
  Keyboard::Press(key);

  // Return
  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject* KeyRelease(PyObject* self, PyObject* args) {
  // Arguments
  int key;
  if (!PyArg_ParseTuple(args, "i", &key)) {
    return NULL;
  }

  // Press key
  Keyboard::Release(key);

  // Return
  Py_INCREF(Py_None);
  return Py_None;
}

static PyObject* GetKey(PyObject* self, PyObject* args) {
  // Arguments
  int key;
  if (!PyArg_ParseTuple(args, "i", &key)) {
    return NULL;
  }

  // Get key
  int status = GetAsyncKeyState(key) & 0x8000;

  // Return
  if (!status) {
    Py_INCREF(Py_False);
    return Py_False;
  }
  else {
    Py_INCREF(Py_True);
    return Py_True;
  }
}

PyMODINIT_FUNC PyInit_P1(void) {
  return PyModule_Create(&P1_module);
}