//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//
// GLOS.H
//
// This is an OS specific header file

#if defined( _WIN32 )

#include <windows.h>

// disable data conversion warnings

#pragma warning(disable : 4244)     // MIPS
#pragma warning(disable : 4136)     // X86
#pragma warning(disable : 4051)     // ALPHA
  
#endif

#if !defined( _WIN32 )

#undef GetCursorPos
#undef timeGetTime

#define WINAPI

typedef void VOID;
typedef void* LPVOID;
typedef unsigned int UINT;
typedef long LONG;
typedef unsigned int DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

typedef int WPARAM;
typedef int LPARAM;
typedef int LRESULT;

typedef void* HANDLE;
typedef HANDLE HDC;
typedef HANDLE HGLRC;
typedef HANDLE HWND;
typedef int WNDPROC;
typedef HANDLE HINSTANCE;
typedef HANDLE HICON;
typedef HANDLE HCURSOR;
typedef HANDLE HBRUSH;
typedef HANDLE HMENU;

typedef char* LPSTR;
typedef const char* LPCTSTR;

typedef int ATOM;

typedef struct
{
	LONG left;
	LONG top;
	LONG right;
	LONG bottom;
} RECT;
typedef RECT* LPRECT;

typedef struct
{
	LONG x;
	LONG y;
} POINT;
typedef POINT* LPPOINT;

typedef struct
{
	HWND   hwnd;
	UINT   message;
	WPARAM wParam;
	LPARAM lParam;
	DWORD  time;
	POINT  pt;
} MSG, *PMSG, *LPMSG;

typedef struct
{
	WORD  nSize;
	WORD  nVersion;
	DWORD dwFlags;
	BYTE  iPixelType;
	BYTE  cColorBits;
	BYTE  cRedBits;
	BYTE  cRedShift;
	BYTE  cGreenBits;
	BYTE  cGreenShift;
	BYTE  cBlueBits;
	BYTE  cBlueShift;
	BYTE  cAlphaBits;
	BYTE  cAlphaShift;
	BYTE  cAccumBits;
	BYTE  cAccumRedBits;
	BYTE  cAccumGreenBits;
	BYTE  cAccumBlueBits;
	BYTE  cAccumAlphaBits;
	BYTE  cDepthBits;
	BYTE  cStencilBits;
	BYTE  cAuxBuffers;
	BYTE  iLayerType;
	BYTE  bReserved;
	DWORD dwLayerMask;
	DWORD dwVisibleMask;
	DWORD dwDamageMask;
} PIXELFORMATDESCRIPTOR, *PPIXELFORMATDESCRIPTOR;

typedef struct
{
	HDC  hdc;
	BOOL fErase;
	RECT rcPaint;
	BOOL fRestore;
	BOOL fIncUpdate;
	BYTE rgbReserved[32];
} PAINTSTRUCT, *PPAINTSTRUCT, *LPPAINTSTRUCT;

typedef struct
{
	UINT      style;
	WNDPROC   lpfnWndProc;
	int       cbClsExtra;
	int       cbWndExtra;
	HINSTANCE hInstance;
	HICON     hIcon;
	HCURSOR   hCursor;
	HBRUSH    hbrBackground;
	LPCTSTR   lpszMenuName;
	LPCTSTR   lpszClassName;
} WNDCLASS, *PWNDCLASS;

#define PFD_DRAW_TO_WINDOW 0
#define PFD_SUPPORT_OPENGL 0
#define PFD_DOUBLEBUFFER 0
#define PFD_TYPE_RGBA 0
#define PFD_MAIN_PLANE 0

#define PM_REMOVE 0

enum
{
	VK_ESCAPE,
	VK_F1,
	VK_UP,
	VK_DOWN,
	VK_LEFT,
	VK_RIGHT,
	VK_INSERT,
	VK_DELETE,
};

