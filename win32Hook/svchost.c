#include"svchost.h"
//��װHOOK
wchar_t ModuleName[] = L"svchost";
int InstllHook()
{
	HANDLE aa = GetModuleHandleW(ModuleName);
	g_hMouseHook = SetWindowsHook(WH_MOUSE, MouseProc,aa,0);
	if (g_hMouseHook == NULL)
		return 0;
	return 1;
}
int UninstallHook() {
	return UnhookWindowsHookEx(g_hMouseHook);
}
//���HOOK������
LRESULT CALLBACK MouseProc(int code, WPARAM wParam, LPARAM lParam)
{
	return 1;
}

