#include "Nexus_c.h"

#ifdef _WIN32

// #############################################################################
//                           WIN API
// #############################################################################
#include <Windows.h>

bool create_window(const char *title, int width, int height)
{
  wchar_t wtitle[256] = {0};
  MultiByteToWideChar(CP_UTF8, 0, title, -1, wtitle, 256);
  
  // Get Instance
  HINSTANCE instance = GetModuleHandleW(0);

  // Create Window Class
  WNDCLASSW wc = {
    .hInstance = instance,
    .hCursor = LoadCursorW(NULL, (LPCWSTR)IDC_ARROW),
    .hIcon = LoadIconW(NULL, (LPCWSTR)IDI_APPLICATION),
    .lpszClassName = (LPCWSTR)wtitle,
    .lpfnWndProc = DefWindowProcW
  };

  // Register Window Class
  if(!RegisterClassW(&wc))
  {
    return false;
  }

  int dwStyle = WS_OVERLAPPEDWINDOW;

  HWND window = CreateWindowExW(
    0,
    (LPCWSTR)wtitle, (LPCWSTR)wtitle,
    dwStyle,
    CW_USEDEFAULT, CW_USEDEFAULT, width, height,
    NULL, NULL,
    instance,
    NULL
  );

  if (!window)
  {
    return false;
  }

  ShowWindow(window, SW_SHOWDEFAULT);
  return true;
}

#endif
