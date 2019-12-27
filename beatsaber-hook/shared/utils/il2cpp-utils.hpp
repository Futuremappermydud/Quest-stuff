#ifndef IL2CPP_UTILS_H
#define IL2CPP_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string>
#include <string_view>
#include <unordered_map>
#include <sstream>
#include "typedefs.h"
#include "il2cpp-functions.hpp"
#include "utils-functions.h"
#include "logging.h"

// function_ptr_t courtesy of DaNike
template<typename TRet, typename ...TArgs>
// A generic function pointer, which can be called with and set to a `getRealOffset` call
using function_ptr_t = TRet(*)(TArgs...);

namespace il2cpp_utils {
    namespace array_utils {
        static char* il2cpp_array_addr_with_size(Il2CppArray *array, int32_t size, uintptr_t idx)
        {
            return ((char*)array) + kIl2CppSizeOfArray + size * idx;
        }
        #define load_array_elema(arr, idx, size) ((((uint8_t*)(arr)) + kIl2CppSizeOfArray) + ((size) * (idx)))

        #define il2cpp_array_setwithsize(array, elementSize, index, value)  \
            do {    \
                void*__p = (void*) il2cpp_utils::array_utils::il2cpp_array_addr_with_size ((array), elementSize, (index)); \
                memcpy(__p, &(value), elementSize); \
            } while (0)
        #define il2cpp_array_setrefwithsize(array, elementSize, index, value)  \
            do {    \
                void*__p = (void*) il2cpp_utils::array_utils::il2cpp_array_addr_with_size ((array), elementSize, (index)); \
                memcpy(__p, value, elementSize); \
                } while (0)
        #define il2cpp_array_addr(array, type, index) ((type*)(void*) il2cpp_utils::array_utils::il2cpp_array_addr_with_size (array, sizeof (type), index))
        #define il2cpp_array_get(array, type, index) ( *(type*)il2cpp_array_addr ((array), type, (index)) )
        #define il2cpp_array_set(array, type, index, value)    \
            do {    \
                type *__p = (type *) il2cpp_array_addr ((array), type, (index));    \
                *__p = (value); \
            } while (0)
        #define il2cpp_array_setref(array, index, value)  \
            do {    \
                void* *__p = (void* *) il2cpp_array_addr ((array), void*, (index)); \
                /* il2cpp_gc_wbarrier_set_arrayref ((array), __p, (MonoObject*)(value));    */\
                *__p = (value);    \
            } while (0)
    }
    // Init all of the usable il2cpp API, if it has yet to be initialized
    // Maximum length of characters of an exception message - 1
    #define EXCEPTION_MESSAGE_SIZE 4096
    // Returns a legible string from an Il2CppException*
    std::string ExceptionToString(Il2CppException* exp);

    // Returns the first matching class from the given namespace and typeName by searching through all assemblies that are loaded.
    Il2CppClass* GetClassFromName(const char* name_space, const char* type_name);

    // Framework provided by DaNike
    namespace il2cpp_type_check {
        template<typename T>
        struct il2cpp_arg_type_ {};

        template<typename T>
        using il2cpp_arg_type = il2cpp_arg_type_<std::decay_t<T>>;

        template<typename T>
        struct il2cpp_arg_type_<T*> { // we assume that pointers are already objects to get the type of
            static inline Il2CppType const* get(T const* arg) {
                return il2cpp_functions::class_get_type(
                    il2cpp_functions::object_get_class(reinterpret_cast<Il2CppObject*>(arg)));
            }
        };

        template<>
        struct il2cpp_arg_type_<int8_t> {
            static inline Il2CppType const* get(int8_t) {
                // return System.SByte
                return il2cpp_functions::class_get_type(il2cpp_utils::GetClassFromName("System", "SByte"));
            }
        };

        template<>
        struct il2cpp_arg_type_<uint8_t> {
            static inline Il2CppType const* get(uint8_t) {
                // return System.Byte
                return il2cpp_functions::class_get_type(il2cpp_utils::GetClassFromName("System", "SByte"));
            }
        };

        template<>
        struct il2cpp_arg_type_<float> {
            static inline Il2CppType const* get(float) {
                // return System.Single
                return il2cpp_functions::class_get_type(il2cpp_utils::GetClassFromName("System", "Single"));
            }
        };

