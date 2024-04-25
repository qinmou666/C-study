#pragma once
#include<Windows.h>
class CMyHook{
public:
	CMyHook();
	~CMyHook();
	BOOL Hook(LPSTR pszModuleName, LPSTR pszFuncName, PROC pfnHookFunc);
	void UnHook();
	BOOL ReHook();
private:
	PROC m_FuncAddress;
	BYTE m_OldBytes[5];
	BYTE m_NewBytes[5];
};