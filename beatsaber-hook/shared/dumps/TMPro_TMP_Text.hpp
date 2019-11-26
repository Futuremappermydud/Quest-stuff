#ifndef TMPro_TMP_Text_DEFINED
#define TMPro_TMP_Text_DEFINED
// This .hpp file was compiled via beatsaber-hook/shared/helper.py's Parse Mode.
// Created by Sc2ad.
// Methods may not be valid!
#include <dlfcn.h>
#include <string_view>
#include "../utils/typedefs.h"
#include "../utils/il2cpp-functions.hpp"
#include "../utils/il2cpp-utils.hpp"
// Contains MethodInfo/Il2CppClass data for: TMPro.TMP_Text
namespace TMPro_TMP_Text {
    // TMPro.TMP_Text
    typedef struct Class : Il2CppObject {
        Il2CppString* m_text; // 0xB0
        uint8_t m_isRightToLeft; // 0xB8
        void* m_fontAsset; // 0xC0
        void* m_currentFontAsset; // 0xC8
        uint8_t m_isSDFShader; // 0xD0
        void* m_sharedMaterial; // 0xD8
        void* m_currentMaterial; // 0xE0
        void* m_materialReferences; // 0xE8
        void* m_materialReferenceIndexLookup; // 0xF0
        void* m_materialReferenceStack; // 0xF8
        int m_currentMaterialIndex; // 0x140
        void* m_fontSharedMaterials; // 0x148
        void* m_fontMaterial; // 0x150
        void* m_fontMaterials; // 0x158
        uint8_t m_isMaterialDirty; // 0x160
        void* m_fontColor32; // 0x164
        void* m_fontColor; // 0x168
        static void* s_colorWhite; // 0x0
        void* m_underlineColor; // 0x178
        void* m_strikethroughColor; // 0x17C
        void* m_highlightColor; // 0x180
        void* m_highlightPadding; // 0x184
        uint8_t m_enableVertexGradient; // 0x194
        void* m_colorMode; // 0x198
        void* m_fontColorGradient; // 0x19C
        void* m_fontColorGradientPreset; // 0x1E0
        void* m_spriteAsset; // 0x1E8
        uint8_t m_tintAllSprites; // 0x1F0
        uint8_t m_tintSprite; // 0x1F1
        void* m_spriteColor; // 0x1F4
        uint8_t m_overrideHtmlColors; // 0x1F8
        void* m_faceColor; // 0x1FC
        void* m_outlineColor; // 0x200
        float m_outlineWidth; // 0x204
        float m_fontSize; // 0x208
        float m_currentFontSize; // 0x20C
        float m_fontSizeBase; // 0x210
        void* m_sizeStack; // 0x218
        void* m_fontWeight; // 0x230
        void* m_FontWeightInternal; // 0x234
        void* m_FontWeightStack; // 0x238
        uint8_t m_enableAutoSizing; // 0x250
        float m_maxFontSize; // 0x254
        float m_minFontSize; // 0x258
        float m_fontSizeMin; // 0x25C
        float m_fontSizeMax; // 0x260
        void* m_fontStyle; // 0x264
        void* m_FontStyleInternal; // 0x268
        void* m_fontStyleStack; // 0x26C
        uint8_t m_isUsingBold; // 0x276
        void* m_textAlignment; // 0x278
        void* m_lineJustification; // 0x27C
        void* m_lineJustificationStack; // 0x280
        void* m_textContainerLocalCorners; // 0x298
        float m_characterSpacing; // 0x2A0
        float m_cSpacing; // 0x2A4
        float m_monoSpacing; // 0x2A8
        float m_wordSpacing; // 0x2AC
        float m_lineSpacing; // 0x2B0
        float m_lineSpacingDelta; // 0x2B4
        float m_lineHeight; // 0x2B8
        float m_lineSpacingMax; // 0x2BC
        float m_paragraphSpacing; // 0x2C0
        float m_charWidthMaxAdj; // 0x2C4
        float m_charWidthAdjDelta; // 0x2C8
        uint8_t m_enableWordWrapping; // 0x2CC
        uint8_t m_isCharacterWrappingEnabled; // 0x2CD
        uint8_t m_isNonBreakingSpace; // 0x2CE
        uint8_t m_isIgnoringAlignment; // 0x2CF
        float m_wordWrappingRatios; // 0x2D0
        void* m_overflowMode; // 0x2D4
        int m_firstOverflowCharacterIndex; // 0x2D8
        void* m_linkedTextComponent; // 0x2E0
        uint8_t m_isLinkedTextComponent; // 0x2E8
        uint8_t m_isTextTruncated; // 0x2E9
        uint8_t m_enableKerning; // 0x2EA
        uint8_t m_enableExtraPadding; // 0x2EB
        uint8_t checkPaddingRequired; // 0x2EC
        uint8_t m_isRichText; // 0x2ED
        uint8_t m_parseCtrlCharacters; // 0x2EE
        uint8_t m_isOverlay; // 0x2EF
        uint8_t m_isOrthographic; // 0x2F0
        uint8_t m_isCullingEnabled; // 0x2F1
        uint8_t m_ignoreRectMaskCulling; // 0x2F2
        uint8_t m_ignoreCulling; // 0x2F3
        void* m_horizontalMapping; // 0x2F4
        void* m_verticalMapping; // 0x2F8
        float m_uvLineOffset; // 0x2FC
        void* m_renderMode; // 0x300
        void* m_geometrySortingOrder; // 0x304
        uint8_t m_VertexBufferAutoSizeReduction; // 0x308
        int m_firstVisibleCharacter; // 0x30C
        int m_maxVisibleCharacters; // 0x310
        int m_maxVisibleWords; // 0x314
        int m_maxVisibleLines; // 0x318
        uint8_t m_useMaxVisibleDescender; // 0x31C
        int m_pageToDisplay; // 0x320
        uint8_t m_isNewPage; // 0x324
        void* m_margin; // 0x328
        float m_marginLeft; // 0x338
        float m_marginRight; // 0x33C
        float m_marginWidth; // 0x340
        float m_marginHeight; // 0x344
        float m_width; // 0x348
        void* m_textInfo; // 0x350
        uint8_t m_havePropertiesChanged; // 0x358
        uint8_t m_isUsingLegacyAnimationComponent; // 0x359
        void* m_transform; // 0x360
        void* m_rectTransform; // 0x368
        uint8_t autoSizeTextContainer_k__BackingField; // 0x370
        uint8_t m_autoSizeTextContainer; // 0x371
        void* m_mesh; // 0x378
        uint8_t m_isVolumetricText; // 0x380
        void* m_spriteAnimator; // 0x388
        float m_flexibleHeight; // 0x390
        float m_flexibleWidth; // 0x394
        float m_minWidth; // 0x398
        float m_minHeight; // 0x39C
        float m_maxWidth; // 0x3A0
        float m_maxHeight; // 0x3A4
        void* m_LayoutElement; // 0x3A8
        float m_preferredWidth; // 0x3B0
        float m_renderedWidth; // 0x3B4
        uint8_t m_isPreferredWidthDirty; // 0x3B8
        float m_preferredHeight; // 0x3BC
        float m_renderedHeight; // 0x3C0
        uint8_t m_isPreferredHeightDirty; // 0x3C4
        uint8_t m_isCalculatingPreferredValues; // 0x3C5
        int m_recursiveCount; // 0x3C8
        int m_layoutPriority; // 0x3CC
        uint8_t m_isCalculateSizeRequired; // 0x3D0
        uint8_t m_isLayoutDirty; // 0x3D1
        uint8_t m_verticesAlreadyDirty; // 0x3D2
        uint8_t m_layoutAlreadyDirty; // 0x3D3
        uint8_t m_isAwake; // 0x3D4
        uint8_t m_isWaitingOnResourceLoad; // 0x3D5
        uint8_t m_isInputParsingRequired; // 0x3D6
        void* m_inputSource; // 0x3D8
        Il2CppString* old_text; // 0x3E0
        float m_fontScale; // 0x3E8
        float m_fontScaleMultiplier; // 0x3EC
        void* m_htmlTag; // 0x3F0
        void* m_xmlAttribute; // 0x3F8
        void* m_attributeParameterValues; // 0x400
        float tag_LineIndent; // 0x408
        float tag_Indent; // 0x40C
        void* m_indentStack; // 0x410
        uint8_t tag_NoParsing; // 0x428
        uint8_t m_isParsingText; // 0x429
        void* m_FXMatrix; // 0x42C
        uint8_t m_isFXMatrixSet; // 0x46C
        void* m_TextParsingBuffer; // 0x470
        void* m_internalCharacterInfo; // 0x478
        void* m_input_CharArray; // 0x480
        int m_charArray_Length; // 0x488
        int m_totalCharacterCount; // 0x48C
        void* m_SavedWordWrapState; // 0x490
        void* m_SavedLineState; // 0x720
        int m_characterCount; // 0x9B0
        int m_firstCharacterOfLine; // 0x9B4
        int m_firstVisibleCharacterOfLine; // 0x9B8
        int m_lastCharacterOfLine; // 0x9BC
        int m_lastVisibleCharacterOfLine; // 0x9C0
        int m_lineNumber; // 0x9C4
        int m_lineVisibleCharacterCount; // 0x9C8
        int m_pageNumber; // 0x9CC
        float m_maxAscender; // 0x9D0
        float m_maxCapHeight; // 0x9D4
        float m_maxDescender; // 0x9D8
        float m_maxLineAscender; // 0x9DC
        float m_maxLineDescender; // 0x9E0
        float m_startOfLineAscender; // 0x9E4
        float m_lineOffset; // 0x9E8
        void* m_meshExtents; // 0x9EC
        void* m_htmlColor; // 0x9FC
        void* m_colorStack; // 0xA00
        void* m_underlineColorStack; // 0xA18
        void* m_strikethroughColorStack; // 0xA30
        void* m_highlightColorStack; // 0xA48
        void* m_colorGradientPreset; // 0xA60
        void* m_colorGradientStack; // 0xA68
        float m_tabSpacing; // 0xA80
        float m_spacing; // 0xA84
        void* m_styleStack; // 0xA88
        void* m_actionStack; // 0xAA0
        float m_padding; // 0xAB8
        float m_baselineOffset; // 0xABC
        void* m_baselineOffsetStack; // 0xAC0
        float m_xAdvance; // 0xAD8
        void* m_textElementType; // 0xADC
        void* m_cached_TextElement; // 0xAE0
        void* m_cached_Underline_Character; // 0xAE8
        void* m_cached_Ellipsis_Character; // 0xAF0
        void* m_defaultSpriteAsset; // 0xAF8
        void* m_currentSpriteAsset; // 0xB00
        int m_spriteCount; // 0xB08
        int m_spriteIndex; // 0xB0C
        int m_spriteAnimationID; // 0xB10
        uint8_t m_ignoreActiveState; // 0xB14
        void* k_Power; // 0xB18
        static void* k_LargePositiveVector2; // 0x4
        static void* k_LargeNegativeVector2; // 0xC
        static float k_LargePositiveFloat; // 0x14
        static float k_LargeNegativeFloat; // 0x18
        static int k_LargePositiveInt; // 0x1C
        static int k_LargeNegativeInt; // 0x20
    } Class;
    static bool __cached = false;
    static Il2CppClass* klass;
    static const MethodInfo* get_text;
    static const MethodInfo* set_text;
    static const MethodInfo* get_isRightToLeftText;
    static const MethodInfo* set_isRightToLeftText;
    static const MethodInfo* get_font;
    static const MethodInfo* set_font;
    static const MethodInfo* get_fontSharedMaterial;
    static const MethodInfo* set_fontSharedMaterial;
    static const MethodInfo* get_fontSharedMaterials;
    static const MethodInfo* set_fontSharedMaterials;
    static const MethodInfo* get_fontMaterial;
    static const MethodInfo* set_fontMaterial;
    static const MethodInfo* get_fontMaterials;
    static const MethodInfo* set_fontMaterials;
    static const MethodInfo* get_color;
    static const MethodInfo* set_color;
    static const MethodInfo* get_alpha;
    static const MethodInfo* set_alpha;
    static const MethodInfo* get_enableVertexGradient;
    static const MethodInfo* set_enableVertexGradient;
    static const MethodInfo* get_colorGradient;
    static const MethodInfo* set_colorGradient;
    static const MethodInfo* get_colorGradientPreset;
    static const MethodInfo* set_colorGradientPreset;
    static const MethodInfo* get_spriteAsset;
    static const MethodInfo* set_spriteAsset;
    static const MethodInfo* get_tintAllSprites;
    static const MethodInfo* set_tintAllSprites;
    static const MethodInfo* get_overrideColorTags;
    static const MethodInfo* set_overrideColorTags;
    static const MethodInfo* get_faceColor;
    static const MethodInfo* set_faceColor;
    static const MethodInfo* get_outlineColor;
    static const MethodInfo* set_outlineColor;
    static const MethodInfo* get_outlineWidth;
    static const MethodInfo* set_outlineWidth;
    static const MethodInfo* get_fontSize;
    static const MethodInfo* set_fontSize;
    static const MethodInfo* get_fontScale;
    static const MethodInfo* get_fontWeight;
    static const MethodInfo* set_fontWeight;
    static const MethodInfo* get_pixelsPerUnit;
    static const MethodInfo* get_enableAutoSizing;
    static const MethodInfo* set_enableAutoSizing;
    static const MethodInfo* get_fontSizeMin;
    static const MethodInfo* set_fontSizeMin;
    static const MethodInfo* get_fontSizeMax;
    static const MethodInfo* set_fontSizeMax;
    static const MethodInfo* get_fontStyle;
    static const MethodInfo* set_fontStyle;
    static const MethodInfo* get_isUsingBold;
    static const MethodInfo* get_alignment;
    static const MethodInfo* set_alignment;
    static const MethodInfo* get_characterSpacing;
    static const MethodInfo* set_characterSpacing;
    static const MethodInfo* get_wordSpacing;
    static const MethodInfo* set_wordSpacing;
    static const MethodInfo* get_lineSpacing;
    static const MethodInfo* set_lineSpacing;
    static const MethodInfo* get_lineSpacingAdjustment;
    static const MethodInfo* set_lineSpacingAdjustment;
    static const MethodInfo* get_paragraphSpacing;
    static const MethodInfo* set_paragraphSpacing;
    static const MethodInfo* get_characterWidthAdjustment;
    static const MethodInfo* set_characterWidthAdjustment;
    static const MethodInfo* get_enableWordWrapping;
    static const MethodInfo* set_enableWordWrapping;
    static const MethodInfo* get_wordWrappingRatios;
    static const MethodInfo* set_wordWrappingRatios;
    static const MethodInfo* get_overflowMode;
    static const MethodInfo* set_overflowMode;
    static const MethodInfo* get_isTextOverflowing;
    static const MethodInfo* get_firstOverflowCharacterIndex;
    static const MethodInfo* get_linkedTextComponent;
    static const MethodInfo* set_linkedTextComponent;
    static const MethodInfo* get_isLinkedTextComponent;
    static const MethodInfo* set_isLinkedTextComponent;
    static const MethodInfo* get_isTextTruncated;
    static const MethodInfo* get_enableKerning;
    static const MethodInfo* set_enableKerning;
    static const MethodInfo* get_extraPadding;
    static const MethodInfo* set_extraPadding;
    static const MethodInfo* get_richText;
    static const MethodInfo* set_richText;
    static const MethodInfo* get_parseCtrlCharacters;
    static const MethodInfo* set_parseCtrlCharacters;
    static const MethodInfo* get_isOverlay;
    static const MethodInfo* set_isOverlay;
    static const MethodInfo* get_isOrthographic;
    static const MethodInfo* set_isOrthographic;
    static const MethodInfo* get_enableCulling;
    static const MethodInfo* set_enableCulling;
    static const MethodInfo* get_ignoreRectMaskCulling;
    static const MethodInfo* set_ignoreRectMaskCulling;
    static const MethodInfo* get_ignoreVisibility;
    static const MethodInfo* set_ignoreVisibility;
    static const MethodInfo* get_horizontalMapping;
    static const MethodInfo* set_horizontalMapping;
    static const MethodInfo* get_verticalMapping;
    static const MethodInfo* set_verticalMapping;
    static const MethodInfo* get_mappingUvLineOffset;
    static const MethodInfo* set_mappingUvLineOffset;
    static const MethodInfo* get_renderMode;
    static const MethodInfo* set_renderMode;
    static const MethodInfo* get_geometrySortingOrder;
    static const MethodInfo* set_geometrySortingOrder;
    static const MethodInfo* get_vertexBufferAutoSizeReduction;
    static const MethodInfo* set_vertexBufferAutoSizeReduction;
    static const MethodInfo* get_firstVisibleCharacter;
    static const MethodInfo* set_firstVisibleCharacter;
    static const MethodInfo* get_maxVisibleCharacters;
    static const MethodInfo* set_maxVisibleCharacters;
    static const MethodInfo* get_maxVisibleWords;
    static const MethodInfo* set_maxVisibleWords;
    static const MethodInfo* get_maxVisibleLines;
    static const MethodInfo* set_maxVisibleLines;
    static const MethodInfo* get_useMaxVisibleDescender;
    static const MethodInfo* set_useMaxVisibleDescender;
    static const MethodInfo* get_pageToDisplay;
    static const MethodInfo* set_pageToDisplay;
    static const MethodInfo* get_margin;
    static const MethodInfo* set_margin;
    static const MethodInfo* get_textInfo;
    static const MethodInfo* get_havePropertiesChanged;
    static const MethodInfo* set_havePropertiesChanged;
    static const MethodInfo* get_isUsingLegacyAnimationComponent;
    static const MethodInfo* set_isUsingLegacyAnimationComponent;
    static const MethodInfo* get_transform;
    static const MethodInfo* get_rectTransform;
    static const MethodInfo* get_autoSizeTextContainer;
    static const MethodInfo* set_autoSizeTextContainer;
    static const MethodInfo* get_mesh;
    static const MethodInfo* get_isVolumetricText;
    static const MethodInfo* set_isVolumetricText;
    static const MethodInfo* get_bounds;
    static const MethodInfo* get_textBounds;
    static const MethodInfo* get_spriteAnimator;
    static const MethodInfo* get_flexibleHeight;
    static const MethodInfo* get_flexibleWidth;
    static const MethodInfo* get_minWidth;
    static const MethodInfo* get_minHeight;
    static const MethodInfo* get_maxWidth;
    static const MethodInfo* get_maxHeight;
    static const MethodInfo* get_layoutElement;
    static const MethodInfo* get_preferredWidth;
    static const MethodInfo* get_preferredHeight;
    static const MethodInfo* get_renderedWidth;
    static const MethodInfo* get_renderedHeight;
    static const MethodInfo* get_layoutPriority;
    static const MethodInfo* LoadFontAsset;
    static const MethodInfo* SetSharedMaterial_Material;
    static const MethodInfo* GetMaterial_Material;
    static const MethodInfo* SetFontBaseMaterial_Material;
    static const MethodInfo* GetSharedMaterials;
    static const MethodInfo* SetSharedMaterials_Material_arr;
    static const MethodInfo* GetMaterials_Material_arr;
    static const MethodInfo* CreateMaterialInstance_Material;
    static const MethodInfo* SetVertexColorGradient_TMP_ColorGradient;
    static const MethodInfo* SetTextSortingOrder_VertexSortingOrder;
    static const MethodInfo* SetTextSortingOrder_int_arr;
    static const MethodInfo* SetFaceColor_Color32;
    static const MethodInfo* SetOutlineColor_Color32;
    static const MethodInfo* SetOutlineThickness_float;
    static const MethodInfo* SetShaderDepth;
    static const MethodInfo* SetCulling;
    static const MethodInfo* GetPaddingForMaterial;
    static const MethodInfo* GetPaddingForMaterial_Material;
    static const MethodInfo* GetTextContainerLocalCorners;
    static const MethodInfo* ForceMeshUpdate;
    static const MethodInfo* ForceMeshUpdate_bool;
    static const MethodInfo* SetTextInternal_string;
    static const MethodInfo* UpdateGeometry_Mesh_int;
    static const MethodInfo* UpdateVertexData_TMP_VertexDataUpdateFlags;
    static const MethodInfo* UpdateVertexData;
    static const MethodInfo* SetVertices_Vector3_arr;
    static const MethodInfo* UpdateMeshPadding;
    static const MethodInfo* CrossFadeColor_Color_float_bool_bool;
    static const MethodInfo* CrossFadeAlpha_float_float_bool;
    static const MethodInfo* InternalCrossFadeColor_Color_float_bool_bool;
    static const MethodInfo* InternalCrossFadeAlpha_float_float_bool;
    static const MethodInfo* ParseInputText;
    static const MethodInfo* SetText_string;
    static const MethodInfo* SetText_string_bool;
    static const MethodInfo* SetText_string_float;
    static const MethodInfo* SetText_string_float_float;
    static const MethodInfo* SetText_string_float_float_float;
    static const MethodInfo* SetText_StringBuilder;
    static const MethodInfo* SetCharArray_char_arr;
    static const MethodInfo* SetCharArray_char_arr_int_int;
    static const MethodInfo* SetCharArray_int_arr_int_int;
    static const MethodInfo* SetTextArrayToCharArray_char_arr_TMP_Text_UnicodeChar_arr;
    static const MethodInfo* StringToCharArray_string_TMP_Text_UnicodeChar_arr;
    static const MethodInfo* StringBuilderToIntArray_StringBuilder_TMP_Text_UnicodeChar_arr;
    static const MethodInfo* ReplaceOpeningStyleTag_string_int_out_int_TMP_Text_UnicodeChar_arr_int;
    static const MethodInfo* ReplaceOpeningStyleTag_int_arr_int_out_int_TMP_Text_UnicodeChar_arr_int;
    static const MethodInfo* ReplaceOpeningStyleTag_char_arr_int_out_int_TMP_Text_UnicodeChar_arr_int;
    static const MethodInfo* ReplaceOpeningStyleTag_StringBuilder_int_out_int_TMP_Text_UnicodeChar_arr_int;
    static const MethodInfo* ReplaceClosingStyleTag_string_int_TMP_Text_UnicodeChar_arr_int;
    static const MethodInfo* ReplaceClosingStyleTag_int_arr_int_TMP_Text_UnicodeChar_arr_int;
    static const MethodInfo* ReplaceClosingStyleTag_char_arr_int_TMP_Text_UnicodeChar_arr_int;
    static const MethodInfo* ReplaceClosingStyleTag_StringBuilder_int_TMP_Text_UnicodeChar_arr_int;
    static const MethodInfo* IsTagName_string_string_int;
    static const MethodInfo* IsTagName_char_arr_string_int;
    static const MethodInfo* IsTagName_int_arr_string_int;
    static const MethodInfo* IsTagName_StringBuilder_string_int;
    static const MethodInfo* GetTagHashCode_string_int_out_int;
    static const MethodInfo* GetTagHashCode_char_arr_int_out_int;
    static const MethodInfo* GetTagHashCode_int_arr_int_out_int;
    static const MethodInfo* GetTagHashCode_StringBuilder_int_out_int;
    static const MethodInfo* ResizeInternalArray_T_arr;
    static const MethodInfo* AddFloatToCharArray_double_int_int;
    static const MethodInfo* AddIntToCharArray_double_int_int;
    static const MethodInfo* SetArraySizes_TMP_Text_UnicodeChar_arr;
    static const MethodInfo* GenerateTextMesh;
    static const MethodInfo* GetPreferredValues;
    static const MethodInfo* GetPreferredValues_float_float;
    static const MethodInfo* GetPreferredValues_string;
    static const MethodInfo* GetPreferredValues_string_float_float;
    static const MethodInfo* GetPreferredWidth;
    static const MethodInfo* GetPreferredWidth_Vector2;
    static const MethodInfo* GetPreferredHeight;
    static const MethodInfo* GetPreferredHeight_Vector2;
    static const MethodInfo* GetRenderedValues;
    static const MethodInfo* GetRenderedValues_bool;
    static const MethodInfo* GetRenderedWidth;
    static const MethodInfo* GetRenderedWidth_bool;
    static const MethodInfo* GetRenderedHeight;
    static const MethodInfo* GetRenderedHeight_bool;
    static const MethodInfo* CalculatePreferredValues_float_Vector2_bool;
    static const MethodInfo* GetCompoundBounds;
    static const MethodInfo* GetTextBounds;
    static const MethodInfo* GetTextBounds_bool;
    static const MethodInfo* AdjustLineOffset_int_int_float;
    static const MethodInfo* ResizeLineExtents_int;
    static const MethodInfo* GetTextInfo_string;
    static const MethodInfo* ComputeMarginSize;
    static const MethodInfo* SaveWordWrappingState_WordWrapState_int_int;
    static const MethodInfo* RestoreWordWrappingState_WordWrapState;
    static const MethodInfo* SaveGlyphVertexInfo_float_float_Color32;
    static const MethodInfo* SaveSpriteVertexInfo_Color32;
    static const MethodInfo* FillCharacterVertexBuffers_int_int;
    static const MethodInfo* FillCharacterVertexBuffers_int_int_bool;
    static const MethodInfo* FillSpriteVertexBuffers_int_int;
    static const MethodInfo* DrawUnderlineMesh_Vector3_Vector3_int_float_float_float_float_Color32;
    static const MethodInfo* DrawTextHighlight_Vector3_Vector3_int_Color32;
    static const MethodInfo* LoadDefaultSettings;
    static const MethodInfo* GetSpecialCharacters_TMP_FontAsset;
    static const MethodInfo* ReplaceTagWithCharacter_int_arr_int_int_char;
    static const MethodInfo* GetFontAssetForWeight_int;
    static const MethodInfo* SetActiveSubMeshes_bool;
    static const MethodInfo* ClearSubMeshObjects;
    static const MethodInfo* ClearMesh;
    static const MethodInfo* ClearMesh_bool;
    static const MethodInfo* GetParsedText;
    static const MethodInfo* PackUV_float_float_float;
    static const MethodInfo* PackUV_float_float;
    static const MethodInfo* InternalUpdate;
    static const MethodInfo* HexToInt_char;
    static const MethodInfo* GetUTF16_string_int;
    static const MethodInfo* GetUTF16_StringBuilder_int;
    static const MethodInfo* GetUTF32_string_int;
    static const MethodInfo* GetUTF32_StringBuilder_int;
    static const MethodInfo* HexCharsToColor_char_arr_int;
    static const MethodInfo* HexCharsToColor_char_arr_int_int;
    static const MethodInfo* GetAttributeParameters_char_arr_int_int_float_arr;
    static const MethodInfo* ConvertToFloat_char_arr_int_int;
    static const MethodInfo* ConvertToFloat_char_arr_int_int_out_int;
    static const MethodInfo* ValidateHtmlTag_TMP_Text_UnicodeChar_arr_int_out_int;
    // The Initialization function that must be called before using any of these definitions
    static void Init() {
        if (!__cached) {
            klass = il2cpp_utils::GetClassFromName("TMPro", "TMP_Text");
            get_text = il2cpp_functions::class_get_method_from_name(klass, "get_text", 0);
            set_text = il2cpp_functions::class_get_method_from_name(klass, "set_text", 1);
            get_isRightToLeftText = il2cpp_functions::class_get_method_from_name(klass, "get_isRightToLeftText", 0);
            set_isRightToLeftText = il2cpp_functions::class_get_method_from_name(klass, "set_isRightToLeftText", 1);
            get_font = il2cpp_functions::class_get_method_from_name(klass, "get_font", 0);
            set_font = il2cpp_functions::class_get_method_from_name(klass, "set_font", 1);
            get_fontSharedMaterial = il2cpp_functions::class_get_method_from_name(klass, "get_fontSharedMaterial", 0);
            set_fontSharedMaterial = il2cpp_functions::class_get_method_from_name(klass, "set_fontSharedMaterial", 1);
            get_fontSharedMaterials = il2cpp_functions::class_get_method_from_name(klass, "get_fontSharedMaterials", 0);
            set_fontSharedMaterials = il2cpp_functions::class_get_method_from_name(klass, "set_fontSharedMaterials", 1);
            get_fontMaterial = il2cpp_functions::class_get_method_from_name(klass, "get_fontMaterial", 0);
            set_fontMaterial = il2cpp_functions::class_get_method_from_name(klass, "set_fontMaterial", 1);
            get_fontMaterials = il2cpp_functions::class_get_method_from_name(klass, "get_fontMaterials", 0);
            set_fontMaterials = il2cpp_functions::class_get_method_from_name(klass, "set_fontMaterials", 1);
            get_color = il2cpp_functions::class_get_method_from_name(klass, "get_color", 0);
            set_color = il2cpp_functions::class_get_method_from_name(klass, "set_color", 1);
            get_alpha = il2cpp_functions::class_get_method_from_name(klass, "get_alpha", 0);
            set_alpha = il2cpp_functions::class_get_method_from_name(klass, "set_alpha", 1);
            get_enableVertexGradient = il2cpp_functions::class_get_method_from_name(klass, "get_enableVertexGradient", 0);
            set_enableVertexGradient = il2cpp_functions::class_get_method_from_name(klass, "set_enableVertexGradient", 1);
            get_colorGradient = il2cpp_functions::class_get_method_from_name(klass, "get_colorGradient", 0);
            set_colorGradient = il2cpp_functions::class_get_method_from_name(klass, "set_colorGradient", 1);
            get_colorGradientPreset = il2cpp_functions::class_get_method_from_name(klass, "get_colorGradientPreset", 0);
            set_colorGradientPreset = il2cpp_functions::class_get_method_from_name(klass, "set_colorGradientPreset", 1);
            get_spriteAsset = il2cpp_functions::class_get_method_from_name(klass, "get_spriteAsset", 0);
            set_spriteAsset = il2cpp_functions::class_get_method_from_name(klass, "set_spriteAsset", 1);
            get_tintAllSprites = il2cpp_functions::class_get_method_from_name(klass, "get_tintAllSprites", 0);
            set_tintAllSprites = il2cpp_functions::class_get_method_from_name(klass, "set_tintAllSprites", 1);
            get_overrideColorTags = il2cpp_functions::class_get_method_from_name(klass, "get_overrideColorTags", 0);
            set_overrideColorTags = il2cpp_functions::class_get_method_from_name(klass, "set_overrideColorTags", 1);
            get_faceColor = il2cpp_functions::class_get_method_from_name(klass, "get_faceColor", 0);
            set_faceColor = il2cpp_functions::class_get_method_from_name(klass, "set_faceColor", 1);
            get_outlineColor = il2cpp_functions::class_get_method_from_name(klass, "get_outlineColor", 0);
            set_outlineColor = il2cpp_functions::class_get_method_from_name(klass, "set_outlineColor", 1);
            get_outlineWidth = il2cpp_functions::class_get_method_from_name(klass, "get_outlineWidth", 0);
            set_outlineWidth = il2cpp_functions::class_get_method_from_name(klass, "set_outlineWidth", 1);
            get_fontSize = il2cpp_functions::class_get_method_from_name(klass, "get_fontSize", 0);
            set_fontSize = il2cpp_functions::class_get_method_from_name(klass, "set_fontSize", 1);
            get_fontScale = il2cpp_functions::class_get_method_from_name(klass, "get_fontScale", 0);
            get_fontWeight = il2cpp_functions::class_get_method_from_name(klass, "get_fontWeight", 0);
            set_fontWeight = il2cpp_functions::class_get_method_from_name(klass, "set_fontWeight", 1);
            get_pixelsPerUnit = il2cpp_functions::class_get_method_from_name(klass, "get_pixelsPerUnit", 0);
            get_enableAutoSizing = il2cpp_functions::class_get_method_from_name(klass, "get_enableAutoSizing", 0);
            set_enableAutoSizing = il2cpp_functions::class_get_method_from_name(klass, "set_enableAutoSizing", 1);
            get_fontSizeMin = il2cpp_functions::class_get_method_from_name(klass, "get_fontSizeMin", 0);
            set_fontSizeMin = il2cpp_functions::class_get_method_from_name(klass, "set_fontSizeMin", 1);
            get_fontSizeMax = il2cpp_functions::class_get_method_from_name(klass, "get_fontSizeMax", 0);
            set_fontSizeMax = il2cpp_functions::class_get_method_from_name(klass, "set_fontSizeMax", 1);
            get_fontStyle = il2cpp_functions::class_get_method_from_name(klass, "get_fontStyle", 0);
            set_fontStyle = il2cpp_functions::class_get_method_from_name(klass, "set_fontStyle", 1);
            get_isUsingBold = il2cpp_functions::class_get_method_from_name(klass, "get_isUsingBold", 0);
            get_alignment = il2cpp_functions::class_get_method_from_name(klass, "get_alignment", 0);
            set_alignment = il2cpp_functions::class_get_method_from_name(klass, "set_alignment", 1);
            get_characterSpacing = il2cpp_functions::class_get_method_from_name(klass, "get_characterSpacing", 0);
            set_characterSpacing = il2cpp_functions::class_get_method_from_name(klass, "set_characterSpacing", 1);
            get_wordSpacing = il2cpp_functions::class_get_method_from_name(klass, "get_wordSpacing", 0);
            set_wordSpacing = il2cpp_functions::class_get_method_from_name(klass, "set_wordSpacing", 1);
            get_lineSpacing = il2cpp_functions::class_get_method_from_name(klass, "get_lineSpacing", 0);
            set_lineSpacing = il2cpp_functions::class_get_method_from_name(klass, "set_lineSpacing", 1);
            get_lineSpacingAdjustment = il2cpp_functions::class_get_method_from_name(klass, "get_lineSpacingAdjustment", 0);
            set_lineSpacingAdjustment = il2cpp_functions::class_get_method_from_name(klass, "set_lineSpacingAdjustment", 1);
            get_paragraphSpacing = il2cpp_functions::class_get_method_from_name(klass, "get_paragraphSpacing", 0);
            set_paragraphSpacing = il2cpp_functions::class_get_method_from_name(klass, "set_paragraphSpacing", 1);
            get_characterWidthAdjustment = il2cpp_functions::class_get_method_from_name(klass, "get_characterWidthAdjustment", 0);
            set_characterWidthAdjustment = il2cpp_functions::class_get_method_from_name(klass, "set_characterWidthAdjustment", 1);
            get_enableWordWrapping = il2cpp_functions::class_get_method_from_name(klass, "get_enableWordWrapping", 0);
            set_enableWordWrapping = il2cpp_functions::class_get_method_from_name(klass, "set_enableWordWrapping", 1);
            get_wordWrappingRatios = il2cpp_functions::class_get_method_from_name(klass, "get_wordWrappingRatios", 0);
            set_wordWrappingRatios = il2cpp_functions::class_get_method_from_name(klass, "set_wordWrappingRatios", 1);
            get_overflowMode = il2cpp_functions::class_get_method_from_name(klass, "get_overflowMode", 0);
            set_overflowMode = il2cpp_functions::class_get_method_from_name(klass, "set_overflowMode", 1);
            get_isTextOverflowing = il2cpp_functions::class_get_method_from_name(klass, "get_isTextOverflowing", 0);
            get_firstOverflowCharacterIndex = il2cpp_functions::class_get_method_from_name(klass, "get_firstOverflowCharacterIndex", 0);
            get_linkedTextComponent = il2cpp_functions::class_get_method_from_name(klass, "get_linkedTextComponent", 0);
            set_linkedTextComponent = il2cpp_functions::class_get_method_from_name(klass, "set_linkedTextComponent", 1);
            get_isLinkedTextComponent = il2cpp_functions::class_get_method_from_name(klass, "get_isLinkedTextComponent", 0);
            set_isLinkedTextComponent = il2cpp_functions::class_get_method_from_name(klass, "set_isLinkedTextComponent", 1);
            get_isTextTruncated = il2cpp_functions::class_get_method_from_name(klass, "get_isTextTruncated", 0);
            get_enableKerning = il2cpp_functions::class_get_method_from_name(klass, "get_enableKerning", 0);
            set_enableKerning = il2cpp_functions::class_get_method_from_name(klass, "set_enableKerning", 1);
            get_extraPadding = il2cpp_functions::class_get_method_from_name(klass, "get_extraPadding", 0);
            set_extraPadding = il2cpp_functions::class_get_method_from_name(klass, "set_extraPadding", 1);
            get_richText = il2cpp_functions::class_get_method_from_name(klass, "get_richText", 0);
            set_richText = il2cpp_functions::class_get_method_from_name(klass, "set_richText", 1);
            get_parseCtrlCharacters = il2cpp_functions::class_get_method_from_name(klass, "get_parseCtrlCharacters", 0);
            set_parseCtrlCharacters = il2cpp_functions::class_get_method_from_name(klass, "set_parseCtrlCharacters", 1);
            get_isOverlay = il2cpp_functions::class_get_method_from_name(klass, "get_isOverlay", 0);
            set_isOverlay = il2cpp_functions::class_get_method_from_name(klass, "set_isOverlay", 1);
            get_isOrthographic = il2cpp_functions::class_get_method_from_name(klass, "get_isOrthographic", 0);
            set_isOrthographic = il2cpp_functions::class_get_method_from_name(klass, "set_isOrthographic", 1);
            get_enableCulling = il2cpp_functions::class_get_method_from_name(klass, "get_enableCulling", 0);
            set_enableCulling = il2cpp_functions::class_get_method_from_name(klass, "set_enableCulling", 1);
            get_ignoreRectMaskCulling = il2cpp_functions::class_get_method_from_name(klass, "get_ignoreRectMaskCulling", 0);
            set_ignoreRectMaskCulling = il2cpp_functions::class_get_method_from_name(klass, "set_ignoreRectMaskCulling", 1);
            get_ignoreVisibility = il2cpp_functions::class_get_method_from_name(klass, "get_ignoreVisibility", 0);
            set_ignoreVisibility = il2cpp_functions::class_get_method_from_name(klass, "set_ignoreVisibility", 1);
            get_horizontalMapping = il2cpp_functions::class_get_method_from_name(klass, "get_horizontalMapping", 0);
            set_horizontalMapping = il2cpp_functions::class_get_method_from_name(klass, "set_horizontalMapping", 1);
            get_verticalMapping = il2cpp_functions::class_get_method_from_name(klass, "get_verticalMapping", 0);
            set_verticalMapping = il2cpp_functions::class_get_method_from_name(klass, "set_verticalMapping", 1);
            get_mappingUvLineOffset = il2cpp_functions::class_get_method_from_name(klass, "get_mappingUvLineOffset", 0);
            set_mappingUvLineOffset = il2cpp_functions::class_get_method_from_name(klass, "set_mappingUvLineOffset", 1);
            get_renderMode = il2cpp_functions::class_get_method_from_name(klass, "get_renderMode", 0);
            set_renderMode = il2cpp_functions::class_get_method_from_name(klass, "set_renderMode", 1);
            get_geometrySortingOrder = il2cpp_functions::class_get_method_from_name(klass, "get_geometrySortingOrder", 0);
            set_geometrySortingOrder = il2cpp_functions::class_get_method_from_name(klass, "set_geometrySortingOrder", 1);
            get_vertexBufferAutoSizeReduction = il2cpp_functions::class_get_method_from_name(klass, "get_vertexBufferAutoSizeReduction", 0);
            set_vertexBufferAutoSizeReduction = il2cpp_functions::class_get_method_from_name(klass, "set_vertexBufferAutoSizeReduction", 1);
            get_firstVisibleCharacter = il2cpp_functions::class_get_method_from_name(klass, "get_firstVisibleCharacter", 0);
            set_firstVisibleCharacter = il2cpp_functions::class_get_method_from_name(klass, "set_firstVisibleCharacter", 1);
            get_maxVisibleCharacters = il2cpp_functions::class_get_method_from_name(klass, "get_maxVisibleCharacters", 0);
            set_maxVisibleCharacters = il2cpp_functions::class_get_method_from_name(klass, "set_maxVisibleCharacters", 1);
            get_maxVisibleWords = il2cpp_functions::class_get_method_from_name(klass, "get_maxVisibleWords", 0);
            set_maxVisibleWords = il2cpp_functions::class_get_method_from_name(klass, "set_maxVisibleWords", 1);
            get_maxVisibleLines = il2cpp_functions::class_get_method_from_name(klass, "get_maxVisibleLines", 0);
            set_maxVisibleLines = il2cpp_functions::class_get_method_from_name(klass, "set_maxVisibleLines", 1);
            get_useMaxVisibleDescender = il2cpp_functions::class_get_method_from_name(klass, "get_useMaxVisibleDescender", 0);
            set_useMaxVisibleDescender = il2cpp_functions::class_get_method_from_name(klass, "set_useMaxVisibleDescender", 1);
            get_pageToDisplay = il2cpp_functions::class_get_method_from_name(klass, "get_pageToDisplay", 0);
            set_pageToDisplay = il2cpp_functions::class_get_method_from_name(klass, "set_pageToDisplay", 1);
            get_margin = il2cpp_functions::class_get_method_from_name(klass, "get_margin", 0);
            set_margin = il2cpp_functions::class_get_method_from_name(klass, "set_margin", 1);
            get_textInfo = il2cpp_functions::class_get_method_from_name(klass, "get_textInfo", 0);
            get_havePropertiesChanged = il2cpp_functions::class_get_method_from_name(klass, "get_havePropertiesChanged", 0);
            set_havePropertiesChanged = il2cpp_functions::class_get_method_from_name(klass, "set_havePropertiesChanged", 1);
            get_isUsingLegacyAnimationComponent = il2cpp_functions::class_get_method_from_name(klass, "get_isUsingLegacyAnimationComponent", 0);
            set_isUsingLegacyAnimationComponent = il2cpp_functions::class_get_method_from_name(klass, "set_isUsingLegacyAnimationComponent", 1);
            get_transform = il2cpp_functions::class_get_method_from_name(klass, "get_transform", 0);
            get_rectTransform = il2cpp_functions::class_get_method_from_name(klass, "get_rectTransform", 0);
            get_autoSizeTextContainer = il2cpp_functions::class_get_method_from_name(klass, "get_autoSizeTextContainer", 0);
            set_autoSizeTextContainer = il2cpp_functions::class_get_method_from_name(klass, "set_autoSizeTextContainer", 1);
            get_mesh = il2cpp_functions::class_get_method_from_name(klass, "get_mesh", 0);
            get_isVolumetricText = il2cpp_functions::class_get_method_from_name(klass, "get_isVolumetricText", 0);
            set_isVolumetricText = il2cpp_functions::class_get_method_from_name(klass, "set_isVolumetricText", 1);
            get_bounds = il2cpp_functions::class_get_method_from_name(klass, "get_bounds", 0);
            get_textBounds = il2cpp_functions::class_get_method_from_name(klass, "get_textBounds", 0);
            get_spriteAnimator = il2cpp_functions::class_get_method_from_name(klass, "get_spriteAnimator", 0);
            get_flexibleHeight = il2cpp_functions::class_get_method_from_name(klass, "get_flexibleHeight", 0);
            get_flexibleWidth = il2cpp_functions::class_get_method_from_name(klass, "get_flexibleWidth", 0);
            get_minWidth = il2cpp_functions::class_get_method_from_name(klass, "get_minWidth", 0);
            get_minHeight = il2cpp_functions::class_get_method_from_name(klass, "get_minHeight", 0);
            get_maxWidth = il2cpp_functions::class_get_method_from_name(klass, "get_maxWidth", 0);
            get_maxHeight = il2cpp_functions::class_get_method_from_name(klass, "get_maxHeight", 0);
            get_layoutElement = il2cpp_functions::class_get_method_from_name(klass, "get_layoutElement", 0);
            get_preferredWidth = il2cpp_functions::class_get_method_from_name(klass, "get_preferredWidth", 0);
            get_preferredHeight = il2cpp_functions::class_get_method_from_name(klass, "get_preferredHeight", 0);
            get_renderedWidth = il2cpp_functions::class_get_method_from_name(klass, "get_renderedWidth", 0);
            get_renderedHeight = il2cpp_functions::class_get_method_from_name(klass, "get_renderedHeight", 0);
            get_layoutPriority = il2cpp_functions::class_get_method_from_name(klass, "get_layoutPriority", 0);
            LoadFontAsset = il2cpp_functions::class_get_method_from_name(klass, "LoadFontAsset", 0);
            SetSharedMaterial_Material = il2cpp_functions::class_get_method_from_name(klass, "SetSharedMaterial", 1);
            GetMaterial_Material = il2cpp_functions::class_get_method_from_name(klass, "GetMaterial", 1);
            SetFontBaseMaterial_Material = il2cpp_functions::class_get_method_from_name(klass, "SetFontBaseMaterial", 1);
            GetSharedMaterials = il2cpp_functions::class_get_method_from_name(klass, "GetSharedMaterials", 0);
            SetSharedMaterials_Material_arr = il2cpp_functions::class_get_method_from_name(klass, "SetSharedMaterials", 1);
            GetMaterials_Material_arr = il2cpp_functions::class_get_method_from_name(klass, "GetMaterials", 1);
            CreateMaterialInstance_Material = il2cpp_functions::class_get_method_from_name(klass, "CreateMaterialInstance", 1);
            SetVertexColorGradient_TMP_ColorGradient = il2cpp_functions::class_get_method_from_name(klass, "SetVertexColorGradient", 1);
            SetTextSortingOrder_VertexSortingOrder = il2cpp_functions::class_get_method_from_name(klass, "SetTextSortingOrder", 1);
            SetTextSortingOrder_int_arr = il2cpp_functions::class_get_method_from_name(klass, "SetTextSortingOrder", 1);
            SetFaceColor_Color32 = il2cpp_functions::class_get_method_from_name(klass, "SetFaceColor", 1);
            SetOutlineColor_Color32 = il2cpp_functions::class_get_method_from_name(klass, "SetOutlineColor", 1);
            SetOutlineThickness_float = il2cpp_functions::class_get_method_from_name(klass, "SetOutlineThickness", 1);
            SetShaderDepth = il2cpp_functions::class_get_method_from_name(klass, "SetShaderDepth", 0);
            SetCulling = il2cpp_functions::class_get_method_from_name(klass, "SetCulling", 0);
            GetPaddingForMaterial = il2cpp_functions::class_get_method_from_name(klass, "GetPaddingForMaterial", 0);
            GetPaddingForMaterial_Material = il2cpp_functions::class_get_method_from_name(klass, "GetPaddingForMaterial", 1);
            GetTextContainerLocalCorners = il2cpp_functions::class_get_method_from_name(klass, "GetTextContainerLocalCorners", 0);
            ForceMeshUpdate = il2cpp_functions::class_get_method_from_name(klass, "ForceMeshUpdate", 0);
            ForceMeshUpdate_bool = il2cpp_functions::class_get_method_from_name(klass, "ForceMeshUpdate", 1);
            SetTextInternal_string = il2cpp_functions::class_get_method_from_name(klass, "SetTextInternal", 1);
            UpdateGeometry_Mesh_int = il2cpp_functions::class_get_method_from_name(klass, "UpdateGeometry", 2);
            UpdateVertexData_TMP_VertexDataUpdateFlags = il2cpp_functions::class_get_method_from_name(klass, "UpdateVertexData", 1);
            UpdateVertexData = il2cpp_functions::class_get_method_from_name(klass, "UpdateVertexData", 0);
            SetVertices_Vector3_arr = il2cpp_functions::class_get_method_from_name(klass, "SetVertices", 1);
            UpdateMeshPadding = il2cpp_functions::class_get_method_from_name(klass, "UpdateMeshPadding", 0);
            CrossFadeColor_Color_float_bool_bool = il2cpp_functions::class_get_method_from_name(klass, "CrossFadeColor", 4);
            CrossFadeAlpha_float_float_bool = il2cpp_functions::class_get_method_from_name(klass, "CrossFadeAlpha", 3);
            InternalCrossFadeColor_Color_float_bool_bool = il2cpp_functions::class_get_method_from_name(klass, "InternalCrossFadeColor", 4);
            InternalCrossFadeAlpha_float_float_bool = il2cpp_functions::class_get_method_from_name(klass, "InternalCrossFadeAlpha", 3);
            ParseInputText = il2cpp_functions::class_get_method_from_name(klass, "ParseInputText", 0);
            SetText_string = il2cpp_functions::class_get_method_from_name(klass, "SetText", 1);
            SetText_string_bool = il2cpp_functions::class_get_method_from_name(klass, "SetText", 2);
            SetText_string_float = il2cpp_functions::class_get_method_from_name(klass, "SetText", 2);
            SetText_string_float_float = il2cpp_functions::class_get_method_from_name(klass, "SetText", 3);
            SetText_string_float_float_float = il2cpp_functions::class_get_method_from_name(klass, "SetText", 4);
            SetText_StringBuilder = il2cpp_functions::class_get_method_from_name(klass, "SetText", 1);
            SetCharArray_char_arr = il2cpp_functions::class_get_method_from_name(klass, "SetCharArray", 1);
            SetCharArray_char_arr_int_int = il2cpp_functions::class_get_method_from_name(klass, "SetCharArray", 3);
            SetCharArray_int_arr_int_int = il2cpp_functions::class_get_method_from_name(klass, "SetCharArray", 3);
            SetTextArrayToCharArray_char_arr_TMP_Text_UnicodeChar_arr = il2cpp_functions::class_get_method_from_name(klass, "SetTextArrayToCharArray", 2);
            StringToCharArray_string_TMP_Text_UnicodeChar_arr = il2cpp_functions::class_get_method_from_name(klass, "StringToCharArray", 2);
            StringBuilderToIntArray_StringBuilder_TMP_Text_UnicodeChar_arr = il2cpp_functions::class_get_method_from_name(klass, "StringBuilderToIntArray", 2);
            ReplaceOpeningStyleTag_string_int_out_int_TMP_Text_UnicodeChar_arr_int = il2cpp_functions::class_get_method_from_name(klass, "ReplaceOpeningStyleTag", 5);
            ReplaceOpeningStyleTag_int_arr_int_out_int_TMP_Text_UnicodeChar_arr_int = il2cpp_functions::class_get_method_from_name(klass, "ReplaceOpeningStyleTag", 5);
            ReplaceOpeningStyleTag_char_arr_int_out_int_TMP_Text_UnicodeChar_arr_int = il2cpp_functions::class_get_method_from_name(klass, "ReplaceOpeningStyleTag", 5);
            ReplaceOpeningStyleTag_StringBuilder_int_out_int_TMP_Text_UnicodeChar_arr_int = il2cpp_functions::class_get_method_from_name(klass, "ReplaceOpeningStyleTag", 5);
            ReplaceClosingStyleTag_string_int_TMP_Text_UnicodeChar_arr_int = il2cpp_functions::class_get_method_from_name(klass, "ReplaceClosingStyleTag", 4);
            ReplaceClosingStyleTag_int_arr_int_TMP_Text_UnicodeChar_arr_int = il2cpp_functions::class_get_method_from_name(klass, "ReplaceClosingStyleTag", 4);
            ReplaceClosingStyleTag_char_arr_int_TMP_Text_UnicodeChar_arr_int = il2cpp_functions::class_get_method_from_name(klass, "ReplaceClosingStyleTag", 4);
            ReplaceClosingStyleTag_StringBuilder_int_TMP_Text_UnicodeChar_arr_int = il2cpp_functions::class_get_method_from_name(klass, "ReplaceClosingStyleTag", 4);
            IsTagName_string_string_int = il2cpp_functions::class_get_method_from_name(klass, "IsTagName", 3);
            IsTagName_char_arr_string_int = il2cpp_functions::class_get_method_from_name(klass, "IsTagName", 3);
            IsTagName_int_arr_string_int = il2cpp_functions::class_get_method_from_name(klass, "IsTagName", 3);
            IsTagName_StringBuilder_string_int = il2cpp_functions::class_get_method_from_name(klass, "IsTagName", 3);
            GetTagHashCode_string_int_out_int = il2cpp_functions::class_get_method_from_name(klass, "GetTagHashCode", 3);
            GetTagHashCode_char_arr_int_out_int = il2cpp_functions::class_get_method_from_name(klass, "GetTagHashCode", 3);
            GetTagHashCode_int_arr_int_out_int = il2cpp_functions::class_get_method_from_name(klass, "GetTagHashCode", 3);
            GetTagHashCode_StringBuilder_int_out_int = il2cpp_functions::class_get_method_from_name(klass, "GetTagHashCode", 3);
            ResizeInternalArray_T_arr = il2cpp_functions::class_get_method_from_name(klass, "ResizeInternalArray", 1);
            AddFloatToCharArray_double_int_int = il2cpp_functions::class_get_method_from_name(klass, "AddFloatToCharArray", 3);
            AddIntToCharArray_double_int_int = il2cpp_functions::class_get_method_from_name(klass, "AddIntToCharArray", 3);
            SetArraySizes_TMP_Text_UnicodeChar_arr = il2cpp_functions::class_get_method_from_name(klass, "SetArraySizes", 1);
            GenerateTextMesh = il2cpp_functions::class_get_method_from_name(klass, "GenerateTextMesh", 0);
            GetPreferredValues = il2cpp_functions::class_get_method_from_name(klass, "GetPreferredValues", 0);
            GetPreferredValues_float_float = il2cpp_functions::class_get_method_from_name(klass, "GetPreferredValues", 2);
            GetPreferredValues_string = il2cpp_functions::class_get_method_from_name(klass, "GetPreferredValues", 1);
            GetPreferredValues_string_float_float = il2cpp_functions::class_get_method_from_name(klass, "GetPreferredValues", 3);
            GetPreferredWidth = il2cpp_functions::class_get_method_from_name(klass, "GetPreferredWidth", 0);
            GetPreferredWidth_Vector2 = il2cpp_functions::class_get_method_from_name(klass, "GetPreferredWidth", 1);
            GetPreferredHeight = il2cpp_functions::class_get_method_from_name(klass, "GetPreferredHeight", 0);
            GetPreferredHeight_Vector2 = il2cpp_functions::class_get_method_from_name(klass, "GetPreferredHeight", 1);
            GetRenderedValues = il2cpp_functions::class_get_method_from_name(klass, "GetRenderedValues", 0);
            GetRenderedValues_bool = il2cpp_functions::class_get_method_from_name(klass, "GetRenderedValues", 1);
            GetRenderedWidth = il2cpp_functions::class_get_method_from_name(klass, "GetRenderedWidth", 0);
            GetRenderedWidth_bool = il2cpp_functions::class_get_method_from_name(klass, "GetRenderedWidth", 1);
            GetRenderedHeight = il2cpp_functions::class_get_method_from_name(klass, "GetRenderedHeight", 0);
            GetRenderedHeight_bool = il2cpp_functions::class_get_method_from_name(klass, "GetRenderedHeight", 1);
            CalculatePreferredValues_float_Vector2_bool = il2cpp_functions::class_get_method_from_name(klass, "CalculatePreferredValues", 3);
            GetCompoundBounds = il2cpp_functions::class_get_method_from_name(klass, "GetCompoundBounds", 0);
            GetTextBounds = il2cpp_functions::class_get_method_from_name(klass, "GetTextBounds", 0);
            GetTextBounds_bool = il2cpp_functions::class_get_method_from_name(klass, "GetTextBounds", 1);
            AdjustLineOffset_int_int_float = il2cpp_functions::class_get_method_from_name(klass, "AdjustLineOffset", 3);
            ResizeLineExtents_int = il2cpp_functions::class_get_method_from_name(klass, "ResizeLineExtents", 1);
            GetTextInfo_string = il2cpp_functions::class_get_method_from_name(klass, "GetTextInfo", 1);
            ComputeMarginSize = il2cpp_functions::class_get_method_from_name(klass, "ComputeMarginSize", 0);
            SaveWordWrappingState_WordWrapState_int_int = il2cpp_functions::class_get_method_from_name(klass, "SaveWordWrappingState", 3);
            RestoreWordWrappingState_WordWrapState = il2cpp_functions::class_get_method_from_name(klass, "RestoreWordWrappingState", 1);
            SaveGlyphVertexInfo_float_float_Color32 = il2cpp_functions::class_get_method_from_name(klass, "SaveGlyphVertexInfo", 3);
            SaveSpriteVertexInfo_Color32 = il2cpp_functions::class_get_method_from_name(klass, "SaveSpriteVertexInfo", 1);
            FillCharacterVertexBuffers_int_int = il2cpp_functions::class_get_method_from_name(klass, "FillCharacterVertexBuffers", 2);
            FillCharacterVertexBuffers_int_int_bool = il2cpp_functions::class_get_method_from_name(klass, "FillCharacterVertexBuffers", 3);
            FillSpriteVertexBuffers_int_int = il2cpp_functions::class_get_method_from_name(klass, "FillSpriteVertexBuffers", 2);
            DrawUnderlineMesh_Vector3_Vector3_int_float_float_float_float_Color32 = il2cpp_functions::class_get_method_from_name(klass, "DrawUnderlineMesh", 8);
            DrawTextHighlight_Vector3_Vector3_int_Color32 = il2cpp_functions::class_get_method_from_name(klass, "DrawTextHighlight", 4);
            LoadDefaultSettings = il2cpp_functions::class_get_method_from_name(klass, "LoadDefaultSettings", 0);
            GetSpecialCharacters_TMP_FontAsset = il2cpp_functions::class_get_method_from_name(klass, "GetSpecialCharacters", 1);
            ReplaceTagWithCharacter_int_arr_int_int_char = il2cpp_functions::class_get_method_from_name(klass, "ReplaceTagWithCharacter", 4);
            GetFontAssetForWeight_int = il2cpp_functions::class_get_method_from_name(klass, "GetFontAssetForWeight", 1);
            SetActiveSubMeshes_bool = il2cpp_functions::class_get_method_from_name(klass, "SetActiveSubMeshes", 1);
            ClearSubMeshObjects = il2cpp_functions::class_get_method_from_name(klass, "ClearSubMeshObjects", 0);
            ClearMesh = il2cpp_functions::class_get_method_from_name(klass, "ClearMesh", 0);
            ClearMesh_bool = il2cpp_functions::class_get_method_from_name(klass, "ClearMesh", 1);
            GetParsedText = il2cpp_functions::class_get_method_from_name(klass, "GetParsedText", 0);
            PackUV_float_float_float = il2cpp_functions::class_get_method_from_name(klass, "PackUV", 3);
            PackUV_float_float = il2cpp_functions::class_get_method_from_name(klass, "PackUV", 2);
            InternalUpdate = il2cpp_functions::class_get_method_from_name(klass, "InternalUpdate", 0);
            HexToInt_char = il2cpp_functions::class_get_method_from_name(klass, "HexToInt", 1);
            GetUTF16_string_int = il2cpp_functions::class_get_method_from_name(klass, "GetUTF16", 2);
            GetUTF16_StringBuilder_int = il2cpp_functions::class_get_method_from_name(klass, "GetUTF16", 2);
            GetUTF32_string_int = il2cpp_functions::class_get_method_from_name(klass, "GetUTF32", 2);
            GetUTF32_StringBuilder_int = il2cpp_functions::class_get_method_from_name(klass, "GetUTF32", 2);
            HexCharsToColor_char_arr_int = il2cpp_functions::class_get_method_from_name(klass, "HexCharsToColor", 2);
            HexCharsToColor_char_arr_int_int = il2cpp_functions::class_get_method_from_name(klass, "HexCharsToColor", 3);
            GetAttributeParameters_char_arr_int_int_float_arr = il2cpp_functions::class_get_method_from_name(klass, "GetAttributeParameters", 4);
            ConvertToFloat_char_arr_int_int = il2cpp_functions::class_get_method_from_name(klass, "ConvertToFloat", 3);
            ConvertToFloat_char_arr_int_int_out_int = il2cpp_functions::class_get_method_from_name(klass, "ConvertToFloat", 4);
            ValidateHtmlTag_TMP_Text_UnicodeChar_arr_int_out_int = il2cpp_functions::class_get_method_from_name(klass, "ValidateHtmlTag", 3);
            __cached = true;
        }
    }
}
#endif /* TMPro_TMP_Text_DEFINED */