        template<>
        struct il2cpp_arg_type_<double> {
            static inline Il2CppType const* get(double) {
                // return System.Double
                return il2cpp_functions::class_get_type(il2cpp_utils::GetClassFromName("System", "Double"));
            }
        };

        template<>
        struct il2cpp_arg_type_<int16_t> {
            static inline Il2CppType const* get(int16_t) {
                // return System.Int16
                return il2cpp_functions::class_get_type(il2cpp_utils::GetClassFromName("System", "Int16"));
            }
        };

        template<>
        struct il2cpp_arg_type_<int> {
            static inline Il2CppType const* get(int) {
                // return System.Int32
                return il2cpp_functions::class_get_type(il2cpp_utils::GetClassFromName("System", "Int32"));
            }
        };

        template<>
        struct il2cpp_arg_type_<int64_t> {
            static inline Il2CppType const* get(int64_t) {
                // return System.Int64
                return il2cpp_functions::class_get_type(il2cpp_utils::GetClassFromName("System", "Int64"));
            }
        };

        // TODO Add more types

        template<typename T>
        struct il2cpp_arg_ptr {
            static inline void* get(T const& arg) {
                return reinterpret_cast<void*>(&arg);
            }
        };
        template<typename T>
        struct il2cpp_arg_ptr<T*> {
            static inline void* get(T* arg) {
                return reinterpret_cast<void*>(arg);
            }
        };
    }

    template<typename... TArgs>
    // Returns if a given MethodInfo's parameters match the Il2CppTypes provided as args
    bool ParameterMatch(const MethodInfo* method, TArgs* ...args) {
        il2cpp_functions::Init();

        constexpr auto count = sizeof...(TArgs);
        Il2CppType* argarr[] = {reinterpret_cast<Il2CppType*>(args)...};
        if (method->parameters_count != count) {
            return false;
        }
        for (int i = 0; i < method->parameters_count; i++) {
            if (!il2cpp_functions::type_equals(method->parameters[i].parameter_type, argarr[i])) {
                return false;
            }
        }
        return true;
    }

    // Returns if a given MethodInfo's parameters match the Il2CppType array provided as type_arr
    bool ParameterMatch(const MethodInfo* method, Il2CppType** type_arr, int count);

    template<typename TObj = Il2CppObject, typename... TArgs>
    // Creates a new object of the given class and Il2CppTypes parameters and casts it to TObj*
    TObj* New(Il2CppClass* klass, TArgs const& ...args) {
        il2cpp_functions::Init();

        constexpr auto count = sizeof...(TArgs);

        void* invokeParams[] = { il2cpp_type_check::il2cpp_arg_ptr<decltype(args)>::get(args)... };
        Il2CppType const* argarr[] = { il2cpp_type_check::il2cpp_arg_type<decltype(args)>::get(args)... };
        // object_new call
        auto obj = il2cpp_functions::object_new(klass);
        // runtime_invoke constructor with right number of args, return null if multiple matches (or take a vector of type pointers to resolve it), return null if constructor errors
        
        void* myIter = nullptr;
        const MethodInfo* current;
        const MethodInfo* ctor = nullptr;
        // Il2CppType* argarr[] = {reinterpret_cast<Il2CppType*>(args)...};
        while ((current = il2cpp_functions::class_get_methods(klass, &myIter))) {
            if (ParameterMatch(current, argarr, count) && strcmp(ctor->name, ".ctor") == 0) {
                ctor = current;
            }
        }
        if (!ctor) {
            log(ERROR, "il2cpp_utils: New: Could not find constructor for provided class!");
            return nullptr;
        }
        // TODO FIX CTOR CHECKING
        if (strcmp(ctor->name, ".ctor") != 0) {
            log(ERROR, "il2cpp_utils: New: Found a method matching parameter count and types, but it is not a constructor!");
            return nullptr;
        }
        Il2CppException* exp = nullptr;
        il2cpp_functions::runtime_invoke(ctor, obj, invokeParams, &exp);
        if (exp) {
            log(ERROR, "il2cpp_utils: New: Failed with exception: %s", ExceptionToString(exp).c_str());
            return nullptr;
        }
        return reinterpret_cast<TObj*>(obj);
    }

