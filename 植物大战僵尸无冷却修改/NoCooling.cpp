//0x69F2C4
#include<windows.h>
#include<stdio.h>
int main() {
	HWND hWnd = FindWindow(L"MainWindow", L"PlantsVsZombies Plus Version 95");
	DWORD hProcessId;
	DWORD hThreadId = GetWindowThreadProcessId(hWnd, &hProcessId);
	if (hThreadId == NULL)
	{
		printf("获取进程ID失败\n");
		return 0;
	}
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, hProcessId);
	if (hProcess == NULL)
	{printf("失败\n");
	return 0;
	}

	unsigned long BaseAddress = 0x69F2C4;
	unsigned long BaseAddressValue;
	BOOL ret;

	DWORD cooling = 0;
	int num;
	printf("输入当前植物栏数量:");
	scanf_s("%d", &num);
	for(int i=0;i<num;i++)
	ret = WriteProcessMemory(hProcess, (void*)(BaseAddress + (i+i* 8)*4), &cooling, sizeof(DWORD), NULL);
	if (ret == false)
	{
		printf("内存修改失败");
		return 0;
	}
	printf("内存修改成功\n");

	ret = ReadProcessMemory(hProcess, (void*)(BaseAddress), &BaseAddressValue, sizeof(unsigned long), NULL);
	if (ret == false)
	{
		printf("内存读取失败");
		return 0;
	}
	else
	{
		printf("内存读取成功");
		printf("%x\n", BaseAddressValue);
	}
}