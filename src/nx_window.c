#include "Nexus_c.h"

// #############################################################################
//                           Statics
// #############################################################################
static bool running = true;

#ifdef _WIN32
// #############################################################################
//                           WIN API
// #############################################################################
#include <Windows.h>

// ------- WIN API Statics ------------------------------- //
static HWND window;
static wchar_t wtitle[256];
static HINSTANCE instance;

// ------- Callbacks ------------------------------- //
static LRESULT CALLBACK window_proc_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
  LRESULT result = 0;

  switch (msg)
  {
  
  case WM_CLOSE:
  {
    running = false;
    DestroyWindow(window);

    break;
  }

  default:
  {
    result = DefWindowProcW(window, msg, wParam, lParam);

    break;
  }
  }

  return result;
}

// ------- Functions ------------------------------- //
bool create_window(const char *title, int width, int height)
{
  MultiByteToWideChar(CP_UTF8, 0, title, -1, wtitle, 256);
  
  // Get Instance
  instance = GetModuleHandleW(0);

  // Create Window Class
  WNDCLASSW wc = {
    .hInstance = instance,
    .hCursor = LoadCursorW(NULL, (LPCWSTR)IDC_ARROW),
    .hIcon = LoadIconW(NULL, (LPCWSTR)IDI_APPLICATION),
    .lpszClassName = wtitle,
    .lpfnWndProc = window_proc_callback
  };

  // Register Window Class
  if(!RegisterClassW(&wc))
  {
    return false;
  }

  int dwStyle = WS_OVERLAPPEDWINDOW;

  window = CreateWindowExW(
    0,
    wtitle, wtitle,
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

bool window_isOpen()
{
  MSG msg = {0};  

  while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
  {
    TranslateMessage(&msg);
    DispatchMessageW(&msg);
  }

  return running;
}

void close_window()
{
  if (window)
  {
    DestroyWindow(window);
    UnregisterClassW(wtitle, instance);
    window = NULL;
    running = false;
  }
}

#endif
