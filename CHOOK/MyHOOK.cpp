#include"MyHOOK.h"
CMyHook::CMyHook(){
	m_FuncAddress = NULL;
	memset(m_OldBytes, 0, 5);
	memset(m_NewBytes, 0, 5);
}
CMyHook::~CMyHook(){
	UnHook();
	m_FuncAddress = NULL;
	memset(m_OldBytes, 0, 5);
	memset(m_NewBytes, 0, 5);
}
BOOL CMyHook::Hook(LPSTR pszModuleName,LPSTR pszFuncName,PROC pfnHookFunc){
	//��ȡָ��ģ���ָ������
	m_FuncAddress = (PROC)GetProcAddress(GetModuleHandle(pszModuleName), pszFuncName);
	if (m_FuncAddress == NULL)
		return false;
	SIZE_T reRet=0;
	ReadProcessMemory(GetCurrentProcess(), m_FuncAddress, m_OldBytes, 5, &reRet);
	//������תָ��
	//jmp address
	m_NewBytes[0] = '\xE9';
	*(DWORD*)(m_NewBytes + 1) = (DWORD)pfnHookFunc - (DWORD)m_FuncAddress - 5;
	WriteProcessMemory(GetCurrentProcess(), m_FuncAddress, m_NewBytes, 5, &reRet);
	return true;
}
void CMyHook::UnHook() {
	if (m_FuncAddress != 0)
	{
		SIZE_T reRet = 0;
		WriteProcessMemory(GetCurrentProcess(), m_FuncAddress, m_OldBytes, 5, &reRet);
	}
}
BOOL CMyHook::ReHook(){
	if (m_FuncAddress ! = 0)
	{
		SIZE_T reRet = 0;
		WriteProcessMemory(GetCurrentProcess(), m_FuncAddress, m_NewBytes, 5, &reRet);
	}
}