#ifndef System_Type_DEFINED
#define System_Type_DEFINED
// This .hpp file was compiled via beatsaber-hook/shared/helper.py's Parse Mode.
// Created by Sc2ad.
// Methods may not be valid!
#include <dlfcn.h>
#include <string_view>
#include "../utils/typedefs.h"
#include "../utils/il2cpp-functions.hpp"
#include "../utils/il2cpp-utils.hpp"
// Contains MethodInfo/Il2CppClass data for: System.Type
namespace System_Type {
    // System.Type
    typedef struct Class {
        static void* FilterAttribute; // 0x0
        static void* FilterName; // 0x8
        static void* FilterNameIgnoreCase; // 0x10
        static void* Missing; // 0x18
        static char16_t Delimiter; // 0x20
        static void* EmptyTypes; // 0x28
        static void* defaultBinder; // 0x30
        void* _impl; // 0x10
    } Class;
    static bool __cached = false;
    static Il2CppClass* klass;
    static const MethodInfo* get_MemberType;
    static const MethodInfo* get_DeclaringType;
    static const MethodInfo* get_DeclaringMethod;
    static const MethodInfo* get_ReflectedType;
    static const MethodInfo* GetType_string_Func2_Func4_bool;
    static const MethodInfo* MakePointerType;
    static const MethodInfo* MakeByRefType;
    static const MethodInfo* MakeArrayType;
    static const MethodInfo* MakeArrayType_int;
    static const MethodInfo* GetTypeCode_Type;
    static const MethodInfo* GetTypeCodeImpl;
    static const MethodInfo* get_DefaultBinder;
    static const MethodInfo* CreateBinder;
    static const MethodInfo* InvokeMember_string_BindingFlags_Binder_object_object_arr_ParameterModifier_arr_CultureInfo_string_arr;
    static const MethodInfo* get_Module;
    static const MethodInfo* get_Assembly;
    static const MethodInfo* get_TypeHandle;
    static const MethodInfo* GetTypeHandle_object;
    static const MethodInfo* get_FullName;
    static const MethodInfo* get_Namespace;
    static const MethodInfo* get_AssemblyQualifiedName;
    static const MethodInfo* GetArrayRank;
    static const MethodInfo* get_BaseType;
    static const MethodInfo* GetConstructor_BindingFlags_Binder_CallingConventions_Type_arr_ParameterModifier_arr;
    static const MethodInfo* GetConstructor_BindingFlags_Binder_Type_arr_ParameterModifier_arr;
    static const MethodInfo* GetConstructor_Type_arr;
    static const MethodInfo* GetConstructorImpl_BindingFlags_Binder_CallingConventions_Type_arr_ParameterModifier_arr;
    static const MethodInfo* GetConstructors;
    static const MethodInfo* GetConstructors_BindingFlags;
    static const MethodInfo* GetMethod_string_BindingFlags_Binder_Type_arr_ParameterModifier_arr;
    static const MethodInfo* GetMethod_string_Type_arr;
    static const MethodInfo* GetMethod_string_BindingFlags;
    static const MethodInfo* GetMethod_string;
    static const MethodInfo* GetMethodImpl_string_BindingFlags_Binder_CallingConventions_Type_arr_ParameterModifier_arr;
    static const MethodInfo* GetMethods;
    static const MethodInfo* GetMethods_BindingFlags;
    static const MethodInfo* GetField_string_BindingFlags;
    static const MethodInfo* GetField_string;
    static const MethodInfo* GetFields;
    static const MethodInfo* GetFields_BindingFlags;
    static const MethodInfo* GetInterfaces;
    static const MethodInfo* GetEvent_string_BindingFlags;
    static const MethodInfo* GetProperty_string_Type_Type_arr;
    static const MethodInfo* GetProperty_string_Type;
    static const MethodInfo* GetProperty_string;
    static const MethodInfo* GetPropertyImpl_string_BindingFlags_Binder_Type_Type_arr_ParameterModifier_arr;
    static const MethodInfo* GetProperties_BindingFlags;
    static const MethodInfo* GetNestedType_string_BindingFlags;
    static const MethodInfo* GetMember_string;
    static const MethodInfo* GetMember_string_BindingFlags;
    static const MethodInfo* GetMember_string_MemberTypes_BindingFlags;
    static const MethodInfo* get_IsNested;
    static const MethodInfo* get_Attributes;
    static const MethodInfo* get_GenericParameterAttributes;
    static const MethodInfo* get_IsNotPublic;
    static const MethodInfo* get_IsPublic;
    static const MethodInfo* get_IsNestedPublic;
    static const MethodInfo* get_IsNestedAssembly;
    static const MethodInfo* get_IsExplicitLayout;
    static const MethodInfo* get_IsClass;
    static const MethodInfo* get_IsInterface;
    static const MethodInfo* get_IsValueType;
    static const MethodInfo* get_IsAbstract;
    static const MethodInfo* get_IsSealed;
    static const MethodInfo* get_IsEnum;
    static const MethodInfo* get_IsSerializable;
    static const MethodInfo* get_IsArray;
    static const MethodInfo* get_IsSzArray;
    static const MethodInfo* get_IsGenericType;
    static const MethodInfo* get_IsGenericTypeDefinition;
    static const MethodInfo* get_IsGenericParameter;
    static const MethodInfo* get_GenericParameterPosition;
    static const MethodInfo* get_ContainsGenericParameters;
    static const MethodInfo* GetGenericParameterConstraints;
    static const MethodInfo* get_IsByRef;
    static const MethodInfo* get_IsPointer;
    static const MethodInfo* get_IsPrimitive;
    static const MethodInfo* get_IsCOMObject;
    static const MethodInfo* get_HasElementType;
    static const MethodInfo* get_IsContextful;
    static const MethodInfo* get_IsMarshalByRef;
    static const MethodInfo* IsValueTypeImpl;
    static const MethodInfo* GetAttributeFlagsImpl;
    static const MethodInfo* IsArrayImpl;
    static const MethodInfo* IsByRefImpl;
    static const MethodInfo* IsPointerImpl;
    static const MethodInfo* IsPrimitiveImpl;
    static const MethodInfo* IsCOMObjectImpl;
    static const MethodInfo* MakeGenericType_Type_arr;
    static const MethodInfo* IsContextfulImpl;
    static const MethodInfo* IsMarshalByRefImpl;
    static const MethodInfo* GetElementType;
    static const MethodInfo* GetGenericArguments;
    static const MethodInfo* GetGenericTypeDefinition;
    static const MethodInfo* HasElementTypeImpl;
    static const MethodInfo* GetRootElementType;
    static const MethodInfo* GetEnumNames;
    static const MethodInfo* GetEnumValues;
    static const MethodInfo* GetEnumRawConstantValues;
    static const MethodInfo* GetEnumData_out_string_arr_out_Array;
    static const MethodInfo* GetEnumUnderlyingType;
    static const MethodInfo* IsEnumDefined_object;
    static const MethodInfo* GetEnumName_object;
    static const MethodInfo* BinarySearch_Array_object;
    static const MethodInfo* IsIntegerType_Type;
    static const MethodInfo* get_UnderlyingSystemType;
    static const MethodInfo* IsSubclassOf_Type;
    static const MethodInfo* IsInstanceOfType_object;
    static const MethodInfo* IsAssignableFrom_Type;
    static const MethodInfo* IsEquivalentTo_Type;
    static const MethodInfo* ImplementInterface_Type;
    static const MethodInfo* FormatTypeName;
    static const MethodInfo* FormatTypeName_bool;
    static const MethodInfo* ToString;
    static const MethodInfo* Equals_object;
    static const MethodInfo* Equals_Type;
    static const MethodInfo* op_Equality_Type_Type;
    static const MethodInfo* op_Inequality_Type_Type;
    static const MethodInfo* GetHashCode;
    static const MethodInfo* GetType;
    static const MethodInfo* internal_from_name_string_bool_bool;
    static const MethodInfo* GetType_string;
    static const MethodInfo* GetType_string_bool;
    static const MethodInfo* GetType_string_bool_bool;
    static const MethodInfo* GetTypeFromHandle_RuntimeTypeHandle;
    static const MethodInfo* internal_from_handle_IntPtr;
    // The Initialization function that must be called before using any of these definitions
    static void Init() {
        if (!__cached) {
            klass = il2cpp_utils::GetClassFromName("System", "Type");
            get_MemberType = il2cpp_functions::class_get_method_from_name(klass, "get_MemberType", 0);
            get_DeclaringType = il2cpp_functions::class_get_method_from_name(klass, "get_DeclaringType", 0);
            get_DeclaringMethod = il2cpp_functions::class_get_method_from_name(klass, "get_DeclaringMethod", 0);
            get_ReflectedType = il2cpp_functions::class_get_method_from_name(klass, "get_ReflectedType", 0);
            GetType_string_Func2_Func4_bool = il2cpp_functions::class_get_method_from_name(klass, "GetType", 6);
            MakePointerType = il2cpp_functions::class_get_method_from_name(klass, "MakePointerType", 0);
            MakeByRefType = il2cpp_functions::class_get_method_from_name(klass, "MakeByRefType", 0);
            MakeArrayType = il2cpp_functions::class_get_method_from_name(klass, "MakeArrayType", 0);
            MakeArrayType_int = il2cpp_functions::class_get_method_from_name(klass, "MakeArrayType", 1);
            GetTypeCode_Type = il2cpp_functions::class_get_method_from_name(klass, "GetTypeCode", 1);
            GetTypeCodeImpl = il2cpp_functions::class_get_method_from_name(klass, "GetTypeCodeImpl", 0);
            get_DefaultBinder = il2cpp_functions::class_get_method_from_name(klass, "get_DefaultBinder", 0);
            CreateBinder = il2cpp_functions::class_get_method_from_name(klass, "CreateBinder", 0);
            InvokeMember_string_BindingFlags_Binder_object_object_arr_ParameterModifier_arr_CultureInfo_string_arr = il2cpp_functions::class_get_method_from_name(klass, "InvokeMember", 8);
            get_Module = il2cpp_functions::class_get_method_from_name(klass, "get_Module", 0);
            get_Assembly = il2cpp_functions::class_get_method_from_name(klass, "get_Assembly", 0);
            get_TypeHandle = il2cpp_functions::class_get_method_from_name(klass, "get_TypeHandle", 0);
            GetTypeHandle_object = il2cpp_functions::class_get_method_from_name(klass, "GetTypeHandle", 1);
            get_FullName = il2cpp_functions::class_get_method_from_name(klass, "get_FullName", 0);
            get_Namespace = il2cpp_functions::class_get_method_from_name(klass, "get_Namespace", 0);
            get_AssemblyQualifiedName = il2cpp_functions::class_get_method_from_name(klass, "get_AssemblyQualifiedName", 0);
            GetArrayRank = il2cpp_functions::class_get_method_from_name(klass, "GetArrayRank", 0);
            get_BaseType = il2cpp_functions::class_get_method_from_name(klass, "get_BaseType", 0);
            GetConstructor_BindingFlags_Binder_CallingConventions_Type_arr_ParameterModifier_arr = il2cpp_functions::class_get_method_from_name(klass, "GetConstructor", 5);
            GetConstructor_BindingFlags_Binder_Type_arr_ParameterModifier_arr = il2cpp_functions::class_get_method_from_name(klass, "GetConstructor", 4);
            GetConstructor_Type_arr = il2cpp_functions::class_get_method_from_name(klass, "GetConstructor", 1);
            GetConstructorImpl_BindingFlags_Binder_CallingConventions_Type_arr_ParameterModifier_arr = il2cpp_functions::class_get_method_from_name(klass, "GetConstructorImpl", 5);
            GetConstructors = il2cpp_functions::class_get_method_from_name(klass, "GetConstructors", 0);
            GetConstructors_BindingFlags = il2cpp_functions::class_get_method_from_name(klass, "GetConstructors", 1);
            GetMethod_string_BindingFlags_Binder_Type_arr_ParameterModifier_arr = il2cpp_functions::class_get_method_from_name(klass, "GetMethod", 5);
            GetMethod_string_Type_arr = il2cpp_functions::class_get_method_from_name(klass, "GetMethod", 2);
            GetMethod_string_BindingFlags = il2cpp_functions::class_get_method_from_name(klass, "GetMethod", 2);
            GetMethod_string = il2cpp_functions::class_get_method_from_name(klass, "GetMethod", 1);
            GetMethodImpl_string_BindingFlags_Binder_CallingConventions_Type_arr_ParameterModifier_arr = il2cpp_functions::class_get_method_from_name(klass, "GetMethodImpl", 6);
            GetMethods = il2cpp_functions::class_get_method_from_name(klass, "GetMethods", 0);
            GetMethods_BindingFlags = il2cpp_functions::class_get_method_from_name(klass, "GetMethods", 1);
            GetField_string_BindingFlags = il2cpp_functions::class_get_method_from_name(klass, "GetField", 2);
            GetField_string = il2cpp_functions::class_get_method_from_name(klass, "GetField", 1);
            GetFields = il2cpp_functions::class_get_method_from_name(klass, "GetFields", 0);
            GetFields_BindingFlags = il2cpp_functions::class_get_method_from_name(klass, "GetFields", 1);
            GetInterfaces = il2cpp_functions::class_get_method_from_name(klass, "GetInterfaces", 0);
            GetEvent_string_BindingFlags = il2cpp_functions::class_get_method_from_name(klass, "GetEvent", 2);
            GetProperty_string_Type_Type_arr = il2cpp_functions::class_get_method_from_name(klass, "GetProperty", 3);
            GetProperty_string_Type = il2cpp_functions::class_get_method_from_name(klass, "GetProperty", 2);
            GetProperty_string = il2cpp_functions::class_get_method_from_name(klass, "GetProperty", 1);
            GetPropertyImpl_string_BindingFlags_Binder_Type_Type_arr_ParameterModifier_arr = il2cpp_functions::class_get_method_from_name(klass, "GetPropertyImpl", 6);
            GetProperties_BindingFlags = il2cpp_functions::class_get_method_from_name(klass, "GetProperties", 1);
            GetNestedType_string_BindingFlags = il2cpp_functions::class_get_method_from_name(klass, "GetNestedType", 2);
            GetMember_string = il2cpp_functions::class_get_method_from_name(klass, "GetMember", 1);
            GetMember_string_BindingFlags = il2cpp_functions::class_get_method_from_name(klass, "GetMember", 2);
            GetMember_string_MemberTypes_BindingFlags = il2cpp_functions::class_get_method_from_name(klass, "GetMember", 3);
            get_IsNested = il2cpp_functions::class_get_method_from_name(klass, "get_IsNested", 0);
            get_Attributes = il2cpp_functions::class_get_method_from_name(klass, "get_Attributes", 0);
            get_GenericParameterAttributes = il2cpp_functions::class_get_method_from_name(klass, "get_GenericParameterAttributes", 0);
            get_IsNotPublic = il2cpp_functions::class_get_method_from_name(klass, "get_IsNotPublic", 0);
            get_IsPublic = il2cpp_functions::class_get_method_from_name(klass, "get_IsPublic", 0);
            get_IsNestedPublic = il2cpp_functions::class_get_method_from_name(klass, "get_IsNestedPublic", 0);
            get_IsNestedAssembly = il2cpp_functions::class_get_method_from_name(klass, "get_IsNestedAssembly", 0);
            get_IsExplicitLayout = il2cpp_functions::class_get_method_from_name(klass, "get_IsExplicitLayout", 0);
            get_IsClass = il2cpp_functions::class_get_method_from_name(klass, "get_IsClass", 0);
            get_IsInterface = il2cpp_functions::class_get_method_from_name(klass, "get_IsInterface", 0);
            get_IsValueType = il2cpp_functions::class_get_method_from_name(klass, "get_IsValueType", 0);
            get_IsAbstract = il2cpp_functions::class_get_method_from_name(klass, "get_IsAbstract", 0);
            get_IsSealed = il2cpp_functions::class_get_method_from_name(klass, "get_IsSealed", 0);
            get_IsEnum = il2cpp_functions::class_get_method_from_name(klass, "get_IsEnum", 0);
            get_IsSerializable = il2cpp_functions::class_get_method_from_name(klass, "get_IsSerializable", 0);
            get_IsArray = il2cpp_functions::class_get_method_from_name(klass, "get_IsArray", 0);
            get_IsSzArray = il2cpp_functions::class_get_method_from_name(klass, "get_IsSzArray", 0);
            get_IsGenericType = il2cpp_functions::class_get_method_from_name(klass, "get_IsGenericType", 0);
            get_IsGenericTypeDefinition = il2cpp_functions::class_get_method_from_name(klass, "get_IsGenericTypeDefinition", 0);
            get_IsGenericParameter = il2cpp_functions::class_get_method_from_name(klass, "get_IsGenericParameter", 0);
            get_GenericParameterPosition = il2cpp_functions::class_get_method_from_name(klass, "get_GenericParameterPosition", 0);
            get_ContainsGenericParameters = il2cpp_functions::class_get_method_from_name(klass, "get_ContainsGenericParameters", 0);
            GetGenericParameterConstraints = il2cpp_functions::class_get_method_from_name(klass, "GetGenericParameterConstraints", 0);
            get_IsByRef = il2cpp_functions::class_get_method_from_name(klass, "get_IsByRef", 0);
            get_IsPointer = il2cpp_functions::class_get_method_from_name(klass, "get_IsPointer", 0);
            get_IsPrimitive = il2cpp_functions::class_get_method_from_name(klass, "get_IsPrimitive", 0);
            get_IsCOMObject = il2cpp_functions::class_get_method_from_name(klass, "get_IsCOMObject", 0);
            get_HasElementType = il2cpp_functions::class_get_method_from_name(klass, "get_HasElementType", 0);
            get_IsContextful = il2cpp_functions::class_get_method_from_name(klass, "get_IsContextful", 0);
            get_IsMarshalByRef = il2cpp_functions::class_get_method_from_name(klass, "get_IsMarshalByRef", 0);
            IsValueTypeImpl = il2cpp_functions::class_get_method_from_name(klass, "IsValueTypeImpl", 0);
            GetAttributeFlagsImpl = il2cpp_functions::class_get_method_from_name(klass, "GetAttributeFlagsImpl", 0);
            IsArrayImpl = il2cpp_functions::class_get_method_from_name(klass, "IsArrayImpl", 0);
            IsByRefImpl = il2cpp_functions::class_get_method_from_name(klass, "IsByRefImpl", 0);
            IsPointerImpl = il2cpp_functions::class_get_method_from_name(klass, "IsPointerImpl", 0);
            IsPrimitiveImpl = il2cpp_functions::class_get_method_from_name(klass, "IsPrimitiveImpl", 0);
            IsCOMObjectImpl = il2cpp_functions::class_get_method_from_name(klass, "IsCOMObjectImpl", 0);
            MakeGenericType_Type_arr = il2cpp_functions::class_get_method_from_name(klass, "MakeGenericType", 1);
            IsContextfulImpl = il2cpp_functions::class_get_method_from_name(klass, "IsContextfulImpl", 0);
            IsMarshalByRefImpl = il2cpp_functions::class_get_method_from_name(klass, "IsMarshalByRefImpl", 0);
            GetElementType = il2cpp_functions::class_get_method_from_name(klass, "GetElementType", 0);
            GetGenericArguments = il2cpp_functions::class_get_method_from_name(klass, "GetGenericArguments", 0);
            GetGenericTypeDefinition = il2cpp_functions::class_get_method_from_name(klass, "GetGenericTypeDefinition", 0);
            HasElementTypeImpl = il2cpp_functions::class_get_method_from_name(klass, "HasElementTypeImpl", 0);
            GetRootElementType = il2cpp_functions::class_get_method_from_name(klass, "GetRootElementType", 0);
            GetEnumNames = il2cpp_functions::class_get_method_from_name(klass, "GetEnumNames", 0);
            GetEnumValues = il2cpp_functions::class_get_method_from_name(klass, "GetEnumValues", 0);
            GetEnumRawConstantValues = il2cpp_functions::class_get_method_from_name(klass, "GetEnumRawConstantValues", 0);
            GetEnumData_out_string_arr_out_Array = il2cpp_functions::class_get_method_from_name(klass, "GetEnumData", 2);
            GetEnumUnderlyingType = il2cpp_functions::class_get_method_from_name(klass, "GetEnumUnderlyingType", 0);
            IsEnumDefined_object = il2cpp_functions::class_get_method_from_name(klass, "IsEnumDefined", 1);
            GetEnumName_object = il2cpp_functions::class_get_method_from_name(klass, "GetEnumName", 1);
            BinarySearch_Array_object = il2cpp_functions::class_get_method_from_name(klass, "BinarySearch", 2);
            IsIntegerType_Type = il2cpp_functions::class_get_method_from_name(klass, "IsIntegerType", 1);
            get_UnderlyingSystemType = il2cpp_functions::class_get_method_from_name(klass, "get_UnderlyingSystemType", 0);
            IsSubclassOf_Type = il2cpp_functions::class_get_method_from_name(klass, "IsSubclassOf", 1);
            IsInstanceOfType_object = il2cpp_functions::class_get_method_from_name(klass, "IsInstanceOfType", 1);
            IsAssignableFrom_Type = il2cpp_functions::class_get_method_from_name(klass, "IsAssignableFrom", 1);
            IsEquivalentTo_Type = il2cpp_functions::class_get_method_from_name(klass, "IsEquivalentTo", 1);
            ImplementInterface_Type = il2cpp_functions::class_get_method_from_name(klass, "ImplementInterface", 1);
            FormatTypeName = il2cpp_functions::class_get_method_from_name(klass, "FormatTypeName", 0);
            FormatTypeName_bool = il2cpp_functions::class_get_method_from_name(klass, "FormatTypeName", 1);
            ToString = il2cpp_functions::class_get_method_from_name(klass, "ToString", 0);
            Equals_object = il2cpp_functions::class_get_method_from_name(klass, "Equals", 1);
            Equals_Type = il2cpp_functions::class_get_method_from_name(klass, "Equals", 1);
            op_Equality_Type_Type = il2cpp_functions::class_get_method_from_name(klass, "op_Equality", 2);
            op_Inequality_Type_Type = il2cpp_functions::class_get_method_from_name(klass, "op_Inequality", 2);
            GetHashCode = il2cpp_functions::class_get_method_from_name(klass, "GetHashCode", 0);
            GetType = il2cpp_functions::class_get_method_from_name(klass, "GetType", 0);
            internal_from_name_string_bool_bool = il2cpp_functions::class_get_method_from_name(klass, "internal_from_name", 3);
            GetType_string = il2cpp_functions::class_get_method_from_name(klass, "GetType", 1);
            GetType_string_bool = il2cpp_functions::class_get_method_from_name(klass, "GetType", 2);
            GetType_string_bool_bool = il2cpp_functions::class_get_method_from_name(klass, "GetType", 3);
            GetTypeFromHandle_RuntimeTypeHandle = il2cpp_functions::class_get_method_from_name(klass, "GetTypeFromHandle", 1);
            internal_from_handle_IntPtr = il2cpp_functions::class_get_method_from_name(klass, "internal_from_handle", 1);
            __cached = true;
        }
    }
}
#endif /* System_Type_DEFINED */