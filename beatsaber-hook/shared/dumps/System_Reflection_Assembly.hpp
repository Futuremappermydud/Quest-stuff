#ifndef System_Reflection_Assembly_DEFINED
#define System_Reflection_Assembly_DEFINED
// This .hpp file was compiled via beatsaber-hook/shared/helper.py's Parse Mode.
// Created by Sc2ad.
// Methods may not be valid!
#include <dlfcn.h>
#include <string_view>
#include "../utils/typedefs.h"
#include "../utils/il2cpp-functions.hpp"
#include "../utils/il2cpp-utils.hpp"
// Contains MethodInfo/Il2CppClass data for: System.Reflection.Assembly
namespace System_Reflection_Assembly {
    // System.Reflection.Assembly
    typedef struct Class {
        IntPtr _mono_assembly; // 0x10
        void* resolve_event_holder; // 0x18
        void* _evidence; // 0x20
        void* _minimum; // 0x28
        void* _optional; // 0x30
        void* _refuse; // 0x38
        void* _granted; // 0x40
        void* _denied; // 0x48
        uint8_t fromByteArray; // 0x50
        Il2CppString* assemblyName; // 0x58
    } Class;
    static bool __cached = false;
    static Il2CppClass* klass;
    static const MethodInfo* get_code_base_bool;
    static const MethodInfo* get_fullname;
    static const MethodInfo* get_location;
    static const MethodInfo* GetAotId;
    static const MethodInfo* GetCodeBase_bool;
    static const MethodInfo* get_CodeBase;
    static const MethodInfo* get_FullName;
    static const MethodInfo* get_Location;
    static const MethodInfo* GetObjectData_SerializationInfo_StreamingContext;
    static const MethodInfo* IsDefined_Type_bool;
    static const MethodInfo* GetCustomAttributes_Type_bool;
    static const MethodInfo* GetManifestResourceInternal_string_out_int_out_Module;
    static const MethodInfo* GetTypes_bool;
    static const MethodInfo* GetTypes;
    static const MethodInfo* GetType_string;
    static const MethodInfo* InternalGetType_Module_string_bool_bool;
    static const MethodInfo* GetName_bool;
    static const MethodInfo* GetName;
    static const MethodInfo* ToString;
    static const MethodInfo* GetAssembly_Type;
    static const MethodInfo* Load_string;
    static const MethodInfo* load_with_partial_name_string_Evidence;
    static const MethodInfo* LoadWithPartialName_string_Evidence;
    static const MethodInfo* LoadWithPartialName_string_Evidence_bool;
    static const MethodInfo* GetModulesInternal;
    static const MethodInfo* GetExecutingAssembly;
    static const MethodInfo* GetCallingAssembly;
    static const MethodInfo* GetHashCode;
    static const MethodInfo* Equals_object;
    static const MethodInfo* CreateNIE;
    static const MethodInfo* get_IsFullyTrusted;
    static const MethodInfo* GetType_string_bool_bool;
    static const MethodInfo* GetModule_string;
    static const MethodInfo* GetModules_bool;
    static const MethodInfo* op_Equality_Assembly_Assembly;
    static const MethodInfo* op_Inequality_Assembly_Assembly;
    // The Initialization function that must be called before using any of these definitions
    static void Init() {
        if (!__cached) {
            klass = il2cpp_utils::GetClassFromName("System.Reflection", "Assembly");
            get_code_base_bool = il2cpp_functions::class_get_method_from_name(klass, "get_code_base", 1);
            get_fullname = il2cpp_functions::class_get_method_from_name(klass, "get_fullname", 0);
            get_location = il2cpp_functions::class_get_method_from_name(klass, "get_location", 0);
            GetAotId = il2cpp_functions::class_get_method_from_name(klass, "GetAotId", 0);
            GetCodeBase_bool = il2cpp_functions::class_get_method_from_name(klass, "GetCodeBase", 1);
            get_CodeBase = il2cpp_functions::class_get_method_from_name(klass, "get_CodeBase", 0);
            get_FullName = il2cpp_functions::class_get_method_from_name(klass, "get_FullName", 0);
            get_Location = il2cpp_functions::class_get_method_from_name(klass, "get_Location", 0);
            GetObjectData_SerializationInfo_StreamingContext = il2cpp_functions::class_get_method_from_name(klass, "GetObjectData", 2);
            IsDefined_Type_bool = il2cpp_functions::class_get_method_from_name(klass, "IsDefined", 2);
            GetCustomAttributes_Type_bool = il2cpp_functions::class_get_method_from_name(klass, "GetCustomAttributes", 2);
            GetManifestResourceInternal_string_out_int_out_Module = il2cpp_functions::class_get_method_from_name(klass, "GetManifestResourceInternal", 3);
            GetTypes_bool = il2cpp_functions::class_get_method_from_name(klass, "GetTypes", 1);
            GetTypes = il2cpp_functions::class_get_method_from_name(klass, "GetTypes", 0);
            GetType_string = il2cpp_functions::class_get_method_from_name(klass, "GetType", 1);
            InternalGetType_Module_string_bool_bool = il2cpp_functions::class_get_method_from_name(klass, "InternalGetType", 4);
            GetName_bool = il2cpp_functions::class_get_method_from_name(klass, "GetName", 1);
            GetName = il2cpp_functions::class_get_method_from_name(klass, "GetName", 0);
            ToString = il2cpp_functions::class_get_method_from_name(klass, "ToString", 0);
            GetAssembly_Type = il2cpp_functions::class_get_method_from_name(klass, "GetAssembly", 1);
            Load_string = il2cpp_functions::class_get_method_from_name(klass, "Load", 1);
            load_with_partial_name_string_Evidence = il2cpp_functions::class_get_method_from_name(klass, "load_with_partial_name", 2);
            LoadWithPartialName_string_Evidence = il2cpp_functions::class_get_method_from_name(klass, "LoadWithPartialName", 2);
            LoadWithPartialName_string_Evidence_bool = il2cpp_functions::class_get_method_from_name(klass, "LoadWithPartialName", 3);
            GetModulesInternal = il2cpp_functions::class_get_method_from_name(klass, "GetModulesInternal", 0);
            GetExecutingAssembly = il2cpp_functions::class_get_method_from_name(klass, "GetExecutingAssembly", 0);
            GetCallingAssembly = il2cpp_functions::class_get_method_from_name(klass, "GetCallingAssembly", 0);
            GetHashCode = il2cpp_functions::class_get_method_from_name(klass, "GetHashCode", 0);
            Equals_object = il2cpp_functions::class_get_method_from_name(klass, "Equals", 1);
            CreateNIE = il2cpp_functions::class_get_method_from_name(klass, "CreateNIE", 0);
            get_IsFullyTrusted = il2cpp_functions::class_get_method_from_name(klass, "get_IsFullyTrusted", 0);
            GetType_string_bool_bool = il2cpp_functions::class_get_method_from_name(klass, "GetType", 3);
            GetModule_string = il2cpp_functions::class_get_method_from_name(klass, "GetModule", 1);
            GetModules_bool = il2cpp_functions::class_get_method_from_name(klass, "GetModules", 1);
            op_Equality_Assembly_Assembly = il2cpp_functions::class_get_method_from_name(klass, "op_Equality", 2);
            op_Inequality_Assembly_Assembly = il2cpp_functions::class_get_method_from_name(klass, "op_Inequality", 2);
            __cached = true;
        }
    }
}
#endif /* System_Reflection_Assembly_DEFINED */