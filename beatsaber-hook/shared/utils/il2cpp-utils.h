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
#include "il2cpp-functions.h"
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
    inline void InitFunctions() {
        if (!il2cpp_functions::initialized) {
            log(WARNING, "il2cpp_utils: IL2CPP Functions Not Initialized!");
            il2cpp_functions::Init();
        }
    }
    // Maximum length of characters of an exception message - 1
    #define EXCEPTION_MESSAGE_SIZE 4096
    // Returns a legible string from an Il2CppException*
    inline std::string ExceptionToString(Il2CppException* exp) {
        char msg[EXCEPTION_MESSAGE_SIZE];
        il2cpp_functions::format_exception(exp, msg, EXCEPTION_MESSAGE_SIZE);
        // auto exception_message = csstrtostr(exp->message);
        // return to_utf8(exception_message);
        return msg;
    }

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

    template<typename TObj = Il2CppObject, typename... TArgs>
    // Creates a new object of the given class and Il2CppTypes parameters and casts it to TObj*
    TObj* New(Il2CppClass* klass, TArgs const& ...args) {
        InitFunctions();

        constexpr auto count = sizeof...(TArgs);

        void* invoke_params[] = { il2cpp_type_check::il2cpp_arg_ptr<decltype(args)>::get(args)... };
        Il2CppType const* argarr[] = { il2cpp_type_check::il2cpp_arg_type<decltype(args)>::get(args)... };
        // object_new call
        auto obj = il2cpp_functions::object_new(klass);
        // runtime_invoke constructor with right number of args, return null if multiple matches (or take a vector of type pointers to resolve it), return null if constructor errors
        
        void* myIter = nullptr;
        const MethodInfo* current;
        const MethodInfo* ctor = nullptr;
        // Il2CppType* argarr[] = {reinterpret_cast<Il2CppType*>(args)...};
        while ((current = il2cpp_functions::class_get_methods(klass, &myIter))) {
            if (ParameterMatch(current, argarr, count)) {
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
        il2cpp_functions::runtime_invoke(ctor, obj, invoke_params, &exp);
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
        InitFunctions();

        void* invoke_params[] = {reinterpret_cast<void*>(args)...};
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
        il2cpp_functions::runtime_invoke(ctor, obj, invoke_params, &exp);
        if (exp) {
            log(ERROR, "il2cpp_utils: New: Failed with exception: %s", ExceptionToString(exp).c_str());
            return nullptr;
        }
        return reinterpret_cast<TObj*>(obj);
    }

    // TODO: add a version with a return like New instead (TObj*)
    template<class... TArgs>
    // Runs a MethodInfo method with the specified parameters, returns false if it errors
    bool RunMethod(void* instance, const MethodInfo* method, TArgs* ...params) {
        Il2CppException* exp = nullptr;
        void* invoke_params[] = {reinterpret_cast<void*>(params)...};
        il2cpp_functions::runtime_invoke(method, instance, invoke_params, &exp);
        if (exp) {
            log(ERROR, "%s: Failed with exception: %s", il2cpp_functions::method_get_name(method),
                il2cpp_utils::ExceptionToString(exp).c_str());
            return false;
        }
        return true;
    }

    template<typename T = MulticastDelegate, typename R, typename... TArgs>
    // Created by zoller27osu
    // Creates an Action and casts it to a MulticastDelegate*
    T* MakeAction(Il2CppObject* obj, function_ptr_t<R, TArgs...> callback, const Il2CppType* actionType) {
        constexpr auto count = sizeof...(TArgs);
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

    // Calls the System.RuntimeType.MakeGenericType(System.Type gt, System.Type[] types) function
    Il2CppReflectionType* MakeGenericType(Il2CppReflectionType* gt, Il2CppArray* types);

    // Function made by zoller27osu, modified by Sc2ad
    Il2CppClass* MakeGeneric(const Il2CppClass* klass, std::initializer_list<const Il2CppClass*> args);

    // Gets the type enum of a given type
    // TODO Remove this method! Replace with default typesystem
    inline int GetTypeEnum(const char* name_space, const char* type_name) {
        auto klass = GetClassFromName(name_space, type_name);
        auto typ = il2cpp_functions::class_get_type(klass);
        return il2cpp_functions::type_get_type(typ);
    }
 
    // Gets a C# name of a type
    static std::unordered_map<int, const char*> typeMap;
    inline const char* TypeGetSimpleName(const Il2CppType* type) {
        if (typeMap.empty()) {
            typeMap[GetTypeEnum("System", "Boolean")] = "bool";
            typeMap[GetTypeEnum("System", "Byte")] = "byte";
            typeMap[GetTypeEnum("System", "SByte")] = "sbyte";
            typeMap[GetTypeEnum("System", "Char")] = "char";
            typeMap[GetTypeEnum("System", "Single")] = "float";
            typeMap[GetTypeEnum("System", "Double")] = "double";
            typeMap[GetTypeEnum("System", "Int16")] = "short";
            typeMap[GetTypeEnum("System", "UInt16")] = "ushort";
            typeMap[GetTypeEnum("System", "Int32")] = "int";
            typeMap[GetTypeEnum("System", "UInt32")] = "uint";
            typeMap[GetTypeEnum("System", "Int64")] = "long";
            typeMap[GetTypeEnum("System", "UInt64")] = "ulong";
            typeMap[GetTypeEnum("System", "Object")] = "object";
            typeMap[GetTypeEnum("System", "String")] = "string";
            typeMap[GetTypeEnum("System", "Void")] = "void";
        }
        auto p = typeMap.find(il2cpp_functions::type_get_type(type));
        if (p != typeMap.end()) {
            return p->second;
        } else {
            return il2cpp_functions::type_get_name(type);
        }
    }
    
    // Function made by zoller27osu, modified by Sc2ad
    // Logs information about the given MethodInfo* as log(DEBUG)
    inline void LogMethod(const MethodInfo* method) {
        InitFunctions();
 
        auto flags = il2cpp_functions::method_get_flags(method, nullptr);
        std::stringstream flagStream;
        if (flags & METHOD_ATTRIBUTE_STATIC) flagStream << "static ";
        if (flags & METHOD_ATTRIBUTE_VIRTUAL) flagStream << "virtual ";
        if (flags & METHOD_ATTRIBUTE_ABSTRACT) flagStream << "abstract ";
        const auto& flagStrRef = flagStream.str();  
        const char* flagStr = flagStrRef.c_str();
        auto retType = il2cpp_functions::method_get_return_type(method);
        auto retTypeStr = TypeGetSimpleName(retType);
        auto methodName = il2cpp_functions::method_get_name(method);
        std::stringstream paramStream;
        for (int i = 0; i < il2cpp_functions::method_get_param_count(method); i++) {
            if (i > 0) paramStream << ", ";
            auto paramType = il2cpp_functions::method_get_param(method, i);
            if (il2cpp_functions::type_is_byref(paramType)) {
                paramStream << "out/ref ";
            }
            paramStream << TypeGetSimpleName(paramType) << " ";
            paramStream << il2cpp_functions::method_get_param_name(method, i);
        }
        const auto& paramStrRef = paramStream.str();
        const char* paramStr = paramStrRef.c_str();
        log(DEBUG, "%s%s %s(%s);", flagStr, retTypeStr, methodName, paramStr);
    }

    // Created by zoller27osu
    // Logs information about the given FieldInfo* as log(DEBUG)
    inline void LogField(FieldInfo* field) {
        InitFunctions();

        auto flags = il2cpp_functions::field_get_flags(field);
        const char* flagStr = (flags & FIELD_ATTRIBUTE_STATIC) ? "static " : "";
        auto type = il2cpp_functions::field_get_type(field);
        auto typeStr = TypeGetSimpleName(type);
        auto name = il2cpp_functions::field_get_name(field);
        auto offset = il2cpp_functions::field_get_offset(field);

        log(DEBUG, "%s%s %s; // 0x%lx, flags: 0x%.4X", flagStr, typeStr, name, offset, flags);
    }

    // Some parts provided by zoller27osu
    // Logs information about the given Il2CppClass* as log(DEBUG)
    inline void LogClass(const Il2CppClass* klass, bool logParents = true) {
        InitFunctions();

        auto unconst = const_cast<Il2CppClass*>(klass);
        log(DEBUG, "======================CLASS INFO FOR CLASS: %s::%s======================", il2cpp_functions::class_get_namespace(unconst), il2cpp_functions::class_get_name(unconst));
        log(DEBUG, "Assembly Name: %s", il2cpp_functions::class_get_assemblyname(klass));
        log(DEBUG, "Rank: %i", il2cpp_functions::class_get_rank(klass));
        log(DEBUG, "Type Token: %i", il2cpp_functions::class_get_type_token(unconst));
        log(DEBUG, "Flags: 0x%.8X", il2cpp_functions::class_get_flags(klass));
        log(DEBUG, "Event Count: %i", klass->event_count);
        log(DEBUG, "Field Count: %i", klass->field_count);
        log(DEBUG, "Method Count: %i", klass->method_count);
        log(DEBUG, "Property Count: %i", klass->property_count);
        log(DEBUG, "Is Generic: %i", il2cpp_functions::class_is_generic(klass));
        log(DEBUG, "Is Abstract: %i", il2cpp_functions::class_is_abstract(klass));
        log(DEBUG, "=========METHODS=========");
        void* myIter = nullptr;
        // const MethodInfo* current;
        // int i = 0;
        // while ((current = il2cpp_functions::class_get_methods(unconst, &myIter))) {
        //     log(DEBUG, "Method %i:", i);
        //     if (!current) {
        //         log(DEBUG, "Null MethodInfo found!");
        //         continue;
        //     }
        //     log(DEBUG, "Name: %s Params: %i", current->name, current->parameters_count);
        //     // LogMethod(current);
        //     i++;
        // }
        for (int i = 0; i < unconst->method_count; i++) {
            if (unconst->methods[i]) {
                log(DEBUG, "Method %i:", i);
                log(DEBUG, "Name: %s Params: %i", unconst->methods[i]->name, unconst->methods[i]->parameters_count);
            } else {
                log(DEBUG, "Method: %i Does not exist!", i);
            }
        }
        auto genClass = klass->generic_class;
        if (genClass) {
            auto genContext = &genClass->context;
            auto genInst = genContext->class_inst;
            if (genInst) {
                for (int i = 0; i < genInst->type_argc; i++) {
                    auto typ = genInst->type_argv[i];
                    log(DEBUG, "  generic type %i: %s", i + 1, TypeGetSimpleName(typ));
                }
            }
        }
        auto declaring = il2cpp_functions::class_get_declaring_type(unconst);
        log(DEBUG, "declaring type: %p", declaring);
        if (declaring) LogClass(declaring);
        auto element = il2cpp_functions::class_get_element_class(unconst);
        log(DEBUG, "element class: %p (self = %p)", element, klass);
        if (element && element != klass) LogClass(element);

        log(DEBUG, "=========FIELDS=========");
        myIter = nullptr;
        FieldInfo* field;
        while ((field = il2cpp_functions::class_get_fields(unconst, &myIter))) {
            LogField(field);
        }
        log(DEBUG, "=========END FIELDS=========");

        auto parent = il2cpp_functions::class_get_parent(unconst);
        log(DEBUG, "parent: %p", parent);
        if (parent && logParents) LogClass(parent);
        log(DEBUG, "==================================================================================");
    }

    // Creates a cs string (allocates it) with the given string_view and returns it
    inline Il2CppString* createcsstr(std::string_view inp) {
        InitFunctions();
        return il2cpp_functions::string_new_len(inp.data(), (uint32_t)inp.length());
    }

    // Returns if a given source object is an object of the given class
    [[nodiscard]] inline bool Match(const Il2CppObject* source, const Il2CppClass* klass) noexcept {
        return (source->klass == klass);
    }

    // Asserts that a given source object is an object of the given class
    inline bool AssertMatch(const Il2CppObject* source, const Il2CppClass* klass) {
        InitFunctions();
        if (!Match(source, klass)) {
            log(CRITICAL, "il2cpp_utils: AssertMatch: Unhandled subtype: namespace %s, class %s", 
                il2cpp_functions::class_get_namespace(source->klass), il2cpp_functions::class_get_name(source->klass));
            std::terminate();
        }
        return true;
    }

    template<class To, class From>
    // Downcasts a class from From* to To*
    [[nodiscard]] inline auto down_cast(From* in) noexcept {
        static_assert(std::is_convertible<To*, From*>::value);
        return static_cast<To*>(in);
    }

    template<typename... TArgs>
    // Returns if a given MethodInfo's parameters match the Il2CppTypes provided as args
    inline bool ParameterMatch(const MethodInfo* method, TArgs* ...args) {
        InitFunctions();

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
    inline bool ParameterMatch(const MethodInfo* method, Il2CppType** type_arr, int count) {
        if (method->parameters_count != count) {
            return false;
        }
        for (int i = 0; i < method->parameters_count; i++) {
            if (!il2cpp_functions::type_equals(method->parameters[i].parameter_type, type_arr[i])) {
                return false;
            }
        }
        return true;
    }

    template<typename... TArgs>
    // Runtime Invoke, but with a list initializer for args
    inline Il2CppObject* RuntimeInvoke(const MethodInfo* method, Il2CppObject* reference, Il2CppException** exc, TArgs* ...args) {
        InitFunctions();


        void* invoke_params[] = {reinterpret_cast<void*>(args)...};
        return il2cpp_functions::runtime_invoke(method, reference, invoke_params, exc);
    }
}
#endif /* IL2CPP_UTILS_H */
