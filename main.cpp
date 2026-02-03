#include <windows.h>
#include <thread>

// Kebap Menu by Selim - Basit DLL İskeleti
void HackThread() {
    while (true) {
        // Sağ Shift basılı mı kontrol et
        if (GetAsyncKeyState(VK_RSHIFT) & 1) {
            // Bir bip sesi çıkar ki çalıştığını anla
            Beep(750, 300); 
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        // Selim'e selam çak
        MessageBoxA(NULL, "Kebap Menu by Selim Yuklendi!", "Basarili", MB_OK);
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)HackThread, NULL, 0, NULL);
    }
    return TRUE;
}
