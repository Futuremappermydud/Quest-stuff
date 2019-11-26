#ifndef CUSTOMUI_DEFINED
#define CUSTOMUI_DEFINED

#include <string.h>
#include <string_view>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include "typedefs.h"

namespace CustomUI {
    // Creates a custom TMP_TextMeshProUGUI object and returns it
    Il2CppObject* createtext(Il2CppObject* parent_transform, std::string_view text, Vector2 anchoredPosition, Vector2 sizeDelta);
}

#endif /* CUSTOMUI_DEFINED */