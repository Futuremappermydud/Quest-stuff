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
#include "customui.hpp"

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
    Il2CppObject* createtext(Il2CppObject* parent_transform, std::string_view text, Vector2 anchoredPosition, Vector2 sizeDelta) {
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

        // Make new GameObject("CustomUIText")
        Il2CppObject* gameObj = il2cpp_utils::NewUnsafe(UnityEngine_GameObject::klass, il2cpp_utils::createcsstr("CustomUIText"));
        bool value = false;
        
        if (!il2cpp_utils::RunMethod(gameObj, UnityEngine_GameObject::SetActive_bool, &value)) {
            // EXCEPTION
            return nullptr;
        }

        // Get Type of TMPro.TextMeshProUGUI
        Il2CppObject* type_tmprougui;
        if (!il2cpp_utils::RunMethod(&type_tmprougui, nullptr, System_Type::GetType_string, il2cpp_utils::createcsstr("TMPro.TextMeshProUGUI"))) {
            // EXCEPTION
            return nullptr;
        }

        // Add Component via type
        Il2CppObject* textMesh;
        if (!il2cpp_utils::RunMethod(&textMesh, gameObj, UnityEngine_GameObject::AddComponent_Type, type_tmprougui)) {
            // EXCEPTION
            return nullptr;
        }

        // Get Type of TMPro.TMP_FontAsset
        Il2CppObject* type_fontasset;
        if (!il2cpp_utils::RunMethod(&type_fontasset, nullptr, System_Type::GetType_string, il2cpp_utils::createcsstr("TMPro.TMP_FontAsset"))) {
            // EXCEPTION
            return nullptr;
        }

        // Find Font Assets
        Array<Il2CppObject*>* allObjects;
        if (!il2cpp_utils::RunMethod(&allObjects, nullptr, UnityEngine_Resources::FindObjectsOfTypeAll_Type, type_fontasset)) {
            // EXCEPTION
            return nullptr;
        }

        // Instantiate first asset, for now, don't care if we match the font name or not.
        int match = -1;
        for (int i = 0; i < allObjects->Length(); i++) {
            // Treat it as a UnityEngine.Object (which it is) and call the name getter
            Il2CppString* assetName;
            if (!il2cpp_utils::RunMethod(&assetName, allObjects->values[i], UnityEngine_Object::get_name)) {
                // EXCEPTION
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
        Il2CppObject* font;
        if (!il2cpp_utils::RunMethod(&font, nullptr, UnityEngine_Object::Instantiate_Object, allObjects->values[match])) {
            // EXCEPTION
            return nullptr;
        }

        // Set font
        void* args7[] = {font};
        if (!il2cpp_utils::RunMethod(textMesh, TMPro_TMP_Text::set_font, font)) {
            // EXCEPTION
            return nullptr;
        }

        // Get RectTransform
        Il2CppObject* rectTransform;
        if (!il2cpp_utils::RunMethod(textMesh, TMPro_TMP_Text::get_rectTransform)) {
            // EXCEPTION
            return nullptr;
        }

        // Set Parent
        bool placeholder = false;
        if (!il2cpp_utils::RunMethod(rectTransform, UnityEngine_Transform::SetParent_Transform_bool, parent_transform, &placeholder)) {
            // EXCEPTION
            return nullptr;
        }

        // Set text
        if (!il2cpp_utils::RunMethod(textMesh, TMPro_TMP_Text::set_text, il2cpp_utils::createcsstr(text))) {
            // EXCEPTION
            return nullptr;
        }

        // Set fontSize
        float val = 4;
        if (!il2cpp_utils::RunMethod(textMesh, TMPro_TMP_Text::set_fontSize, &val)) {
            // EXCEPTION
            return nullptr;
        }

        // Set color
        Color c = {1.0, 1.0, 1.0, 1.0};
        if (!il2cpp_utils::RunMethod(textMesh, TMPro_TMP_Text::set_color, &c)) {
            // EXCEPTION
            return nullptr;
        }

        // Set rectTransform.anchorMin
        Vector2 anch_min = {0.5, 0.5};
        if (!il2cpp_utils::RunMethod(rectTransform, UnityEngine_RectTransform::set_anchorMin, &anch_min)) {
            // EXCEPTION
            return nullptr;
        }

        // Set rectTransform.anchorMax
        Vector2 anch_max = {0.5, 0.5};
        if (!il2cpp_utils::RunMethod(rectTransform, UnityEngine_RectTransform::set_anchorMax, &anch_max)) {
            // EXCEPTION
            return nullptr;
        }

        // Set rectTransform.sizeDelta
        if (!il2cpp_utils::RunMethod(rectTransform, UnityEngine_RectTransform::set_sizeDelta, &sizeDelta)) {
            // EXCEPTION
            return nullptr;
        }

        // Set rectTransform.anchoredPosition
        if (!il2cpp_utils::RunMethod(rectTransform, UnityEngine_RectTransform::set_anchoredPosition, &anchoredPosition)) {
            // EXCEPTION
            return nullptr;
        }

        // SetActive
        bool place = true;
        if (!il2cpp_utils::RunMethod(gameObj, UnityEngine_GameObject::SetActive_bool, &place)) {
            // EXCEPTION
            return nullptr;
        }

        return textMesh;
    }
}