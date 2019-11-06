#ifndef UnityEngine_GameObject_DEFINED
#define UnityEngine_GameObject_DEFINED
// This .hpp file was compiled via beatsaber-hook/shared/helper.py's Parse Mode.
// Created by Sc2ad.
// Methods may not be valid!
#include <dlfcn.h>
#include <string_view>
#include "../utils/typedefs.h"
#include "../utils/il2cpp-functions.hpp"
#include "../utils/il2cpp-utils.hpp"
// Contains MethodInfo/Il2CppClass data for: UnityEngine.GameObject
namespace UnityEngine_GameObject {
    // UnityEngine.GameObject
    typedef struct Class : Il2CppObject {
    } Class;
    static bool __cached = false;
    static Il2CppClass* klass;
    static const MethodInfo* CreatePrimitive_PrimitiveType;
    static const MethodInfo* GetComponent_generic;
    static const MethodInfo* GetComponent_Type;
    static const MethodInfo* GetComponentFastPath_Type_IntPtr;
    static const MethodInfo* GetComponentByName_string;
    static const MethodInfo* GetComponent_string;
    static const MethodInfo* GetComponentInChildren_Type_bool;
    static const MethodInfo* GetComponentInChildren_Type;
    static const MethodInfo* GetComponentInChildren_generic;
    static const MethodInfo* GetComponentInChildren_bool_generic;
    static const MethodInfo* GetComponentInParent_Type;
    static const MethodInfo* GetComponentsInternal_Type_bool_bool_bool_bool_object;
    static const MethodInfo* GetComponents_Type;
    static const MethodInfo* GetComponents;
    static const MethodInfo* GetComponents_List1;
    static const MethodInfo* GetComponentsInChildren_Type_bool;
    static const MethodInfo* GetComponentsInChildren_bool;
    static const MethodInfo* GetComponentsInChildren_bool_List1;
    static const MethodInfo* GetComponentsInChildren;
    static const MethodInfo* GetComponentsInParent_Type_bool;
    static const MethodInfo* GetComponentsInParent_bool_List1;
    static const MethodInfo* GetComponentsInParent_bool;
    static const MethodInfo* Internal_AddComponentWithType_Type;
    static const MethodInfo* AddComponent_Type;
    static const MethodInfo* AddComponent_generic;
    static const MethodInfo* get_transform;
    static const MethodInfo* get_layer;
    static const MethodInfo* set_layer;
    static const MethodInfo* SetActive_bool;
    static const MethodInfo* get_activeSelf;
    static const MethodInfo* get_activeInHierarchy;
    static const MethodInfo* get_tag;
    static const MethodInfo* set_tag;
    static const MethodInfo* FindGameObjectsWithTag_string;
    static const MethodInfo* SendMessage_string_object_SendMessageOptions;
    static const MethodInfo* BroadcastMessage_string_object_SendMessageOptions;
    static const MethodInfo* Internal_CreateGameObject_GameObject_string;
    static const MethodInfo* Find_string;
    static const MethodInfo* get_scene;
    static const MethodInfo* get_gameObject;
    static const MethodInfo* get_scene_Injected_out_Scene;
    // The Initialization function that must be called before using any of these definitions
    static void Init() {
        if (!__cached) {
            klass = il2cpp_utils::GetClassFromName("UnityEngine", "GameObject");
            CreatePrimitive_PrimitiveType = il2cpp_functions::class_get_method_from_name(klass, "CreatePrimitive", 1);
            GetComponent_generic = il2cpp_functions::class_get_method_from_name(klass, "GetComponent", 0);
            GetComponent_Type = il2cpp_functions::class_get_method_from_name(klass, "GetComponent", 1);
            GetComponentFastPath_Type_IntPtr = il2cpp_functions::class_get_method_from_name(klass, "GetComponentFastPath", 2);
            GetComponentByName_string = il2cpp_functions::class_get_method_from_name(klass, "GetComponentByName", 1);
            GetComponent_string = il2cpp_functions::class_get_method_from_name(klass, "GetComponent", 1);
            GetComponentInChildren_Type_bool = il2cpp_functions::class_get_method_from_name(klass, "GetComponentInChildren", 2);
            GetComponentInChildren_Type = il2cpp_functions::class_get_method_from_name(klass, "GetComponentInChildren", 1);
            GetComponentInChildren_generic = il2cpp_functions::class_get_method_from_name(klass, "GetComponentInChildren", 0);
            GetComponentInChildren_bool_generic = il2cpp_functions::class_get_method_from_name(klass, "GetComponentInChildren", 1);
            GetComponentInParent_Type = il2cpp_functions::class_get_method_from_name(klass, "GetComponentInParent", 1);
            GetComponentsInternal_Type_bool_bool_bool_bool_object = il2cpp_functions::class_get_method_from_name(klass, "GetComponentsInternal", 6);
            GetComponents_Type = il2cpp_functions::class_get_method_from_name(klass, "GetComponents", 1);
            GetComponents = il2cpp_functions::class_get_method_from_name(klass, "GetComponents", 0);
            GetComponents_List1 = il2cpp_functions::class_get_method_from_name(klass, "GetComponents", 1);
            GetComponentsInChildren_Type_bool = il2cpp_functions::class_get_method_from_name(klass, "GetComponentsInChildren", 2);
            GetComponentsInChildren_bool = il2cpp_functions::class_get_method_from_name(klass, "GetComponentsInChildren", 1);
            GetComponentsInChildren_bool_List1 = il2cpp_functions::class_get_method_from_name(klass, "GetComponentsInChildren", 2);
            GetComponentsInChildren = il2cpp_functions::class_get_method_from_name(klass, "GetComponentsInChildren", 0);
            GetComponentsInParent_Type_bool = il2cpp_functions::class_get_method_from_name(klass, "GetComponentsInParent", 2);
            GetComponentsInParent_bool_List1 = il2cpp_functions::class_get_method_from_name(klass, "GetComponentsInParent", 2);
            GetComponentsInParent_bool = il2cpp_functions::class_get_method_from_name(klass, "GetComponentsInParent", 1);
            Internal_AddComponentWithType_Type = il2cpp_functions::class_get_method_from_name(klass, "Internal_AddComponentWithType", 1);
            AddComponent_Type = il2cpp_functions::class_get_method_from_name(klass, "AddComponent", 1);
            AddComponent_generic = il2cpp_functions::class_get_method_from_name(klass, "AddComponent", 0);
            get_transform = il2cpp_functions::class_get_method_from_name(klass, "get_transform", 0);
            get_layer = il2cpp_functions::class_get_method_from_name(klass, "get_layer", 0);
            set_layer = il2cpp_functions::class_get_method_from_name(klass, "set_layer", 1);
            SetActive_bool = il2cpp_functions::class_get_method_from_name(klass, "SetActive", 1);
            get_activeSelf = il2cpp_functions::class_get_method_from_name(klass, "get_activeSelf", 0);
            get_activeInHierarchy = il2cpp_functions::class_get_method_from_name(klass, "get_activeInHierarchy", 0);
            get_tag = il2cpp_functions::class_get_method_from_name(klass, "get_tag", 0);
            set_tag = il2cpp_functions::class_get_method_from_name(klass, "set_tag", 1);
            FindGameObjectsWithTag_string = il2cpp_functions::class_get_method_from_name(klass, "FindGameObjectsWithTag", 1);
            SendMessage_string_object_SendMessageOptions = il2cpp_functions::class_get_method_from_name(klass, "SendMessage", 3);
            BroadcastMessage_string_object_SendMessageOptions = il2cpp_functions::class_get_method_from_name(klass, "BroadcastMessage", 3);
            Internal_CreateGameObject_GameObject_string = il2cpp_functions::class_get_method_from_name(klass, "Internal_CreateGameObject", 2);
            Find_string = il2cpp_functions::class_get_method_from_name(klass, "Find", 1);
            get_scene = il2cpp_functions::class_get_method_from_name(klass, "get_scene", 0);
            get_gameObject = il2cpp_functions::class_get_method_from_name(klass, "get_gameObject", 0);
            get_scene_Injected_out_Scene = il2cpp_functions::class_get_method_from_name(klass, "get_scene_Injected", 1);
            __cached = true;
        }
    }
}
#endif /* UnityEngine_GameObject_DEFINED */