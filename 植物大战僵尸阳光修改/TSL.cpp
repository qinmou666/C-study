#include <windows.h>
#include<stdio.h>
int main() {
	//��ȡ���ھ��
	HWND hWnd = FindWindow(L"MainWindow", L"PlantsVsZombies Plus Version 95");
	if (hWnd == NULL)
	{
		printf("��ȡ���ھ��ʧ��");
		return 0;
	}else
	printf("�ɹ���ȡ���ھ��: %x\n", hWnd);
	//��ȡ���ڽ����߳�
	DWORD ProcessId;
	DWORD ThreadId = GetWindowThreadProcessId(hWnd, &ProcessId);
	if (ThreadId == 0)
	{
		printf("��ȡ�����߳�ʧ��\n");
		return 0;
	}
	else
		printf("�ɹ�: %x\n", ThreadId);
	
	//�����ַ
		//1ͨ������ID�ҵ����̾��
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, ProcessId);
	if (hProcess == NULL)
		printf("�򿪽��̾��ʧ��");
	else
		printf("�򿪽��̳ɹ�:%x\n", hProcess);
	//0x5560    0x768    0x6A9EC0
	unsigned long nSunBaseAddress = 0x6A9EC0;
		unsigned long nSunBaseAddressValue;
		BOOL ret;
	ret = ReadProcessMemory(hProcess, (void*)nSunBaseAddress,&nSunBaseAddressValue,sizeof(unsigned long),NULL);
	if (ret == false)
	{
		printf("��ȡ�ڴ�ʧ��");
		return 0;
	}
	else
		printf("��ȡ�ڴ�ɹ�%x\n", nSunBaseAddressValue);
	//��һ��ƫ��
	unsigned long FristOffset=0x768;
	unsigned long FristOffsetValue;
	ret=ReadProcessMemory(hProcess, (void*)(nSunBaseAddressValue + FristOffset), &FristOffsetValue, sizeof(unsigned long), NULL);
	if (ret == false)
	{
		printf("��һ�ζ�ȡ�ڴ�ʧ��");
		return 0;
	}
	else
		printf("�ڶ��ζ�ȡ�ڴ�ɹ�%x\n", FristOffsetValue);
	//�ڶ���ƫ�� ��ǰ�����ַ
	unsigned long nSecondOffset = 0x5560;
	unsigned long nSecondOffsetValue;
	ret=ReadProcessMemory(hProcess, (void*)(FristOffsetValue + nSecondOffset), &nSecondOffsetValue, sizeof(unsigned long), NULL);

	//�޸�����
	DWORD nSumNum;
	printf("��������Ҫ�޸ĵ���������:");
	scanf_s("%d", &nSumNum);

	ret=WriteProcessMemory(hProcess, (void*)(nSecondOffset+FristOffsetValue), &nSumNum, sizeof(int), NULL);
	if (ret == false)
	{
		printf("�����޸�ʧ��\n");
		return 0;
	}
	else
		printf("�����޸ĳɹ����޸�ǰ�����ַ%x\n", nSecondOffset + FristOffsetValue);
}

