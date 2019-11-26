#ifndef UnityEngine_RectTransform_DEFINED
#define UnityEngine_RectTransform_DEFINED
// This .hpp file was compiled via beatsaber-hook/shared/helper.py's Parse Mode.
// Created by Sc2ad.
// Methods may not be valid!
#include <dlfcn.h>
#include <string_view>
#include "../utils/typedefs.h"
#include "../utils/il2cpp-functions.hpp"
#include "../utils/il2cpp-utils.hpp"
// Contains MethodInfo/Il2CppClass data for: UnityEngine.RectTransform
namespace UnityEngine_RectTransform {
    // UnityEngine.RectTransform
    typedef struct Class {
        static void* reapplyDrivenProperties; // 0x0
    } Class;
    static bool __cached = false;
    static Il2CppClass* klass;
    static const MethodInfo* add_reapplyDrivenProperties_RectTransform_ReapplyDrivenProperties;
    static const MethodInfo* remove_reapplyDrivenProperties_RectTransform_ReapplyDrivenProperties;
    static const MethodInfo* get_rect;
    static const MethodInfo* get_anchorMin;
    static const MethodInfo* set_anchorMin;
    static const MethodInfo* get_anchorMax;
    static const MethodInfo* set_anchorMax;
    static const MethodInfo* get_anchoredPosition;
    static const MethodInfo* set_anchoredPosition;
    static const MethodInfo* get_sizeDelta;
    static const MethodInfo* set_sizeDelta;
    static const MethodInfo* get_pivot;
    static const MethodInfo* set_pivot;
    static const MethodInfo* set_anchoredPosition3D;
    static const MethodInfo* set_offsetMin;
    static const MethodInfo* set_offsetMax;
    static const MethodInfo* GetLocalCorners_Vector3_arr;
    static const MethodInfo* GetWorldCorners_Vector3_arr;
    static const MethodInfo* SetInsetAndSizeFromParentEdge_RectTransform_Edge_float_float;
    static const MethodInfo* SetSizeWithCurrentAnchors_RectTransform_Axis_float;
    static const MethodInfo* SendReapplyDrivenProperties_RectTransform;
    static const MethodInfo* GetParentSize;
    static const MethodInfo* get_rect_Injected_out_Rect;
    static const MethodInfo* get_anchorMin_Injected_out_Vector2;
    static const MethodInfo* set_anchorMin_Injected;
    static const MethodInfo* get_anchorMax_Injected_out_Vector2;
    static const MethodInfo* set_anchorMax_Injected;
    static const MethodInfo* get_anchoredPosition_Injected_out_Vector2;
    static const MethodInfo* set_anchoredPosition_Injected;
    static const MethodInfo* get_sizeDelta_Injected_out_Vector2;
    static const MethodInfo* set_sizeDelta_Injected;
    static const MethodInfo* get_pivot_Injected_out_Vector2;
    static const MethodInfo* set_pivot_Injected;
    // The Initialization function that must be called before using any of these definitions
    static void Init() {
        if (!__cached) {
            klass = il2cpp_utils::GetClassFromName("UnityEngine", "RectTransform");
            add_reapplyDrivenProperties_RectTransform_ReapplyDrivenProperties = il2cpp_functions::class_get_method_from_name(klass, "add_reapplyDrivenProperties", 1);
            remove_reapplyDrivenProperties_RectTransform_ReapplyDrivenProperties = il2cpp_functions::class_get_method_from_name(klass, "remove_reapplyDrivenProperties", 1);
            get_rect = il2cpp_functions::class_get_method_from_name(klass, "get_rect", 0);
            get_anchorMin = il2cpp_functions::class_get_method_from_name(klass, "get_anchorMin", 0);
            set_anchorMin = il2cpp_functions::class_get_method_from_name(klass, "set_anchorMin", 1);
            get_anchorMax = il2cpp_functions::class_get_method_from_name(klass, "get_anchorMax", 0);
            set_anchorMax = il2cpp_functions::class_get_method_from_name(klass, "set_anchorMax", 1);
            get_anchoredPosition = il2cpp_functions::class_get_method_from_name(klass, "get_anchoredPosition", 0);
            set_anchoredPosition = il2cpp_functions::class_get_method_from_name(klass, "set_anchoredPosition", 1);
            get_sizeDelta = il2cpp_functions::class_get_method_from_name(klass, "get_sizeDelta", 0);
            set_sizeDelta = il2cpp_functions::class_get_method_from_name(klass, "set_sizeDelta", 1);
            get_pivot = il2cpp_functions::class_get_method_from_name(klass, "get_pivot", 0);
            set_pivot = il2cpp_functions::class_get_method_from_name(klass, "set_pivot", 1);
            set_anchoredPosition3D = il2cpp_functions::class_get_method_from_name(klass, "set_anchoredPosition3D", 1);
            set_offsetMin = il2cpp_functions::class_get_method_from_name(klass, "set_offsetMin", 1);
            set_offsetMax = il2cpp_functions::class_get_method_from_name(klass, "set_offsetMax", 1);
            GetLocalCorners_Vector3_arr = il2cpp_functions::class_get_method_from_name(klass, "GetLocalCorners", 1);
            GetWorldCorners_Vector3_arr = il2cpp_functions::class_get_method_from_name(klass, "GetWorldCorners", 1);
            SetInsetAndSizeFromParentEdge_RectTransform_Edge_float_float = il2cpp_functions::class_get_method_from_name(klass, "SetInsetAndSizeFromParentEdge", 3);
            SetSizeWithCurrentAnchors_RectTransform_Axis_float = il2cpp_functions::class_get_method_from_name(klass, "SetSizeWithCurrentAnchors", 2);
            SendReapplyDrivenProperties_RectTransform = il2cpp_functions::class_get_method_from_name(klass, "SendReapplyDrivenProperties", 1);
            GetParentSize = il2cpp_functions::class_get_method_from_name(klass, "GetParentSize", 0);
            get_rect_Injected_out_Rect = il2cpp_functions::class_get_method_from_name(klass, "get_rect_Injected", 1);
            get_anchorMin_Injected_out_Vector2 = il2cpp_functions::class_get_method_from_name(klass, "get_anchorMin_Injected", 1);
            set_anchorMin_Injected = il2cpp_functions::class_get_method_from_name(klass, "set_anchorMin_Injected", 1);
            get_anchorMax_Injected_out_Vector2 = il2cpp_functions::class_get_method_from_name(klass, "get_anchorMax_Injected", 1);
            set_anchorMax_Injected = il2cpp_functions::class_get_method_from_name(klass, "set_anchorMax_Injected", 1);
            get_anchoredPosition_Injected_out_Vector2 = il2cpp_functions::class_get_method_from_name(klass, "get_anchoredPosition_Injected", 1);
            set_anchoredPosition_Injected = il2cpp_functions::class_get_method_from_name(klass, "set_anchoredPosition_Injected", 1);
            get_sizeDelta_Injected_out_Vector2 = il2cpp_functions::class_get_method_from_name(klass, "get_sizeDelta_Injected", 1);
            set_sizeDelta_Injected = il2cpp_functions::class_get_method_from_name(klass, "set_sizeDelta_Injected", 1);
            get_pivot_Injected_out_Vector2 = il2cpp_functions::class_get_method_from_name(klass, "get_pivot_Injected", 1);
            set_pivot_Injected = il2cpp_functions::class_get_method_from_name(klass, "set_pivot_Injected", 1);
            __cached = true;
        }
    }
}
#endif /* UnityEngine_RectTransform_DEFINED */