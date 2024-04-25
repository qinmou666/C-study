// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include<windows.h>

#pragma comment(linker,"/EXPORT:CreateCompatibleDC=c_gdi42.CreateCompatibleDC")
#pragma comment(linker,"/EXPORT:CreateDIBSection=c_gdi42.CreateDIBSection")
#pragma comment(linker,"/EXPORT:CreateFontA=c_gdi42.CreateFontA")
#pragma comment(linker,"/EXPORT:CreateFontIndirectA=c_gdi42.CreateFontIndirectA")
#pragma comment(linker,"/EXPORT:CreateSolidBrush=c_gdi42.CreateSolidBrush")
#pragma comment(linker,"/EXPORT:DeleteDC=c_gdi42.DeleteDC")
#pragma comment(linker,"/EXPORT:DeleteObject=c_gdi42.DeleteObject")
#pragma comment(linker,"/EXPORT:GetDeviceCaps=c_gdi42.GetDeviceCaps")
#pragma comment(linker,"/EXPORT:GetObjectA=c_gdi42.GetObjectA")
#pragma comment(linker,"/EXPORT:GetStockObject=c_gdi42.GetStockObject")
#pragma comment(linker,"/EXPORT:GetTextExtentPoint32A=c_gdi42.GetTextExtentPoint32A")
#pragma comment(linker,"/EXPORT:GetTextMetricsA=c_gdi42.GetTextMetricsA")
#pragma comment(linker,"/EXPORT:IntersectClipRect=c_gdi42.IntersectClipRect")
#pragma comment(linker,"/EXPORT:SelectObject=c_gdi42.SelectObject")
#pragma comment(linker,"/EXPORT:SetBkMode=c_gdi42.SetBkMode")
#pragma comment(linker,"/EXPORT:SetTextColor=c_gdi42.SetTextColor")
#pragma comment(linker,"/EXPORT:TextOutA=c_gdi42.TextOutA")


