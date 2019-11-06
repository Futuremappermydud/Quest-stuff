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

#define FlyingScoreEffect_InitAndPresent 0xA49BFC

MAKE_HOOK(FlyingObjectInit, FlyingObjectInit_offset, void, void *self, void *NoteCutInfo ,int multiplier , float duration, Vector3 targetPos, Color Color) {
    log(DEBUG, "Called FlyingScoreEffect_InitAndPresent!);
    return FlyingScoreEffect_InitAndPresent(self);
}   