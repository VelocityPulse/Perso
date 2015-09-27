#ifdef KEYDLL3_EXPORTS
#define KEYDLL3_API __declspec(dllexport)
#else
#define KEYDLL3_API __declspec(dllimport)
#endif // KEYDLL3_API

#include <windows.h>

// Keyboard hook installer
KEYDLL3_API void installhook(HWND h);

// Keyboard hook uninstaller
KEYDLL3_API void removehook();

// hook procedure
KEYDLL3_API LRESULT CALLBACK HookProc( int ncode,
                                       WPARAM wparam,
                                       LPARAM lparam);
