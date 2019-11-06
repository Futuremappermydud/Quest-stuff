#ifndef IL2CPP_HELPER_H
#define IL2CPP_HELPER_H

#include "typedefs.h"
#include <string>
#include <string_view>
#include <unordered_map>
#include <sstream>
#include "logging.h"

template<typename TRet, typename ...TArgs>
// A generic function pointer, which can be called with and set to a `getRealOffset` call
using function_ptr_t = TRet(*)(TArgs...);

namespace array_utils {   
    static char* il2cpp_array_addr_with_size(Il2CppArray *array, int32_t size, uintptr_t idx)
    {
        return ((char*)array) + kIl2CppSizeOfArray + size * idx;
    }
    #define load_array_elema(arr, idx, size) ((((uint8_t*)(arr)) + kIl2CppSizeOfArray) + ((size) * (idx)))

    #define il2cpp_array_setwithsize(array, elementSize, index, value)  \
        do {    \
            void*__p = (void*) array_utils::il2cpp_array_addr_with_size ((array), elementSize, (index)); \
            memcpy(__p, &(value), elementSize); \
        } while (0)
    #define il2cpp_array_setrefwithsize(array, elementSize, index, value)  \
        do {    \
            void*__p = (void*) array_utils::il2cpp_array_addr_with_size ((array), elementSize, (index)); \
            memcpy(__p, value, elementSize); \
        } while (0)
    #define il2cpp_array_addr(array, type, index) ((type*)(void*) array_utils::il2cpp_array_addr_with_size (array, sizeof (type), index))
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

class IL2CPP_Helper {
    private:
        bool initialized = false;
    public:
    
        bool IsInitialized();
        void Initialize();

