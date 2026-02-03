#include <windows.h>

// Bu kısım DLL'in giriş kapısıdır.
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        // Oyunun içine girdiği an bu bip sesini duyman lazım!
        Beep(750, 500); 
        // Bu kutu çıkmıyorsa enjeksiyon başarısızdır.
        MessageBoxA(NULL, "Sistem Aktif: DLL Basariyla Enjekte Edildi!", "Selim Test", MB_OK | MB_ICONINFORMATION);
        break;
    }
    return TRUE;
}
