#ifndef UnityEngine_Component_DEFINED
#define UnityEngine_Component_DEFINED
// This .hpp file was compiled via beatsaber-hook/shared/helper.py's Parse Mode.
// Created by Sc2ad.
// Methods may not be valid!
#include <dlfcn.h>
#include <string_view>
#include "../utils/typedefs.h"
#include "../utils/il2cpp-functions.hpp"
#include "../utils/il2cpp-utils.hpp"
// Contains MethodInfo/Il2CppClass data for: UnityEngine.Component
namespace UnityEngine_Component {
    // UnityEngine.Component
    typedef struct Class : Il2CppObject {
    } Class;
    static bool __cached = false;
    static Il2CppClass* klass;
    static const MethodInfo* get_transform;
    static const MethodInfo* get_gameObject;
    static const MethodInfo* GetComponent_Type;
    static const MethodInfo* GetComponentFastPath_Type_IntPtr;
    static const MethodInfo* GetComponent_generic;
    static const MethodInfo* GetComponentInChildren_Type_bool;
    static const MethodInfo* GetComponentInChildren_generic;
    static const MethodInfo* GetComponentsInChildren_Type_bool;
    static const MethodInfo* GetComponentsInChildren_bool;
    static const MethodInfo* GetComponentsInChildren_bool_List1;
    static const MethodInfo* GetComponentsInChildren;
    static const MethodInfo* GetComponentsInChildren_List1;
    static const MethodInfo* GetComponentInParent_Type;
    static const MethodInfo* GetComponentInParent_generic;
    static const MethodInfo* GetComponentsInParent_Type_bool;
    static const MethodInfo* GetComponentsInParent_bool;
    static const MethodInfo* GetComponentsInParent_bool_List1;
    static const MethodInfo* GetComponentsInParent;
    static const MethodInfo* GetComponents_Type;
    static const MethodInfo* GetComponentsForListInternal_Type_object;
    static const MethodInfo* GetComponents_Type_List1;
    static const MethodInfo* GetComponents_List1;
    static const MethodInfo* get_tag;
    static const MethodInfo* set_tag;
    static const MethodInfo* GetComponents;
    // The Initialization function that must be called before using any of these definitions
    static void Init() {
        if (!__cached) {
            klass = il2cpp_utils::GetClassFromName("UnityEngine", "Component");
            get_transform = il2cpp_functions::class_get_method_from_name(klass, "get_transform", 0);
            get_gameObject = il2cpp_functions::class_get_method_from_name(klass, "get_gameObject", 0);
            GetComponent_Type = il2cpp_functions::class_get_method_from_name(klass, "GetComponent", 1);
            GetComponentFastPath_Type_IntPtr = il2cpp_functions::class_get_method_from_name(klass, "GetComponentFastPath", 2);
            GetComponent_generic = il2cpp_functions::class_get_method_from_name(klass, "GetComponent", 0);
            GetComponentInChildren_Type_bool = il2cpp_functions::class_get_method_from_name(klass, "GetComponentInChildren", 2);
            GetComponentInChildren_generic = il2cpp_functions::class_get_method_from_name(klass, "GetComponentInChildren", 0);
            GetComponentsInChildren_Type_bool = il2cpp_functions::class_get_method_from_name(klass, "GetComponentsInChildren", 2);
            GetComponentsInChildren_bool = il2cpp_functions::class_get_method_from_name(klass, "GetComponentsInChildren", 1);
            GetComponentsInChildren_bool_List1 = il2cpp_functions::class_get_method_from_name(klass, "GetComponentsInChildren", 2);
            GetComponentsInChildren = il2cpp_functions::class_get_method_from_name(klass, "GetComponentsInChildren", 0);
            GetComponentsInChildren_List1 = il2cpp_functions::class_get_method_from_name(klass, "GetComponentsInChildren", 1);
            GetComponentInParent_Type = il2cpp_functions::class_get_method_from_name(klass, "GetComponentInParent", 1);
            GetComponentInParent_generic = il2cpp_functions::class_get_method_from_name(klass, "GetComponentInParent", 0);
            GetComponentsInParent_Type_bool = il2cpp_functions::class_get_method_from_name(klass, "GetComponentsInParent", 2);
            GetComponentsInParent_bool = il2cpp_functions::class_get_method_from_name(klass, "GetComponentsInParent", 1);
            GetComponentsInParent_bool_List1 = il2cpp_functions::class_get_method_from_name(klass, "GetComponentsInParent", 2);
            GetComponentsInParent = il2cpp_functions::class_get_method_from_name(klass, "GetComponentsInParent", 0);
            GetComponents_Type = il2cpp_functions::class_get_method_from_name(klass, "GetComponents", 1);
            GetComponentsForListInternal_Type_object = il2cpp_functions::class_get_method_from_name(klass, "GetComponentsForListInternal", 2);
            GetComponents_Type_List1 = il2cpp_functions::class_get_method_from_name(klass, "GetComponents", 2);
            GetComponents_List1 = il2cpp_functions::class_get_method_from_name(klass, "GetComponents", 1);
            get_tag = il2cpp_functions::class_get_method_from_name(klass, "get_tag", 0);
            set_tag = il2cpp_functions::class_get_method_from_name(klass, "set_tag", 1);
            GetComponents = il2cpp_functions::class_get_method_from_name(klass, "GetComponents", 0);
            __cached = true;
        }
    }
}
#endif /* UnityEngine_Component_DEFINED */