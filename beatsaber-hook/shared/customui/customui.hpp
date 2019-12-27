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
#include "../utils/typedefs.h"

#include "../dumps/UnityEngine_GameObject.hpp"
#include "../dumps/UnityEngine_RectTransform.hpp"
#include "../dumps/UnityEngine_Transform.hpp"
#include "../dumps/TMPro_TextMeshProUGUI.hpp"
#include "../dumps/UnityEngine_Resources.hpp"
#include "../dumps/UnityEngine_Object.hpp"
#include "../dumps/System_Type.hpp"
#include "../dumps/TMPro_TMP_FontAsset.hpp"
#include "../dumps/TMPro_TMP_Text.hpp"

namespace CustomUI {
    // Creates a custom TMP_TextMeshProUGUI object and returns it
    Il2CppObject* createtext(Il2CppObject* parent_transform, std::string_view text, Vector2 anchoredPosition, Vector2 sizeDelta);
    // Mod Settings Container Class
    class ModSettings {
        private:
            ModSettings();
            Il2CppObject* _gottenMainMenuButton;
            Il2CppObject* _createdButton;
            Il2CppObject* _flowCoordinator;
            static ModSettings* _instance;
        public:
            static ModSettings* GetInstance();
            static void AddButtonToMainScreen();
            static void SetupViewControllerTransform(Il2CppObject* viewController);
    };
    class CustomFlowCoordinator {
        public:
            void PresentFlowCoordinator(Il2CppObject* flowCoordinator, function_ptr_t<void> callback);
    };
    static Il2CppObject* CreateFlowCoordinator(function_ptr_t<void, bool, int> didActivate);
}

#endif /* CUSTOMUI_DEFINED */