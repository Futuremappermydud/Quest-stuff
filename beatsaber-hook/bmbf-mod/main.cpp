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
#include <sys/mman.h>
#include <errno.h>
#include "../shared/inline-hook/inlineHook.h"
#include "../shared/utils/utils.h"
#include <regex.h>
#include "../shared/inline-hook/And64InlineHook.hpp"

#define ASSETS_REGEX "\\/data\\/app\\/com\\.beatgames\\.beatsaber-[0-9]\\/base\\.apk\\/assets\\/bin\\/Data\\/(.*)"
const char* ASSETS_TARGET = "/sdcard/BMBFData/BeatSaberAssets/";

#define SONGS_REGEX "\\/data\\/app\\/com\\.beatgames\\.beatsaber-[0-9]\\/base\\.apk\\/assets\\/bin\\/Data\\/CustomSongs\\/(.*)"
const char* SONGS_TARGET = "/sdcard/BMBFData/CustomSongs/";

#define STARTSWITH(pre, str) ((strlen(str) < strlen(pre)) ? 0 : strncmp(pre, str, strlen(pre)) == 0)

regex_t assetsRegex;
regex_t songsRegex;
uint globalOpid = 0;

MAKE_HOOK_NAT(open_nat, open, int, char* path, int oflag, mode_t mode)
{
    int opid = globalOpid++;
    int filePtr = -1;
    char bfr[500];
    regmatch_t pmatch[2];
    if (regexec(&songsRegex, path, 2, pmatch, 0) == 0) {
        //log_print(INFO, "%i ** OPEN: SONG remap path match **", opid);
        //log_print(INFO, "%i From: %s\n", opid, path);        
        memset(bfr, 0, sizeof bfr);
        strcpy(bfr, SONGS_TARGET);
        strcpy(bfr+strlen(SONGS_TARGET), path + pmatch[1].rm_so);
        //log_print(INFO, "%i To: %s\n", opid, bfr);
        filePtr = open_nat(bfr, oflag, mode);
        if (filePtr < 0) {
            //log_print(INFO, "%i ** OPEN: No SONG remap, remapped file did not open **", opid);
            //log_print(INFO, "%i errno: %i %s", opid, errno, strerror(errno));
            return open_nat(path, oflag, mode);
        } else
        {
            //log_print(INFO, "OPEN: SONG REMAP SUCCESS to: %s", bfr);
            return filePtr;
        }
    } else if (regexec(&assetsRegex, path, 2, pmatch, 0) == 0) {
        //log_print(INFO, "%i ** OPEN: ASSET remap path match **", opid);
        //log_print(INFO, "%i From: %s\n", opid, path);        
        memset(bfr, 0, sizeof bfr);
        strcpy(bfr, ASSETS_TARGET);
        strcpy(bfr+strlen(ASSETS_TARGET), path + pmatch[1].rm_so);
        //log_print(INFO, "%i To: %s\n", opid, bfr);
        filePtr = open_nat(bfr, oflag, mode);
        if (filePtr < 0) {
            //log_print(INFO, "%i ** OPEN: No ASSET remap, remapped file did not open **", opid);
            //log_print(INFO, "%i errno: %i %s", opid, errno, strerror(errno));
            return open_nat(path, oflag, mode);
        } else
        {
            //log_print(INFO, "OPEN: ASSET REMAP SUCCESS to: %s", bfr);
            return filePtr;
        }
    } else {
      //  if (!STARTSWITH("/sys", path) && !STARTSWITH("/proc", path) && !STARTSWITH("/dev", path))
        //    log_print(INFO, "%i Normal open: %s", opid, path);

        return open_nat(path, oflag, mode);
    }
}

MAKE_HOOK_NAT(stat_nat, stat, int, char *path, struct stat *buf)
{
    int opid = globalOpid++;
    int statResult = -1;
    char bfr[500];
    regmatch_t pmatch[2];
    if (regexec(&songsRegex, path, 2, pmatch, 0) == 0) {
        //log_print(INFO, "%i ^^ STAT: SONG remap path match ^^", opid);
        //log_print(INFO, "%i From: %s\n", opid, path);        
        memset(bfr, 0, sizeof bfr);
        strcpy(bfr, SONGS_TARGET);
        strcpy(bfr+strlen(SONGS_TARGET), path + pmatch[1].rm_so);
        //log_print(INFO, "%i To: %s\n", opid, bfr);
        statResult = stat_nat(bfr, buf);
        if (statResult < 0) {
            //log_print(INFO, "%i ^^ STAT: No SONG remap, remapped file did not stat ^^", opid);
            //log_print(INFO, "%i errno: %i %s", opid, errno, strerror(errno));
            return stat_nat(path, buf);
        } else
        {
            log_print(INFO, "STAT: SONG REMAP SUCCESS to: %s", bfr);
            return statResult;
        }
    } else if (regexec(&assetsRegex, path, 2, pmatch, 0) == 0) {
        //log_print(INFO, "%i ^^ STAT: ASSET remap path match ^^", opid);
        //log_print(INFO, "%i From: %s\n", opid, path);        
        memset(bfr, 0, sizeof bfr);
        strcpy(bfr, ASSETS_TARGET);
        strcpy(bfr+strlen(ASSETS_TARGET), path + pmatch[1].rm_so);
        //log_print(INFO, "%i To: %s\n", opid, bfr);
        statResult = stat_nat(bfr, buf);
        if (statResult < 0) {
            //log_print(INFO, "%i ^^ STAT: No ASSET remap, remapped file did not stat ^^", opid);
           // log_print(INFO, "%i errno: %i %s", opid, errno, strerror(errno));
            return stat_nat(path, buf);
        } else
        {
           // log_print(INFO, "STAT: ASSET REMAP SUCCESS To: %s", bfr);
            return statResult;
        }
    } else {
     //   if (!STARTSWITH("/sys", path) && !STARTSWITH("/proc", path) && !STARTSWITH("/dev", path))
       //     log_print(INFO, "%i Normal stat: %s", opid, path);

        return stat_nat(path, buf);
    }
}


__attribute__((constructor)) void lib_main()
{
    log_print(INFO, "Init of BMBF file remapper");
    if (regcomp(&assetsRegex, ASSETS_REGEX,REG_ICASE|REG_EXTENDED) != 0) {
        log_print(INFO, "Failed to compile regex for assets!");
    }
    if (regcomp(&songsRegex, SONGS_REGEX,REG_ICASE|REG_EXTENDED) != 0) {
        log_print(INFO, "Failed to compile regex for songs!");
    }
    
    INSTALL_HOOK_NAT(open_nat);
    log_print(INFO, "open hook installed!");
	INSTALL_HOOK_NAT(stat_nat);
    log_print(INFO, "stat hook installed!");
}

void init() noexcept {
    log_print(INFO, "Called bmbfmod init!");
}

void load() noexcept {
    log_print(INFO, "Called bmbfmod load!");
}