/*
#pragma comment(linker,"/EXPORT:CreateCompatibleDC=_JmpCreateCompatibleDC")
#pragma comment(linker,"/EXPORT:CreateDIBSection=_JmpCreateDIBSection")
#pragma comment(linker,"/EXPORT:CreateFontA=_JmpCreateFontA")
#pragma comment(linker,"/EXPORT:CreateFontIndirectA=_JmpCreateFontIndirectA")
#pragma comment(linker,"/EXPORT:CreateSolidBrush=_JmpCreateSolidBrush")
#pragma comment(linker,"/EXPORT:DeleteDC=_JmpDeleteDC")
#pragma comment(linker,"/EXPORT:DeleteObject=_JmpDeleteObject")
#pragma comment(linker,"/EXPORT:GetDeviceCaps=_JmpGetDeviceCaps")
#pragma comment(linker,"/EXPORT:GetObjectA=_JmpGetObjectA")
#pragma comment(linker,"/EXPORT:GetStockObject=_JmpGetStockObject")
#pragma comment(linker,"/EXPORT:GetTextExtentPoint32A=_JmpGetTextExtentPoint32A")
#pragma comment(linker,"/EXPORT:GetTextMetricsA=_JmpGetTextMetricsA")
#pragma comment(linker,"/EXPORT:IntersectClipRect=_JmpIntersectClipRect")
#pragma comment(linker,"/EXPORT:SelectObject=_JmpSelectObject")
#pragma comment(linker,"/EXPORT:SetBkMode=_JmpSetBkMode")
#pragma comment(linker,"/EXPORT:SetTextColor=_JmpSetTextColor")
#pragma comment(linker,"/EXPORT:TextOutA=_JmpTextOutA")

void* pCreateCompatibleDC = nullptr;
void* pCreateDIBSection = nullptr;
void* pCreateFontA = nullptr;
void* pCreateFontIndirectA = nullptr;
void* pCreateSolidBrush = nullptr;
void* pDeleteDC = nullptr;
void* pDeleteObject = nullptr;
void* pGetDeviceCaps = nullptr;
void* pGetObjectA = nullptr;
void* pGetStockObject = nullptr;
void* pGetTextExtentPoint32A = nullptr;
void* pGetTextMetricsA = nullptr;
void* pIntersectClipRect = nullptr;
void* pSelectObject = nullptr;
void* pSetBkMode = nullptr;
void* pSetTextColor = nullptr;
void* pTextOutA = nullptr;


extern"C" {
    __declspec(naked)void __cdecl JmpCreateCompatibleDC(void) {
        __asm jmp pCreateCompatibleDC;
    }
    __declspec(naked)void __cdecl JmpCreateDIBSection(void) {
        __asm jmp pCreateDIBSection;

    }
    __declspec(naked)void __cdecl JmpCreateFontA(void) {
        __asm jmp pCreateFontA;
    }
    __declspec(naked)void __cdecl JmpCreateFontIndirectA(void) {
        __asm   jmp pCreateFontIndirectA;

    }
    __declspec(naked)void __cdecl JmpCreateSolidBrush(void) {
        __asm  jmp pCreateSolidBrush;

    }
    __declspec(naked)void __cdecl JmpDeleteDC(void) {
        __asm  jmp pDeleteDC;

    }
    __declspec(naked)void __cdecl JmpDeleteObject(void) {
        __asm jmp pDeleteObject;
    }
    __declspec(naked)void __cdecl JmpGetDeviceCaps(void) {
        __asm jmp pGetDeviceCaps;
    }
    __declspec(naked)void __cdecl JmpGetObjectA(void) {
        __asm   jmp pGetObjectA;
    }
    __declspec(naked)void __cdecl JmpGetStockObject(void) {
        __asm   jmp pGetStockObject;
    }
    __declspec(naked)void __cdecl JmpGetTextExtentPoint32A(void) {
        __asm  jmp pGetTextExtentPoint32A;
    }
    __declspec(naked)void __cdecl JmpGetTextMetricsA(void) {
        __asm   jmp pGetTextMetricsA;
    }
    __declspec(naked)void __cdecl JmpIntersectClipRect(void) {
        __asm    jmp pIntersectClipRect;

    }
    __declspec(naked)void __cdecl JmpSelectObject(void) {
        __asm    jmp pSelectObject;
    }
    __declspec(naked)void __cdecl JmpSetBkMode(void) {
        __asm jmp pSetBkMode;
        
    }
    __declspec(naked)void __cdecl JmpSetTextColor(void) {
        __asm jmp pSetTextColor;

    }
    __declspec(naked)void __cdecl JmpTextOutA(void) {
        __asm jmp pTextOutA;

    }
};

 void Run() {
    wchar_t wPath[MAX_PATH]{};
    GetModuleFileName(GetModuleHandle(nullptr), wPath, MAX_PATH);
    std::wstring wsPath = wPath;
    wsPath.erase(wsPath.rfind(L"\\") + 1);
    wsPath += L"c_gdi42.dll";
    HMODULE hModule = LoadLibrary(wsPath.c_str());
    pCreateCompatibleDC = GetProcAddress(hModule, "CreateCompatibleDC");
    pCreateDIBSection = GetProcAddress(hModule, "CreateDIBSection");
    pCreateFontA = GetProcAddress(hModule, "CreateFontA");
    pCreateFontIndirectA = GetProcAddress(hModule, "CreateFontIndirectA");
    pCreateSolidBrush = GetProcAddress(hModule, "CreateSolidBrush");
    pDeleteDC = GetProcAddress(hModule, "DeleteDC");
    pDeleteObject = GetProcAddress(hModule, "DeleteObject");
    pGetDeviceCaps = GetProcAddress(hModule, "GetDeviceCaps");
    pGetObjectA = GetProcAddress(hModule, "GetObjectA");
    pGetStockObject = GetProcAddress(hModule, "GetStockObject");
    pGetTextExtentPoint32A = GetProcAddress(hModule, "GetTextExtentPoint32A");
    pGetTextMetricsA = GetProcAddress(hModule, "GetTextMetricsA");
    pIntersectClipRect = GetProcAddress(hModule, "IntersectClipRect");
    pSelectObject = GetProcAddress(hModule, "SelectObject");
    pSetBkMode = GetProcAddress(hModule, "SetBkMode");
    pSetTextColor = GetProcAddress(hModule, "SetTextColor");
    pTextOutA = GetProcAddress(hModule, "TextOutA");

}
 */


BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved){
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
    {//HWND hWnd = FindWindow(L"MainWindow", L"PlantsVsZombies Plus Version 95");
    //MessageBox(hWnd, L"注入成功", L"info", NULL);
    //Run();
    break; }
    case DLL_PROCESS_DETACH:
        break;
    }
}