#pragma once

#include <Windows.h>

class Keyboard {
public:
  static void Press(WORD key);
  static void Release(WORD key);
private:
  Keyboard();

  static void Send(WORD code, DWORD flags);
};
