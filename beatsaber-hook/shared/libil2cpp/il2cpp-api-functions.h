#ifndef DO_API_NO_RETURN
#define DO_API_NO_RETURN(r, n, p) DO_API(r,n,p)
#endif


void il2cpp_init(const char* domain_name);
void il2cpp_init_utf16(const Il2CppChar * domain_name);
void il2cpp_shutdown();
void il2cpp_set_config_dir(const char *config_path);
void il2cpp_set_data_dir(const char *data_path);
void il2cpp_set_temp_dir(const char *temp_path);
void il2cpp_set_commandline_arguments(int argc, const char* const argv[], const char* basedir);
void il2cpp_set_commandline_arguments_utf16(int argc, const Il2CppChar * const argv[], const char* basedir);
void il2cpp_set_config_utf16(const Il2CppChar * executablePath);
void il2cpp_set_config(const char* executablePath);

void il2cpp_set_memory_callbacks(Il2CppMemoryCallbacks * callbacks);
const Il2CppImage* il2cpp_get_corlib();
void il2cpp_add_internal_call(const char* name, Il2CppMethodPointer method);
Il2CppMethodPointer il2cpp_resolve_icall(const char* name);

void* il2cpp_alloc(size_t size);
void il2cpp_free(void* ptr);

// array
Il2CppClass* il2cpp_array_class_get(Il2CppClass * element_class, uint32_t rank);
uint32_t il2cpp_array_length(Il2CppArray * array);
uint32_t il2cpp_array_get_byte_length(Il2CppArray * array);
Il2CppArray* il2cpp_array_new(Il2CppClass * elementTypeInfo, il2cpp_array_size_t length);
Il2CppArray* il2cpp_array_new_specific(Il2CppClass * arrayTypeInfo, il2cpp_array_size_t length);
Il2CppArray* il2cpp_array_new_full(Il2CppClass * array_class, il2cpp_array_size_t * lengths, il2cpp_array_size_t * lower_bounds);
Il2CppClass* il2cpp_bounded_array_class_get(Il2CppClass * element_class, uint32_t rank, bool bounded);
int il2cpp_array_element_size(const Il2CppClass * array_class);

// assembly
const Il2CppImage* il2cpp_assembly_get_image(const Il2CppAssembly * assembly);

// class
const Il2CppType* il2cpp_class_enum_basetype(Il2CppClass * klass);
bool il2cpp_class_is_generic(const Il2CppClass * klass);
bool il2cpp_class_is_inflated(const Il2CppClass * klass);
bool il2cpp_class_is_assignable_from(Il2CppClass * klass, Il2CppClass * oklass);
bool il2cpp_class_is_subclass_of(Il2CppClass * klass, Il2CppClass * klassc, bool check_interfaces);
bool il2cpp_class_has_parent(Il2CppClass * klass, Il2CppClass * klassc);
Il2CppClass* il2cpp_class_from_il2cpp_type(const Il2CppType * type);
Il2CppClass* il2cpp_class_from_name(const Il2CppImage * image, const char* namespaze, const char *name);
Il2CppClass* il2cpp_class_from_system_type(Il2CppReflectionType * type);
Il2CppClass* il2cpp_class_get_element_class(Il2CppClass * klass);
const EventInfo* il2cpp_class_get_events(Il2CppClass * klass, void* *iter);
FieldInfo* il2cpp_class_get_fields(Il2CppClass * klass, void* *iter);
Il2CppClass* il2cpp_class_get_nested_types(Il2CppClass * klass, void* *iter);
Il2CppClass* il2cpp_class_get_interfaces(Il2CppClass * klass, void* *iter);
const PropertyInfo* il2cpp_class_get_properties(Il2CppClass * klass, void* *iter);
const PropertyInfo* il2cpp_class_get_property_from_name(Il2CppClass * klass, const char *name);
FieldInfo* il2cpp_class_get_field_from_name(Il2CppClass * klass, const char *name);
const MethodInfo* il2cpp_class_get_methods(Il2CppClass * klass, void* *iter);
const MethodInfo* il2cpp_class_get_method_from_name(Il2CppClass * klass, const char* name, int argsCount);
const char* il2cpp_class_get_name(Il2CppClass * klass);
const char* il2cpp_class_get_namespace(Il2CppClass * klass);
Il2CppClass* il2cpp_class_get_parent(Il2CppClass * klass);
Il2CppClass* il2cpp_class_get_declaring_type(Il2CppClass * klass);
int32_t il2cpp_class_instance_size(Il2CppClass * klass);
size_t il2cpp_class_num_fields(const Il2CppClass * enumKlass);
bool il2cpp_class_is_valuetype(const Il2CppClass * klass);
int32_t il2cpp_class_value_size(Il2CppClass * klass, uint32_t * align);
bool il2cpp_class_is_blittable(const Il2CppClass * klass);
int il2cpp_class_get_flags(const Il2CppClass * klass);
bool il2cpp_class_is_abstract(const Il2CppClass * klass);
bool il2cpp_class_is_interface(const Il2CppClass * klass);
int il2cpp_class_array_element_size(const Il2CppClass * klass);
Il2CppClass* il2cpp_class_from_type(const Il2CppType * type);
const Il2CppType* il2cpp_class_get_type(Il2CppClass * klass);
uint32_t il2cpp_class_get_type_token(Il2CppClass * klass);
bool il2cpp_class_has_attribute(Il2CppClass * klass, Il2CppClass * attr_class);
bool il2cpp_class_has_references(Il2CppClass * klass);
bool il2cpp_class_is_enum(const Il2CppClass * klass);
const Il2CppImage* il2cpp_class_get_image(Il2CppClass * klass);
const char* il2cpp_class_get_assemblyname(const Il2CppClass * klass);
int il2cpp_class_get_rank(const Il2CppClass * klass);

