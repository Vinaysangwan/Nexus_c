#include "Nexus_c.h"

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
#define WGL_CONTEXT_MAJOR_VERSION_ARB     0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB     0x2092
#define WGL_CONTEXT_FLAGS_ARB             0x2094
#define WGL_CONTEXT_PROFILE_MASK_ARB      0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB  0x00000001
#define WGL_CONTEXT_DEBUG_BIT_ARB         0x00000001
#include <Windows.h>
#include <Windowsx.h>

// ------- WIN API typedefs ------------------------------- //
typedef HGLRC(WINAPI* PFNWGLCREATECONTEXTATTRIBSARBPROC)(HDC, HGLRC, const int*);
typedef BOOL (WINAPI *PFNWGLSWAPINTERVALEXTPROC)(int interval);

// ------- WIN API Statics ------------------------------- //
static HWND window;
static wchar_t wtitle[256];
static HINSTANCE instance;
static HDC dc;
static HGLRC glrc;
static PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = NULL;

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

  case WM_KEYDOWN:
  case WM_KEYUP:
  case WM_SYSKEYDOWN:
  case WM_SYSKEYUP:
  {
    if (wParam < KEY_COUNT)
    {
      if (msg == WM_KEYDOWN || msg == WM_SYSKEYDOWN)
        input.currKeys[wParam] = 1;
      else if (msg == WM_KEYUP || msg == WM_SYSKEYUP)
        input.currKeys[wParam] = 0;
    }
  
    break;
  }

  case WM_LBUTTONDOWN: input.currMouseBtns[MOUSE_LEFT]   = 1; break;
  case WM_LBUTTONUP:   input.currMouseBtns[MOUSE_LEFT]   = 0; break;
  case WM_RBUTTONDOWN: input.currMouseBtns[MOUSE_RIGHT]  = 1; break;
  case WM_RBUTTONUP:   input.currMouseBtns[MOUSE_RIGHT]  = 0; break;
  case WM_MBUTTONDOWN: input.currMouseBtns[MOUSE_MIDDLE] = 1; break;
  case WM_MBUTTONUP:   input.currMouseBtns[MOUSE_MIDDLE] = 0; break;

  case WM_MOUSEMOVE:
  {
    input.mouseX = GET_X_LPARAM(lParam);
    input.mouseY = GET_Y_LPARAM(lParam);
    break;
  }

  case WM_MOUSEWHEEL:
  {
    input.mouseScroll = GET_WHEEL_DELTA_WPARAM(wParam) / WHEEL_DELTA;
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
bool window_create(const char *title, int width, int height)
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

  RECT rect = {0, 0, width, height};
  AdjustWindowRect(&rect, dwStyle, FALSE);

  // Create Window
  window = CreateWindowExW(
    0,
    wtitle, wtitle,
    dwStyle,
    CW_USEDEFAULT, CW_USEDEFAULT,
    rect.right - rect.left, rect.bottom - rect.top,
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
  
  // create dummy OpenGL Context
  HGLRC dummy_glrc = wglCreateContext(dc);
  if (!dummy_glrc)
  {
    return false;
  }
  if (!wglMakeCurrent(dc, dummy_glrc))
  {
    return false;
  }

  // load the extension
  PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = 
    (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
  if (!wglCreateContextAttribsARB)
  {
    return false;
  }

  // destroy dummy context
  wglMakeCurrent(NULL, NULL);
  wglDeleteContext(dummy_glrc);

  // Context Attribs
  int attribs[] = {
    WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
    WGL_CONTEXT_MINOR_VERSION_ARB, 3,
    WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
    0
  };

  // create real OpenGL 4.3 core context
  glrc = wglCreateContextAttribsARB(dc, NULL, attribs);
  if (!glrc)
  {
    return false;
  }
  if (!wglMakeCurrent(dc, glrc))
  {
    return false;
  }

  // Create Funcitons Pointer for SwapIntervals
  wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC) wglGetProcAddress("wglSwapIntervalEXT");

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

bool window_isOpen(void)
{
  // Update Inputs
  input_update();

  // Process Messages
  MSG msg = {0};
  while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
  {
    TranslateMessage(&msg);
    DispatchMessageW(&msg);
  }

  return running;
}

void window_swap_buffers(void)
{
  // Swap Window Buffer
  SwapBuffers(dc);
  ValidateRect(window, NULL);
}

void window_close(void)
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

void window_set_vsync(bool enable)
{
  if (wglSwapIntervalEXT)
  {
    wglSwapIntervalEXT(enable ? 1 : 0);
  }
}

#elif __linux__
// TODO: Add Code to Support Linux

#elif __APPLE__
// TODO: Add Code to Support Apple

#endif

// #############################################################################
//                           Common Functions
// #############################################################################

int window_get_width(void)
{
  return windowWidth;
}

int window_get_height(void)
{
  return windowHeight;
}

Vec2i window_get_size(void)
{
  return (Vec2i){windowWidth, windowHeight};
}

void clear_background(const Color *color)
{
  glClearColor((float)color->r / 255.0f, (float)color->g / 255.0f, (float)color->b / 255.0f, (float)color->a / 255.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

void window_stop(void)
{
  running = false;
}
