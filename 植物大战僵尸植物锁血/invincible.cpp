#include<windows.h>
#include<stdio.h>
int main() {
	HWND hWnd = FindWindow(L"MainWindow", L"PlantsVsZombies Plus Version 95");
	DWORD hProcessId;
	DWORD hThreadId = GetWindowThreadProcessId(hWnd, &hProcessId);
	if (hThreadId == NULL)
	{
		printf("��ȡ����IDʧ��\n");
		return 0;
	}
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, hProcessId);
	if (hProcess == NULL)
	{
		printf("ʧ��\n");
		return 0;
	}

	unsigned long BaseAddress = 0x40058a;
	unsigned long BaseAddressValue;
	DWORD code = 0x10;
	BOOL ret;
	ret = WriteProcessMemory(hProcess, (void*)(BaseAddress), &code, sizeof(DWORD), NULL);
}