        void (*init)(const char* domain_name);
	    void (*init_utf16)(const Il2CppChar * domain_name);
	    void (*shutdown)();
	    void (*set_config_dir)(const char *config_path);
	    void (*set_data_dir)(const char *data_path);
	    void (*set_temp_dir)(const char *temp_path);
	    void (*set_commandline_arguments)(int argc, const char* const argv[], const char* basedir);
	    void (*set_commandline_arguments_utf16)(int argc, const Il2CppChar * const argv[], const char* basedir);
	    void (*set_config_utf16)(const Il2CppChar * executablePath);
	    void (*set_config)(const char* executablePath);
	    void (*set_memory_callbacks)(Il2CppMemoryCallbacks * callbacks);
	    const Il2CppImage* (*get_corlib)();
	    void (*add_internal_call)(const char* name, Il2CppMethodPointer method);
	    Il2CppMethodPointer (*resolve_icall)(const char* name);
	    void* (*alloc)(size_t size);
	    void (*free)(void* ptr);
	    Il2CppClass* (*array_class_get)(Il2CppClass * element_class, uint32_t rank);
	    uint32_t (*array_length)(Il2CppArray * array);
	    uint32_t (*array_get_byte_length)(Il2CppArray * array);
	    Il2CppArray* (*array_new)(Il2CppClass * elementTypeInfo, il2cpp_array_size_t length);
	    Il2CppArray* (*array_new_specific)(Il2CppClass * arrayTypeInfo, il2cpp_array_size_t length);
	    Il2CppArray* (*array_new_full)(Il2CppClass * array_class, il2cpp_array_size_t * lengths, il2cpp_array_size_t * lower_bounds);
	    Il2CppClass* (*bounded_array_class_get)(Il2CppClass * element_class, uint32_t rank, bool bounded);
	    int (*array_element_size)(const Il2CppClass * array_class);
	    const Il2CppImage* (*assembly_get_image)(const Il2CppAssembly * assembly);
	    const Il2CppType* (*class_enum_basetype)(Il2CppClass * klass);
	    bool (*class_is_generic)(const Il2CppClass * klass);
	    bool (*class_is_inflated)(const Il2CppClass * klass);
	    bool (*class_is_assignable_from)(Il2CppClass * klass, Il2CppClass * oklass);
	    bool (*class_is_subclass_of)(Il2CppClass * klass, Il2CppClass * klassc, bool check_interfaces);
	    bool (*class_has_parent)(Il2CppClass * klass, Il2CppClass * klassc);
	    Il2CppClass* (*class_from_il2cpp_type)(const Il2CppType * type);
	    Il2CppClass* (*class_from_name)(const Il2CppImage * image, const char* namespaze, const char *name);
	    Il2CppClass* (*class_from_system_type)(Il2CppReflectionType * type);
	    Il2CppClass* (*class_get_element_class)(Il2CppClass * klass);
	    const EventInfo* (*class_get_events)(Il2CppClass * klass, void* *iter);
	    FieldInfo* (*class_get_fields)(Il2CppClass * klass, void* *iter);
	    Il2CppClass* (*class_get_nested_types)(Il2CppClass * klass, void* *iter);
	    Il2CppClass* (*class_get_interfaces)(Il2CppClass * klass, void* *iter);
	    const PropertyInfo* (*class_get_properties)(Il2CppClass * klass, void* *iter);
	    const PropertyInfo* (*class_get_property_from_name)(Il2CppClass * klass, const char *name);
	    FieldInfo* (*class_get_field_from_name)(Il2CppClass * klass, const char *name);
	    const MethodInfo* (*class_get_methods)(Il2CppClass * klass, void* *iter);
	    const MethodInfo* (*class_get_method_from_name)(Il2CppClass * klass, const char* name, int argsCount);
	    const char* (*class_get_name)(Il2CppClass * klass);
	    const char* (*class_get_namespace)(Il2CppClass * klass);
	    Il2CppClass* (*class_get_parent)(Il2CppClass * klass);
	    Il2CppClass* (*class_get_declaring_type)(Il2CppClass * klass);
	    int32_t (*class_instance_size)(Il2CppClass * klass);
	    size_t (*class_num_fields)(const Il2CppClass * enumKlass);
	    bool (*class_is_valuetype)(const Il2CppClass * klass);
	    int32_t (*class_value_size)(Il2CppClass * klass, uint32_t * align);
	    bool (*class_is_blittable)(const Il2CppClass * klass);
	    int (*class_get_flags)(const Il2CppClass * klass);
	    bool (*class_is_abstract)(const Il2CppClass * klass);
	    bool (*class_is_interface)(const Il2CppClass * klass);
	    int (*class_array_element_size)(const Il2CppClass * klass);
	    Il2CppClass* (*class_from_type)(const Il2CppType * type);
	    const Il2CppType* (*class_get_type)(Il2CppClass * klass);
	    uint32_t (*class_get_type_token)(Il2CppClass * klass);
	    bool (*class_has_attribute)(Il2CppClass * klass, Il2CppClass * attr_class);
	    bool (*class_has_references)(Il2CppClass * klass);
	    bool (*class_is_enum)(const Il2CppClass * klass);
	    const Il2CppImage* (*class_get_image)(Il2CppClass * klass);
	    const char* (*class_get_assemblyname)(const Il2CppClass * klass);
	    int (*class_get_rank)(const Il2CppClass * klass);
	    size_t (*class_get_bitmap_size)(const Il2CppClass * klass);
	    void (*class_get_bitmap)(Il2CppClass * klass, size_t * bitmap);
	    bool (*stats_dump_to_file)(const char *path);
	    uint64_t (*stats_get_value)(Il2CppStat stat);
	    Il2CppDomain* (*domain_get)();
	    const Il2CppAssembly* (*domain_assembly_open)(Il2CppDomain * domain, const char* name);
	    const Il2CppAssembly** (*domain_get_assemblies)(const Il2CppDomain * domain, size_t * size);
	    Il2CppException* (*exception_from_name_msg)(const Il2CppImage * image, const char *name_space, const char *name, const char *msg);
	    Il2CppException* (*get_exception_argument_null)(const char *arg);
	    void (*format_exception)(const Il2CppException * ex, char* message, int message_size);
	    void (*format_stack_trace)(const Il2CppException * ex, char* output, int output_size);
	    void (*unhandled_exception)(Il2CppException*);
	    int (*field_get_flags)(FieldInfo * field);
	    const char* (*field_get_name)(FieldInfo * field);
	    Il2CppClass* (*field_get_parent)(FieldInfo * field);
	    size_t (*field_get_offset)(FieldInfo * field);
	    const Il2CppType* (*field_get_type)(FieldInfo * field);
	    void (*field_get_value)(Il2CppObject * obj, FieldInfo * field, void *value);
	    Il2CppObject* (*field_get_value_object)(FieldInfo * field, Il2CppObject * obj);
	    bool (*field_has_attribute)(FieldInfo * field, Il2CppClass * attr_class);
	    void (*field_set_value)(Il2CppObject * obj, FieldInfo * field, void *value);
	    void (*field_static_get_value)(FieldInfo * field, void *value);
	    void (*field_static_set_value)(FieldInfo * field, void *value);
	    void (*field_set_value_object)(Il2CppObject * instance, FieldInfo * field, Il2CppObject * value);
	    void (*gc_collect)(int maxGenerations);
	    int32_t (*gc_collect_a_little)();
	    void (*gc_disable)();
	    void (*gc_enable)();
	    bool (*gc_is_disabled)();
	    int64_t (*gc_get_used_size)();
	    int64_t (*gc_get_heap_size)();
	    void (*gc_wbarrier_set_field)(Il2CppObject * obj, void **targetAddress, void *object);
	    uint32_t (*gchandle_new)(Il2CppObject * obj, bool pinned);
	    uint32_t (*gchandle_new_weakref)(Il2CppObject * obj, bool track_resurrection);
	    Il2CppObject* (*gchandle_get_target )(uint32_t gchandle);
	    void (*gchandle_free)(uint32_t gchandle);
	    void* (*unity_liveness_calculation_begin)(Il2CppClass * filter, int max_object_count, il2cpp_register_object_callback callback, void* userdata, il2cpp_WorldChangedCallback onWorldStarted, il2cpp_WorldChangedCallback onWorldStopped);
	    void (*unity_liveness_calculation_end)(void* state);
	    void (*unity_liveness_calculation_from_root)(Il2CppObject * root, void* state);
	    void (*unity_liveness_calculation_from_statics)(void* state);
	    const Il2CppType* (*method_get_return_type)(const MethodInfo * method);
	    Il2CppClass* (*method_get_declaring_type)(const MethodInfo * method);
	    const char* (*method_get_name)(const MethodInfo * method);
	    const MethodInfo* (*method_get_from_reflection)(const Il2CppReflectionMethod * method);
	    Il2CppReflectionMethod* (*method_get_object)(const MethodInfo * method, Il2CppClass * refclass);
	    bool (*method_is_generic)(const MethodInfo * method);
	    bool (*method_is_inflated)(const MethodInfo * method);
	    bool (*method_is_instance)(const MethodInfo * method);
	    uint32_t (*method_get_param_count)(const MethodInfo * method);
	    const Il2CppType* (*method_get_param)(const MethodInfo * method, uint32_t index);
	    Il2CppClass* (*method_get_class)(const MethodInfo * method);
	    bool (*method_has_attribute)(const MethodInfo * method, Il2CppClass * attr_class);
	    uint32_t (*method_get_flags)(const MethodInfo * method, uint32_t * iflags);
	    uint32_t (*method_get_token)(const MethodInfo * method);
	    const char* (*method_get_param_name)(const MethodInfo * method, uint32_t index);
	    void (*profiler_install)(Il2CppProfiler * prof, Il2CppProfileFunc shutdown_callback);
	    void (*profiler_set_events)(Il2CppProfileFlags events);
	    void (*profiler_install_enter_leave)(Il2CppProfileMethodFunc enter, Il2CppProfileMethodFunc fleave);
	    void (*profiler_install_allocation)(Il2CppProfileAllocFunc callback);
	    void (*profiler_install_gc)(Il2CppProfileGCFunc callback, Il2CppProfileGCResizeFunc heap_resize_callback);
	    void (*profiler_install_fileio)(Il2CppProfileFileIOFunc callback);
	    void (*profiler_install_thread)(Il2CppProfileThreadFunc start, Il2CppProfileThreadFunc end);
	    uint32_t (*property_get_flags)(PropertyInfo * prop);
	    const MethodInfo* (*property_get_get_method)(PropertyInfo * prop);
	    const MethodInfo* (*property_get_set_method)(PropertyInfo * prop);
	    const char* (*property_get_name)(PropertyInfo * prop);
	    Il2CppClass* (*property_get_parent)(PropertyInfo * prop);
	    Il2CppClass* (*object_get_class)(Il2CppObject * obj);
	    uint32_t (*object_get_size)(Il2CppObject * obj);
	    const MethodInfo* (*object_get_virtual_method)(Il2CppObject * obj, const MethodInfo * method);
	    Il2CppObject* (*object_new)(const Il2CppClass * klass);
	    void* (*object_unbox)(Il2CppObject * obj);
	    Il2CppObject* (*value_box)(Il2CppClass * klass, void* data);
	    void (*monitor_enter)(Il2CppObject * obj);
	    bool (*monitor_try_enter)(Il2CppObject * obj, uint32_t timeout);
	    void (*monitor_exit)(Il2CppObject * obj);
	    void (*monitor_pulse)(Il2CppObject * obj);
	    void (*monitor_pulse_all)(Il2CppObject * obj);
	    void (*monitor_wait)(Il2CppObject * obj);
	    bool (*monitor_try_wait)(Il2CppObject * obj, uint32_t timeout);
	    Il2CppObject* (*runtime_invoke)(const MethodInfo * method, void *obj, void **params, Il2CppException **exc);
	    Il2CppObject* (*runtime_invoke_convert_args)(const MethodInfo * method, void *obj, Il2CppObject **params, int paramCount, Il2CppException **exc);
	    void (*runtime_class_init)(Il2CppClass * klass);
	    void (*runtime_object_init)(Il2CppObject * obj);
	    void (*runtime_object_init_exception)(Il2CppObject * obj, Il2CppException** exc);
	    void (*runtime_unhandled_exception_policy_set)(Il2CppRuntimeUnhandledExceptionPolicy value);
	    int32_t (*string_length)(Il2CppString * str);
	    Il2CppChar* (*string_chars)(Il2CppString * str);
	    Il2CppString* (*string_new)(const char* str);
	    Il2CppString* (*string_new_len)(const char* str, uint32_t length);
	    Il2CppString* (*string_new_utf16)(const Il2CppChar * text, int32_t len);
	    Il2CppString* (*string_new_wrapper)(const char* str);
	    Il2CppString* (*string_intern)(Il2CppString * str);
	    Il2CppString* (*string_is_interned)(Il2CppString * str);
	    Il2CppThread* (*thread_current)();
	    Il2CppThread* (*thread_attach)(Il2CppDomain * domain);
	    void (*thread_detach)(Il2CppThread * thread);
	    Il2CppThread** (*thread_get_all_attached_threads)(size_t * size);
	    bool (*is_vm_thread)(Il2CppThread * thread);
	    void (*current_thread_walk_frame_stack)(Il2CppFrameWalkFunc func, void* user_data);
	    void (*thread_walk_frame_stack)(Il2CppThread * thread, Il2CppFrameWalkFunc func, void* user_data);
	    bool (*current_thread_get_top_frame)(Il2CppStackFrameInfo * frame);
	    bool (*thread_get_top_frame)(Il2CppThread * thread, Il2CppStackFrameInfo * frame);
	    bool (*current_thread_get_frame_at)(int32_t offset, Il2CppStackFrameInfo * frame);
	    bool (*thread_get_frame_at)(Il2CppThread * thread, int32_t offset, Il2CppStackFrameInfo * frame);
	    int32_t (*current_thread_get_stack_depth)();
	    int32_t (*thread_get_stack_depth)(Il2CppThread * thread);
	    Il2CppObject* (*type_get_object)(const Il2CppType * type);
	    int (*type_get_type)(const Il2CppType * type);
	    Il2CppClass* (*type_get_class_or_element_class)(const Il2CppType * type);
	    char* (*type_get_name)(const Il2CppType * type);
	    bool (*type_is_byref)(const Il2CppType * type);
	    uint32_t (*type_get_attrs)(const Il2CppType * type);
	    bool (*type_equals)(const Il2CppType * type, const Il2CppType * otherType);
	    char* (*type_get_assembly_qualified_name)(const Il2CppType * type);
	    const Il2CppAssembly* (*image_get_assembly)(const Il2CppImage * image);
	    const char* (*image_get_name)(const Il2CppImage * image);
	    const char* (*image_get_filename)(const Il2CppImage * image);
	    const MethodInfo* (*image_get_entry_point)(const Il2CppImage * image);
	    size_t (*image_get_class_count)(const Il2CppImage * image);
	    const Il2CppClass* (*image_get_class)(const Il2CppImage * image, size_t index);
	    Il2CppManagedMemorySnapshot* (*capture_memory_snapshot)();
	    void (*free_captured_memory_snapshot)(Il2CppManagedMemorySnapshot * snapshot);
	    void (*set_find_plugin_callback)(Il2CppSetFindPlugInCallback method);
	    void (*register_log_callback)(Il2CppLogCallback method);
	    void (*debugger_set_agent_options)(const char* options);
	    bool (*is_debugger_attached)();
	    void (*unity_install_unitytls_interface)(const void* unitytlsInterfaceStruct);
	    Il2CppCustomAttrInfo* (*custom_attrs_from_class)(Il2CppClass * klass);
	    Il2CppCustomAttrInfo* (*custom_attrs_from_method)(const MethodInfo * method);
	    Il2CppObject* (*custom_attrs_get_attr)(Il2CppCustomAttrInfo * ainfo, Il2CppClass * attr_klass);
	    bool (*custom_attrs_has_attr)(Il2CppCustomAttrInfo * ainfo, Il2CppClass * attr_klass);
	    Il2CppArray* (*custom_attrs_construct)(Il2CppCustomAttrInfo * cinfo);
	    void (*custom_attrs_free)(Il2CppCustomAttrInfo * ainfo);
    
