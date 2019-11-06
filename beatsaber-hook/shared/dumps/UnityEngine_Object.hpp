#ifndef UnityEngine_Object_DEFINED
#define UnityEngine_Object_DEFINED
// This .hpp file was compiled via beatsaber-hook/shared/helper.py's Parse Mode.
// Created by Sc2ad.
// Methods may not be valid!
#include <dlfcn.h>
#include <string_view>
#include "../utils/typedefs.h"
#include "../utils/il2cpp-functions.hpp"
#include "../utils/il2cpp-utils.hpp"
// Contains MethodInfo/Il2CppClass data for: UnityEngine.Object
namespace UnityEngine_Object {
    // UnityEngine.Object
    typedef struct Class : Il2CppObject {
        IntPtr m_CachedPtr; // 0x10
        static int OffsetOfInstanceIDInCPlusPlusObject; // 0x0
    } Class;
    static bool __cached = false;
    static Il2CppClass* klass;
    static const MethodInfo* GetInstanceID;
    static const MethodInfo* GetHashCode;
    static const MethodInfo* Equals_object;
    static const MethodInfo* op_Implicit_Object;
    static const MethodInfo* CompareBaseObjects_Object_Object;
    static const MethodInfo* IsNativeObjectAlive_Object;
    static const MethodInfo* GetCachedPtr;
    static const MethodInfo* get_name;
    static const MethodInfo* set_name;
    static const MethodInfo* Instantiate_Object_Vector3_Quaternion;
    static const MethodInfo* Instantiate_Object_Vector3_Quaternion_Transform;
    static const MethodInfo* Instantiate_Object;
    static const MethodInfo* Instantiate_Object_Transform_bool;
    static const MethodInfo* Instantiate_T_generic;
    static const MethodInfo* Instantiate_T_Vector3_Quaternion_generic;
    static const MethodInfo* Instantiate_T_Vector3_Quaternion_Transform_generic;
    static const MethodInfo* Instantiate_T_Transform_generic;
    static const MethodInfo* Instantiate_T_Transform_bool_generic;
    static const MethodInfo* Destroy_Object_float;
    static const MethodInfo* Destroy_Object;
    static const MethodInfo* DestroyImmediate_Object_bool;
    static const MethodInfo* DestroyImmediate_Object;
    static const MethodInfo* FindObjectsOfType_Type;
    static const MethodInfo* DontDestroyOnLoad_Object;
    static const MethodInfo* get_hideFlags;
    static const MethodInfo* set_hideFlags;
    static const MethodInfo* FindObjectsOfType;
    static const MethodInfo* FindObjectOfType_generic;
    static const MethodInfo* CheckNullArgument_object_string;
    static const MethodInfo* FindObjectOfType_Type;
    static const MethodInfo* ToString;
    static const MethodInfo* op_Equality_Object_Object;
    static const MethodInfo* op_Inequality_Object_Object;
    static const MethodInfo* GetOffsetOfInstanceIDInCPlusPlusObject;
    static const MethodInfo* Internal_CloneSingle_Object;
    static const MethodInfo* Internal_CloneSingleWithParent_Object_Transform_bool;
    static const MethodInfo* Internal_InstantiateSingle_Object_Vector3_Quaternion;
    static const MethodInfo* Internal_InstantiateSingleWithParent_Object_Transform_Vector3_Quaternion;
    static const MethodInfo* ToString_Object;
    static const MethodInfo* GetName_Object;
    static const MethodInfo* SetName_Object_string;
    static const MethodInfo* FindObjectFromInstanceID_int;
    static const MethodInfo* Internal_InstantiateSingle_Injected_Object_Vector3_Quaternion;
    static const MethodInfo* Internal_InstantiateSingleWithParent_Injected_Object_Transform_Vector3_Quaternion;
    // The Initialization function that must be called before using any of these definitions
    static void Init() {
        if (!__cached) {
            klass = il2cpp_utils::GetClassFromName("UnityEngine", "Object");
            GetInstanceID = il2cpp_functions::class_get_method_from_name(klass, "GetInstanceID", 0);
            GetHashCode = il2cpp_functions::class_get_method_from_name(klass, "GetHashCode", 0);
            Equals_object = il2cpp_functions::class_get_method_from_name(klass, "Equals", 1);
            op_Implicit_Object = il2cpp_functions::class_get_method_from_name(klass, "op_Implicit", 1);
            CompareBaseObjects_Object_Object = il2cpp_functions::class_get_method_from_name(klass, "CompareBaseObjects", 2);
            IsNativeObjectAlive_Object = il2cpp_functions::class_get_method_from_name(klass, "IsNativeObjectAlive", 1);
            GetCachedPtr = il2cpp_functions::class_get_method_from_name(klass, "GetCachedPtr", 0);
            get_name = il2cpp_functions::class_get_method_from_name(klass, "get_name", 0);
            set_name = il2cpp_functions::class_get_method_from_name(klass, "set_name", 1);
            Instantiate_Object_Vector3_Quaternion = il2cpp_functions::class_get_method_from_name(klass, "Instantiate", 3);
            Instantiate_Object_Vector3_Quaternion_Transform = il2cpp_functions::class_get_method_from_name(klass, "Instantiate", 4);
            Instantiate_Object = il2cpp_functions::class_get_method_from_name(klass, "Instantiate", 1);
            Instantiate_Object_Transform_bool = il2cpp_functions::class_get_method_from_name(klass, "Instantiate", 3);
            Instantiate_T_generic = il2cpp_functions::class_get_method_from_name(klass, "Instantiate", 1);
            Instantiate_T_Vector3_Quaternion_generic = il2cpp_functions::class_get_method_from_name(klass, "Instantiate", 3);
            Instantiate_T_Vector3_Quaternion_Transform_generic = il2cpp_functions::class_get_method_from_name(klass, "Instantiate", 4);
            Instantiate_T_Transform_generic = il2cpp_functions::class_get_method_from_name(klass, "Instantiate", 2);
            Instantiate_T_Transform_bool_generic = il2cpp_functions::class_get_method_from_name(klass, "Instantiate", 3);
            Destroy_Object_float = il2cpp_functions::class_get_method_from_name(klass, "Destroy", 2);
            Destroy_Object = il2cpp_functions::class_get_method_from_name(klass, "Destroy", 1);
            DestroyImmediate_Object_bool = il2cpp_functions::class_get_method_from_name(klass, "DestroyImmediate", 2);
            DestroyImmediate_Object = il2cpp_functions::class_get_method_from_name(klass, "DestroyImmediate", 1);
            FindObjectsOfType_Type = il2cpp_functions::class_get_method_from_name(klass, "FindObjectsOfType", 1);
            DontDestroyOnLoad_Object = il2cpp_functions::class_get_method_from_name(klass, "DontDestroyOnLoad", 1);
            get_hideFlags = il2cpp_functions::class_get_method_from_name(klass, "get_hideFlags", 0);
            set_hideFlags = il2cpp_functions::class_get_method_from_name(klass, "set_hideFlags", 1);
            FindObjectsOfType = il2cpp_functions::class_get_method_from_name(klass, "FindObjectsOfType", 0);
            FindObjectOfType_generic = il2cpp_functions::class_get_method_from_name(klass, "FindObjectOfType", 0);
            CheckNullArgument_object_string = il2cpp_functions::class_get_method_from_name(klass, "CheckNullArgument", 2);
            FindObjectOfType_Type = il2cpp_functions::class_get_method_from_name(klass, "FindObjectOfType", 1);
            ToString = il2cpp_functions::class_get_method_from_name(klass, "ToString", 0);
            op_Equality_Object_Object = il2cpp_functions::class_get_method_from_name(klass, "op_Equality", 2);
            op_Inequality_Object_Object = il2cpp_functions::class_get_method_from_name(klass, "op_Inequality", 2);
            GetOffsetOfInstanceIDInCPlusPlusObject = il2cpp_functions::class_get_method_from_name(klass, "GetOffsetOfInstanceIDInCPlusPlusObject", 0);
            Internal_CloneSingle_Object = il2cpp_functions::class_get_method_from_name(klass, "Internal_CloneSingle", 1);
            Internal_CloneSingleWithParent_Object_Transform_bool = il2cpp_functions::class_get_method_from_name(klass, "Internal_CloneSingleWithParent", 3);
            Internal_InstantiateSingle_Object_Vector3_Quaternion = il2cpp_functions::class_get_method_from_name(klass, "Internal_InstantiateSingle", 3);
            Internal_InstantiateSingleWithParent_Object_Transform_Vector3_Quaternion = il2cpp_functions::class_get_method_from_name(klass, "Internal_InstantiateSingleWithParent", 4);
            ToString_Object = il2cpp_functions::class_get_method_from_name(klass, "ToString", 1);
            GetName_Object = il2cpp_functions::class_get_method_from_name(klass, "GetName", 1);
            SetName_Object_string = il2cpp_functions::class_get_method_from_name(klass, "SetName", 2);
            FindObjectFromInstanceID_int = il2cpp_functions::class_get_method_from_name(klass, "FindObjectFromInstanceID", 1);
            Internal_InstantiateSingle_Injected_Object_Vector3_Quaternion = il2cpp_functions::class_get_method_from_name(klass, "Internal_InstantiateSingle_Injected", 3);
            Internal_InstantiateSingleWithParent_Injected_Object_Transform_Vector3_Quaternion = il2cpp_functions::class_get_method_from_name(klass, "Internal_InstantiateSingleWithParent_Injected", 4);
            __cached = true;
        }
    }
}
#endif /* UnityEngine_Object_DEFINED */