// testing only
size_t il2cpp_class_get_bitmap_size(const Il2CppClass * klass);
void il2cpp_class_get_bitmap(Il2CppClass * klass, size_t * bitmap);

// stats
bool il2cpp_stats_dump_to_file(const char *path);
uint64_t il2cpp_stats_get_value(Il2CppStat stat);

// domain
Il2CppDomain* il2cpp_domain_get();
const Il2CppAssembly* il2cpp_domain_assembly_open(Il2CppDomain * domain, const char* name);
const Il2CppAssembly** il2cpp_domain_get_assemblies(const Il2CppDomain * domain, size_t * size);

// exception
void il2cpp_raise_exception(Il2CppException*);
Il2CppException* il2cpp_exception_from_name_msg(const Il2CppImage * image, const char *name_space, const char *name, const char *msg);
Il2CppException* il2cpp_get_exception_argument_null(const char *arg);
void il2cpp_format_exception(const Il2CppException * ex, char* message, int message_size);
void il2cpp_format_stack_trace(const Il2CppException * ex, char* output, int output_size);
void il2cpp_unhandled_exception(Il2CppException*);

// field
int il2cpp_field_get_flags(FieldInfo * field);
const char* il2cpp_field_get_name(FieldInfo * field);
Il2CppClass* il2cpp_field_get_parent(FieldInfo * field);
size_t il2cpp_field_get_offset(FieldInfo * field);
const Il2CppType* il2cpp_field_get_type(FieldInfo * field);
void il2cpp_field_get_value(Il2CppObject * obj, FieldInfo * field, void *value);
Il2CppObject* il2cpp_field_get_value_object(FieldInfo * field, Il2CppObject * obj);
bool il2cpp_field_has_attribute(FieldInfo * field, Il2CppClass * attr_class);
void il2cpp_field_set_value(Il2CppObject * obj, FieldInfo * field, void *value);
void il2cpp_field_static_get_value(FieldInfo * field, void *value);
void il2cpp_field_static_set_value(FieldInfo * field, void *value);
void il2cpp_field_set_value_object(Il2CppObject * instance, FieldInfo * field, Il2CppObject * value);

// gc
void il2cpp_gc_collect(int maxGenerations);
int32_t il2cpp_gc_collect_a_little();
void il2cpp_gc_disable();
void il2cpp_gc_enable();
bool il2cpp_gc_is_disabled();
int64_t il2cpp_gc_get_used_size();
int64_t il2cpp_gc_get_heap_size();
void il2cpp_gc_wbarrier_set_field(Il2CppObject * obj, void **targetAddress, void *object);

// gchandle
uint32_t il2cpp_gchandle_new(Il2CppObject * obj, bool pinned);
uint32_t il2cpp_gchandle_new_weakref(Il2CppObject * obj, bool track_resurrection);
Il2CppObject* il2cpp_gchandle_get_target (uint32_t gchandle);
void il2cpp_gchandle_free(uint32_t gchandle);

