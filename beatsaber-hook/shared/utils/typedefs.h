#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <type_traits>
#include <cassert>
// For including il2cpp properly
#ifdef _MSC_VER
#undef _MSC_VER
#endif
#ifndef __GNUC__
#define __GNUC__
#endif

#include "il2cpp-config.h"
#include "il2cpp-api-types.h"
#include "il2cpp-class-internals.h"
#include "il2cpp-object-internals.h"
#include "il2cpp-tabledefs.h"
#include "utils/Il2CppHashMap.h"
#include "utils/HashUtils.h"
#include "utils/StringUtils.h"
#include <dlfcn.h>

#ifdef __cplusplus
template<class T>
struct is_value_type : std::integral_constant< 
    bool,
    (std::is_arithmetic<T>::value || std::is_enum<T>::value ||
    std::is_pointer<T>::value) &&
    !std::is_base_of<Il2CppObject, T>::value
> {};

typedef struct ArrayBounds
{
    int32_t length;
    int32_t lower_bound;
} ArrayBounds;

template<class T>
struct Array : public Il2CppObject
{
    static_assert(is_value_type<T>::value, "T must be a C# value type! (primitive, pointer or Struct)");
    /* bounds is NULL for szarrays */
    ArrayBounds *bounds;
    /* total number of elements of the array */
    int32_t max_length;
    T values[0];

    int32_t Length() {
        if (bounds) {
            return bounds->length;
        }
        return max_length;
    }
};

struct NamespaceAndNamePairHash
{
    size_t operator()(const std::pair<const char*, const char*>& pair) const
    {
        return il2cpp::utils::HashUtils::Combine(il2cpp::utils::StringUtils::Hash(pair.first), il2cpp::utils::StringUtils::Hash(pair.second));
    }
};

struct NamespaceAndNamePairEquals
{
    bool operator()(const std::pair<const char*, const char*>& p1, const std::pair<const char*, const char*>& p2) const
    {
        return !strcmp(p1.first, p2.first) && !strcmp(p1.second, p2.second);
    }
};

struct Il2CppNameToTypeDefinitionIndexHashTable : public Il2CppHashMap<std::pair<const char*, const char*>, TypeDefinitionIndex, NamespaceAndNamePairHash, NamespaceAndNamePairEquals>
{
    typedef Il2CppHashMap<std::pair<const char*, const char*>, TypeDefinitionIndex, NamespaceAndNamePairHash, NamespaceAndNamePairEquals> Base;
    Il2CppNameToTypeDefinitionIndexHashTable() : Base()
    {
    }
};

extern "C" {
#endif /* __cplusplus */
#ifndef __cplusplus
typedef struct Il2CppObject {
    void* vtable;
    void* monitor;
} Il2CppObject;
#endif /* !__cplusplus */

// C# SPECIFIC

// System.IntPtr
typedef struct IntPtr {
    void* value;
} IntPtr;

// System.DelegateData
typedef struct DelegateData : Il2CppObject {
    Il2CppReflectionType* target_type;
    Il2CppString* method_name;
    bool curied_first_arg;
} DelegateData;

// See il2cpp-object-internals.h/Il2CppDelegate
// System.Delegate
typedef struct Delegate : Il2CppObject
{
    Il2CppMethodPointer method_ptr; // 0x8
    InvokerMethod invoke_impl; // 0xC
    Il2CppObject* m_target; // 0x10
    IntPtr* method; // 0x14
    void* delegate_trampoline; // 0x18
    intptr_t extra_arg; // 0x1C

    /*
    * If non-NULL, this points to a memory location which stores the address of
    * the compiled code of the method, or NULL if it is not yet compiled.
    */
    uint8_t** method_code; // 0x20
    Il2CppReflectionMethod* method_info; // 0x24
    Il2CppReflectionMethod* original_method_info; // 0x28
    DelegateData* data; // 0x2C
    bool method_is_virtual; // 0x30
} Delegate;

// System.MulticastDelegate
typedef struct MulticastDelegate : Delegate
{
    Array<Delegate*>* delegates;
} MulticastDelegate;

// UNITY SPECIFIC

// UnityEngine.Color
typedef struct Color {
    float r;
    float g;
    float b;
    float a;
} Color;

// UnityEngine.Vector2
typedef struct Vector2 {
    float x;
    float y;
} Vector2;

// UnityEngine.Vector3
typedef struct Vector3 {
    float x;
    float y;
    float z;
} Vector3;

// UnityEngine.Quaternion
typedef struct Quaternion {
    float x;
    float y;
    float z;
    float w;
} Quaternion;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TYPEDEFS_H */
