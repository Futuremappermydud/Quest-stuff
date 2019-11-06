#ifndef TMPro_TextMeshProUGUI_DEFINED
#define TMPro_TextMeshProUGUI_DEFINED
// This .hpp file was compiled via beatsaber-hook/shared/helper.py's Parse Mode.
// Created by Sc2ad.
// Methods may not be valid!
#include <dlfcn.h>
#include <string_view>
#include "../utils/typedefs.h"
#include "../utils/il2cpp-functions.hpp"
#include "../utils/il2cpp-utils.hpp"
// Contains MethodInfo/Il2CppClass data for: TMPro.TextMeshProUGUI
namespace TMPro_TextMeshProUGUI {
    // TMPro.TextMeshProUGUI
    typedef struct Class : Il2CppObject {
        uint8_t m_isRebuildingLayout; // 0xB20
        uint8_t m_hasFontAssetChanged; // 0xB21
        void* m_subTextObjects; // 0xB28
        float m_previousLossyScaleY; // 0xB30
        void* m_RectTransformCorners; // 0xB38
        void* m_canvasRenderer; // 0xB40
        void* m_canvas; // 0xB48
        uint8_t m_isFirstAllocation; // 0xB50
        int m_max_characters; // 0xB54
        uint8_t m_isMaskingEnabled; // 0xB58
        void* m_baseMaterial; // 0xB60
        uint8_t m_isScrollRegionSet; // 0xB68
        int m_stencilID; // 0xB6C
        void* m_maskOffset; // 0xB70
        void* m_EnvMapMatrix; // 0xB80
        uint8_t m_isRegisteredForEvents; // 0xBC0
        int m_recursiveCountA; // 0xBC4
        int loopCountA; // 0xBC8
    } Class;
    static bool __cached = false;
    static Il2CppClass* klass;
    static const MethodInfo* get_materialForRendering;
    static const MethodInfo* get_autoSizeTextContainer;
    static const MethodInfo* set_autoSizeTextContainer;
    static const MethodInfo* get_mesh;
    static const MethodInfo* get_canvasRenderer;
    static const MethodInfo* CalculateLayoutInputHorizontal;
    static const MethodInfo* CalculateLayoutInputVertical;
    static const MethodInfo* SetVerticesDirty;
    static const MethodInfo* SetLayoutDirty;
    static const MethodInfo* SetMaterialDirty;
    static const MethodInfo* SetAllDirty;
    static const MethodInfo* Rebuild_CanvasUpdate;
    static const MethodInfo* UpdateSubObjectPivot;
    static const MethodInfo* GetModifiedMaterial_Material;
    static const MethodInfo* UpdateMaterial;
    static const MethodInfo* get_maskOffset;
    static const MethodInfo* set_maskOffset;
    static const MethodInfo* RecalculateClipping;
    static const MethodInfo* RecalculateMasking;
    static const MethodInfo* Cull_Rect_bool;
    static const MethodInfo* UpdateMeshPadding;
    static const MethodInfo* InternalCrossFadeColor_Color_float_bool_bool;
    static const MethodInfo* InternalCrossFadeAlpha_float_float_bool;
    static const MethodInfo* ForceMeshUpdate;
    static const MethodInfo* ForceMeshUpdate_bool;
    static const MethodInfo* GetTextInfo_string;
    static const MethodInfo* ClearMesh;
    static const MethodInfo* UpdateGeometry_Mesh_int;
    static const MethodInfo* UpdateVertexData_TMP_VertexDataUpdateFlags;
    static const MethodInfo* UpdateVertexData;
    static const MethodInfo* UpdateFontAsset;
    static const MethodInfo* Awake;
    static const MethodInfo* OnEnable;
    static const MethodInfo* OnDisable;
    static const MethodInfo* OnDestroy;
    static const MethodInfo* LoadFontAsset;
    static const MethodInfo* GetCanvas;
    static const MethodInfo* UpdateEnvMapMatrix;
    static const MethodInfo* EnableMasking;
    static const MethodInfo* DisableMasking;
    static const MethodInfo* UpdateMask;
    static const MethodInfo* GetMaterial_Material;
    static const MethodInfo* GetMaterials_Material_arr;
    static const MethodInfo* SetSharedMaterial_Material;
    static const MethodInfo* GetSharedMaterials;
    static const MethodInfo* SetSharedMaterials_Material_arr;
    static const MethodInfo* SetOutlineThickness_float;
    static const MethodInfo* SetFaceColor_Color32;
    static const MethodInfo* SetOutlineColor_Color32;
    static const MethodInfo* SetShaderDepth;
    static const MethodInfo* SetCulling;
    static const MethodInfo* SetPerspectiveCorrection;
    static const MethodInfo* GetPaddingForMaterial_Material;
    static const MethodInfo* GetPaddingForMaterial;
    static const MethodInfo* SetMeshArrays_int;
    static const MethodInfo* SetArraySizes_TMP_Text_UnicodeChar_arr;
    static const MethodInfo* ComputeMarginSize;
    static const MethodInfo* OnDidApplyAnimationProperties;
    static const MethodInfo* OnCanvasHierarchyChanged;
    static const MethodInfo* OnTransformParentChanged;
    static const MethodInfo* OnRectTransformDimensionsChange;
    static const MethodInfo* InternalUpdate;
    static const MethodInfo* OnPreRenderCanvas;
    static const MethodInfo* GenerateTextMesh;
    static const MethodInfo* GetTextContainerLocalCorners;
    static const MethodInfo* SetActiveSubMeshes_bool;
    static const MethodInfo* GetCompoundBounds;
    static const MethodInfo* UpdateSDFScale_float;
    static const MethodInfo* AdjustLineOffset_int_int_float;
    // The Initialization function that must be called before using any of these definitions
    static void Init() {
        if (!__cached) {
            klass = il2cpp_utils::GetClassFromName("TMPro", "TextMeshProUGUI");
            get_materialForRendering = il2cpp_functions::class_get_method_from_name(klass, "get_materialForRendering", 0);
            get_autoSizeTextContainer = il2cpp_functions::class_get_method_from_name(klass, "get_autoSizeTextContainer", 0);
            set_autoSizeTextContainer = il2cpp_functions::class_get_method_from_name(klass, "set_autoSizeTextContainer", 1);
            get_mesh = il2cpp_functions::class_get_method_from_name(klass, "get_mesh", 0);
            get_canvasRenderer = il2cpp_functions::class_get_method_from_name(klass, "get_canvasRenderer", 0);
            CalculateLayoutInputHorizontal = il2cpp_functions::class_get_method_from_name(klass, "CalculateLayoutInputHorizontal", 0);
            CalculateLayoutInputVertical = il2cpp_functions::class_get_method_from_name(klass, "CalculateLayoutInputVertical", 0);
            SetVerticesDirty = il2cpp_functions::class_get_method_from_name(klass, "SetVerticesDirty", 0);
            SetLayoutDirty = il2cpp_functions::class_get_method_from_name(klass, "SetLayoutDirty", 0);
            SetMaterialDirty = il2cpp_functions::class_get_method_from_name(klass, "SetMaterialDirty", 0);
            SetAllDirty = il2cpp_functions::class_get_method_from_name(klass, "SetAllDirty", 0);
            Rebuild_CanvasUpdate = il2cpp_functions::class_get_method_from_name(klass, "Rebuild", 1);
            UpdateSubObjectPivot = il2cpp_functions::class_get_method_from_name(klass, "UpdateSubObjectPivot", 0);
            GetModifiedMaterial_Material = il2cpp_functions::class_get_method_from_name(klass, "GetModifiedMaterial", 1);
            UpdateMaterial = il2cpp_functions::class_get_method_from_name(klass, "UpdateMaterial", 0);
            get_maskOffset = il2cpp_functions::class_get_method_from_name(klass, "get_maskOffset", 0);
            set_maskOffset = il2cpp_functions::class_get_method_from_name(klass, "set_maskOffset", 1);
            RecalculateClipping = il2cpp_functions::class_get_method_from_name(klass, "RecalculateClipping", 0);
            RecalculateMasking = il2cpp_functions::class_get_method_from_name(klass, "RecalculateMasking", 0);
            Cull_Rect_bool = il2cpp_functions::class_get_method_from_name(klass, "Cull", 2);
            UpdateMeshPadding = il2cpp_functions::class_get_method_from_name(klass, "UpdateMeshPadding", 0);
            InternalCrossFadeColor_Color_float_bool_bool = il2cpp_functions::class_get_method_from_name(klass, "InternalCrossFadeColor", 4);
            InternalCrossFadeAlpha_float_float_bool = il2cpp_functions::class_get_method_from_name(klass, "InternalCrossFadeAlpha", 3);
            ForceMeshUpdate = il2cpp_functions::class_get_method_from_name(klass, "ForceMeshUpdate", 0);
            ForceMeshUpdate_bool = il2cpp_functions::class_get_method_from_name(klass, "ForceMeshUpdate", 1);
            GetTextInfo_string = il2cpp_functions::class_get_method_from_name(klass, "GetTextInfo", 1);
            ClearMesh = il2cpp_functions::class_get_method_from_name(klass, "ClearMesh", 0);
            UpdateGeometry_Mesh_int = il2cpp_functions::class_get_method_from_name(klass, "UpdateGeometry", 2);
            UpdateVertexData_TMP_VertexDataUpdateFlags = il2cpp_functions::class_get_method_from_name(klass, "UpdateVertexData", 1);
            UpdateVertexData = il2cpp_functions::class_get_method_from_name(klass, "UpdateVertexData", 0);
            UpdateFontAsset = il2cpp_functions::class_get_method_from_name(klass, "UpdateFontAsset", 0);
            Awake = il2cpp_functions::class_get_method_from_name(klass, "Awake", 0);
            OnEnable = il2cpp_functions::class_get_method_from_name(klass, "OnEnable", 0);
            OnDisable = il2cpp_functions::class_get_method_from_name(klass, "OnDisable", 0);
            OnDestroy = il2cpp_functions::class_get_method_from_name(klass, "OnDestroy", 0);
            LoadFontAsset = il2cpp_functions::class_get_method_from_name(klass, "LoadFontAsset", 0);
            GetCanvas = il2cpp_functions::class_get_method_from_name(klass, "GetCanvas", 0);
            UpdateEnvMapMatrix = il2cpp_functions::class_get_method_from_name(klass, "UpdateEnvMapMatrix", 0);
            EnableMasking = il2cpp_functions::class_get_method_from_name(klass, "EnableMasking", 0);
            DisableMasking = il2cpp_functions::class_get_method_from_name(klass, "DisableMasking", 0);
            UpdateMask = il2cpp_functions::class_get_method_from_name(klass, "UpdateMask", 0);
            GetMaterial_Material = il2cpp_functions::class_get_method_from_name(klass, "GetMaterial", 1);
            GetMaterials_Material_arr = il2cpp_functions::class_get_method_from_name(klass, "GetMaterials", 1);
            SetSharedMaterial_Material = il2cpp_functions::class_get_method_from_name(klass, "SetSharedMaterial", 1);
            GetSharedMaterials = il2cpp_functions::class_get_method_from_name(klass, "GetSharedMaterials", 0);
            SetSharedMaterials_Material_arr = il2cpp_functions::class_get_method_from_name(klass, "SetSharedMaterials", 1);
            SetOutlineThickness_float = il2cpp_functions::class_get_method_from_name(klass, "SetOutlineThickness", 1);
            SetFaceColor_Color32 = il2cpp_functions::class_get_method_from_name(klass, "SetFaceColor", 1);
            SetOutlineColor_Color32 = il2cpp_functions::class_get_method_from_name(klass, "SetOutlineColor", 1);
            SetShaderDepth = il2cpp_functions::class_get_method_from_name(klass, "SetShaderDepth", 0);
            SetCulling = il2cpp_functions::class_get_method_from_name(klass, "SetCulling", 0);
            SetPerspectiveCorrection = il2cpp_functions::class_get_method_from_name(klass, "SetPerspectiveCorrection", 0);
            GetPaddingForMaterial_Material = il2cpp_functions::class_get_method_from_name(klass, "GetPaddingForMaterial", 1);
            GetPaddingForMaterial = il2cpp_functions::class_get_method_from_name(klass, "GetPaddingForMaterial", 0);
            SetMeshArrays_int = il2cpp_functions::class_get_method_from_name(klass, "SetMeshArrays", 1);
            SetArraySizes_TMP_Text_UnicodeChar_arr = il2cpp_functions::class_get_method_from_name(klass, "SetArraySizes", 1);
            ComputeMarginSize = il2cpp_functions::class_get_method_from_name(klass, "ComputeMarginSize", 0);
            OnDidApplyAnimationProperties = il2cpp_functions::class_get_method_from_name(klass, "OnDidApplyAnimationProperties", 0);
            OnCanvasHierarchyChanged = il2cpp_functions::class_get_method_from_name(klass, "OnCanvasHierarchyChanged", 0);
            OnTransformParentChanged = il2cpp_functions::class_get_method_from_name(klass, "OnTransformParentChanged", 0);
            OnRectTransformDimensionsChange = il2cpp_functions::class_get_method_from_name(klass, "OnRectTransformDimensionsChange", 0);
            InternalUpdate = il2cpp_functions::class_get_method_from_name(klass, "InternalUpdate", 0);
            OnPreRenderCanvas = il2cpp_functions::class_get_method_from_name(klass, "OnPreRenderCanvas", 0);
            GenerateTextMesh = il2cpp_functions::class_get_method_from_name(klass, "GenerateTextMesh", 0);
            GetTextContainerLocalCorners = il2cpp_functions::class_get_method_from_name(klass, "GetTextContainerLocalCorners", 0);
            SetActiveSubMeshes_bool = il2cpp_functions::class_get_method_from_name(klass, "SetActiveSubMeshes", 1);
            GetCompoundBounds = il2cpp_functions::class_get_method_from_name(klass, "GetCompoundBounds", 0);
            UpdateSDFScale_float = il2cpp_functions::class_get_method_from_name(klass, "UpdateSDFScale", 1);
            AdjustLineOffset_int_int_float = il2cpp_functions::class_get_method_from_name(klass, "AdjustLineOffset", 3);
            __cached = true;
        }
    }
}
#endif /* TMPro_TextMeshProUGUI_DEFINED */