	    // MANUALLY DEFINED CONST DEFINITIONS
	    const Il2CppType* (*class_get_type_const)(const Il2CppClass * klass);
	    const char* (*class_get_name_const)(const Il2CppClass * klass);

        Il2CppClass* GetClassFromName(const char* name_space, const char* type_name);

        template<typename T>
        struct il2cpp_arg_type_ {};

        template<typename T>
        using il2cpp_arg_type = il2cpp_arg_type_<std::decay_t<T>>;

        template<typename T>
        struct il2cpp_arg_type_<T*> { // we assume that pointers are already objects to get the type of
             inline Il2CppType const* get(IL2CPP_Helper* helper, T const* arg) {
                return helper->class_get_type(
                    helper->object_get_class(reinterpret_cast<Il2CppObject*>(arg)));
            }
        };

        template<>
        struct il2cpp_arg_type_<int8_t> {
            inline Il2CppType const* get(IL2CPP_Helper* helper, int8_t) {
                // return System.SByte
                return helper->class_get_type(helper->GetClassFromName("System", "SByte"));
            }
        };

        template<>
        struct il2cpp_arg_type_<uint8_t> {
            inline Il2CppType const* get(IL2CPP_Helper* helper, uint8_t) {
                // return System.Byte
                return helper->class_get_type(helper->GetClassFromName("System", "SByte"));
            }
        };

