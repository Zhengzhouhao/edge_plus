#include "edge++.h"

extern "C" BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID pv)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);
        hInstance = hModule;

        // 保持系统dll原有功能
        LoadSysDll(hModule);

        LPWSTR cmd = GetCommandLineW();
        if (!wcsstr(cmd, L"--type="))
        {
            UI();
        }
    }
    return TRUE;
}