// liveness
void* il2cpp_unity_liveness_calculation_begin(Il2CppClass * filter, int max_object_count, il2cpp_register_object_callback callback, void* userdata, il2cpp_WorldChangedCallback onWorldStarted, il2cpp_WorldChangedCallback onWorldStopped);
void il2cpp_unity_liveness_calculation_end(void* state);
void il2cpp_unity_liveness_calculation_from_root(Il2CppObject * root, void* state);
void il2cpp_unity_liveness_calculation_from_statics(void* state);

// method
const Il2CppType* il2cpp_method_get_return_type(const MethodInfo * method);
Il2CppClass* il2cpp_method_get_declaring_type(const MethodInfo * method);
const char* il2cpp_method_get_name(const MethodInfo * method);
const MethodInfo* il2cpp_method_get_from_reflection(const Il2CppReflectionMethod * method);
Il2CppReflectionMethod* il2cpp_method_get_object(const MethodInfo * method, Il2CppClass * refclass);
bool il2cpp_method_is_generic(const MethodInfo * method);
bool il2cpp_method_is_inflated(const MethodInfo * method);
bool il2cpp_method_is_instance(const MethodInfo * method);
uint32_t il2cpp_method_get_param_count(const MethodInfo * method);
const Il2CppType* il2cpp_method_get_param(const MethodInfo * method, uint32_t index);
Il2CppClass* il2cpp_method_get_class(const MethodInfo * method);
bool il2cpp_method_has_attribute(const MethodInfo * method, Il2CppClass * attr_class);
uint32_t il2cpp_method_get_flags(const MethodInfo * method, uint32_t * iflags);
uint32_t il2cpp_method_get_token(const MethodInfo * method);
const char* il2cpp_method_get_param_name(const MethodInfo * method, uint32_t index);

// profiler
#if IL2CPP_ENABLE_PROFILER

void il2cpp_profiler_install(Il2CppProfiler * prof, Il2CppProfileFunc shutdown_callback);
void il2cpp_profiler_set_events(Il2CppProfileFlags events);
void il2cpp_profiler_install_enter_leave(Il2CppProfileMethodFunc enter, Il2CppProfileMethodFunc fleave);
void il2cpp_profiler_install_allocation(Il2CppProfileAllocFunc callback);
void il2cpp_profiler_install_gc(Il2CppProfileGCFunc callback, Il2CppProfileGCResizeFunc heap_resize_callback);
void il2cpp_profiler_install_fileio(Il2CppProfileFileIOFunc callback);
void il2cpp_profiler_install_thread(Il2CppProfileThreadFunc start, Il2CppProfileThreadFunc end);

#endif

// property
uint32_t il2cpp_property_get_flags(PropertyInfo * prop);
const MethodInfo* il2cpp_property_get_get_method(PropertyInfo * prop);
const MethodInfo* il2cpp_property_get_set_method(PropertyInfo * prop);
const char* il2cpp_property_get_name(PropertyInfo * prop);
Il2CppClass* il2cpp_property_get_parent(PropertyInfo * prop);

// object
Il2CppClass* il2cpp_object_get_class(Il2CppObject * obj);
uint32_t il2cpp_object_get_size(Il2CppObject * obj);
const MethodInfo* il2cpp_object_get_virtual_method(Il2CppObject * obj, const MethodInfo * method);
Il2CppObject* il2cpp_object_new(const Il2CppClass * klass);
void* il2cpp_object_unbox(Il2CppObject * obj);

Il2CppObject* il2cpp_value_box(Il2CppClass * klass, void* data);

// monitor
void il2cpp_monitor_enter(Il2CppObject * obj);
bool il2cpp_monitor_try_enter(Il2CppObject * obj, uint32_t timeout);
void il2cpp_monitor_exit(Il2CppObject * obj);
void il2cpp_monitor_pulse(Il2CppObject * obj);
void il2cpp_monitor_pulse_all(Il2CppObject * obj);
void il2cpp_monitor_wait(Il2CppObject * obj);
bool il2cpp_monitor_try_wait(Il2CppObject * obj, uint32_t timeout);

// runtime
Il2CppObject* il2cpp_runtime_invoke(const MethodInfo * method, void *obj, void **params, Il2CppException **exc);
Il2CppObject* il2cpp_runtime_invoke_convert_args(const MethodInfo * method, void *obj, Il2CppObject **params, int paramCount, Il2CppException **exc);
void il2cpp_runtime_class_init(Il2CppClass * klass);
void il2cpp_runtime_object_init(Il2CppObject * obj);

void il2cpp_runtime_object_init_exception(Il2CppObject * obj, Il2CppException** exc);