        template<>
        struct il2cpp_arg_type_<float> {
            inline Il2CppType const* get(IL2CPP_Helper* helper, float) {
                // return System.Single
                return helper->class_get_type(helper->GetClassFromName("System", "Single"));
            }
        };

        template<>
        struct il2cpp_arg_type_<double> {
            inline Il2CppType const* get(IL2CPP_Helper* helper, double) {
                // return System.Double
                return helper->class_get_type(helper->GetClassFromName("System", "Double"));
            }
        };

        template<>
        struct il2cpp_arg_type_<int16_t> {
            inline Il2CppType const* get(IL2CPP_Helper* helper, int16_t) {
                // return System.Int16
                return helper->class_get_type(helper->GetClassFromName("System", "Int16"));
            }
        };

        template<>
        struct il2cpp_arg_type_<int> {
            inline Il2CppType const* get(IL2CPP_Helper* helper, int) {
                // return System.Int32
                return helper->class_get_type(helper->GetClassFromName("System", "Int32"));
            }
        };

        template<>
        struct il2cpp_arg_type_<int64_t> {
            inline Il2CppType const* get(IL2CPP_Helper* helper, int64_t) {
                // return System.Int64
                return helper->class_get_type(helper->GetClassFromName("System", "Int64"));
            }
        };

