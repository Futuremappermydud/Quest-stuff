#include <regex.h>

#define ASSETS_REGEX "\\/data\\/app\\/com\\.beatgames\\.beatsaber-[0-9]\\/base\\.apk\\/assets\\/bin\\/Data\\/(.*)"

int main() {
    regex_t regex;
    int status;
    regmatch_t pmatch[2];
    char * test = "/data/app/com.beatgames.beatsaber-2/base.apk/assets/bin/Data/sharedassets12.assets.split0";

    if (regcomp(&regex, ASSETS_REGEX, REG_ICASE|REG_EXTENDED) != 0) {
        printf("good\n");
        status = regexec(&regex, test, 2, pmatch, 0);
        if (status == 0)
        {
            printf("found match\n");
        }
        else
        {
            printf("nomatch\n");
        }
        
    }
    else
    {
        printf("error\n");
    }
    return 0;
}

 