enum
{
	WM_CREATE,
	WM_PAINT,
	WM_KEYDOWN,
	WM_KEYUP,
	WM_MBUTTONDOWN,
	WM_MBUTTONUP,
	WM_RBUTTONDOWN,
	WM_LBUTTONDOWN,
	WM_RBUTTONUP,
	WM_LBUTTONUP,
	WM_SIZE,
	WM_NCCALCSIZE,
	WM_CLOSE,
	WM_DESTROY,
};

enum
{
	MK_LBUTTON,
	MK_RBUTTON,
	MK_MBUTTON,
};

enum
{
	WVR_REDRAW,
};

enum
{
	SM_CXSCREEN,
	SM_CYSCREEN,
};

enum
{
	WS_OVERLAPPED,
	WS_CAPTION,
	WS_SYSMENU,
	WS_THICKFRAME,
	WS_MAXIMIZEBOX,
	WS_CLIPSIBLINGS,
	WS_CLIPCHILDREN,
};

enum
{
	SW_SHOWDEFAULT,
};

static const char* IDC_ARROW = "";

int MessageBox(HWND, LPCTSTR, LPCTSTR, UINT)
{
	return 0;
}

BOOL GetWindowRect(HWND, LPRECT)
{
	return TRUE;
}

BOOL GetCursorPos(LPPOINT)
{
	return TRUE;
}

BOOL SetCursorPos(int, int)
{
	return TRUE;
}

int ChoosePixelFormat(HDC, const PIXELFORMATDESCRIPTOR*)
{
	return TRUE;
}

BOOL SetPixelFormat(HDC, int, const PIXELFORMATDESCRIPTOR*)
{
	return TRUE;
}

BOOL GetClientRect(HWND, LPRECT)
{
	return TRUE;
}

HDC GetDC(HWND)
{
	return 0;
}

HGLRC wglCreateContext(HDC)
{
	return 0;
}

BOOL wglMakeCurrent(HDC, HGLRC)
{
	return TRUE;
}

HDC BeginPaint(HWND, LPPAINTSTRUCT)
{
	return 0;
}

BOOL SwapBuffers(HDC)
{
	return 0;
}

BOOL EndPaint(HWND, const PAINTSTRUCT*)
{
	return TRUE;
}

HWND SetCapture(HWND)
{
	return 0;
}

int ShowCursor(BOOL)
{
	return 0;
}

BOOL ReleaseCapture(void)
{
	return TRUE;
}

BOOL InvalidateRect(HWND, const RECT*, BOOL)
{
	return TRUE;
}

LRESULT DefWindowProc(HWND, UINT, WPARAM, LPARAM)
{
	return 0;
}

BOOL DestroyWindow(HWND)
{
	return TRUE;
}

HGLRC wglGetCurrentContext(void)
{
	return 0;
}

HDC wglGetCurrentDC(void)
{
	return 0;
}

BOOL wglDeleteContext(HGLRC)
{
	return TRUE;
}

int ReleaseDC(HWND, HDC)
{
	return 0;
}

VOID PostQuitMessage(int)
{
}

HCURSOR LoadCursor(HINSTANCE, LPCTSTR)
{
	return 0;
}

ATOM RegisterClass(const WNDCLASS*)
{
	return 0;
}

int GetSystemMetrics(int)
{
	return 0;
}

HWND CreateWindow(LPCTSTR, LPCTSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, LPVOID)
{
	return 0;
}

BOOL ShowWindow(HWND, int)
{
	return true;
}

DWORD timeGetTime(void)
{
	return 0;
}

VOID Sleep(DWORD)
{
}

void OutputDebugString(LPCTSTR)
{
}

BOOL PeekMessage(LPMSG, HWND, UINT, UINT, UINT)
{
	return TRUE;
}

BOOL TranslateMessage(const MSG*)
{
	return TRUE;
}

LRESULT DispatchMessage(const MSG*)
{
	return 0;
}

#endif
