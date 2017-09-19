#include "keyboard.h"

const UINT vk2sc[512] = {
     0,                     0, // [0x00] Undefined
     0,                     0, // [0x01] VK_LBUTTON - Left mouse button
     0,                     0, // [0x02] VK_RBUTTON - Right mouse button
     0,                     0, // [0x03] VK_CANCEL - Control-break processing
     0,                     0, // [0x04] VK_MBUTTON - Middle mouse button
     0,                     0, // [0x05] VK_XBUTTON - X1 mouse button
     0,                     0, // [0x06] VK_XBUTTON2 - X2 mouse button
     0,                     0, // [0x07] Undefined
  0x0E,                     0, // [0x08] VK_BACK BACKSPACE key
  0x0F,                     0, // [0x09] VK_TAB - TAB key
     0,                     0, // [0x0A] Reserved
     0,                     0, // [0x0B] Reserved
     0,                     0, // [0x0C] VK_CLEAR - CLEAR key
  0x1C,                     0, // [0x0D] VK_RETURN - ENTER key
     0,                     0, // [0x0E] Undefined
     0,                     0, // [0x0F] Undefined
     0,                     0, // [0x10] VK_SHIFT - SHIFT key
     0,                     0, // [0x11] VK_CONTROL - CTRL key
     0,                     0, // [0x12] VK_MENU - ALT key
     0,                     0, // [0x13] VK_PAUSE - PAUSE key
  0x3A,                     0, // [0x14] VK_CAPITAL - CAPS LOCK key
     0,                     0, // [0x15] VK_KANA - IME Kana mode
                               // [0x15] VK_HANGUEL - IME Hanguel mode
                               // [0x15] VK_HANGUL - IME Hangul mode
     0,                     0, // [0x16] Undefined
     0,                     0, // [0x17] VK_JUNJA - IME Junja mode
     0,                     0, // [0x18] VK_FINAL - IME Final mode
     0,                     0, // [0x19] VK_HANJA - IME Hanja mode
                               // [0x19] VK_KANJI - IME Kanji mode
     0,                     0, // [0x1A] Undefined
  0x01,                     0, // [0x1B] VK_ESCAPE - ESC key
     0,                     0, // [0x1C] VK_CONVERT - IME convert
     0,                     0, // [0x1D] VK_NONCONVERT - IME nonconvert
     0,                     0, // [0x1E] VK_ACCEPT - IME accept
     0,                     0, // [0x1F] VK_MODECHANGE - IME mode change request
  0x39,                     0, // [0x20] VK_SPACE - SPACEBAR key
  0x49, KEYEVENTF_EXTENDEDKEY, // [0x21] VK_PRIOR - PAGE UP key
  0x51, KEYEVENTF_EXTENDEDKEY, // [0x22] VK_NEXT - PAGE DOWN key
  0x4F, KEYEVENTF_EXTENDEDKEY, // [0x23] VK_END - END key
  0x47, KEYEVENTF_EXTENDEDKEY, // [0x24] VK_HOME - HOME key
  0x4B, KEYEVENTF_EXTENDEDKEY, // [0x25] VK_LEFT - LEFT ARROW key
  0x48, KEYEVENTF_EXTENDEDKEY, // [0x26] VK_UP - UP ARROW key
  0x4D, KEYEVENTF_EXTENDEDKEY, // [0x27] VK_RIGHT - RIGHT ARROW key
  0x50, KEYEVENTF_EXTENDEDKEY, // [0x28] VK_DOWN - DOWN ARROW key
     0,                     0, // [0x29] VK_SELECT - SELECT key
     0,                     0, // [0x2A] VK_PRINT - PRINT key
     0,                     0, // [0x2B] VK_EXECUTE - EXECUTE key
     0,                     0, // [0x2C] VK_SNAPSHOT - PRINT SCREEN key
  0x52, KEYEVENTF_EXTENDEDKEY, // [0x2D] VK_INSERT - INS key
  0x53, KEYEVENTF_EXTENDEDKEY, // [0x2E] VK_DELETE - DEL key
     0,                     0, // [0x2F] VK_HELP - HELP key
  0x0B,                     0, // [0x30] 0 key
  0x02,                     0, // [0x31] 1 key
  0x03,                     0, // [0x32] 2 key
  0x04,                     0, // [0x33] 3 key
  0x05,                     0, // [0x34] 4 key
  0x06,                     0, // [0x35] 5 key
  0x07,                     0, // [0x36] 6 key
  0x08,                     0, // [0x37] 7 key
  0x09,                     0, // [0x38] 8 key
  0x0A,                     0, // [0x39] 9 key
     0,                     0, // [0x3A] Undefined
     0,                     0, // [0x3B] Undefined
     0,                     0, // [0x3C] Undefined
     0,                     0, // [0x3D] Undefined
     0,                     0, // [0x3E] Undefined
     0,                     0, // [0x3F] Undefined
     0,                     0, // [0x40] Undefined
  0x1E,                     0, // [0x41] A key
  0x30,                     0, // [0x42] B key
  0x2E,                     0, // [0x43] C key
  0x20,                     0, // [0x44] D key
  0x12,                     0, // [0x45] E key
  0x21,                     0, // [0x46] F key
  0x22,                     0, // [0x47] G key
  0x23,                     0, // [0x48] H key
  0x17,                     0, // [0x49] I key
  0x24,                     0, // [0x4A] J key
  0x25,                     0, // [0x4B] K key
  0x26,                     0, // [0x4C] L key
  0x32,                     0, // [0x4D] M key
  0x31,                     0, // [0x4E] N key
  0x18,                     0, // [0x4F] O key
  0x19,                     0, // [0x50] P key
  0x10,                     0, // [0x51] Q key
  0x13,                     0, // [0x52] R key
  0x1F,                     0, // [0x53] S key
  0x14,                     0, // [0x54] T key
  0x16,                     0, // [0x55] U key
  0x2F,                     0, // [0x56] V key
  0x11,                     0, // [0x57] W key
  0x2D,                     0, // [0x58] X key
  0x15,                     0, // [0x59] Y key
  0x2C,                     0, // [0x5A] Z key
     0,                     0, // [0x5B] VK_LWIN - Left Windows key
     0,                     0, // [0x5C] VK_RWIN - Right Windows key
  0x5D, KEYEVENTF_EXTENDEDKEY, // [0x5D] VK_APPS - Applications key
     0,                     0, // [0x5E] Reserved
  0x5F, KEYEVENTF_EXTENDEDKEY, // [0x5F] VK_SLEEP - Computer Sleep key
  0x52,                     0, // [0x60] VK_NUMPAD0 - Numeric keypad 0 key
  0x4B,                     0, // [0x61] VK_NUMPAD1 - Numeric keypad 1 key
  0x4C,                     0, // [0x62] VK_NUMPAD2 - Numeric keypad 2 key
  0x4D,                     0, // [0x63] VK_NUMPAD3 - Numeric keypad 3 key
  0x4B,                     0, // [0x64] VK_NUMPAD4 - Numeric keypad 4 key
  0x4C,                     0, // [0x65] VK_NUMPAD5 - Numeric keypad 5 key
  0x4D,                     0, // [0x66] VK_NUMPAD6 - Numeric keypad 6 key
  0x47,                     0, // [0x67] VK_NUMPAD7 - Numeric keypad 7 key
  0x48,                     0, // [0x68] VK_NUMPAD8 - Numeric keypad 8 key
  0x49,                     0, // [0x69] VK_NUMPAD9 - Numeric keypad 9 key
  0x37,                     0, // [0x6A] VK_MULTIPLY - Multiply key
  0x4E,                     0, // [0x6B] VK_ADD - Add key
  0x53,                     0, // [0x6C] VK_SEPARATOR - Separator key
  0x4A,                     0, // [0x6D] VK_SUBTRACT - Subtract key
  0x4E,                     0, // [0x6E] VK_DECIMAL - Decimal key
  0x35, KEYEVENTF_EXTENDEDKEY, // [0x6F] VK_DIVIDE - Divide key
  0x3B,                     0, // [0x70] VK_F1 - F1 key
  0x3C,                     0, // [0x71] VK_F2 - F2 key
  0x3D,                     0, // [0x72] VK_F3 - F3 key
  0x3E,                     0, // [0x73] VK_F4 - F4 key
  0x3F,                     0, // [0x74] VK_F5 - F5 key
  0x40,                     0, // [0x75] VK_F6 - F6 key
  0x41,                     0, // [0x76] VK_F7 - F7 key
  0x42,                     0, // [0x77] VK_F8 - F8 key
  0x43,                     0, // [0x78] VK_F9 - F9 key
  0x44,                     0, // [0x79] VK_F10 - F10 key
  0x57,                     0, // [0x7A] VK_F11 - F11 key
  0x58,                     0, // [0x7B] VK_F12 - F12 key
     0,                     0, // [0x7C] VK_F13 - F13 key
     0,                     0, // [0x7D] VK_F14 - F14 key
     0,                     0, // [0x7E] VK_F15 - F15 key
     0,                     0, // [0x7F] VK_F16 - F16 key
     0,                     0, // [0x80] VK_F17 - F17 key
     0,                     0, // [0x81] VK_F18 - F18 key
     0,                     0, // [0x82] VK_F19 - F19 key
     0,                     0, // [0x83] VK_F20 - F20 key
     0,                     0, // [0x84] VK_F21 - F21 key
     0,                     0, // [0x85] VK_F22 - F22 key
     0,                     0, // [0x86] VK_F23 - F23 key
     0,                     0, // [0x87] VK_F24 - F24 key
     0,                     0, // [0x88] Unassigned
     0,                     0, // [0x89] Unassigned
     0,                     0, // [0x8A] Unassigned
     0,                     0, // [0x8B] Unassigned
     0,                     0, // [0x8C] Unassigned
     0,                     0, // [0x8D] Unassigned
     0,                     0, // [0x8E] Unassigned
     0,                     0, // [0x8F] Unassigned
  0x45,                     0, // [0x90] VK_NUMLOCK - NUM LOCK key
  0x46,                     0, // [0x91] VK_SCROLL - SCROLL LOCK key
     0,                     0, // [0x92] OEM specific
     0,                     0, // [0x93] OEM specific
     0,                     0, // [0x94] OEM specific
     0,                     0, // [0x95] OEM specific
     0,                     0, // [0x96] OEM specific
     0,                     0, // [0x97] Unassigned
     0,                     0, // [0x98] Unassigned
     0,                     0, // [0x99] Unassigned
     0,                     0, // [0x9A] Unassigned
     0,                     0, // [0x9B] Unassigned
     0,                     0, // [0x9C] Unassigned
     0,                     0, // [0x9D] Unassigned
     0,                     0, // [0x9E] Unassigned
     0,                     0, // [0x9F] Unassigned
  0x2A,                     0, // [0xA0] VK_LSHIFT - Left SHIFT key
  0x36,                     0, // [0xA1] VK_RSHIFT - Right SHIFT key
  0x1D,                     0, // [0xA2] VK_LCONTROL - Left CONTROL key
  0x1D, KEYEVENTF_EXTENDEDKEY, // [0xA3] VK_RCONTROL - Right CONTROL key
  0x5B, KEYEVENTF_EXTENDEDKEY, // [0xA4] VK_LMENU - Left MENU key
  0x5C, KEYEVENTF_EXTENDEDKEY, // [0xA5] VK_RMENU - Right MENU key
  0x6A, KEYEVENTF_EXTENDEDKEY, // [0xA6] VK_BROWSER_BACK - Browser Back key
  0x69, KEYEVENTF_EXTENDEDKEY, // [0xA7] VK_BROWSER_FORWARD - Browser Forward key
  0x67, KEYEVENTF_EXTENDEDKEY, // [0xA8] VK_BROWSER_REFRESH - Browser Refresh key
  0x68, KEYEVENTF_EXTENDEDKEY, // [0xA9] VK_BROWSER_STOP - Browser Stop key
  0x65, KEYEVENTF_EXTENDEDKEY, // [0xAA] VK_BROWSER_SEARCH - Browser Search key
  0x66, KEYEVENTF_EXTENDEDKEY, // [0xAB] VK_BROWSER_FAVORITES - Browser Favorites key
  0x32, KEYEVENTF_EXTENDEDKEY, // [0xAC] VK_BROWSER_HOME - Browser Start and Home key
  0x20, KEYEVENTF_EXTENDEDKEY, // [0xAD] VK_VOLUME_MUTE - Volume Mute key
  0x2E, KEYEVENTF_EXTENDEDKEY, // [0xAE] VK_VOLUME_DOWN - Volume Down key
  0x30, KEYEVENTF_EXTENDEDKEY, // [0xAF] VK_VOLUME_UP - Volume Up key
  0x19, KEYEVENTF_EXTENDEDKEY, // [0xB0] VK_MEDIA_NEXT_TRACK - Next Track key
  0x10, KEYEVENTF_EXTENDEDKEY, // [0xB1] VK_MEDIA_PREV_TRACK - Previous Track key
  0x24, KEYEVENTF_EXTENDEDKEY, // [0xB2] VK_MEDIA_STOP - Stop Media key
  0x22, KEYEVENTF_EXTENDEDKEY, // [0xB3] VK_MEDIA_PLAY_PAUSE - Play/Pause Media key
  0x6C, KEYEVENTF_EXTENDEDKEY, // [0xB4] VK_LAUNCH_MAIL - Start Mail key
  0x6D, KEYEVENTF_EXTENDEDKEY, // [0xB5] VK_LAUNCH_MEDIA_SELECT - Select Media key
     0,                     0, // [0xB6] VK_LAUNCH_APP1 - Start Application 1 key
     0,                     0, // [0xB7] VK_LAUNCH_APP2 - Start Application 2 key
     0,                     0, // [0xB8] Reserved
     0,                     0, // [0xB9] Reserved
  0x27,                     0, // [0xBA] VK_OEM_1 - ';:' key
  0x0D,                     0, // [0xBB] VK_OEM_PLUS - '+' key
  0x33,                     0, // [0xBC] VK_OEM_COMMA - ',' key
  0x0C,                     0, // [0xBD] VK_OEM_MINUS - '-' key
  0x34,                     0, // [0xBE] VK_OEM_PERIOD - '.' key
  0x35,                     0, // [0xBF] VK_OEM_2 - '/?' key
  0x29,                     0, // [0xC0] VK_OEM_3 - '`~' key
     0,                     0, // [0xC1] Reserved
     0,                     0, // [0xC2] Reserved
     0,                     0, // [0xC3] Reserved
     0,                     0, // [0xC4] Reserved
     0,                     0, // [0xC5] Reserved
     0,                     0, // [0xC6] Reserved
     0,                     0, // [0xC7] Reserved
     0,                     0, // [0xC8] Reserved
     0,                     0, // [0xC9] Reserved
     0,                     0, // [0xCA] Reserved
     0,                     0, // [0xCB] Reserved
     0,                     0, // [0xCC] Reserved
     0,                     0, // [0xCD] Reserved
     0,                     0, // [0xCE] Reserved
     0,                     0, // [0xCF] Reserved
     0,                     0, // [0xD0] Reserved
     0,                     0, // [0xD1] Reserved
     0,                     0, // [0xD2] Reserved
     0,                     0, // [0xD3] Reserved
     0,                     0, // [0xD4] Reserved
     0,                     0, // [0xD5] Reserved
     0,                     0, // [0xD6] Reserved
     0,                     0, // [0xD7] Reserved
     0,                     0, // [0xD8] Unassigned
     0,                     0, // [0xD9] Unassigned
     0,                     0, // [0xDA] Unassigned
  0x1A,                     0, // [0xDB] VK_OEM_4 - '[{' key
  0x2B,                     0, // [0xDC] VK_OEM_5 - '\|' key
  0x1B,                     0, // [0xDD] VK_OEM_6 - ']}' key
  0x28,                     0, // [0xDE] VK_OEM_7 - 'single-quote/double-quote' key
     0,                     0, // [0xDF] VK_OEM_8 - miscellaneous
     0,                     0, // [0xE0] Reserved
     0,                     0, // [0xE1] OEM specific
     0,                     0, // [0xE2] VK_OEM_102 - Either the angle bracket key or the backslash key on the RT 102-key keyboard
     0,                     0, // [0xE3] OEM specific
     0,                     0, // [0xE4] OEM specific
     0,                     0, // [0xE5] VK_PROCESSKEY - IME PROCESS key
     0,                     0, // [0xE6] OEM specific
     0,                     0, // [0xE7] VK_PACKET - Used to pass Unicode characters as if they were keystrokes
     0,                     0, // [0xE8] Unassigned
     0,                     0, // [0xE9] OEM specific
     0,                     0, // [0xEA] OEM specific
     0,                     0, // [0xEB] OEM specific
     0,                     0, // [0xEC] OEM specific
     0,                     0, // [0xED] OEM specific
     0,                     0, // [0xEE] OEM specific
     0,                     0, // [0xEF] OEM specific
     0,                     0, // [0xF0] OEM specific
     0,                     0, // [0xF1] OEM specific
     0,                     0, // [0xF2] OEM specific
     0,                     0, // [0xF3] OEM specific
     0,                     0, // [0xF4] OEM specific
     0,                     0, // [0xF5] OEM specific
     0,                     0, // [0xF6] VK_ATTN - Attn key
     0,                     0, // [0xF7] VK_CRSEL - CrSel key
     0,                     0, // [0xF8] VK_EXSEL - ExSel key
     0,                     0, // [0xF9] VK_EREOF - Erase EOF key
     0,                     0, // [0xFA] VK_PLAY - Play key
     0,                     0, // [0xFB] VK_ZOOM - Zoom key
     0,                     0, // [0xFC] VK_NONAME - Reserved
     0,                     0, // [0xFD] VK_PA1 - PA1 key
     0,                     0  // [0xFE] VK_OEM_CLEAR - Clear key
};

void Keyboard::Send(WORD code, DWORD flags) {
  INPUT input;

  // Set input key
  input.type = INPUT_KEYBOARD;
  input.ki.wVk = 0;
  input.ki.wScan = code;
  input.ki.dwFlags = KEYEVENTF_SCANCODE | flags;
  input.ki.time = 0;
  input.ki.dwExtraInfo = 0;

  // Send key-press input
  if (SendInput(1, &input, sizeof(INPUT)) != 1) {
    // [E] Failed to send input
  }
}

void Keyboard::Press(WORD key) {
  Send(vk2sc[2 * key], vk2sc[2 * key + 1]);
}

void Keyboard::Release(WORD key) {
  Send(vk2sc[2 * key], vk2sc[2 * key + 1] | KEYEVENTF_KEYUP);
}