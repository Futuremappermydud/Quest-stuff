#ifndef UnityEngine_Resources_DEFINED
#define UnityEngine_Resources_DEFINED
// This .hpp file was compiled via beatsaber-hook/shared/helper.py's Parse Mode.
// Created by Sc2ad.
// Methods may not be valid!
#include <dlfcn.h>
#include <string_view>
#include "../utils/typedefs.h"
#include "../utils/il2cpp-functions.hpp"
#include "../utils/il2cpp-utils.hpp"
// Contains MethodInfo/Il2CppClass data for: UnityEngine.Resources
namespace UnityEngine_Resources {
    // UnityEngine.Resources
    typedef struct Class {
    } Class;
    static bool __cached = false;
    static Il2CppClass* klass;
    static const MethodInfo* ConvertObjects_Object_arr;
    static const MethodInfo* FindObjectsOfTypeAll_Type;
    static const MethodInfo* FindObjectsOfTypeAll;
    static const MethodInfo* Load_string;
    static const MethodInfo* Load_string_generic;
    static const MethodInfo* Load_string_Type;
    static const MethodInfo* LoadAll_string_Type;
    static const MethodInfo* LoadAll_string;
    static const MethodInfo* GetBuiltinResource_Type_string;
    static const MethodInfo* GetBuiltinResource_string_generic;
    static const MethodInfo* UnloadUnusedAssets;
    // The Initialization function that must be called before using any of these definitions
    static void Init() {
        if (!__cached) {
            klass = il2cpp_utils::GetClassFromName("UnityEngine", "Resources");
            ConvertObjects_Object_arr = il2cpp_functions::class_get_method_from_name(klass, "ConvertObjects", 1);
            FindObjectsOfTypeAll_Type = il2cpp_functions::class_get_method_from_name(klass, "FindObjectsOfTypeAll", 1);
            FindObjectsOfTypeAll = il2cpp_functions::class_get_method_from_name(klass, "FindObjectsOfTypeAll", 0);
            Load_string = il2cpp_functions::class_get_method_from_name(klass, "Load", 1);
            Load_string_generic = il2cpp_functions::class_get_method_from_name(klass, "Load", 1);
            Load_string_Type = il2cpp_functions::class_get_method_from_name(klass, "Load", 2);
            LoadAll_string_Type = il2cpp_functions::class_get_method_from_name(klass, "LoadAll", 2);
            LoadAll_string = il2cpp_functions::class_get_method_from_name(klass, "LoadAll", 1);
            GetBuiltinResource_Type_string = il2cpp_functions::class_get_method_from_name(klass, "GetBuiltinResource", 2);
            GetBuiltinResource_string_generic = il2cpp_functions::class_get_method_from_name(klass, "GetBuiltinResource", 1);
            UnloadUnusedAssets = il2cpp_functions::class_get_method_from_name(klass, "UnloadUnusedAssets", 0);
            __cached = true;
        }
    }
}
#endif /* UnityEngine_Resources_DEFINED */