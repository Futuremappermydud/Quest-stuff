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

#define MOD_ID "XPre"
#define VERSION "0.0.1"

#include "../beatsaber-hook/shared/inline-hook/inlineHook.h"
#include "../beatsaber-hook/shared/utils/utils.h"
#include "../beatsaber-hook/shared/utils/il2cpp-utils.hpp"

using namespace std;

MAKE_HOOK_OFFSETLESS(ColorScheme(string colorSchemeId, string colorSchemeName, bool isEditable, Color saberAColor, Color saberBColor, Color environmentColor0, Color environmentColor1, Color obstaclesColor)) {
    Il2CppClass* Class = il2cpp_utils::GetClassFromName("", "ColorScheme")
    Il2CppString* id = il2cpp_utils::createcsstr("colorSchemeID");
    Il2CppString* name = il2cpp_utils::createcsstr("colorSchemeName");
    Color LeftSaber = {1.0f, 1.0f, 1.0f, 1.0f};
    Color RightSaber = {1.0f, 1.0f, 1.0f, 1.0f};
    Color LeftLight = {1.0f, 1.0f, 1.0f, 1.0f};
    Color RightLight = {1.0f, 1.0f, 1.0f, 1.0f};
    Color Walls = {1.0f, 1.0f, 1.0f, 1.0f};
    m["_colorSchemesDict"] = id;
    m["_colorSchemesDict"] = name;
    m["_colorSchemesDict"] = LeftSaber;
    m["_colorSchemesDict"] = RightSaber;
    m["_colorSchemesDict"] = LeftLight;
    m["_colorSchemesDict"] = RightLight;
    m["_colorSchemesDict"] = Walls;
    _colorSchemesList.push_back (id);
    _colorSchemesList.push_back (name);
    _colorSchemesList.push_back (LeftSaber);
    _colorSchemesList.push_back (RightSaber);
    _colorSchemesList.push_back (LeftLight);
    _colorSchemesList.push_back (RightLight);
    _colorSchemesList.push_back (Walls);
    /* now i need to based on sc2ad
    well, first you need to get the actual ColorSettings instance
then you need to get those fields
then you call the Add method on both of them */
    bool isEditable = false
}
auto myCustomColorScheme = il2cpp_utils::NewUnsafe(colorSchemeClass, colorSchemeId, colorSchemeName, isEditable, &saberAColor, &saberBColor, &envColor0, &envColor1, &obstacleColor)
void* libil2cpphandle;
MAKE_HOOK_OFFSETLESS(init_hook, void, const char* domain_name) {
    dlclose(libil2cpphandle);
    init_hook(domain_name);
    log(DEBUG, "Installing SongPreviewRemover");
    auto klass = il2cpp_utils::GetClassFromName("", "SongPreviewPlayer");
    auto method = il2cpp_utils::GetMethod(klass, "set_volume", 1);
    INSTALL_HOOK_OFFSETLESS(set_volume, method);
    log(DEBUG, "Successfully installed SongPreviewRemover!");
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
};