#include "nx_window.h"

// #############################################################################
//                           Statics
// #############################################################################
static bool running = true;
static int windowWidth = 0;
static int windowHeight = 0;

#ifdef _WIN32

// #############################################################################
//                           WIN API
// #############################################################################
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>

// ------- WIN API Statics ------------------------------- //
static HWND window;
static wchar_t wtitle[256];
static HINSTANCE instance;
static HDC dc;
static HGLRC glrc;

// ------- Callbacks ------------------------------- //
static LRESULT CALLBACK window_proc_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
  LRESULT result = 0;

  switch (msg)
  {
  case WM_DESTROY:
  {
    PostQuitMessage(0);
    
    break;
  }
  
  case WM_CLOSE:
  {
    running = false;
    DestroyWindow(window);

    break;
  }

  case WM_ERASEBKGND:
  {
    return 1;
    
    break;
  }

  case WM_SIZE:
  {
    if (wParam != SIZE_MINIMIZED)
    {
      windowWidth = LOWORD(lParam);
      windowHeight = HIWORD(lParam);
    }

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
    .style = CS_HREDRAW | CS_VREDRAW,
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

  // Create Window
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

  windowWidth = width;
  windowHeight = height;

  // Get DC
  dc = GetDC(window);

  // Set Pixel Format
  PIXELFORMATDESCRIPTOR pfd = {
    .nSize = sizeof(PIXELFORMATDESCRIPTOR),
    .nVersion = 1,
    .dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
    .iPixelType = PFD_TYPE_RGBA,
    .cColorBits = 32,
    .cAlphaBits = 8,
    .cDepthBits = 24,
    .cStencilBits = 8
  };
  int pixelFormat = ChoosePixelFormat(dc, &pfd);
  if(!pixelFormat)
  {
    return false;
  }
  if(!SetPixelFormat(dc, pixelFormat, &pfd))
  {
    return false;
  }

  // Create OpenGL Context
  glrc = wglCreateContext(dc);
  if (!glrc)
  {
    return false;
  }
  if (!wglMakeCurrent(dc, glrc))
  {
    return false;
  }

  // Init GLAD
  if(!gladLoadGL())
  {
    return false;
  }

  // Set glViewport
  glViewport(0, 0, width, height);

  // Display Window
  ShowWindow(window, SW_SHOWDEFAULT);
  return true;
}

bool window_isOpen()
{
  // Swap Window Buffer
  SwapBuffers(dc);
  ValidateRect(window, NULL);
  
  // Process Messages
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
    // OpenGL Cleanup
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(glrc);
    ReleaseDC(window, dc);

    // Window Cleanup    
    DestroyWindow(window);
    UnregisterClassW(wtitle, instance);
    window = NULL;
    running = false;
  }
}

#endif

// #############################################################################
//                           Common Functions
// #############################################################################

int get_window_width()
{
  return windowWidth;
}

int get_window_height()
{
  return windowHeight;
}

Vec2i get_window_size()
{
  return (Vec2i){windowWidth, windowHeight};
}

void clear_background(const Color *color)
{
  glClearColor((float)color->r, (float)color->g, (float)color->b, (float)color->a);
  glClear(GL_COLOR_BUFFER_BIT);
}
