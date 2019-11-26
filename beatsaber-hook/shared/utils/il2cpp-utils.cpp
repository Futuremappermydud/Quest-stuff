#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string>
#include <string_view>
#include "il2cpp-utils.hpp"
#include "logging.h"

namespace il2cpp_utils {
    void InitFunctions() {
        if (!il2cpp_functions::initialized) {
            log(INFO, "Init: %p", il2cpp_functions::Init);
            log(WARNING, "il2cpp_utils: IL2CPP Functions Not Initialized!");
            il2cpp_functions::Init();
        } else {
            log(DEBUG, "il2cpp_utils:: IL2CPP Functions already initialized!");
        }
    }

    // Maximum length of characters of an exception message - 1
    #define EXCEPTION_MESSAGE_SIZE 4096

    // Returns a legible string from an Il2CppException*
    std::string ExceptionToString(Il2CppException* exp) {
        char msg[EXCEPTION_MESSAGE_SIZE];
        il2cpp_functions::format_exception(exp, msg, EXCEPTION_MESSAGE_SIZE);
        // auto exception_message = csstrtostr(exp->message);
        // return to_utf8(exception_message);
        return msg;
    }

    bool ParameterMatch(const MethodInfo* method, Il2CppType** type_arr, int count) {
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

    Il2CppClass* GetClassFromName(const char* name_space, const char* type_name) {
        InitFunctions();

        auto dom = il2cpp_functions::domain_get();
        if (!dom) {
            log(ERROR, "GetClassFromName: Could not get domain!");
            return nullptr;
        }
        size_t assemb_count;
        const Il2CppAssembly** allAssemb = il2cpp_functions::domain_get_assemblies(dom, &assemb_count);

        for (int i = 0; i < assemb_count; i++) {
            auto assemb = allAssemb[i];
            auto img = il2cpp_functions::assembly_get_image(assemb);
            if (!img) {
                log(ERROR, "Assembly with name: %s has a null image!", assemb->aname.name);
                continue;
            }
            auto klass = il2cpp_functions::class_from_name(img, name_space, type_name);
            if (klass) {
                return klass;
            }
        }
        log(ERROR, "il2cpp_utils: GetClassFromName: Could not find class with namepace: %s and name: %s", name_space, type_name);
        return nullptr;
    }

    const MethodInfo* GetMethod(Il2CppClass* klass, std::string_view methodName, int argsCount) {
        if (!klass) return nullptr;
        auto methodInfo = il2cpp_functions::class_get_method_from_name(klass, methodName.data(), argsCount);
        if (!methodInfo) {
            log(ERROR, "could not find method %s with %i parameters in class %s (namespace '%s')!", methodName.data(),
                argsCount, il2cpp_functions::class_get_name(klass), il2cpp_functions::class_get_namespace(klass));
            return nullptr;
        }
        return methodInfo;
    }

    FieldInfo* FindField(Il2CppClass* klass, std::string_view fieldName) {
        if (!klass) return nullptr;
        auto field = il2cpp_functions::class_get_field_from_name(klass, fieldName.data());
        if (!field) {
            log(ERROR, "could not find field %s in class %s (namespace '%s')!", fieldName.data(),
                il2cpp_functions::class_get_name(klass), il2cpp_functions::class_get_namespace(klass));
        }
        return field;
    }

    bool SetFieldValue(Il2CppObject* instance, FieldInfo* field, void* value) {
        InitFunctions();
        if (!field) {
            log(ERROR, "il2cpp_utils: SetFieldValue: Null field parameter!");
            return false;
        }
        if (instance) {
            il2cpp_functions::field_set_value(instance, field, value);
        } else { // Fallback to perform a static field set
            il2cpp_functions::field_static_set_value(field, value);
        }
        return true;
    }

    bool SetFieldValue(Il2CppClass* klass, std::string_view fieldName, void* value) {
        InitFunctions();
        if (!klass) {
            log(ERROR, "il2cpp_utils: SetFieldValue: Null klass parameter!");
            return false;
        }
        auto field = FindField(klass, fieldName);
        if (!field) return false;
        return SetFieldValue(nullptr, field, value);
    }

    bool SetFieldValue(Il2CppObject* instance, std::string_view fieldName, void* value) {
        InitFunctions();
        if (!instance) {
            log(ERROR, "il2cpp_utils: SetFieldValue: Null instance parameter!");
            return false;
        }
        auto klass = il2cpp_functions::object_get_class(instance);
        if (!klass) {
            log(ERROR, "il2cpp_utils: SetFieldValue: Could not find object class!");
            return false;
        }
        auto field = FindField(klass, fieldName);
        if (!field) return false;
        return SetFieldValue(instance, field, value);
    }

    Il2CppReflectionType* MakeGenericType(Il2CppReflectionType* gt, Il2CppArray* types) {
        InitFunctions();

        auto runtimeType = GetClassFromName("System", "RuntimeType");
        if (!runtimeType) {
            log(ERROR, "il2cpp_utils: MakeGenericType: Failed to get System.RuntimeType!");
            return nullptr;
        }
        auto makeGenericMethod = il2cpp_functions::class_get_method_from_name(runtimeType, "MakeGenericType", 2);
        if (!makeGenericMethod) {
            log(ERROR, "il2cpp_utils: MakeGenericType: Failed to get RuntimeType.MakeGenericType(param1, param2) method!");
            return nullptr;
        }

        Il2CppException* exp = nullptr;
        void* params[] = {reinterpret_cast<void*>(gt), reinterpret_cast<void*>(types)};
        auto genericType = il2cpp_functions::runtime_invoke(makeGenericMethod, nullptr, params, &exp);
        if (exp) {
            log(ERROR, "il2cpp_utils: MakeGenericType: Failed with exception: %s", ExceptionToString(exp).c_str());
            return nullptr;
        }
        return reinterpret_cast<Il2CppReflectionType*>(genericType);
    }

    Il2CppClass* MakeGeneric(const Il2CppClass* klass, std::initializer_list<const Il2CppClass*> args) {
        InitFunctions();
 
        auto typ = GetClassFromName("System", "Type");
        if (!typ) {
            return nullptr;
        }
        auto getType = il2cpp_functions::class_get_method_from_name(typ, "GetType", 1);
        if (!getType) {
            log(ERROR, "il2cpp_utils: MakeGeneric: Failed to get System.Type.GetType(param1) method!");
            return nullptr;
        }
 
        auto klassType = il2cpp_functions::type_get_object(il2cpp_functions::class_get_type_const(klass));
        if (!klassType) {
            log(ERROR, "il2cpp_utils: MakeGeneric: Failed to get class type object!");
            return nullptr;
        }
 
        // Call Type.MakeGenericType on it
        auto a = il2cpp_functions::array_new_specific(typ, args.size());
        if (!a) {
            log(ERROR, "il2cpp_utils: MakeGeneric: Failed to make new array with length: %zu", args.size());
            return nullptr;
        }
 
        int i = 0;
        for (auto arg : args) {
            auto t = il2cpp_functions::class_get_type_const(arg);
            auto o = il2cpp_functions::type_get_object(t);
            if (!o) {
                log(ERROR, "il2cpp_utils: MakeGeneric: Failed to get type for %s", il2cpp_functions::class_get_name_const(arg));
                return nullptr;
            }
            il2cpp_array_set(a, void*, i, reinterpret_cast<void*>(o));
            i++;
        }

        auto reflection_type = MakeGenericType(reinterpret_cast<Il2CppReflectionType*>(klassType), a);
        if (!reflection_type) {
            log(ERROR, "il2cpp_utils: MakeGeneric: Failed to MakeGenericType from Il2CppReflectionType and Il2CppArray!");
            return nullptr;
        }

        auto ret = il2cpp_functions::class_from_system_type(reinterpret_cast<Il2CppReflectionType*>(reflection_type));
        if (!ret) {
            log(ERROR, "il2cpp_utils: MakeGeneric: Failed to get class from Il2CppReflectionType!");
            return nullptr;
        }
        log(DEBUG, "il2cpp_utils: MakeGeneric: returning %s", il2cpp_functions::class_get_name(ret));
        return ret;
    }

    // Gets the type enum of a given type
    // TODO Remove this method! Replace with default typesystem
    int GetTypeEnum(const char* name_space, const char* type_name) {
        auto klass = GetClassFromName(name_space, type_name);
        auto typ = il2cpp_functions::class_get_type(klass);
        return il2cpp_functions::type_get_type(typ);
    }

    static std::unordered_map<int, const char*> typeMap;

    const char* TypeGetSimpleName(const Il2CppType* type) {
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

    void LogMethod(const MethodInfo* method) {
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
        methodName = methodName ? methodName : "__noname__";
        std::stringstream paramStream;
        for (int i = 0; i < il2cpp_functions::method_get_param_count(method); i++) {
            if (i > 0) paramStream << ", ";
            auto paramType = il2cpp_functions::method_get_param(method, i);
            if (il2cpp_functions::type_is_byref(paramType)) {
                paramStream << "out/ref ";
            }
            paramStream << TypeGetSimpleName(paramType) << " ";
            auto name = il2cpp_functions::method_get_param_name(method, i);
            paramStream << (name ? name : "__noname__");
        }
        const auto& paramStrRef = paramStream.str();
        const char* paramStr = paramStrRef.c_str();
        log(DEBUG, "%s%s %s(%s);", flagStr, retTypeStr, methodName, paramStr);
    }

    void LogField(FieldInfo* field) {
        InitFunctions();

        auto flags = il2cpp_functions::field_get_flags(field);
        const char* flagStr = (flags & FIELD_ATTRIBUTE_STATIC) ? "static " : "";
        auto type = il2cpp_functions::field_get_type(field);
        auto typeStr = TypeGetSimpleName(type);
        auto name = il2cpp_functions::field_get_name(field);
        name = name ? name : "__noname__";
        auto offset = il2cpp_functions::field_get_offset(field);

        log(DEBUG, "%s%s %s; // 0x%lx, flags: 0x%.4X", flagStr, typeStr, name, offset, flags);
    }

    void LogClass(const Il2CppClass* klass, bool logParents) {
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
                    log(DEBUG, " generic type %i: %s", i + 1, TypeGetSimpleName(typ));
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

    Il2CppString* createcsstr(std::string_view inp) {
        InitFunctions();
        return il2cpp_functions::string_new_len(inp.data(), (uint32_t)inp.length());
    }

    [[nodiscard]] bool Match(const Il2CppObject* source, const Il2CppClass* klass) noexcept {
        return (source->klass == klass);
    }

    bool AssertMatch(const Il2CppObject* source, const Il2CppClass* klass) {
        InitFunctions();
        if (!Match(source, klass)) {
            log(CRITICAL, "il2cpp_utils: AssertMatch: Unhandled subtype: namespace %s, class %s", 
                il2cpp_functions::class_get_namespace(source->klass), il2cpp_functions::class_get_name(source->klass));
            std::terminate();
        }
        return true;
    }
}