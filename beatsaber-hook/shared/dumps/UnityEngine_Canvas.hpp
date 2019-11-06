#ifndef UnityEngine_Canvas_DEFINED
#define UnityEngine_Canvas_DEFINED
// This .hpp file was compiled via beatsaber-hook/shared/helper.py's Parse Mode.
// Created by Sc2ad.
// Methods may not be valid!
#include <dlfcn.h>
#include <string_view>
#include "../utils/typedefs.h"
#include "../utils/il2cpp-functions.hpp"
#include "../utils/il2cpp-utils.hpp"
// Contains MethodInfo/Il2CppClass data for: UnityEngine.Canvas
namespace UnityEngine_Canvas {
    // UnityEngine.Canvas
    typedef struct Class : Il2CppObject {
        static void* willRenderCanvases; // 0x0
    } Class;
    static bool __cached = false;
    static Il2CppClass* klass;
    static const MethodInfo* add_willRenderCanvases_Canvas_WillRenderCanvases;
    static const MethodInfo* remove_willRenderCanvases_Canvas_WillRenderCanvases;
    static const MethodInfo* get_renderMode;
    static const MethodInfo* set_renderMode;
    static const MethodInfo* get_isRootCanvas;
    static const MethodInfo* get_scaleFactor;
    static const MethodInfo* set_scaleFactor;
    static const MethodInfo* get_referencePixelsPerUnit;
    static const MethodInfo* set_referencePixelsPerUnit;
    static const MethodInfo* get_pixelPerfect;
    static const MethodInfo* set_pixelPerfect;
    static const MethodInfo* get_renderOrder;
    static const MethodInfo* get_overrideSorting;
    static const MethodInfo* set_overrideSorting;
    static const MethodInfo* get_sortingOrder;
    static const MethodInfo* set_sortingOrder;
    static const MethodInfo* get_targetDisplay;
    static const MethodInfo* get_sortingLayerID;
    static const MethodInfo* set_sortingLayerID;
    static const MethodInfo* get_additionalShaderChannels;
    static const MethodInfo* set_additionalShaderChannels;
    static const MethodInfo* get_rootCanvas;
    static const MethodInfo* get_worldCamera;
    static const MethodInfo* set_worldCamera;
    static const MethodInfo* GetDefaultCanvasMaterial;
    static const MethodInfo* GetETC1SupportedCanvasMaterial;
    static const MethodInfo* ForceUpdateCanvases;
    static const MethodInfo* SendWillRenderCanvases;
    // The Initialization function that must be called before using any of these definitions
    static void Init() {
        if (!__cached) {
            klass = il2cpp_utils::GetClassFromName("UnityEngine", "Canvas");
            add_willRenderCanvases_Canvas_WillRenderCanvases = il2cpp_functions::class_get_method_from_name(klass, "add_willRenderCanvases", 1);
            remove_willRenderCanvases_Canvas_WillRenderCanvases = il2cpp_functions::class_get_method_from_name(klass, "remove_willRenderCanvases", 1);
            get_renderMode = il2cpp_functions::class_get_method_from_name(klass, "get_renderMode", 0);
            set_renderMode = il2cpp_functions::class_get_method_from_name(klass, "set_renderMode", 1);
            get_isRootCanvas = il2cpp_functions::class_get_method_from_name(klass, "get_isRootCanvas", 0);
            get_scaleFactor = il2cpp_functions::class_get_method_from_name(klass, "get_scaleFactor", 0);
            set_scaleFactor = il2cpp_functions::class_get_method_from_name(klass, "set_scaleFactor", 1);
            get_referencePixelsPerUnit = il2cpp_functions::class_get_method_from_name(klass, "get_referencePixelsPerUnit", 0);
            set_referencePixelsPerUnit = il2cpp_functions::class_get_method_from_name(klass, "set_referencePixelsPerUnit", 1);
            get_pixelPerfect = il2cpp_functions::class_get_method_from_name(klass, "get_pixelPerfect", 0);
            set_pixelPerfect = il2cpp_functions::class_get_method_from_name(klass, "set_pixelPerfect", 1);
            get_renderOrder = il2cpp_functions::class_get_method_from_name(klass, "get_renderOrder", 0);
            get_overrideSorting = il2cpp_functions::class_get_method_from_name(klass, "get_overrideSorting", 0);
            set_overrideSorting = il2cpp_functions::class_get_method_from_name(klass, "set_overrideSorting", 1);
            get_sortingOrder = il2cpp_functions::class_get_method_from_name(klass, "get_sortingOrder", 0);
            set_sortingOrder = il2cpp_functions::class_get_method_from_name(klass, "set_sortingOrder", 1);
            get_targetDisplay = il2cpp_functions::class_get_method_from_name(klass, "get_targetDisplay", 0);
            get_sortingLayerID = il2cpp_functions::class_get_method_from_name(klass, "get_sortingLayerID", 0);
            set_sortingLayerID = il2cpp_functions::class_get_method_from_name(klass, "set_sortingLayerID", 1);
            get_additionalShaderChannels = il2cpp_functions::class_get_method_from_name(klass, "get_additionalShaderChannels", 0);
            set_additionalShaderChannels = il2cpp_functions::class_get_method_from_name(klass, "set_additionalShaderChannels", 1);
            get_rootCanvas = il2cpp_functions::class_get_method_from_name(klass, "get_rootCanvas", 0);
            get_worldCamera = il2cpp_functions::class_get_method_from_name(klass, "get_worldCamera", 0);
            set_worldCamera = il2cpp_functions::class_get_method_from_name(klass, "set_worldCamera", 1);
            GetDefaultCanvasMaterial = il2cpp_functions::class_get_method_from_name(klass, "GetDefaultCanvasMaterial", 0);
            GetETC1SupportedCanvasMaterial = il2cpp_functions::class_get_method_from_name(klass, "GetETC1SupportedCanvasMaterial", 0);
            ForceUpdateCanvases = il2cpp_functions::class_get_method_from_name(klass, "ForceUpdateCanvases", 0);
            SendWillRenderCanvases = il2cpp_functions::class_get_method_from_name(klass, "SendWillRenderCanvases", 0);
            __cached = true;
        }
    }
}
#endif /* UnityEngine_Canvas_DEFINED */