void il2cpp_runtime_unhandled_exception_policy_set(Il2CppRuntimeUnhandledExceptionPolicy value);

// string
int32_t il2cpp_string_length(Il2CppString * str);
Il2CppChar* il2cpp_string_chars(Il2CppString * str);
Il2CppString* il2cpp_string_new(const char* str);
Il2CppString* il2cpp_string_new_len(const char* str, uint32_t length);
Il2CppString* il2cpp_string_new_utf16(const Il2CppChar * text, int32_t len);
Il2CppString* il2cpp_string_new_wrapper(const char* str);
Il2CppString* il2cpp_string_intern(Il2CppString * str);
Il2CppString* il2cpp_string_is_interned(Il2CppString * str);

// thread
Il2CppThread* il2cpp_thread_current();
Il2CppThread* il2cpp_thread_attach(Il2CppDomain * domain);
void il2cpp_thread_detach(Il2CppThread * thread);

Il2CppThread** il2cpp_thread_get_all_attached_threads(size_t * size);
bool il2cpp_is_vm_thread(Il2CppThread * thread);

// stacktrace
void il2cpp_current_thread_walk_frame_stack(Il2CppFrameWalkFunc func, void* user_data);
void il2cpp_thread_walk_frame_stack(Il2CppThread * thread, Il2CppFrameWalkFunc func, void* user_data);
bool il2cpp_current_thread_get_top_frame(Il2CppStackFrameInfo * frame);
bool il2cpp_thread_get_top_frame(Il2CppThread * thread, Il2CppStackFrameInfo * frame);
bool il2cpp_current_thread_get_frame_at(int32_t offset, Il2CppStackFrameInfo * frame);
bool il2cpp_thread_get_frame_at(Il2CppThread * thread, int32_t offset, Il2CppStackFrameInfo * frame);
int32_t il2cpp_current_thread_get_stack_depth();
int32_t il2cpp_thread_get_stack_depth(Il2CppThread * thread);

// type
Il2CppObject* il2cpp_type_get_object(const Il2CppType * type);
int il2cpp_type_get_type(const Il2CppType * type);
Il2CppClass* il2cpp_type_get_class_or_element_class(const Il2CppType * type);
char* il2cpp_type_get_name(const Il2CppType * type);
bool il2cpp_type_is_byref(const Il2CppType * type);
uint32_t il2cpp_type_get_attrs(const Il2CppType * type);
bool il2cpp_type_equals(const Il2CppType * type, const Il2CppType * otherType);
char* il2cpp_type_get_assembly_qualified_name(const Il2CppType * type);

// image
const Il2CppAssembly* il2cpp_image_get_assembly(const Il2CppImage * image);
const char* il2cpp_image_get_name(const Il2CppImage * image);
const char* il2cpp_image_get_filename(const Il2CppImage * image);
const MethodInfo* il2cpp_image_get_entry_point(const Il2CppImage * image);

size_t il2cpp_image_get_class_count(const Il2CppImage * image);
const Il2CppClass* il2cpp_image_get_class(const Il2CppImage * image, size_t index);

// Memory information
Il2CppManagedMemorySnapshot* il2cpp_capture_memory_snapshot();
void il2cpp_free_captured_memory_snapshot(Il2CppManagedMemorySnapshot * snapshot);

void il2cpp_set_find_plugin_callback(Il2CppSetFindPlugInCallback method);

// Logging
void il2cpp_register_log_callback(Il2CppLogCallback method);

// Debugger
void il2cpp_debugger_set_agent_options(const char* options);
bool il2cpp_is_debugger_attached();

// TLS module
void il2cpp_unity_install_unitytls_interface(const void* unitytlsInterfaceStruct);

// custom attributes
Il2CppCustomAttrInfo* il2cpp_custom_attrs_from_class(Il2CppClass * klass);
Il2CppCustomAttrInfo* il2cpp_custom_attrs_from_method(const MethodInfo * method);

Il2CppObject* il2cpp_custom_attrs_get_attr(Il2CppCustomAttrInfo * ainfo, Il2CppClass * attr_klass);
bool il2cpp_custom_attrs_has_attr(Il2CppCustomAttrInfo * ainfo, Il2CppClass * attr_klass);
Il2CppArray* il2cpp_custom_attrs_construct(Il2CppCustomAttrInfo * cinfo);

void il2cpp_custom_attrs_free(Il2CppCustomAttrInfo * ainfo);
