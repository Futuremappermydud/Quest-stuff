// To use, simply add customui.cpp to your Android.mk, and #include customui.h
// CUSTOM UI

#include <jni.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "utils.h"
#include <android/log.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include "customui.h"

using namespace std;

#include "../dumps/UnityEngine_GameObject.h"
#include "../dumps/UnityEngine_RectTransform.h"
#include "../dumps/UnityEngine_Transform.h"
#include "../dumps/TMPro_TextMeshProUGUI.h"
#include "../dumps/UnityEngine_Resources.h"
#include "../dumps/UnityEngine_Object.h"
#include "../dumps/System_Type.h"
#include "../dumps/TMPro_TMP_FontAsset.h"
#include "../dumps/TMPro_TMP_Text.h"

namespace CustomUI {
    Il2CppObject* createtext(Il2CppObject* parent_transform, string_view text, Vector2 anchoredPosition, Vector2 sizeDelta) {
        // Initialize necessary MethodInfos
        UnityEngine_GameObject::Init();
        UnityEngine_Object::Init();
        UnityEngine_RectTransform::Init();
        UnityEngine_Resources::Init();
        UnityEngine_Transform::Init();
        TMPro_TextMeshProUGUI::Init();
        System_Type::Init();
        TMPro_TMP_FontAsset::Init();
        TMPro_TMP_Text::Init();

        Il2CppObject* gameObj = il2cpp_utils::NewUnsafe(UnityEngine_GameObject::klass, il2cpp_utils::createcsstr("CustomUIText"));
        Il2CppException* exp;
        bool value = false;
        void* args1[] = {&value};
        il2cpp_functions::runtime_invoke(UnityEngine_GameObject::SetActive_bool, gameObj, args1, &exp);
        if (exp) {
            // EXCEPTION
            log(CRITICAL, "%s", il2cpp_utils::ExceptionToString(exp).c_str());
            return nullptr;
        }

        // Get Type of TMPro.TextMeshProUGUI
        void* args2[] = {il2cpp_utils::createcsstr("TMPro.TextMeshProUGUI")};
        Il2CppObject* type_tmprougui = il2cpp_functions::runtime_invoke(System_Type::GetType_string, nullptr, args2, &exp);
        if (exp) {
            // EXCEPTION
            log(CRITICAL, "%s", il2cpp_utils::ExceptionToString(exp).c_str());
            return nullptr;
        }
        // Add Component via type
        void* args3[] = {type_tmprougui};
        Il2CppObject* textMesh = il2cpp_functions::runtime_invoke(UnityEngine_GameObject::AddComponent_Type, gameObj, args3, &exp);
        if (exp) {
            // EXCEPTION
            log(CRITICAL, "%s", il2cpp_utils::ExceptionToString(exp).c_str());
            return nullptr;
        }

        // Get Type of TMPro.TMP_FontAsset
        void* args4[] = {il2cpp_utils::createcsstr("TMPro.TMP_FontAsset")};
        Il2CppObject* type_fontasset = il2cpp_functions::runtime_invoke(System_Type::GetType_string, nullptr, args4, &exp);
        if (exp) {
            // EXCEPTION
            log(CRITICAL, "%s", il2cpp_utils::ExceptionToString(exp).c_str());
            return nullptr;
        }

        // Find Font Assets
        void* args5[] = {type_fontasset};
        auto allObjects = reinterpret_cast<Array<Il2CppObject*>*>(il2cpp_functions::runtime_invoke(UnityEngine_Resources::FindObjectsOfTypeAll_Type, nullptr, args5, &exp));
        if (exp) {
            // EXCEPTION
            log(CRITICAL, "%s", il2cpp_utils::ExceptionToString(exp).c_str());
            return nullptr;
        }

        // Instantiate first asset, for now, don't care if we match the font name or not.
        int match = -1;
        for (int i = 0; i < allObjects->Length(); i++) {
            // Treat it as a UnityEngine.Object (which it is) and call the name getter
            Il2CppString* assetName = reinterpret_cast<Il2CppString*>(il2cpp_functions::runtime_invoke(UnityEngine_Object::get_name, allObjects->values[i], nullptr, &exp));
            if (exp) {
                // EXCEPTION
                log(CRITICAL, "%s", il2cpp_utils::ExceptionToString(exp).c_str());
                return nullptr;
            }
            if (strcmp(to_utf8(csstrtostr(assetName)).c_str(), "Teko-Medium SDF No Glow") == 0) {
                // Found matching asset
                match = i;
                break;
            }
        }
        if (match == -1) {
            log(CRITICAL, "Could not find matching TMP_FontAsset!");
            return nullptr;
        }

        // Instantiate font
        void* args6[] = {allObjects->values[match]};
        auto font = il2cpp_functions::runtime_invoke(UnityEngine_Object::Instantiate_Object, nullptr, args6, &exp);
        if (exp) {
            // EXCEPTION
            log(CRITICAL, "%s", il2cpp_utils::ExceptionToString(exp).c_str());
            return nullptr;
        }

        // Set font
        void* args7[] = {font};
        il2cpp_functions::runtime_invoke(TMPro_TMP_Text::set_font, textMesh, args7, &exp);
        if (exp) {
            // EXCEPTION
            log(CRITICAL, "%s", il2cpp_utils::ExceptionToString(exp).c_str());
            return nullptr;
        }

        // Get RectTransform
        auto rectTransform = il2cpp_functions::runtime_invoke(TMPro_TMP_Text::get_rectTransform, textMesh, nullptr, &exp);
        if (exp) {
            // EXCEPTION
            log(CRITICAL, "%s", il2cpp_utils::ExceptionToString(exp).c_str());
            return nullptr;
        }

        // Set Parent
        bool placeholder = false;
        void* args8[] = {parent_transform, &placeholder};
        il2cpp_functions::runtime_invoke(UnityEngine_Transform::SetParent_Transform_bool, rectTransform, args8, &exp);
        if (exp) {
            // EXCEPTION
            log(CRITICAL, "%s", il2cpp_utils::ExceptionToString(exp).c_str());
            return nullptr;
        }

        // Set text
        void* args9[] = {il2cpp_utils::createcsstr(text)};
        il2cpp_functions::runtime_invoke(TMPro_TMP_Text::set_text, textMesh, args9, &exp);
        if (exp) {
            // EXCEPTION
            log(CRITICAL, "%s", il2cpp_utils::ExceptionToString(exp).c_str());
            return nullptr;
        }

        // Set fontSize
        float val = 4;
        void* args10[] = {&val};
        il2cpp_functions::runtime_invoke(TMPro_TMP_Text::set_fontSize, textMesh, args10, &exp);
        if (exp) {
            // EXCEPTION
            log(CRITICAL, "%s", il2cpp_utils::ExceptionToString(exp).c_str());
            return nullptr;
        }

        // Set color
        Color c = {0.0, 0.0, 0.0, 0.0};
        void* args11[] = {&c};
        il2cpp_functions::runtime_invoke(TMPro_TMP_Text::set_color, textMesh, args11, &exp);
        if (exp) {
            // EXCEPTION
            log(CRITICAL, "%s", il2cpp_utils::ExceptionToString(exp).c_str());
            return nullptr;
        }

        // Set rectTransform.anchorMin
        Vector2 anch_min = {0.5, 0.5};
        void* args12[] = {&anch_min};
        il2cpp_functions::runtime_invoke(UnityEngine_RectTransform::set_anchorMin, rectTransform, args12, &exp);
        if (exp) {
            // EXCEPTION
            log(CRITICAL, "%s", il2cpp_utils::ExceptionToString(exp).c_str());
            return nullptr;
        }

        // Set rectTransform.anchorMax
        Vector2 anch_max = {0.5, 0.5};
        void* args13[] = {&anch_max};
        il2cpp_functions::runtime_invoke(UnityEngine_RectTransform::set_anchorMax, rectTransform, args13, &exp);
        if (exp) {
            // EXCEPTION
            log(CRITICAL, "%s", il2cpp_utils::ExceptionToString(exp).c_str());
            return nullptr;
        }

        // Set rectTransform.sizeDelta
        void* args14[] = {&sizeDelta};
        il2cpp_functions::runtime_invoke(UnityEngine_RectTransform::set_sizeDelta, rectTransform, args14, &exp);
        if (exp) {
            // EXCEPTION
            log(CRITICAL, "%s", il2cpp_utils::ExceptionToString(exp).c_str());
            return nullptr;
        }

        // Set rectTransform.anchoredPosition
        void* args15[] = {&anchoredPosition};
        il2cpp_functions::runtime_invoke(UnityEngine_RectTransform::set_anchoredPosition, rectTransform, args15, &exp);
        if (exp) {
            // EXCEPTION
            log(CRITICAL, "%s", il2cpp_utils::ExceptionToString(exp).c_str());
            return nullptr;
        }

        // SetActive
        bool place = true;
        void* args16[] = {&place};
        il2cpp_functions::runtime_invoke(UnityEngine_GameObject::SetActive_bool, gameObj, args16, &exp);
        if (exp) {
            // EXCEPTION
            log(CRITICAL, "%s", il2cpp_utils::ExceptionToString(exp).c_str());
            return nullptr;
        }

        return textMesh;
    }
}