    template<typename TObj = Il2CppObject, typename... TArgs>
    // Creates a New object of the given class and parameters and casts it to TObj*
    // DOES NOT PERFORM TYPE-SAFE CHECKING!
    TObj* NewUnsafe(Il2CppClass* klass, TArgs* ...args) {
        il2cpp_functions::Init();

        void* invokeParams[] = {reinterpret_cast<void*>(args)...};
        // object_new call
        auto obj = il2cpp_functions::object_new(klass);
        // runtime_invoke constructor with right number of args, return null if constructor errors
        constexpr auto count = sizeof...(TArgs);
        log(DEBUG, "Attempting to find .ctor with paramCount: %lu for class name: %s", count, il2cpp_functions::class_get_name(klass));
        const MethodInfo* ctor = il2cpp_functions::class_get_method_from_name(klass, ".ctor", count);

        if (!ctor) {
            log(ERROR, "il2cpp_utils: New: Could not find constructor for provided class!");
            return nullptr;
        }
        Il2CppException* exp;
        il2cpp_functions::runtime_invoke(ctor, obj, invokeParams, &exp);
        if (exp) {
            log(ERROR, "il2cpp_utils: New: Failed with exception: %s", ExceptionToString(exp).c_str());
            return nullptr;
        }
        return reinterpret_cast<TObj*>(obj);
    }

    // Returns the MethodInfo for the method on the given class with the given name and number of arguments
    // TODO: HASH MAP KNOWN FUNCTIONS
    // Created by zoller27osu
    const MethodInfo* GetMethod(Il2CppClass* klass, std::string_view methodName, int argsCount);

    // Returns the MethodInfo for the method on class found via namespace and name with the given name and number of arguments
    const MethodInfo* GetMethod(std::string_view nameSpace, std::string_view className, std::string_view methodName, int argsCount);

    // Returns the MethodInfo for the method on the given instance
    const MethodInfo* GetMethod(Il2CppObject* instance, std::string_view methodName, int argsCount);

    template<class TOut, class... TArgs>
    // Runs a MethodInfo with the specified parameters and instance, with return type TOut
    // Assumes a static method if instance == nullptr
    // Returns false if it fails
    // Created by zoller27osu, modified by Sc2ad
    bool RunMethod(TOut* out, void* instance, const MethodInfo* method, TArgs* ...params) {
        il2cpp_functions::Init();
        if (!method) {
            log(ERROR, "il2cpp_utils: RunMethod: Null MethodInfo!");
            return false;
        }
        Il2CppException* exp = nullptr;
        void* invokeParams[] = {reinterpret_cast<void*>(params)...};
        auto ret = il2cpp_functions::runtime_invoke(method, instance, invokeParams, &exp);
        if constexpr (std::is_pointer<TOut>::value) {
            *out = reinterpret_cast<TOut>(ret);
        } else {
            *out = *reinterpret_cast<TOut*>(il2cpp_functions::object_unbox(ret));
        }

        if (exp) {
            log(ERROR, "il2cpp_utils: RunMethod: %s: Failed with exception: %s", il2cpp_functions::method_get_name(method),
                il2cpp_utils::ExceptionToString(exp).c_str());
            return false;
        }
        return true;
    }

    template<class... TArgs>
    // Runs a MethodInfo with the specified parameters and instance; best for void return type
    // Assumes a static method if instance == nullptr
    // Returns false if it fails
    // Created by zoller27osu
    bool RunMethod(void* instance, const MethodInfo* method, TArgs* ...params) {
        void* out = nullptr;
        return RunMethod(&out, instance, method, params...);
    }

    template<class TOut, class... TArgs>
    // Runs a static method with the specified method name, with return type TOut
    // Returns false if it fails
    // Created by zoller27osu, modified by Sc2ad
    bool RunMethod(TOut* out, Il2CppClass* klass, std::string_view methodName, TArgs* ...params) {
        il2cpp_functions::Init();
        if (!klass) {
            log(ERROR, "il2cpp_utils: RunMethod: Null klass parameter!");
            return false;
        }
        auto method = GetMethod(klass, methodName, sizeof...(TArgs));
        if (!method) return false;
        return RunMethod(out, nullptr, method, params...);
    }

    template<class TOut, class... TArgs>
    // Runs a method with the specified method name, with return type TOut
    // Returns false if it fails
    // Created by zoller27osu, modified by Sc2ad
    bool RunMethod(TOut* out, Il2CppObject* instance, std::string_view methodName, TArgs* ...params) {
        il2cpp_functions::Init();
        if (!instance) {
            log(ERROR, "il2cpp_utils: RunMethod: Null instance parameter!");
            return false;
        }
        auto klass = il2cpp_functions::object_get_class(instance);
        if (!klass) {
            log(ERROR, "il2cpp_utils: RunMethod: Could not get the object's class!");
            return false;
        }
        auto method = GetMethod(klass, methodName, sizeof...(TArgs));
        if (!method) return false;
        return RunMethod(out, instance, method, params...);
    }

