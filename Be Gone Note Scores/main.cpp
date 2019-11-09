#include <android/log.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <linux/limits.h>
#include <sys/sendfile.h>
#include <sys/stat.h>

#define MOD_ID "Xscore"
#define VERSION "0.0.1"

#include "../beatsaber-hook/shared/inline-hook/inlineHook.h"
#include "../beatsaber-hook/shared/utils/utils.h"

using namespace std;

MAKE_HOOK_OFFSETLESS(FlyingObjectEffect, void, Il2CppObject* self, Il2CppObject* noteCutInfo ,int multiplier , float duration, Il2CppObject* targetPos,  Il2CppObject* color) {
    duration = 0 ;
    return FlyingObjectEffect(self, noteCutInfo, multiplier, duration, targetPos, color);
}
void* libil2cpphandle;
MAKE_HOOK_OFFSETLESS(init_hook, void, const char* domain_name) {
    dlclose(libil2cpphandle);
    init_hook(domain_name);
    log(DEBUG, "Installing Begonescores");
    auto klass = il2cpp_utils::GetClassFromName("", "FlyingObjectEffect");
    auto il2cpp_utils::GetMethod(klass, "InitAndPresent", 5);
    INSTALL_HOOK_OFFSETLESS(FlyingObjectEffect, "InitAndPresent");
    log(DEBUG, "Successfully installed Begonescores!");
}

// ...

__attribute__((constructor)) void lib_main() {
    #ifdef __aarch64__
    log(INFO, "Is 64 bit!");
    #endif
    il2cpp_functions::Init();
    libil2cpphandle = dlopen(IL2CPP_SO_PATH, RTLD_LOCAL | RTLD_LAZY);
    // optional, just gets the 2nd round of logging out of the way:
    il2cpp_utils::GetClassFromName("", "HealthWarningFlowCoordinator");
    INSTALL_HOOK_DIRECT(init_hook, il2cpp_functions::init);
}