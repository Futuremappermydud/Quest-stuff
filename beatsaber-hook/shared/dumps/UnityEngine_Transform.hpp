#ifndef UnityEngine_Transform_DEFINED
#define UnityEngine_Transform_DEFINED
// This .hpp file was compiled via beatsaber-hook/shared/helper.py's Parse Mode.
// Created by Sc2ad.
// Methods may not be valid!
#include <dlfcn.h>
#include <string_view>
#include "../utils/typedefs.h"
#include "../utils/il2cpp-functions.hpp"
#include "../utils/il2cpp-utils.hpp"
// Contains MethodInfo/Il2CppClass data for: UnityEngine.Transform
namespace UnityEngine_Transform {
    // UnityEngine.Transform
    typedef struct Class {
    } Class;
    static bool __cached = false;
    static Il2CppClass* klass;
    static const MethodInfo* get_position;
    static const MethodInfo* set_position;
    static const MethodInfo* get_localPosition;
    static const MethodInfo* set_localPosition;
    static const MethodInfo* set_eulerAngles;
    static const MethodInfo* get_localEulerAngles;
    static const MethodInfo* set_localEulerAngles;
    static const MethodInfo* get_right;
    static const MethodInfo* get_up;
    static const MethodInfo* get_forward;
    static const MethodInfo* get_rotation;
    static const MethodInfo* set_rotation;
    static const MethodInfo* get_localRotation;
    static const MethodInfo* set_localRotation;
    static const MethodInfo* get_localScale;
    static const MethodInfo* set_localScale;
    static const MethodInfo* get_parent;
    static const MethodInfo* set_parent;
    static const MethodInfo* get_parentInternal;
    static const MethodInfo* set_parentInternal;
    static const MethodInfo* GetParent;
    static const MethodInfo* SetParent_Transform;
    static const MethodInfo* SetParent_Transform_bool;
    static const MethodInfo* get_worldToLocalMatrix;
    static const MethodInfo* get_localToWorldMatrix;
    static const MethodInfo* SetPositionAndRotation_Vector3_Quaternion;
    static const MethodInfo* Translate_Vector3_Space;
    static const MethodInfo* Translate_float_float_float;
    static const MethodInfo* Rotate_Vector3_Space;
    static const MethodInfo* Rotate_Vector3;
    static const MethodInfo* Rotate_float_float_float;
    static const MethodInfo* RotateAroundInternal_Vector3_float;
    static const MethodInfo* Rotate_Vector3_float_Space;
    static const MethodInfo* LookAt_Transform_Vector3;
    static const MethodInfo* LookAt_Vector3_Vector3;
    static const MethodInfo* LookAt_Vector3;
    static const MethodInfo* Internal_LookAt_Vector3_Vector3;
    static const MethodInfo* TransformDirection_Vector3;
    static const MethodInfo* InverseTransformDirection_Vector3;
    static const MethodInfo* TransformVector_Vector3;
    static const MethodInfo* InverseTransformVector_Vector3;
    static const MethodInfo* TransformPoint_Vector3;
    static const MethodInfo* InverseTransformPoint_Vector3;
    static const MethodInfo* get_childCount;
    static const MethodInfo* SetAsFirstSibling;
    static const MethodInfo* SetAsLastSibling;
    static const MethodInfo* SetSiblingIndex_int;
    static const MethodInfo* FindRelativeTransformWithPath_Transform_string_bool;
    static const MethodInfo* Find_string;
    static const MethodInfo* get_lossyScale;
    static const MethodInfo* IsChildOf_Transform;
    static const MethodInfo* get_hasChanged;
    static const MethodInfo* set_hasChanged;
    static const MethodInfo* GetEnumerator;
    static const MethodInfo* GetChild_int;
    static const MethodInfo* get_position_Injected_out_Vector3;
    static const MethodInfo* set_position_Injected;
    static const MethodInfo* get_localPosition_Injected_out_Vector3;
    static const MethodInfo* set_localPosition_Injected;
    static const MethodInfo* get_rotation_Injected_out_Quaternion;
    static const MethodInfo* set_rotation_Injected;
    static const MethodInfo* get_localRotation_Injected_out_Quaternion;
    static const MethodInfo* set_localRotation_Injected;
    static const MethodInfo* get_localScale_Injected_out_Vector3;
    static const MethodInfo* set_localScale_Injected;
    static const MethodInfo* get_worldToLocalMatrix_Injected_out_Matrix4x4;
    static const MethodInfo* get_localToWorldMatrix_Injected_out_Matrix4x4;
    static const MethodInfo* SetPositionAndRotation_Injected_Vector3_Quaternion;
    static const MethodInfo* RotateAroundInternal_Injected_Vector3_float;
    static const MethodInfo* Internal_LookAt_Injected_Vector3_Vector3;
    static const MethodInfo* TransformDirection_Injected_Vector3_out_Vector3;
    static const MethodInfo* InverseTransformDirection_Injected_Vector3_out_Vector3;
    static const MethodInfo* TransformVector_Injected_Vector3_out_Vector3;
    static const MethodInfo* InverseTransformVector_Injected_Vector3_out_Vector3;
    static const MethodInfo* TransformPoint_Injected_Vector3_out_Vector3;
    static const MethodInfo* InverseTransformPoint_Injected_Vector3_out_Vector3;
    static const MethodInfo* get_lossyScale_Injected_out_Vector3;
    // The Initialization function that must be called before using any of these definitions
    static void Init() {
        if (!__cached) {
            klass = il2cpp_utils::GetClassFromName("UnityEngine", "Transform");
            get_position = il2cpp_functions::class_get_method_from_name(klass, "get_position", 0);
            set_position = il2cpp_functions::class_get_method_from_name(klass, "set_position", 1);
            get_localPosition = il2cpp_functions::class_get_method_from_name(klass, "get_localPosition", 0);
            set_localPosition = il2cpp_functions::class_get_method_from_name(klass, "set_localPosition", 1);
            set_eulerAngles = il2cpp_functions::class_get_method_from_name(klass, "set_eulerAngles", 1);
            get_localEulerAngles = il2cpp_functions::class_get_method_from_name(klass, "get_localEulerAngles", 0);
            set_localEulerAngles = il2cpp_functions::class_get_method_from_name(klass, "set_localEulerAngles", 1);
            get_right = il2cpp_functions::class_get_method_from_name(klass, "get_right", 0);
            get_up = il2cpp_functions::class_get_method_from_name(klass, "get_up", 0);
            get_forward = il2cpp_functions::class_get_method_from_name(klass, "get_forward", 0);
            get_rotation = il2cpp_functions::class_get_method_from_name(klass, "get_rotation", 0);
            set_rotation = il2cpp_functions::class_get_method_from_name(klass, "set_rotation", 1);
            get_localRotation = il2cpp_functions::class_get_method_from_name(klass, "get_localRotation", 0);
            set_localRotation = il2cpp_functions::class_get_method_from_name(klass, "set_localRotation", 1);
            get_localScale = il2cpp_functions::class_get_method_from_name(klass, "get_localScale", 0);
            set_localScale = il2cpp_functions::class_get_method_from_name(klass, "set_localScale", 1);
            get_parent = il2cpp_functions::class_get_method_from_name(klass, "get_parent", 0);
            set_parent = il2cpp_functions::class_get_method_from_name(klass, "set_parent", 1);
            get_parentInternal = il2cpp_functions::class_get_method_from_name(klass, "get_parentInternal", 0);
            set_parentInternal = il2cpp_functions::class_get_method_from_name(klass, "set_parentInternal", 1);
            GetParent = il2cpp_functions::class_get_method_from_name(klass, "GetParent", 0);
            SetParent_Transform = il2cpp_functions::class_get_method_from_name(klass, "SetParent", 1);
            SetParent_Transform_bool = il2cpp_functions::class_get_method_from_name(klass, "SetParent", 2);
            get_worldToLocalMatrix = il2cpp_functions::class_get_method_from_name(klass, "get_worldToLocalMatrix", 0);
            get_localToWorldMatrix = il2cpp_functions::class_get_method_from_name(klass, "get_localToWorldMatrix", 0);
            SetPositionAndRotation_Vector3_Quaternion = il2cpp_functions::class_get_method_from_name(klass, "SetPositionAndRotation", 2);
            Translate_Vector3_Space = il2cpp_functions::class_get_method_from_name(klass, "Translate", 2);
            Translate_float_float_float = il2cpp_functions::class_get_method_from_name(klass, "Translate", 3);
            Rotate_Vector3_Space = il2cpp_functions::class_get_method_from_name(klass, "Rotate", 2);
            Rotate_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "Rotate", 1);
            Rotate_float_float_float = il2cpp_functions::class_get_method_from_name(klass, "Rotate", 3);
            RotateAroundInternal_Vector3_float = il2cpp_functions::class_get_method_from_name(klass, "RotateAroundInternal", 2);
            Rotate_Vector3_float_Space = il2cpp_functions::class_get_method_from_name(klass, "Rotate", 3);
            LookAt_Transform_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "LookAt", 2);
            LookAt_Vector3_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "LookAt", 2);
            LookAt_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "LookAt", 1);
            Internal_LookAt_Vector3_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "Internal_LookAt", 2);
            TransformDirection_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "TransformDirection", 1);
            InverseTransformDirection_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "InverseTransformDirection", 1);
            TransformVector_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "TransformVector", 1);
            InverseTransformVector_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "InverseTransformVector", 1);
            TransformPoint_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "TransformPoint", 1);
            InverseTransformPoint_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "InverseTransformPoint", 1);
            get_childCount = il2cpp_functions::class_get_method_from_name(klass, "get_childCount", 0);
            SetAsFirstSibling = il2cpp_functions::class_get_method_from_name(klass, "SetAsFirstSibling", 0);
            SetAsLastSibling = il2cpp_functions::class_get_method_from_name(klass, "SetAsLastSibling", 0);
            SetSiblingIndex_int = il2cpp_functions::class_get_method_from_name(klass, "SetSiblingIndex", 1);
            FindRelativeTransformWithPath_Transform_string_bool = il2cpp_functions::class_get_method_from_name(klass, "FindRelativeTransformWithPath", 3);
            Find_string = il2cpp_functions::class_get_method_from_name(klass, "Find", 1);
            get_lossyScale = il2cpp_functions::class_get_method_from_name(klass, "get_lossyScale", 0);
            IsChildOf_Transform = il2cpp_functions::class_get_method_from_name(klass, "IsChildOf", 1);
            get_hasChanged = il2cpp_functions::class_get_method_from_name(klass, "get_hasChanged", 0);
            set_hasChanged = il2cpp_functions::class_get_method_from_name(klass, "set_hasChanged", 1);
            GetEnumerator = il2cpp_functions::class_get_method_from_name(klass, "GetEnumerator", 0);
            GetChild_int = il2cpp_functions::class_get_method_from_name(klass, "GetChild", 1);
            get_position_Injected_out_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "get_position_Injected", 1);
            set_position_Injected = il2cpp_functions::class_get_method_from_name(klass, "set_position_Injected", 1);
            get_localPosition_Injected_out_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "get_localPosition_Injected", 1);
            set_localPosition_Injected = il2cpp_functions::class_get_method_from_name(klass, "set_localPosition_Injected", 1);
            get_rotation_Injected_out_Quaternion = il2cpp_functions::class_get_method_from_name(klass, "get_rotation_Injected", 1);
            set_rotation_Injected = il2cpp_functions::class_get_method_from_name(klass, "set_rotation_Injected", 1);
            get_localRotation_Injected_out_Quaternion = il2cpp_functions::class_get_method_from_name(klass, "get_localRotation_Injected", 1);
            set_localRotation_Injected = il2cpp_functions::class_get_method_from_name(klass, "set_localRotation_Injected", 1);
            get_localScale_Injected_out_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "get_localScale_Injected", 1);
            set_localScale_Injected = il2cpp_functions::class_get_method_from_name(klass, "set_localScale_Injected", 1);
            get_worldToLocalMatrix_Injected_out_Matrix4x4 = il2cpp_functions::class_get_method_from_name(klass, "get_worldToLocalMatrix_Injected", 1);
            get_localToWorldMatrix_Injected_out_Matrix4x4 = il2cpp_functions::class_get_method_from_name(klass, "get_localToWorldMatrix_Injected", 1);
            SetPositionAndRotation_Injected_Vector3_Quaternion = il2cpp_functions::class_get_method_from_name(klass, "SetPositionAndRotation_Injected", 2);
            RotateAroundInternal_Injected_Vector3_float = il2cpp_functions::class_get_method_from_name(klass, "RotateAroundInternal_Injected", 2);
            Internal_LookAt_Injected_Vector3_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "Internal_LookAt_Injected", 2);
            TransformDirection_Injected_Vector3_out_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "TransformDirection_Injected", 2);
            InverseTransformDirection_Injected_Vector3_out_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "InverseTransformDirection_Injected", 2);
            TransformVector_Injected_Vector3_out_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "TransformVector_Injected", 2);
            InverseTransformVector_Injected_Vector3_out_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "InverseTransformVector_Injected", 2);
            TransformPoint_Injected_Vector3_out_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "TransformPoint_Injected", 2);
            InverseTransformPoint_Injected_Vector3_out_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "InverseTransformPoint_Injected", 2);
            get_lossyScale_Injected_out_Vector3 = il2cpp_functions::class_get_method_from_name(klass, "get_lossyScale_Injected", 1);
            __cached = true;
        }
    }
}
#endif /* UnityEngine_Transform_DEFINED */