    template<class... TArgs>
    // Runs a static method with the specified method name; best for void return type
    // Returns false if it fails
    // Created by zoller27osu
    bool RunMethod(Il2CppClass* klass, std::string_view methodName, TArgs* ...params) {
        void* out = nullptr;
        return RunMethod(&out, klass, methodName, params...);
    }

    template<class... TArgs>
    // Runs a method with the specified method name; best for void return type
    // Returns false if it fails
    // Created by zoller27osu
    bool RunMethod(Il2CppObject* instance, std::string_view methodName, TArgs* ...params) {
        void* out = nullptr;
        return RunMethod(&out, instance, methodName, params...);
    }

    // Returns the FieldInfo for the field of the given class with the given name
    // Created by zoller27osu
    FieldInfo* FindField(Il2CppClass* klass, std::string_view fieldName);

    // Gets an Il2cppObject* from the given object instance and FieldInfo
    // instance can only be null for static fields
    // Returns nullptr if it fails
    Il2CppObject* GetFieldValue(Il2CppObject* instance, FieldInfo* field);

    // Gets an Il2CppObject* from the given class and field name
    // Returns nullptr if it fails
    // Created by zoller27
    Il2CppObject* GetFieldValue(Il2CppClass* klass, std::string_view fieldName);

    // Gets an Il2CppObject* from the given object instance and field name
    // Returns nullptr if it fails
    // Created by darknight1050, modified by Sc2ad
    Il2CppObject* GetFieldValue(Il2CppObject* instance, std::string_view fieldName);

    // Wrapper around the non-template GetFieldValue's that casts the result for you
    template<class TOut, class... TArgs>
    TOut* GetFieldValue(TArgs... params) {
        static_assert(sizeof...(TArgs) == 2);
        static_assert(std::is_base_of<Il2CppObject, TOut>::value, "The return type of this function must inherit Il2CppObject! See GetFieldValueUnsafe for an alternative.");
        return reinterpret_cast<TOut*>(GetFieldValue(params...));
    }

    template<typename TOut>
    // Gets a value from the given object instance, and FieldInfo, with return type TOut
    // Returns false if it fails
    // Assumes a static field if instance == nullptr
    // Created by darknight1050, modified by Sc2ad and zoller27osu
    bool GetFieldValue(TOut* out, Il2CppObject* instance, FieldInfo* field) {
        il2cpp_functions::Init();
        if (!field) {
            log(ERROR, "il2cpp_utils: GetFieldValue: Null FieldInfo!");
            return false;
        }
        if (instance) {
            il2cpp_functions::field_get_value(instance, field, (void*)out);
        } else { // Fallback to perform a static field set
            il2cpp_functions::field_static_get_value(field, (void*)out);
        }
		return true;
    }

    template<typename TOut>
    // Gets the value of the field with type TOut and the given name from the given class 
    // Returns false if it fails
    // Adapted by zoller27osu
    bool GetFieldValue(TOut* out, Il2CppClass* klass, std::string_view fieldName) {
        il2cpp_functions::Init();
        if (!klass) {
            log(ERROR, "il2cpp_utils: GetFieldValue: Could not find object class!");
            return false;
        }
        auto field = FindField(klass, fieldName);
        if (!field) return false;
        return GetFieldValue(out, nullptr, field);
    }

    template<typename TOut>
    // Gets a value from the given object instance and field name, with return type TOut
    // Returns false if it fails
    // Created by darknight1050, modified by Sc2ad and zoller27osu
    bool GetFieldValue(TOut* out, Il2CppObject* instance, std::string_view fieldName) {
        il2cpp_functions::Init();
        if (!instance) {
            log(ERROR, "il2cpp_utils: GetFieldValue: Null instance parameter!");
            return false;
        }
        auto klass = il2cpp_functions::object_get_class(instance);
        if (!klass) {
            log(ERROR, "il2cpp_utils: GetFieldValue: Could not find object class!");
            return false;
        }
        auto field = FindField(klass, fieldName);
        if (!field) return false;
        return GetFieldValue(out, instance, field);
    }

