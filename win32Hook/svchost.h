#include<windows.h>
HHOOK g_hMouseHook;

__declspec(dllexport) int InstallHook();
__declspec(dllexport) int UninstallHook();
LRESULT CALLBACK MouseProc(int code, WPARAM wParam, LPARAM lParam);