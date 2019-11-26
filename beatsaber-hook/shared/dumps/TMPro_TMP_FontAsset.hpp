#ifndef TMPro_TMP_FontAsset_DEFINED
#define TMPro_TMP_FontAsset_DEFINED
// This .hpp file was compiled via beatsaber-hook/shared/helper.py's Parse Mode.
// Created by Sc2ad.
// Methods may not be valid!
#include <dlfcn.h>
#include <string_view>
#include "../utils/typedefs.h"
#include "../utils/il2cpp-functions.hpp"
#include "../utils/il2cpp-utils.hpp"
// Contains MethodInfo/Il2CppClass data for: TMPro.TMP_FontAsset
namespace TMPro_TMP_FontAsset {
    // TMPro.TMP_FontAsset
    typedef struct Class : Il2CppObject {
        Il2CppString* m_Version; // 0x30
        Il2CppString* m_SourceFontFileGUID; // 0x38
        void* m_SourceFontFile; // 0x40
        void* m_AtlasPopulationMode; // 0x48
        void* m_FaceInfo; // 0x50
        void* m_GlyphTable; // 0xA8
        void* m_GlyphLookupDictionary; // 0xB0
        void* m_CharacterTable; // 0xB8
        void* m_CharacterLookupDictionary; // 0xC0
        void* m_AtlasTexture; // 0xC8
        void* m_AtlasTextures; // 0xD0
        int m_AtlasTextureIndex; // 0xD8
        void* m_UsedGlyphRects; // 0xE0
        void* m_FreeGlyphRects; // 0xE8
        void* m_fontInfo; // 0xF0
        void* atlas; // 0xF8
        int m_AtlasWidth; // 0x100
        int m_AtlasHeight; // 0x104
        int m_AtlasPadding; // 0x108
        void* m_AtlasRenderMode; // 0x10C
        void* m_glyphInfoList; // 0x110
        void* m_KerningTable; // 0x118
        void* m_FontFeatureTable; // 0x120
        void* fallbackFontAssets; // 0x128
        void* m_FallbackFontAssetTable; // 0x130
        void* m_CreationSettings; // 0x138
        void* m_FontWeightTable; // 0x190
        void* fontWeights; // 0x198
        float normalStyle; // 0x1A0
        float normalSpacingOffset; // 0x1A4
        float boldStyle; // 0x1A8
        float boldSpacing; // 0x1AC
        char italicStyle; // 0x1B0
        char tabSize; // 0x1B1
        char m_oldTabSize; // 0x1B2
        uint8_t m_IsFontAssetLookupTablesDirty; // 0x1B3
        void* m_GlyphsToPack; // 0x1B8
        void* m_GlyphsPacked; // 0x1C0
        void* m_GlyphsToRender; // 0x1C8
        void* m_GlyphIndexList; // 0x1D0
        void* m_CharactersToAdd; // 0x1D8
        static void* s_GlyphIndexArray; // 0x0
        static void* s_MissingCharacterList; // 0x8
    } Class;
    static bool __cached = false;
    static Il2CppClass* klass;
    static const MethodInfo* get_version;
    static const MethodInfo* set_version;
    static const MethodInfo* get_sourceFontFile;
    static const MethodInfo* set_sourceFontFile;
    static const MethodInfo* get_atlasPopulationMode;
    static const MethodInfo* set_atlasPopulationMode;
    static const MethodInfo* get_faceInfo;
    static const MethodInfo* set_faceInfo;
    static const MethodInfo* get_glyphTable;
    static const MethodInfo* set_glyphTable;
    static const MethodInfo* get_glyphLookupTable;
    static const MethodInfo* get_characterTable;
    static const MethodInfo* set_characterTable;
    static const MethodInfo* get_characterLookupTable;
    static const MethodInfo* get_atlasTexture;
    static const MethodInfo* get_atlasTextures;
    static const MethodInfo* set_atlasTextures;
    static const MethodInfo* get_usedGlyphRects;
    static const MethodInfo* set_usedGlyphRects;
    static const MethodInfo* get_freeGlyphRects;
    static const MethodInfo* set_freeGlyphRects;
    static const MethodInfo* get_fontInfo;
    static const MethodInfo* get_atlasWidth;
    static const MethodInfo* set_atlasWidth;
    static const MethodInfo* get_atlasHeight;
    static const MethodInfo* set_atlasHeight;
    static const MethodInfo* get_atlasPadding;
    static const MethodInfo* set_atlasPadding;
    static const MethodInfo* get_atlasRenderMode;
    static const MethodInfo* set_atlasRenderMode;
    static const MethodInfo* get_fontFeatureTable;
    static const MethodInfo* set_fontFeatureTable;
    static const MethodInfo* get_fallbackFontAssetTable;
    static const MethodInfo* set_fallbackFontAssetTable;
    static const MethodInfo* get_creationSettings;
    static const MethodInfo* set_creationSettings;
    static const MethodInfo* get_fontWeightTable;
    static const MethodInfo* set_fontWeightTable;
    static const MethodInfo* CreateFontAsset_Font;
    static const MethodInfo* CreateFontAsset_Font_int_int_GlyphRenderMode_int_int_optional_AtlasPopulationMode;
    static const MethodInfo* Awake;
    static const MethodInfo* InitializeDictionaryLookupTables;
    static const MethodInfo* ReadFontAssetDefinition;
    static const MethodInfo* SortCharacterTable;
    static const MethodInfo* SortGlyphTable;
    static const MethodInfo* SortGlyphAndCharacterTables;
    static const MethodInfo* HasCharacter_int;
    static const MethodInfo* HasCharacter_char;
    static const MethodInfo* HasCharacter_char_bool;
    static const MethodInfo* HasCharacter_Internal_char_bool;
    static const MethodInfo* HasCharacters_string_out_List1;
    static const MethodInfo* HasCharacters_string;
    static const MethodInfo* GetCharacters_TMP_FontAsset;
    static const MethodInfo* GetCharactersArray_TMP_FontAsset;
    static const MethodInfo* TryAddCharacters_uint_arr;
    static const MethodInfo* TryAddCharacters_uint_arr_out_uint_arr;
    static const MethodInfo* TryAddCharacters_string;
    static const MethodInfo* TryAddCharacters_string_out_string;
    static const MethodInfo* TryAddCharacter_Internal_uint;
    static const MethodInfo* AddCharacter_Internal_uint_Glyph;
    static const MethodInfo* TryAddCharacterInternal_uint_out_TMP_Character;
    static const MethodInfo* GetGlyphIndex_uint;
    static const MethodInfo* UpdateAtlasTexture;
    static const MethodInfo* UpdateGlyphAdjustmentRecords_uint_uint;
    static const MethodInfo* ClearFontAssetData_optional_bool;
    static const MethodInfo* UpgradeFontAsset;
    static const MethodInfo* UpgradeGlyphAdjustmentTableToFontFeatureTable;
    // The Initialization function that must be called before using any of these definitions
    static void Init() {
        if (!__cached) {
            klass = il2cpp_utils::GetClassFromName("TMPro", "TMP_FontAsset");
            get_version = il2cpp_functions::class_get_method_from_name(klass, "get_version", 0);
            set_version = il2cpp_functions::class_get_method_from_name(klass, "set_version", 1);
            get_sourceFontFile = il2cpp_functions::class_get_method_from_name(klass, "get_sourceFontFile", 0);
            set_sourceFontFile = il2cpp_functions::class_get_method_from_name(klass, "set_sourceFontFile", 1);
            get_atlasPopulationMode = il2cpp_functions::class_get_method_from_name(klass, "get_atlasPopulationMode", 0);
            set_atlasPopulationMode = il2cpp_functions::class_get_method_from_name(klass, "set_atlasPopulationMode", 1);
            get_faceInfo = il2cpp_functions::class_get_method_from_name(klass, "get_faceInfo", 0);
            set_faceInfo = il2cpp_functions::class_get_method_from_name(klass, "set_faceInfo", 1);
            get_glyphTable = il2cpp_functions::class_get_method_from_name(klass, "get_glyphTable", 0);
            set_glyphTable = il2cpp_functions::class_get_method_from_name(klass, "set_glyphTable", 1);
            get_glyphLookupTable = il2cpp_functions::class_get_method_from_name(klass, "get_glyphLookupTable", 0);
            get_characterTable = il2cpp_functions::class_get_method_from_name(klass, "get_characterTable", 0);
            set_characterTable = il2cpp_functions::class_get_method_from_name(klass, "set_characterTable", 1);
            get_characterLookupTable = il2cpp_functions::class_get_method_from_name(klass, "get_characterLookupTable", 0);
            get_atlasTexture = il2cpp_functions::class_get_method_from_name(klass, "get_atlasTexture", 0);
            get_atlasTextures = il2cpp_functions::class_get_method_from_name(klass, "get_atlasTextures", 0);
            set_atlasTextures = il2cpp_functions::class_get_method_from_name(klass, "set_atlasTextures", 1);
            get_usedGlyphRects = il2cpp_functions::class_get_method_from_name(klass, "get_usedGlyphRects", 0);
            set_usedGlyphRects = il2cpp_functions::class_get_method_from_name(klass, "set_usedGlyphRects", 1);
            get_freeGlyphRects = il2cpp_functions::class_get_method_from_name(klass, "get_freeGlyphRects", 0);
            set_freeGlyphRects = il2cpp_functions::class_get_method_from_name(klass, "set_freeGlyphRects", 1);
            get_fontInfo = il2cpp_functions::class_get_method_from_name(klass, "get_fontInfo", 0);
            get_atlasWidth = il2cpp_functions::class_get_method_from_name(klass, "get_atlasWidth", 0);
            set_atlasWidth = il2cpp_functions::class_get_method_from_name(klass, "set_atlasWidth", 1);
            get_atlasHeight = il2cpp_functions::class_get_method_from_name(klass, "get_atlasHeight", 0);
            set_atlasHeight = il2cpp_functions::class_get_method_from_name(klass, "set_atlasHeight", 1);
            get_atlasPadding = il2cpp_functions::class_get_method_from_name(klass, "get_atlasPadding", 0);
            set_atlasPadding = il2cpp_functions::class_get_method_from_name(klass, "set_atlasPadding", 1);
            get_atlasRenderMode = il2cpp_functions::class_get_method_from_name(klass, "get_atlasRenderMode", 0);
            set_atlasRenderMode = il2cpp_functions::class_get_method_from_name(klass, "set_atlasRenderMode", 1);
            get_fontFeatureTable = il2cpp_functions::class_get_method_from_name(klass, "get_fontFeatureTable", 0);
            set_fontFeatureTable = il2cpp_functions::class_get_method_from_name(klass, "set_fontFeatureTable", 1);
            get_fallbackFontAssetTable = il2cpp_functions::class_get_method_from_name(klass, "get_fallbackFontAssetTable", 0);
            set_fallbackFontAssetTable = il2cpp_functions::class_get_method_from_name(klass, "set_fallbackFontAssetTable", 1);
            get_creationSettings = il2cpp_functions::class_get_method_from_name(klass, "get_creationSettings", 0);
            set_creationSettings = il2cpp_functions::class_get_method_from_name(klass, "set_creationSettings", 1);
            get_fontWeightTable = il2cpp_functions::class_get_method_from_name(klass, "get_fontWeightTable", 0);
            set_fontWeightTable = il2cpp_functions::class_get_method_from_name(klass, "set_fontWeightTable", 1);
            CreateFontAsset_Font = il2cpp_functions::class_get_method_from_name(klass, "CreateFontAsset", 1);
            CreateFontAsset_Font_int_int_GlyphRenderMode_int_int_optional_AtlasPopulationMode = il2cpp_functions::class_get_method_from_name(klass, "CreateFontAsset", 8);
            Awake = il2cpp_functions::class_get_method_from_name(klass, "Awake", 0);
            InitializeDictionaryLookupTables = il2cpp_functions::class_get_method_from_name(klass, "InitializeDictionaryLookupTables", 0);
            ReadFontAssetDefinition = il2cpp_functions::class_get_method_from_name(klass, "ReadFontAssetDefinition", 0);
            SortCharacterTable = il2cpp_functions::class_get_method_from_name(klass, "SortCharacterTable", 0);
            SortGlyphTable = il2cpp_functions::class_get_method_from_name(klass, "SortGlyphTable", 0);
            SortGlyphAndCharacterTables = il2cpp_functions::class_get_method_from_name(klass, "SortGlyphAndCharacterTables", 0);
            HasCharacter_int = il2cpp_functions::class_get_method_from_name(klass, "HasCharacter", 1);
            HasCharacter_char = il2cpp_functions::class_get_method_from_name(klass, "HasCharacter", 1);
            HasCharacter_char_bool = il2cpp_functions::class_get_method_from_name(klass, "HasCharacter", 2);
            HasCharacter_Internal_char_bool = il2cpp_functions::class_get_method_from_name(klass, "HasCharacter_Internal", 2);
            HasCharacters_string_out_List1 = il2cpp_functions::class_get_method_from_name(klass, "HasCharacters", 2);
            HasCharacters_string = il2cpp_functions::class_get_method_from_name(klass, "HasCharacters", 1);
            GetCharacters_TMP_FontAsset = il2cpp_functions::class_get_method_from_name(klass, "GetCharacters", 1);
            GetCharactersArray_TMP_FontAsset = il2cpp_functions::class_get_method_from_name(klass, "GetCharactersArray", 1);
            TryAddCharacters_uint_arr = il2cpp_functions::class_get_method_from_name(klass, "TryAddCharacters", 1);
            TryAddCharacters_uint_arr_out_uint_arr = il2cpp_functions::class_get_method_from_name(klass, "TryAddCharacters", 2);
            TryAddCharacters_string = il2cpp_functions::class_get_method_from_name(klass, "TryAddCharacters", 1);
            TryAddCharacters_string_out_string = il2cpp_functions::class_get_method_from_name(klass, "TryAddCharacters", 2);
            TryAddCharacter_Internal_uint = il2cpp_functions::class_get_method_from_name(klass, "TryAddCharacter_Internal", 1);
            AddCharacter_Internal_uint_Glyph = il2cpp_functions::class_get_method_from_name(klass, "AddCharacter_Internal", 2);
            TryAddCharacterInternal_uint_out_TMP_Character = il2cpp_functions::class_get_method_from_name(klass, "TryAddCharacterInternal", 2);
            GetGlyphIndex_uint = il2cpp_functions::class_get_method_from_name(klass, "GetGlyphIndex", 1);
            UpdateAtlasTexture = il2cpp_functions::class_get_method_from_name(klass, "UpdateAtlasTexture", 0);
            UpdateGlyphAdjustmentRecords_uint_uint = il2cpp_functions::class_get_method_from_name(klass, "UpdateGlyphAdjustmentRecords", 2);
            ClearFontAssetData_optional_bool = il2cpp_functions::class_get_method_from_name(klass, "ClearFontAssetData", 2);
            UpgradeFontAsset = il2cpp_functions::class_get_method_from_name(klass, "UpgradeFontAsset", 0);
            UpgradeGlyphAdjustmentTableToFontFeatureTable = il2cpp_functions::class_get_method_from_name(klass, "UpgradeGlyphAdjustmentTableToFontFeatureTable", 0);
            __cached = true;
        }
    }
}
#endif /* TMPro_TMP_FontAsset_DEFINED */