    // An unsafe wrapper around the TOut GetFieldValues; il2cpp should unbox when appropriate
    template<class TOut, class... TArgs>
    TOut GetFieldValueUnsafe(TArgs... params) {
        static_assert(sizeof...(TArgs) == 2);
        TOut out;
        GetFieldValue(&out, params...);
        return out;
    }

    // Sets the value of a given field, given an object instance and FieldInfo
    // Unbox "value" before passing if it is an Il2CppObject but the field is a primitive or struct!
    // Returns false if it fails
    // Assumes static field if instance == nullptr
    bool SetFieldValue(Il2CppObject* instance, FieldInfo* field, void* value);

    // Sets the value of a given field, given an object instance and field name
    // Unbox "value" before passing if it is an Il2CppObject but the field is a primitive or struct!
    // Returns false if it fails
    // Adapted by zoller27osu
    bool SetFieldValue(Il2CppClass* klass, std::string_view fieldName, void* value);

    // Sets the value of a given field, given an object instance and field name
    // Unbox "value" before passing if it is an Il2CppObject but the field is a primitive or struct!
    // Returns false if it fails
    bool SetFieldValue(Il2CppObject* instance, std::string_view fieldName, void* value);

    template<typename T = MulticastDelegate, typename R, typename... TArgs>
    // Creates an Action and casts it to a MulticastDelegate*
    // Created by zoller27osu
    T* MakeAction(Il2CppObject* obj, function_ptr_t<R, TArgs...> callback, const Il2CppType* actionType) {
        Il2CppClass* actionClass = il2cpp_functions::class_from_il2cpp_type(actionType);

        /* 
        * TODO: call PlatformInvoke::MarshalFunctionPointerToDelegate directly instead of copying code from it,
        * or at least use a cache like utils::NativeDelegateMethodCache::GetNativeDelegate(nativeFunctionPointer);
        */
        const MethodInfo* invoke = il2cpp_functions::class_get_method_from_name(actionClass, "Invoke", -1);  // well-formed Actions have only 1 invoke method
        MethodInfo* method = (MethodInfo*) calloc(1, sizeof(MethodInfo));
        method->methodPointer = (Il2CppMethodPointer)callback;
        method->invoker_method = NULL;
        method->parameters_count = invoke->parameters_count;
        method->slot = kInvalidIl2CppMethodSlot;
        method->is_marshaled_from_native = true;  // "a fake MethodInfo wrapping a native function pointer"
        // In the event that a function is static, this will behave as normal
        if (obj == nullptr) method->flags |= METHOD_ATTRIBUTE_STATIC;

        // TODO: figure out why passing method directly doesn't work
        auto action = il2cpp_utils::NewUnsafe<T>(actionClass, obj, &method);
        auto asDelegate = reinterpret_cast<Delegate*>(action);
        if (asDelegate->method_ptr != (void*)callback) {
            log(ERROR, "Created Action's method_ptr (%p) is incorrect (should be %p)!", asDelegate->method_ptr, callback);
            return nullptr;
        }
        return action;
    }

    template<typename T = MulticastDelegate>
    T* MakeAction(Il2CppObject* obj, void* callback, const Il2CppType* actionType) {
        auto tmp = reinterpret_cast<function_ptr_t<void>>(callback);
        return MakeAction(obj, tmp, actionType);
    }

    // Calls the System.RuntimeType.MakeGenericType(System.Type gt, System.Type[] types) function
    Il2CppReflectionType* MakeGenericType(Il2CppReflectionType* gt, Il2CppArray* types);

    // Function made by zoller27osu, modified by Sc2ad
    Il2CppClass* MakeGeneric(const Il2CppClass* klass, std::initializer_list<const Il2CppClass*> args);
 
    // Gets a C# name of a type
    const char* TypeGetSimpleName(const Il2CppType* type);
    
    // Function made by zoller27osu, modified by Sc2ad
    // Logs information about the given MethodInfo* as log(DEBUG)
    void LogMethod(const MethodInfo* method);

    // Created by zoller27osu
    // Logs information about the given FieldInfo* as log(DEBUG)
    void LogField(FieldInfo* field);

    // Some parts provided by zoller27osu
    // Logs information about the given Il2CppClass* as log(DEBUG)
    void LogClass(const Il2CppClass* klass, bool logParents = true);

