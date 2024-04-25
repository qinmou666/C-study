#include <windows.h>
#include<stdio.h>
int main() {
	//获取窗口句柄
	HWND hWnd = FindWindow(L"MainWindow", L"PlantsVsZombies Plus Version 95");
	if (hWnd == NULL)
	{
		printf("获取窗口句柄失败");
		return 0;
	}else
	printf("成功获取窗口句柄: %x\n", hWnd);
	//获取窗口进程线程
	DWORD ProcessId;
	DWORD ThreadId = GetWindowThreadProcessId(hWnd, &ProcessId);
	if (ThreadId == 0)
	{
		printf("获取进程线程失败\n");
		return 0;
	}
	else
		printf("成功: %x\n", ThreadId);
	
	//阳光地址
		//1通过进程ID找到进程句柄
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, ProcessId);
	if (hProcess == NULL)
		printf("打开进程句柄失败");
	else
		printf("打开进程成功:%x\n", hProcess);
	//0x5560    0x768    0x6A9EC0
	unsigned long nSunBaseAddress = 0x6A9EC0;
		unsigned long nSunBaseAddressValue;
		BOOL ret;
	ret = ReadProcessMemory(hProcess, (void*)nSunBaseAddress,&nSunBaseAddressValue,sizeof(unsigned long),NULL);
	if (ret == false)
	{
		printf("读取内存失败");
		return 0;
	}
	else
		printf("读取内存成功%x\n", nSunBaseAddressValue);
	//第一次偏移
	unsigned long FristOffset=0x768;
	unsigned long FristOffsetValue;
	ret=ReadProcessMemory(hProcess, (void*)(nSunBaseAddressValue + FristOffset), &FristOffsetValue, sizeof(unsigned long), NULL);
	if (ret == false)
	{
		printf("第一次读取内存失败");
		return 0;
	}
	else
		printf("第二次读取内存成功%x\n", FristOffsetValue);
	//第二次偏移 当前阳光地址
	unsigned long nSecondOffset = 0x5560;
	unsigned long nSecondOffsetValue;
	ret=ReadProcessMemory(hProcess, (void*)(FristOffsetValue + nSecondOffset), &nSecondOffsetValue, sizeof(unsigned long), NULL);

	//修改阳光
	DWORD nSumNum;
	printf("输入你需要修改的阳光数量:");
	scanf_s("%d", &nSumNum);

	ret=WriteProcessMemory(hProcess, (void*)(nSecondOffset+FristOffsetValue), &nSumNum, sizeof(int), NULL);
	if (ret == false)
	{
		printf("阳光修改失败\n");
		return 0;
	}
	else
		printf("阳光修改成功，修改前阳光地址%x\n", nSecondOffset + FristOffsetValue);
}

