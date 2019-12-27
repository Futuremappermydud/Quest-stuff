// To use, simply add customui.cpp to your Android.mk, and #include customui.hpp
// CUSTOM UI

#include "../utils/utils.h"
#include "customui.hpp"

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
    // Only construct one!
    ModSettings::ModSettings() {
        log(DEBUG, "Creating new ModSettings object!");
    }
    ModSettings* ModSettings::GetInstance() {
        if (_instance == nullptr) {
            _instance = new ModSettings();
        }
        return _instance;
    }
    void ModSettings::AddButtonToMainScreen() {
        // Create types needed here:
        // Create button type here
        auto static componentClass = il2cpp_utils::GetClassFromName("UnityEngine", "Component");
        auto static objClass = il2cpp_utils::GetClassFromName("UnityEngine", "Object");
        auto static goClass = il2cpp_utils::GetClassFromName("UnityEngine", "GameObject");
        auto static buttonClass = il2cpp_utils::GetClassFromName("UnityEngine.UI", "Button");
        auto static transformClass = il2cpp_utils::GetClassFromName("UnityEngine", "Transform");
        auto static localizedTextMeshProUGUIClass = il2cpp_utils::GetClassFromName("Polyglot", "LocalizedTextMeshProUGUI");
        auto static unityEventClass = il2cpp_utils::GetClassFromName("UnityEngine.Events", "UnityEvent");
        auto static unityActionClass = il2cpp_utils::GetClassFromName("UnityEngine.Events", "UnityAction");

        auto static findMethod = il2cpp_utils::GetMethod(goClass, "Find", 1);
        auto static getTransform = il2cpp_utils::GetMethod(componentClass, "get_transform", 0);
        auto static getChild = il2cpp_utils::GetMethod(transformClass, "GetChild", 1);
        auto static transformSetSiblingIndex = il2cpp_utils::GetMethod(transformClass, "SetSiblingIndex", 1);
        auto static instantiate = il2cpp_utils::GetMethod(objClass, "Instantiate", 2);
        auto static nonGenericGetComponent = il2cpp_utils::GetMethod(componentClass, "GetComponent", 1);
        auto static nonGenericGetComponentInChildren = il2cpp_utils::GetMethod(componentClass, "GetComponentInChildren", 1);
        auto static buttonGetOnClick = il2cpp_utils::GetMethod(buttonClass, "get_onClick", 0);
        auto static unityEventAddListener = il2cpp_utils::GetMethod(unityEventClass, "AddListener", 1);

        auto static buttonType = il2cpp_functions::class_get_type(buttonClass);
        auto static localizedTextMeshProUGUIType = il2cpp_functions::class_get_type(localizedTextMeshProUGUIClass);
        auto static unityActionType = il2cpp_functions::class_get_type(unityActionClass);

        Il2CppObject* transform = nullptr;
        uint16_t count = 0;
        while (transform == nullptr && count < 10000) {
            auto static menuLocation = il2cpp_utils::createcsstr("MainMenuViewController/BottomPanel/Buttons");
            if (il2cpp_utils::RunMethod(&transform, findMethod, menuLocation)) {
                il2cpp_utils::RunMethod(&transform, transform, getTransform);
            }
            ++count;
        }
        if (transform == nullptr) {
            log(CRITICAL, "Could not find bottom panel buttons even after 10000 attempts!");
            exit(1);
        }

        // createdButton = UnityEngine.Object.Instantiate(transform.GetChild(0), transform).GetComponent(typeof(UnityEngine.UI.Button));
        Il2CppObject* buttonChild0;
        int childNumber = 0;
        il2cpp_utils::RunMethod(&buttonChild0, transform, getChild, &childNumber);
        Il2CppObject* createdButton;
        il2cpp_utils::RunMethod(&createdButton, objClass, instantiate, buttonChild0, transform);
        il2cpp_utils::RunMethod(&createdButton, createdButton, nonGenericGetComponent, buttonType);
        // createdButton.get_transform().GetChild(0).GetChild(1).GetComponentInChildren(typeof(Polyglot.LocalizedTextMeshProUGUI)).set_Key("Mod Settings");
        Il2CppObject* buttonTransform;
        il2cpp_utils::RunMethod(&buttonTransform, createdButton, getTransform);
        Il2CppObject* temp;
        il2cpp_utils::RunMethod(&temp, buttonTransform, getChild, &childNumber);
        childNumber = 1;
        il2cpp_utils::RunMethod(&temp, temp, getChild, &childNumber);
        il2cpp_utils::RunMethod(&temp, temp, nonGenericGetComponentInChildren, localizedTextMeshProUGUIType);
        il2cpp_utils::RunMethod(&temp, temp, "set_Key", il2cpp_utils::createcsstr("Mod Settings"));
        // createdButton.get_onClick().AddListener(PresentSettings);
        il2cpp_utils::RunMethod(&temp, createdButton, buttonGetOnClick);
        auto action = il2cpp_utils::MakeAction(createdButton, (void*)PresentSettings, unityActionType);
        il2cpp_utils::RunMethod(temp, unityEventAddListener, action);
        // createdButton.get_transform().SetSiblingIndex(0);
        childNumber = 0;
        il2cpp_utils::RunMethod(buttonTransform, transformSetSiblingIndex, &childNumber);
    }
    void PresentSettings() {

    }
}