        // TODO Add more types

        template<typename T>
        struct il2cpp_arg_ptr {
            inline void* get(T const& arg) {
                return reinterpret_cast<void*>(&arg);
            }
        };
        template<typename T>
        struct il2cpp_arg_ptr<T*> {
            inline void* get(T* arg) {
                return reinterpret_cast<void*>(arg);
            }
        };
       
        #define EXCEPTION_MESSAGE_SIZE 4096 
        inline std::string ExceptionToString(Il2CppException* exp) {
            char msg[EXCEPTION_MESSAGE_SIZE];
            format_exception(exp, msg, EXCEPTION_MESSAGE_SIZE);
            return msg;
        }

        template<typename... TArgs>
        // Returns if a given MethodInfo's parameters match the Il2CppTypes provided as args
        inline bool ParameterMatch(const MethodInfo* method, TArgs* ...args) {
            constexpr auto count = sizeof...(TArgs);
            Il2CppType* argarr[] = {reinterpret_cast<Il2CppType*>(args)...};
            if (method->parameters_count != count) {
                return false;
            }
            for (int i = 0; i < method->parameters_count; i++) {
                if (!type_equals(method->parameters[i].parameter_type, argarr[i])) {
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
                if (!type_equals(method->parameters[i].parameter_type, type_arr[i])) {
                    return false;
                }
            }
            return true;
        }

        template<typename TObj = Il2CppObject, typename... TArgs>
        // Creates a new object of the given class and Il2CppTypes parameters and casts it to TObj*
        TObj* New(Il2CppClass* klass, TArgs const& ...args) {

            constexpr auto count = sizeof...(TArgs);

            void* invoke_params[] = { il2cpp_arg_ptr<decltype(args)>::get(args)... };
            Il2CppType const* argarr[] = { il2cpp_arg_type<decltype(args)>::get(args)... };
            // object_new call
            auto obj = object_new(klass);
            // runtime_invoke constructor with right number of args, return null if multiple matches (or take a vector of type pointers to resolve it), return null if constructor errors
            
            void* myIter = nullptr;
            const MethodInfo* current;
            const MethodInfo* ctor = nullptr;
            // Il2CppType* argarr[] = {reinterpret_cast<Il2CppType*>(args)...};
            while ((current = class_get_methods(klass, &myIter))) {
                if (ParameterMatch(current, argarr, count) && strcmp(ctor->name, ".ctor") == 0) {
                    ctor = current;
                }
            }
            if (!ctor) {
                log(ERROR, "IL2CPP_Helper: New: Could not find constructor for provided class!");
                return nullptr;
            }
            // TODO FIX CTOR CHECKING
            if (strcmp(ctor->name, ".ctor") != 0) {
                log(ERROR, "IL2CPP_Helper: New: Found a method matching parameter count and types, but it is not a constructor!");
                return nullptr;
            }
            Il2CppException* exp = nullptr;
            runtime_invoke(ctor, obj, invoke_params, &exp);
            if (exp) {
                log(ERROR, "IL2CPP_Helper: New: Failed with exception: %s", ExceptionToString(exp).c_str());
                return nullptr;
            }
            return reinterpret_cast<TObj*>(obj);
        }

        template<typename TObj = Il2CppObject, typename... TArgs>
        // Creates a New object of the given class and parameters and casts it to TObj*
        // DOES NOT PERFORM TYPE-SAFE CHECKING!
        TObj* NewUnsafe(Il2CppClass* klass, TArgs* ...args) {
            void* invoke_params[] = {reinterpret_cast<void*>(args)...};
            // object_new call
            auto obj = object_new(klass);
            // runtime_invoke constructor with right number of args, return null if constructor errors
            constexpr auto count = sizeof...(TArgs);
            log(DEBUG, "Attempting to find .ctor with paramCount: %lu for class name: %s", count, class_get_name(klass));
            const MethodInfo* ctor = class_get_method_from_name(klass, ".ctor", count);

            if (!ctor) {
                log(ERROR, "IL2CPP_Helper: New: Could not find constructor for provided class!");
                return nullptr;
            }
            Il2CppException* exp;
            runtime_invoke(ctor, obj, invoke_params, &exp);
            if (exp) {
                log(ERROR, "IL2CPP_Helper: New: Failed with exception: %s", ExceptionToString(exp).c_str());
                return nullptr;
            }
            return reinterpret_cast<TObj*>(obj);
        }
        
        Il2CppObject* GetFieldObjectValue(Il2CppObject* instance, std::string_view fieldName);
        
        template<class TOut>
        bool GetFieldValue(TOut* out, Il2CppObject* instance, std::string_view fieldName) {
            if (!instance) {
                log(ERROR, "IL2CPP_Helper: GetFieldValue: Null instance parameter!");
                return false;
            }
            auto klass = object_get_class(instance);
            if (!klass) {
                log(ERROR, "IL2CPP_Helper: GetFieldValue: Could not get object class!");
                return false;
            }
            auto field = class_get_field_from_name(klass, fieldName.data());
            if (!field) {
                log(ERROR, "IL2CPP_Helper: GetFieldValue: Could not find field %s in class %s (namespace '%s')!", fieldName.data(), class_get_name(klass), class_get_namespace(klass));
                return false;
            }
            field_get_value(instance, field, out);
            return true;
        }
        
        bool SetFieldObjectValue(Il2CppObject* instance, std::string_view fieldName, Il2CppObject* value);

        bool SetFieldValue(Il2CppObject* instance, std::string_view fieldName, void* value);
        
        template<class TOut, class... TArgs>
        // Runs a MethodInfo method with the specified parameters and instance, with return type TOut
        // Returns false if it fails
        // Created by zoller27osu, modified by Sc2ad
        bool RunMethod(TOut* out, void* instance, const MethodInfo* method, TArgs* ...params) {
              if (!method) {
                log(ERROR, "IL2CPP_Helper: RunMethod: Null MethodInfo!");
                return false;
            }
            Il2CppException* exp = nullptr;
            void* invoke_params[] = {reinterpret_cast<void*>(params)...};
            auto ret = runtime_invoke(method, instance, invoke_params, &exp);
            if constexpr (std::is_pointer<TOut>::value) {
                *out = reinterpret_cast<TOut>(ret);
            } else {
                *out = *reinterpret_cast<TOut*>(object_unbox(ret));
            }
            if (exp) {
                log(ERROR, "IL2CPP_Helper: RunMethod: %s: Failed with exception: %s", method_get_name(method),
                    ExceptionToString(exp).c_str());
                return false;
            }
            return true;
        }

        template<class... TArgs>
        // Runs a MethodInfo method with the specified parameters and instance, assuming a void return type.
        // Returns false if it fails
        // Created by zoller27osu
        bool RunMethod(void* instance, const MethodInfo* method, TArgs* ...params) {
            void* out = nullptr;
            return RunMethod(&out, instance, method, params...);
        }

        template<class TOut, class... TArgs>
        // Runs a method with the specified method name, with return type TOut
        // Returns false if it fails
        // Created by zoller27osu, modified by Sc2ad
        bool RunMethodInClass(TOut* out, Il2CppClass* klass, Il2CppObject* instance, std::string_view methodName, TArgs* ...params) {
            auto method = class_get_method_from_name(klass, methodName.data(), sizeof...(TArgs));
            if (!method) {
                log(ERROR, "IL2CPP_Helper: RunMethod: Could not find method %s with %lu parameters in class %s (namespace '%s')!", methodName.data(),
                    sizeof...(TArgs), class_get_name(klass), class_get_namespace(klass));
                return false;
            }
            return RunMethod(out, instance, method, params...);
        }

        template<class TOut, class... TArgs>
        // Runs a method with the specified method name, with return type TOut
        // Returns false if it fails
        // Created by zoller27osu, modified by Sc2ad
        bool RunMethod(TOut* out, Il2CppObject* instance, std::string_view methodName, TArgs* ...params) {
            if (!instance) {
                log(ERROR, "IL2CPP_Helper: RunMethod: Null instance parameter!");
                return false;
            }
            auto klass = object_get_class(instance);
            if (!klass) {
                log(ERROR, "IL2CPP_Helper: RunMethod: Could not get object class!");
                return false;
            }
            return RunMethodInClass(out, klass, instance, methodName, params...);
        }

        template<class TOut, class... TArgs>
        // Runs a method with the specified method name, with return type TOut
        // Returns false if it fails
        // Created by zoller27osu, modified by Sc2ad
        bool RunStaticMethod(TOut* out, Il2CppClass* klass, std::string_view methodName, TArgs* ...params) {
            if (!klass) {
                log(ERROR, "IL2CPP_Helper: RunMethod: Null class!");
                return false;
            }
            return RunMethodInClass(out, klass, nullptr, methodName, params...);
        }

        template<class TOut, class... TArgs>
        // Runs a method with the specified method name, with return type TOut
        // Returns false if it fails
        // Created by zoller27osu, modified by Sc2ad
        bool RunStaticMethod(TOut* out, Il2CppObject* instance, std::string_view methodName, TArgs* ...params) {
            if (!instance) {
                log(ERROR, "IL2CPP_Helper: RunMethod: Null instance parameter!");
                return false;
            }
            auto klass = object_get_class(instance);
            if (!klass) {
                log(ERROR, "IL2CPP_Helper: RunMethod: Could not get object class!");
                return false;
            }
            return RunMethodInClass(out, klass, nullptr, methodName, params...);
        }

        template<class... TArgs>
        // Runs a method with the specified method name, assuming a void return type
        // Returns false if it fails
        // Created by zoller27osu
        bool RunMethod(Il2CppObject* instance, std::string_view methodName, TArgs* ...params) {
            void* out = nullptr;
            return RunMethod(&out, instance, methodName, params...);
        }

        template<class... TArgs>
        // Runs a method with the specified method name, assuming a void return type
        // Returns false if it fails
        // Created by zoller27osu
        bool RunStaticMethod(Il2CppClass* klass, std::string_view methodName, TArgs* ...params) {
            void* out = nullptr;
            return RunStaticMethod(&out, klass, methodName, params...);
        }

        template<class... TArgs>
        // Runs a method with the specified method name, assuming a void return type
        // Returns false if it fails
        // Created by zoller27osu
        bool RunStaticMethod(Il2CppObject* instance, std::string_view methodName, TArgs* ...params) {
            void* out = nullptr;
            return RunStaticMethod(&out, instance, methodName, params...);
        }

        template<typename T = MulticastDelegate, typename R, typename... TArgs>
        // Created by zoller27osu
        // Creates an Action and casts it to a MulticastDelegate*
        T* MakeAction(Il2CppObject* obj, function_ptr_t<R, TArgs...> callback, const Il2CppType* actionType) {
            constexpr auto count = sizeof...(TArgs);
            Il2CppClass* actionClass = class_from_il2cpp_type(actionType);

            /* 
            * TODO: call PlatformInvoke::MarshalFunctionPointerToDelegate directly instead of copying code from it,
            * or at least use a cache like utils::NativeDelegateMethodCache::GetNativeDelegate(nativeFunctionPointer);
            */
            const MethodInfo* invoke = class_get_method_from_name(actionClass, "Invoke", -1);  // well-formed Actions have only 1 invoke method
            MethodInfo* method = (MethodInfo*) calloc(1, sizeof(MethodInfo));
            method->methodPointer = (Il2CppMethodPointer)callback;
            method->invoker_method = NULL;
            method->parameters_count = invoke->parameters_count;
            method->slot = kInvalidIl2CppMethodSlot;
            method->is_marshaled_from_native = true;  // "a fake MethodInfo wrapping a native function pointer"
            // In the event that a function is static, this will behave as normal
            if (obj == nullptr) method->flags |= METHOD_ATTRIBUTE_STATIC;

            // TODO: figure out why passing method directly doesn't work
            auto action = NewUnsafe<T>(actionClass, obj, &method);
            auto asDelegate = reinterpret_cast<Delegate*>(action);
            if (asDelegate->method_ptr != (void*)callback) {
                log(ERROR, "Created Action's method_ptr (%p) is incorrect (should be %p)!", asDelegate->method_ptr, callback);
                return nullptr;
            }

            return action;
        }
        template<typename T = MulticastDelegate>
        // Created by zoller27osu
        // Creates an Action and casts it to a MulticastDelegate*
        T* MakeAction(Il2CppObject* obj, void* callback, const Il2CppType* actionType) {
            Il2CppClass* actionClass = class_from_il2cpp_type(actionType);

            /* 
            * TODO: call PlatformInvoke::MarshalFunctionPointerToDelegate directly instead of copying code from it,
            * or at least use a cache like utils::NativeDelegateMethodCache::GetNativeDelegate(nativeFunctionPointer);
            */
            const MethodInfo* invoke = class_get_method_from_name(actionClass, "Invoke", -1);  // well-formed Actions have only 1 invoke method
            MethodInfo* method = (MethodInfo*) calloc(1, sizeof(MethodInfo));
            method->methodPointer = (Il2CppMethodPointer)callback;
            method->invoker_method = NULL;
            method->parameters_count = 0;
            method->slot = kInvalidIl2CppMethodSlot;
            method->is_marshaled_from_native = true;  // "a fake MethodInfo wrapping a native function pointer"
            // In the event that a function is static, this will behave as normal
            if (obj == nullptr) method->flags |= METHOD_ATTRIBUTE_STATIC;

            // TODO: figure out why passing method directly doesn't work
            auto action = NewUnsafe<T>(actionClass, obj, &method);
            auto asDelegate = reinterpret_cast<Delegate*>(action);
            if (asDelegate->method_ptr != callback) {
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
            auto typ = class_get_type(klass);
            return type_get_type(typ);
        }
    
        // Gets a C# name of a type
        std::unordered_map<int, const char*> typeMap;
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
            auto p = typeMap.find(type_get_type(type));
            if (p != typeMap.end()) {
                return p->second;
            } else {
                return type_get_name(type);
            }
        }
        
        // Function made by zoller27osu, modified by Sc2ad
        // Logs information about the given MethodInfo* as log(DEBUG)
        inline void LogMethod(const MethodInfo* method) {
            auto flags = method_get_flags(method, nullptr);
            std::stringstream flagStream;
            if (flags & METHOD_ATTRIBUTE_STATIC) flagStream << "static ";
            if (flags & METHOD_ATTRIBUTE_VIRTUAL) flagStream << "virtual ";
            if (flags & METHOD_ATTRIBUTE_ABSTRACT) flagStream << "abstract ";
            const auto& flagStrRef = flagStream.str();  
            const char* flagStr = flagStrRef.c_str();
            auto retType = method_get_return_type(method);
            auto retTypeStr = TypeGetSimpleName(retType);
            auto methodName = method_get_name(method);
            methodName = methodName ? methodName : "__noname__";
            std::stringstream paramStream;
            for (int i = 0; i < method_get_param_count(method); i++) {
                if (i > 0) paramStream << ", ";
                auto paramType = method_get_param(method, i);
                if (type_is_byref(paramType)) {
                    paramStream << "out/ref ";
                }
                paramStream << TypeGetSimpleName(paramType) << " ";
                auto name = method_get_param_name(method, i);
                paramStream << (name ? name : "__noname__");
            }
            const auto& paramStrRef = paramStream.str();
            const char* paramStr = paramStrRef.c_str();
            log(DEBUG, "%s%s %s(%s);", flagStr, retTypeStr, methodName, paramStr);
        }

        // Created by zoller27osu
        // Logs information about the given FieldInfo* as log(DEBUG)
        inline void LogField(FieldInfo* field) {
            auto flags = field_get_flags(field);
            const char* flagStr = (flags & FIELD_ATTRIBUTE_STATIC) ? "static " : "";
            auto type = field_get_type(field);
            auto typeStr = TypeGetSimpleName(type);
            auto name = field_get_name(field);
            name = name ? name : "__noname__";
            auto offset = field_get_offset(field);

            log(DEBUG, "%s%s %s; // 0x%lx, flags: 0x%.4X", flagStr, typeStr, name, offset, flags);
        }

        // Some parts provided by zoller27osu
        // Logs information about the given Il2CppClass* as log(DEBUG)
        inline void LogClass(const Il2CppClass* klass, bool logParents = true) {
            auto unconst = const_cast<Il2CppClass*>(klass);
            log(DEBUG, "======================CLASS INFO FOR CLASS: %s::%s======================", class_get_namespace(unconst), class_get_name(unconst));
            log(DEBUG, "Assembly Name: %s", class_get_assemblyname(klass));
            log(DEBUG, "Rank: %i", class_get_rank(klass));
            log(DEBUG, "Type Token: %i", class_get_type_token(unconst));
            log(DEBUG, "Flags: 0x%.8X", class_get_flags(klass));
            log(DEBUG, "Event Count: %i", klass->event_count);
            log(DEBUG, "Field Count: %i", klass->field_count);
            log(DEBUG, "Method Count: %i", klass->method_count);
            log(DEBUG, "Property Count: %i", klass->property_count);
            log(DEBUG, "Is Generic: %i", class_is_generic(klass));
            log(DEBUG, "Is Abstract: %i", class_is_abstract(klass));
            log(DEBUG, "=========METHODS=========");
            void* myIter = nullptr;
            // const MethodInfo* current;
            // int i = 0;
            // while ((current = class_get_methods(unconst, &myIter))) {
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
            auto declaring = class_get_declaring_type(unconst);
            log(DEBUG, "declaring type: %p", declaring);
            if (declaring) LogClass(declaring);
            auto element = class_get_element_class(unconst);
            log(DEBUG, "element class: %p (self = %p)", element, klass);
            if (element && element != klass) LogClass(element);

            log(DEBUG, "=========FIELDS=========");
            myIter = nullptr;
            FieldInfo* field;
            while ((field = class_get_fields(unconst, &myIter))) {
                LogField(field);
            }
            log(DEBUG, "=========END FIELDS=========");

            auto parent = class_get_parent(unconst);
            log(DEBUG, "parent: %p", parent);
            if (parent && logParents) LogClass(parent);
            log(DEBUG, "==================================================================================");
        }

        // Creates a cs string (allocates it) with the given string_view and returns it
        inline Il2CppString* createcsstr(std::string_view inp) {
            return string_new_len(inp.data(), (uint32_t)inp.length());
        }

        // Returns if a given source object is an object of the given class
        // Created by zoller27osu
        [[nodiscard]] inline bool Match(const Il2CppObject* source, const Il2CppClass* klass) noexcept {
            return (source->klass == klass);
        }

        // Asserts that a given source object is an object of the given class
        // Created by zoller27osu
        inline bool AssertMatch(const Il2CppObject* source, const Il2CppClass* klass) {
            if (!Match(source, klass)) {
                log(CRITICAL, "IL2CPP_Helper: AssertMatch: Unhandled subtype: namespace %s, class %s", 
                    class_get_namespace(source->klass), class_get_name(source->klass));
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
        // Runtime Invoke, but with a list initializer for args
        inline Il2CppObject* RuntimeInvoke(const MethodInfo* method, Il2CppObject* reference, Il2CppException** exc, TArgs* ...args) {
            void* invoke_params[] = {reinterpret_cast<void*>(args)...};
            return runtime_invoke(method, reference, invoke_params, exc);
        }

};

#endif /* IL2CPP_HELPER_H */