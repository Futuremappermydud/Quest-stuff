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

#define MOD_ID "Begonescores"
#define VERSION "0.0.1"

#include "../beatsaber-hook/shared/inline-hook/inlineHook.h"
#include "../beatsaber-hook/shared/utils/utils.h"

using namespace std;

MAKE_HOOK_OFFSETLESS(FlyingObjectInit, void, void *self, void *NoteCutInfo ,int multiplier , float duration, Vector3 targetPos, Color Color) {
{
    duration = false ;
    return FlyingObjectInit(self, NoteCutInfo, multiplier, duration, Vector3 targetPos, Color Color;
}

__attribute__((constructor)) void lib_main()
{
    #ifdef __aarch64__
    log(INFO, "Is 64 bit!");
    #endif
    log(DEBUG, "Installing Begonescores");
    INSTALL_HOOK(FlyingObjectInit);
    log(DEBUG, "Successfully installed Begonescores!");
}