    // Get function at 0x84fff0 (v1.5.0)
    // This is the `MetadataCache::GetExportedTypeFromIndex` method which returns a `TypeDefinitionIndex`
    #define MetadataCache_GetExportedTypeFromIndex (void*)0x84FFF0
    
    // Get function: at 0x84fba4 (v1.5.0)
    // This is the `MetadataCache::GetTypeInfoFromTypeDefinitionIndex` method which returns an `Il2CppClass*`
    #define MetadataCache_GetTypeInfoFromTypeDefinitionIndex (void*)0x84FBA4

    // Get function: at 0x84ffbc (v1.5.0)
    // This is the `MetaDataCache::GetTypeFromIndex` method which returns an `const Il2CppTypeDefinition*`
    #define MetadataCache_GetTypeFromIndex (void*)0x84FFBC

    // Get function: 0x84e5e8 at (v1.5.0)
    // This is the `MetadataCache::GetStringFromIndex` method which returns a `const char*`
    #define MetadataCache_GetStringFromIndex (void*)0x84E5E8

    // Get function: 0x8500bc at (v1.5.0)
    // This is the `MetadataCache::GetNestedTypeFromIndex` method which returns an `Il2CppClass*`
    #define MetadataCache_GetNestedTypeFromIndex (void*)0x8500BC

    // Get function: 0x8504bc at (v1.5.0)
    // This is the `MetadataCache::GetIndexForTypeDefinition` method which returns a `TypeDefinitionIndex`
    #define MetadataCache_GetIndexForTypeDefinition (void*)0x8504BC

    // Logs all classes (from every namespace) that start with the given prefix
    // WARNING: THIS FUNCTION IS VERY SLOW. ONLY USE THIS FUNCTION ONCE AND WITH A FAIRLY SPECIFIC PREFIX!
    // THIS FUNCTION IS ALSO VERSION VOLATILE, SINCE IT USES A HARDCODED OFFSET!
    void LogClasses(std::string_view classPrefix);

    // Adds the given TypeDefinitionIndex to the class hash table of a given image
    // Mainly used in LogClasses
    // THIS FUNCTION IS VERSION VOLATILE, SINCE IT USES A HARDCODED OFFSET!
    void AddTypeToNametoClassHashTable(const Il2CppImage* img, TypeDefinitionIndex index);

    // Adds the given nested types of the namespaze, parentName, and klass to the hastable
    // Mainly used in AddTypeToNametoClassHashTable
    // THIS FUNCTION IS VERSION VOLATILE, SINCE IT USES A HARDCODED OFFSET!
    void AddNestedTypesToNametoClassHashTable(Il2CppNameToTypeDefinitionIndexHashTable* hashTable, const char *namespaze, const std::string& parentName, Il2CppClass *klass);

    // Adds the given nested types of typeDefinition to the class hash table of a given image
    // Mainly used in AddTypeToNametoClassHashTable
    // THIS FUNCTION IS VERSION VOLATILE, SINCE IT USES A HARDCODED OFFSET!
    void AddNestedTypesToNametoClassHashTable(const Il2CppImage* img, const Il2CppTypeDefinition* typeDefinition);

    // Creates a cs string (allocates it) with the given string_view and returns it
    Il2CppString* createcsstr(std::string_view inp);

    // Returns if a given source object is an object of the given class
    // Created by zoller27osu
    [[nodiscard]] bool Match(const Il2CppObject* source, const Il2CppClass* klass) noexcept;

    // Asserts that a given source object is an object of the given class
    // Created by zoller27osu
    bool AssertMatch(const Il2CppObject* source, const Il2CppClass* klass);

    template<class To, class From>
    // Downcasts a class from From* to To*
    [[nodiscard]] auto down_cast(From* in) noexcept {
        static_assert(std::is_convertible<To*, From*>::value);
        return static_cast<To*>(in);
    }

    template<typename... TArgs>
    // Runtime Invoke, but with a list initializer for args
    Il2CppObject* RuntimeInvoke(const MethodInfo* method, Il2CppObject* reference, Il2CppException** exc, TArgs* ...args) {
        il2cpp_functions::Init();

        void* invokeParams[] = {reinterpret_cast<void*>(args)...};
        return il2cpp_functions::runtime_invoke(method, reference, invokeParams, exc);
    }
}
#endif /* IL2CPP_UTILS_H */
