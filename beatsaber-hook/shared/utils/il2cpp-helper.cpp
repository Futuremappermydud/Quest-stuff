#include "il2cpp-helper.hpp"
#include "logging.h"

bool IL2CPP_Helper::IsInitialized(){
	return initialized;
}

void IL2CPP_Helper::Initialize(){
	if (initialized) return;
	log(INFO, "IL2CPP_Helper: Initializing all IL2CPP Functions...");
	void *imagehandle = dlopen("/data/app/com.beatgames.beatsaber-1/lib/arm64/libil2cpp.so", 0x00000 | 0x00001);

	*(void**)(&init) = dlsym(imagehandle, "il2cpp_init");
	log(INFO, "Loaded: il2cpp_init");
	*(void**)(&init_utf16) = dlsym(imagehandle, "il2cpp_init_utf16");
	log(INFO, "Loaded: il2cpp_init_utf16");
	*(void**)(&shutdown) = dlsym(imagehandle, "il2cpp_shutdown");
	log(INFO, "Loaded: il2cpp_shutdown");
	*(void**)(&set_config_dir) = dlsym(imagehandle, "il2cpp_set_config_dir");
	log(INFO, "Loaded: il2cpp_set_config_dir");
	*(void**)(&set_data_dir) = dlsym(imagehandle, "il2cpp_set_data_dir");
	log(INFO, "Loaded: il2cpp_set_data_dir");
	*(void**)(&set_temp_dir) = dlsym(imagehandle, "il2cpp_set_temp_dir");
	log(INFO, "Loaded: il2cpp_set_temp_dir");
	*(void**)(&set_commandline_arguments) = dlsym(imagehandle, "il2cpp_set_commandline_arguments");
	log(INFO, "Loaded: il2cpp_set_commandline_arguments");
	*(void**)(&set_commandline_arguments_utf16) = dlsym(imagehandle, "il2cpp_set_commandline_arguments_utf16");
	log(INFO, "Loaded: il2cpp_set_commandline_arguments_utf16");
	*(void**)(&set_config_utf16) = dlsym(imagehandle, "il2cpp_set_config_utf16");
	log(INFO, "Loaded: il2cpp_set_config_utf16");
	*(void**)(&set_config) = dlsym(imagehandle, "il2cpp_set_config");
	log(INFO, "Loaded: il2cpp_set_config");
	*(void**)(&set_memory_callbacks) = dlsym(imagehandle, "il2cpp_set_memory_callbacks");
	log(INFO, "Loaded: il2cpp_set_memory_callbacks");
	*(void**)(&get_corlib) = dlsym(imagehandle, "il2cpp_get_corlib");
	log(INFO, "Loaded: il2cpp_get_corlib");
	*(void**)(&add_internal_call) = dlsym(imagehandle, "il2cpp_add_internal_call");
	log(INFO, "Loaded: il2cpp_add_internal_call");
	*(void**)(&resolve_icall) = dlsym(imagehandle, "il2cpp_resolve_icall");
	log(INFO, "Loaded: il2cpp_resolve_icall");
	*(void**)(&alloc) = dlsym(imagehandle, "il2cpp_alloc");
	log(INFO, "Loaded: il2cpp_alloc");
	*(void**)(&free) = dlsym(imagehandle, "il2cpp_free");
	log(INFO, "Loaded: il2cpp_free");
	*(void**)(&array_class_get) = dlsym(imagehandle, "il2cpp_array_class_get");
	log(INFO, "Loaded: il2cpp_array_class_get");
	*(void**)(&array_length) = dlsym(imagehandle, "il2cpp_array_length");
	log(INFO, "Loaded: il2cpp_array_length");
	*(void**)(&array_get_byte_length) = dlsym(imagehandle, "il2cpp_array_get_byte_length");
	log(INFO, "Loaded: il2cpp_array_get_byte_length");
	*(void**)(&array_new) = dlsym(imagehandle, "il2cpp_array_new");
	log(INFO, "Loaded: il2cpp_array_new");
	*(void**)(&array_new_specific) = dlsym(imagehandle, "il2cpp_array_new_specific");
	log(INFO, "Loaded: il2cpp_array_new_specific");
	*(void**)(&array_new_full) = dlsym(imagehandle, "il2cpp_array_new_full");
	log(INFO, "Loaded: il2cpp_array_new_full");
	*(void**)(&bounded_array_class_get) = dlsym(imagehandle, "il2cpp_bounded_array_class_get");
	log(INFO, "Loaded: il2cpp_bounded_array_class_get");
	*(void**)(&array_element_size) = dlsym(imagehandle, "il2cpp_array_element_size");
	log(INFO, "Loaded: il2cpp_array_element_size");
	*(void**)(&assembly_get_image) = dlsym(imagehandle, "il2cpp_assembly_get_image");
	log(INFO, "Loaded: il2cpp_assembly_get_image");
	*(void**)(&class_enum_basetype) = dlsym(imagehandle, "il2cpp_class_enum_basetype");
	log(INFO, "Loaded: il2cpp_class_enum_basetype");
	*(void**)(&class_is_generic) = dlsym(imagehandle, "il2cpp_class_is_generic");
	log(INFO, "Loaded: il2cpp_class_is_generic");
	*(void**)(&class_is_inflated) = dlsym(imagehandle, "il2cpp_class_is_inflated");
	log(INFO, "Loaded: il2cpp_class_is_inflated");
	*(void**)(&class_is_assignable_from) = dlsym(imagehandle, "il2cpp_class_is_assignable_from");
	log(INFO, "Loaded: il2cpp_class_is_assignable_from");
	*(void**)(&class_is_subclass_of) = dlsym(imagehandle, "il2cpp_class_is_subclass_of");
	log(INFO, "Loaded: il2cpp_class_is_subclass_of");
	*(void**)(&class_has_parent) = dlsym(imagehandle, "il2cpp_class_has_parent");
	log(INFO, "Loaded: il2cpp_class_has_parent");
	*(void**)(&class_from_il2cpp_type) = dlsym(imagehandle, "il2cpp_class_from_il2cpp_type");
	log(INFO, "Loaded: il2cpp_class_from_il2cpp_type");
	*(void**)(&class_from_name) = dlsym(imagehandle, "il2cpp_class_from_name");
	log(INFO, "Loaded: il2cpp_class_from_name");
	*(void**)(&class_from_system_type) = dlsym(imagehandle, "il2cpp_class_from_system_type");
	log(INFO, "Loaded: il2cpp_class_from_system_type");
	*(void**)(&class_get_element_class) = dlsym(imagehandle, "il2cpp_class_get_element_class");
	log(INFO, "Loaded: il2cpp_class_get_element_class");
	*(void**)(&class_get_events) = dlsym(imagehandle, "il2cpp_class_get_events");
	log(INFO, "Loaded: il2cpp_class_get_events");
	*(void**)(&class_get_fields) = dlsym(imagehandle, "il2cpp_class_get_fields");
	log(INFO, "Loaded: il2cpp_class_get_fields");
	*(void**)(&class_get_nested_types) = dlsym(imagehandle, "il2cpp_class_get_nested_types");
	log(INFO, "Loaded: il2cpp_class_get_nested_types");
	*(void**)(&class_get_interfaces) = dlsym(imagehandle, "il2cpp_class_get_interfaces");
	log(INFO, "Loaded: il2cpp_class_get_interfaces");
	*(void**)(&class_get_properties) = dlsym(imagehandle, "il2cpp_class_get_properties");
	log(INFO, "Loaded: il2cpp_class_get_properties");
	*(void**)(&class_get_property_from_name) = dlsym(imagehandle, "il2cpp_class_get_property_from_name");
	log(INFO, "Loaded: il2cpp_class_get_property_from_name");
	*(void**)(&class_get_field_from_name) = dlsym(imagehandle, "il2cpp_class_get_field_from_name");
	log(INFO, "Loaded: il2cpp_class_get_field_from_name");
	*(void**)(&class_get_methods) = dlsym(imagehandle, "il2cpp_class_get_methods");
	log(INFO, "Loaded: il2cpp_class_get_methods");
	*(void**)(&class_get_method_from_name) = dlsym(imagehandle, "il2cpp_class_get_method_from_name");
	log(INFO, "Loaded: il2cpp_class_get_method_from_name");
	*(void**)(&class_get_name) = dlsym(imagehandle, "il2cpp_class_get_name");
	log(INFO, "Loaded: il2cpp_class_get_name");
	*(void**)(&class_get_namespace) = dlsym(imagehandle, "il2cpp_class_get_namespace");
	log(INFO, "Loaded: il2cpp_class_get_namespace");
	*(void**)(&class_get_parent) = dlsym(imagehandle, "il2cpp_class_get_parent");
	log(INFO, "Loaded: il2cpp_class_get_parent");
	*(void**)(&class_get_declaring_type) = dlsym(imagehandle, "il2cpp_class_get_declaring_type");
	log(INFO, "Loaded: il2cpp_class_get_declaring_type");
	*(void**)(&class_instance_size) = dlsym(imagehandle, "il2cpp_class_instance_size");
	log(INFO, "Loaded: il2cpp_class_instance_size");
	*(void**)(&class_num_fields) = dlsym(imagehandle, "il2cpp_class_num_fields");
	log(INFO, "Loaded: il2cpp_class_num_fields");
	*(void**)(&class_is_valuetype) = dlsym(imagehandle, "il2cpp_class_is_valuetype");
	log(INFO, "Loaded: il2cpp_class_is_valuetype");
	*(void**)(&class_value_size) = dlsym(imagehandle, "il2cpp_class_value_size");
	log(INFO, "Loaded: il2cpp_class_value_size");
	*(void**)(&class_is_blittable) = dlsym(imagehandle, "il2cpp_class_is_blittable");
	log(INFO, "Loaded: il2cpp_class_is_blittable");
	*(void**)(&class_get_flags) = dlsym(imagehandle, "il2cpp_class_get_flags");
	log(INFO, "Loaded: il2cpp_class_get_flags");
	*(void**)(&class_is_abstract) = dlsym(imagehandle, "il2cpp_class_is_abstract");
	log(INFO, "Loaded: il2cpp_class_is_abstract");
	*(void**)(&class_is_interface) = dlsym(imagehandle, "il2cpp_class_is_interface");
	log(INFO, "Loaded: il2cpp_class_is_interface");
	*(void**)(&class_array_element_size) = dlsym(imagehandle, "il2cpp_class_array_element_size");
	log(INFO, "Loaded: il2cpp_class_array_element_size");
	*(void**)(&class_from_type) = dlsym(imagehandle, "il2cpp_class_from_type");
	log(INFO, "Loaded: il2cpp_class_from_type");
	*(void**)(&class_get_type) = dlsym(imagehandle, "il2cpp_class_get_type");
	log(INFO, "Loaded: il2cpp_class_get_type");
	*(void**)(&class_get_type_token) = dlsym(imagehandle, "il2cpp_class_get_type_token");
	log(INFO, "Loaded: il2cpp_class_get_type_token");
	*(void**)(&class_has_attribute) = dlsym(imagehandle, "il2cpp_class_has_attribute");
	log(INFO, "Loaded: il2cpp_class_has_attribute");
	*(void**)(&class_has_references) = dlsym(imagehandle, "il2cpp_class_has_references");
	log(INFO, "Loaded: il2cpp_class_has_references");
	*(void**)(&class_is_enum) = dlsym(imagehandle, "il2cpp_class_is_enum");
	log(INFO, "Loaded: il2cpp_class_is_enum");
	*(void**)(&class_get_image) = dlsym(imagehandle, "il2cpp_class_get_image");
	log(INFO, "Loaded: il2cpp_class_get_image");
	*(void**)(&class_get_assemblyname) = dlsym(imagehandle, "il2cpp_class_get_assemblyname");
	log(INFO, "Loaded: il2cpp_class_get_assemblyname");
	*(void**)(&class_get_rank) = dlsym(imagehandle, "il2cpp_class_get_rank");
	log(INFO, "Loaded: il2cpp_class_get_rank");
	*(void**)(&class_get_bitmap_size) = dlsym(imagehandle, "il2cpp_class_get_bitmap_size");
	log(INFO, "Loaded: il2cpp_class_get_bitmap_size");
	*(void**)(&class_get_bitmap) = dlsym(imagehandle, "il2cpp_class_get_bitmap");
	log(INFO, "Loaded: il2cpp_class_get_bitmap");
	*(void**)(&stats_dump_to_file) = dlsym(imagehandle, "il2cpp_stats_dump_to_file");
	log(INFO, "Loaded: il2cpp_stats_dump_to_file");
	*(void**)(&stats_get_value) = dlsym(imagehandle, "il2cpp_stats_get_value");
	log(INFO, "Loaded: il2cpp_stats_get_value");
	*(void**)(&domain_get) = dlsym(imagehandle, "il2cpp_domain_get");
	log(INFO, "Loaded: il2cpp_domain_get");
	*(void**)(&domain_assembly_open) = dlsym(imagehandle, "il2cpp_domain_assembly_open");
	log(INFO, "Loaded: il2cpp_domain_assembly_open");
	*(void**)(&domain_get_assemblies) = dlsym(imagehandle, "il2cpp_domain_get_assemblies");
	log(INFO, "Loaded: il2cpp_domain_get_assemblies");
	*(void**)(&exception_from_name_msg) = dlsym(imagehandle, "il2cpp_exception_from_name_msg");
	log(INFO, "Loaded: il2cpp_exception_from_name_msg");
	*(void**)(&get_exception_argument_null) = dlsym(imagehandle, "il2cpp_get_exception_argument_null");
	log(INFO, "Loaded: il2cpp_get_exception_argument_null");
	*(void**)(&format_exception) = dlsym(imagehandle, "il2cpp_format_exception");
	log(INFO, "Loaded: il2cpp_format_exception");
	*(void**)(&format_stack_trace) = dlsym(imagehandle, "il2cpp_format_stack_trace");
	log(INFO, "Loaded: il2cpp_format_stack_trace");
	*(void**)(&unhandled_exception) = dlsym(imagehandle, "il2cpp_unhandled_exception");
	log(INFO, "Loaded: il2cpp_unhandled_exception");
	*(void**)(&field_get_flags) = dlsym(imagehandle, "il2cpp_field_get_flags");
	log(INFO, "Loaded: il2cpp_field_get_flags");
	*(void**)(&field_get_name) = dlsym(imagehandle, "il2cpp_field_get_name");
	log(INFO, "Loaded: il2cpp_field_get_name");
	*(void**)(&field_get_parent) = dlsym(imagehandle, "il2cpp_field_get_parent");
	log(INFO, "Loaded: il2cpp_field_get_parent");
	*(void**)(&field_get_offset) = dlsym(imagehandle, "il2cpp_field_get_offset");
	log(INFO, "Loaded: il2cpp_field_get_offset");
	*(void**)(&field_get_type) = dlsym(imagehandle, "il2cpp_field_get_type");
	log(INFO, "Loaded: il2cpp_field_get_type");
	*(void**)(&field_get_value) = dlsym(imagehandle, "il2cpp_field_get_value");
	log(INFO, "Loaded: il2cpp_field_get_value");
	*(void**)(&field_get_value_object) = dlsym(imagehandle, "il2cpp_field_get_value_object");
	log(INFO, "Loaded: il2cpp_field_get_value_object");
	*(void**)(&field_has_attribute) = dlsym(imagehandle, "il2cpp_field_has_attribute");
	log(INFO, "Loaded: il2cpp_field_has_attribute");
	*(void**)(&field_set_value) = dlsym(imagehandle, "il2cpp_field_set_value");
	log(INFO, "Loaded: il2cpp_field_set_value");
	*(void**)(&field_static_get_value) = dlsym(imagehandle, "il2cpp_field_static_get_value");
	log(INFO, "Loaded: il2cpp_field_static_get_value");
	*(void**)(&field_static_set_value) = dlsym(imagehandle, "il2cpp_field_static_set_value");
	log(INFO, "Loaded: il2cpp_field_static_set_value");
	*(void**)(&field_set_value_object) = dlsym(imagehandle, "il2cpp_field_set_value_object");
	log(INFO, "Loaded: il2cpp_field_set_value_object");
	*(void**)(&gc_collect) = dlsym(imagehandle, "il2cpp_gc_collect");
	log(INFO, "Loaded: il2cpp_gc_collect");
	*(void**)(&gc_collect_a_little) = dlsym(imagehandle, "il2cpp_gc_collect_a_little");
	log(INFO, "Loaded: il2cpp_gc_collect_a_little");
	*(void**)(&gc_disable) = dlsym(imagehandle, "il2cpp_gc_disable");
	log(INFO, "Loaded: il2cpp_gc_disable");
	*(void**)(&gc_enable) = dlsym(imagehandle, "il2cpp_gc_enable");
	log(INFO, "Loaded: il2cpp_gc_enable");
	*(void**)(&gc_is_disabled) = dlsym(imagehandle, "il2cpp_gc_is_disabled");
	log(INFO, "Loaded: il2cpp_gc_is_disabled");
	*(void**)(&gc_get_used_size) = dlsym(imagehandle, "il2cpp_gc_get_used_size");
	log(INFO, "Loaded: il2cpp_gc_get_used_size");
	*(void**)(&gc_get_heap_size) = dlsym(imagehandle, "il2cpp_gc_get_heap_size");
	log(INFO, "Loaded: il2cpp_gc_get_heap_size");
	*(void**)(&gc_wbarrier_set_field) = dlsym(imagehandle, "il2cpp_gc_wbarrier_set_field");
	log(INFO, "Loaded: il2cpp_gc_wbarrier_set_field");
	*(void**)(&gchandle_new) = dlsym(imagehandle, "il2cpp_gchandle_new");
	log(INFO, "Loaded: il2cpp_gchandle_new");
	*(void**)(&gchandle_new_weakref) = dlsym(imagehandle, "il2cpp_gchandle_new_weakref");
	log(INFO, "Loaded: il2cpp_gchandle_new_weakref");
	*(void**)(&gchandle_get_target ) = dlsym(imagehandle, "il2cpp_gchandle_get_target ");
	log(INFO, "Loaded: il2cpp_gchandle_get_target ");
	*(void**)(&gchandle_free) = dlsym(imagehandle, "il2cpp_gchandle_free");
	log(INFO, "Loaded: il2cpp_gchandle_free");
	*(void**)(&unity_liveness_calculation_begin) = dlsym(imagehandle, "il2cpp_unity_liveness_calculation_begin");
	log(INFO, "Loaded: il2cpp_unity_liveness_calculation_begin");
	*(void**)(&unity_liveness_calculation_end) = dlsym(imagehandle, "il2cpp_unity_liveness_calculation_end");
	log(INFO, "Loaded: il2cpp_unity_liveness_calculation_end");
	*(void**)(&unity_liveness_calculation_from_root) = dlsym(imagehandle, "il2cpp_unity_liveness_calculation_from_root");
	log(INFO, "Loaded: il2cpp_unity_liveness_calculation_from_root");
	*(void**)(&unity_liveness_calculation_from_statics) = dlsym(imagehandle, "il2cpp_unity_liveness_calculation_from_statics");
	log(INFO, "Loaded: il2cpp_unity_liveness_calculation_from_statics");
	*(void**)(&method_get_return_type) = dlsym(imagehandle, "il2cpp_method_get_return_type");
	log(INFO, "Loaded: il2cpp_method_get_return_type");
	*(void**)(&method_get_declaring_type) = dlsym(imagehandle, "il2cpp_method_get_declaring_type");
	log(INFO, "Loaded: il2cpp_method_get_declaring_type");
	*(void**)(&method_get_name) = dlsym(imagehandle, "il2cpp_method_get_name");
	log(INFO, "Loaded: il2cpp_method_get_name");
	*(void**)(&method_get_from_reflection) = dlsym(imagehandle, "il2cpp_method_get_from_reflection");
	log(INFO, "Loaded: il2cpp_method_get_from_reflection");
	*(void**)(&method_get_object) = dlsym(imagehandle, "il2cpp_method_get_object");
	log(INFO, "Loaded: il2cpp_method_get_object");
	*(void**)(&method_is_generic) = dlsym(imagehandle, "il2cpp_method_is_generic");
	log(INFO, "Loaded: il2cpp_method_is_generic");
	*(void**)(&method_is_inflated) = dlsym(imagehandle, "il2cpp_method_is_inflated");
	log(INFO, "Loaded: il2cpp_method_is_inflated");
	*(void**)(&method_is_instance) = dlsym(imagehandle, "il2cpp_method_is_instance");
	log(INFO, "Loaded: il2cpp_method_is_instance");
	*(void**)(&method_get_param_count) = dlsym(imagehandle, "il2cpp_method_get_param_count");
	log(INFO, "Loaded: il2cpp_method_get_param_count");
	*(void**)(&method_get_param) = dlsym(imagehandle, "il2cpp_method_get_param");
	log(INFO, "Loaded: il2cpp_method_get_param");
	*(void**)(&method_get_class) = dlsym(imagehandle, "il2cpp_method_get_class");
	log(INFO, "Loaded: il2cpp_method_get_class");
	*(void**)(&method_has_attribute) = dlsym(imagehandle, "il2cpp_method_has_attribute");
	log(INFO, "Loaded: il2cpp_method_has_attribute");
	*(void**)(&method_get_flags) = dlsym(imagehandle, "il2cpp_method_get_flags");
	log(INFO, "Loaded: il2cpp_method_get_flags");
	*(void**)(&method_get_token) = dlsym(imagehandle, "il2cpp_method_get_token");
	log(INFO, "Loaded: il2cpp_method_get_token");
	*(void**)(&method_get_param_name) = dlsym(imagehandle, "il2cpp_method_get_param_name");
	log(INFO, "Loaded: il2cpp_method_get_param_name");
	*(void**)(&profiler_install) = dlsym(imagehandle, "il2cpp_profiler_install");
	log(INFO, "Loaded: il2cpp_profiler_install");
	*(void**)(&profiler_set_events) = dlsym(imagehandle, "il2cpp_profiler_set_events");
	log(INFO, "Loaded: il2cpp_profiler_set_events");
	*(void**)(&profiler_install_enter_leave) = dlsym(imagehandle, "il2cpp_profiler_install_enter_leave");
	log(INFO, "Loaded: il2cpp_profiler_install_enter_leave");
	*(void**)(&profiler_install_allocation) = dlsym(imagehandle, "il2cpp_profiler_install_allocation");
	log(INFO, "Loaded: il2cpp_profiler_install_allocation");
	*(void**)(&profiler_install_gc) = dlsym(imagehandle, "il2cpp_profiler_install_gc");
	log(INFO, "Loaded: il2cpp_profiler_install_gc");
	*(void**)(&profiler_install_fileio) = dlsym(imagehandle, "il2cpp_profiler_install_fileio");
	log(INFO, "Loaded: il2cpp_profiler_install_fileio");
	*(void**)(&profiler_install_thread) = dlsym(imagehandle, "il2cpp_profiler_install_thread");
	log(INFO, "Loaded: il2cpp_profiler_install_thread");
	*(void**)(&property_get_flags) = dlsym(imagehandle, "il2cpp_property_get_flags");
	log(INFO, "Loaded: il2cpp_property_get_flags");
	*(void**)(&property_get_get_method) = dlsym(imagehandle, "il2cpp_property_get_get_method");
	log(INFO, "Loaded: il2cpp_property_get_get_method");
	*(void**)(&property_get_set_method) = dlsym(imagehandle, "il2cpp_property_get_set_method");
	log(INFO, "Loaded: il2cpp_property_get_set_method");
	*(void**)(&property_get_name) = dlsym(imagehandle, "il2cpp_property_get_name");
	log(INFO, "Loaded: il2cpp_property_get_name");
	*(void**)(&property_get_parent) = dlsym(imagehandle, "il2cpp_property_get_parent");
	log(INFO, "Loaded: il2cpp_property_get_parent");
	*(void**)(&object_get_class) = dlsym(imagehandle, "il2cpp_object_get_class");
	log(INFO, "Loaded: il2cpp_object_get_class");
	*(void**)(&object_get_size) = dlsym(imagehandle, "il2cpp_object_get_size");
	log(INFO, "Loaded: il2cpp_object_get_size");
	*(void**)(&object_get_virtual_method) = dlsym(imagehandle, "il2cpp_object_get_virtual_method");
	log(INFO, "Loaded: il2cpp_object_get_virtual_method");
	*(void**)(&object_new) = dlsym(imagehandle, "il2cpp_object_new");
	log(INFO, "Loaded: il2cpp_object_new");
	*(void**)(&object_unbox) = dlsym(imagehandle, "il2cpp_object_unbox");
	log(INFO, "Loaded: il2cpp_object_unbox");
	*(void**)(&value_box) = dlsym(imagehandle, "il2cpp_value_box");
	log(INFO, "Loaded: il2cpp_value_box");
	*(void**)(&monitor_enter) = dlsym(imagehandle, "il2cpp_monitor_enter");
	log(INFO, "Loaded: il2cpp_monitor_enter");
	*(void**)(&monitor_try_enter) = dlsym(imagehandle, "il2cpp_monitor_try_enter");
	log(INFO, "Loaded: il2cpp_monitor_try_enter");
	*(void**)(&monitor_exit) = dlsym(imagehandle, "il2cpp_monitor_exit");
	log(INFO, "Loaded: il2cpp_monitor_exit");
	*(void**)(&monitor_pulse) = dlsym(imagehandle, "il2cpp_monitor_pulse");
	log(INFO, "Loaded: il2cpp_monitor_pulse");
	*(void**)(&monitor_pulse_all) = dlsym(imagehandle, "il2cpp_monitor_pulse_all");
	log(INFO, "Loaded: il2cpp_monitor_pulse_all");
	*(void**)(&monitor_wait) = dlsym(imagehandle, "il2cpp_monitor_wait");
	log(INFO, "Loaded: il2cpp_monitor_wait");
	*(void**)(&monitor_try_wait) = dlsym(imagehandle, "il2cpp_monitor_try_wait");
	log(INFO, "Loaded: il2cpp_monitor_try_wait");
	*(void**)(&runtime_invoke) = dlsym(imagehandle, "il2cpp_runtime_invoke");
	log(INFO, "Loaded: il2cpp_runtime_invoke");
	*(void**)(&runtime_invoke_convert_args) = dlsym(imagehandle, "il2cpp_runtime_invoke_convert_args");
	log(INFO, "Loaded: il2cpp_runtime_invoke_convert_args");
	*(void**)(&runtime_class_init) = dlsym(imagehandle, "il2cpp_runtime_class_init");
	log(INFO, "Loaded: il2cpp_runtime_class_init");
	*(void**)(&runtime_object_init) = dlsym(imagehandle, "il2cpp_runtime_object_init");
	log(INFO, "Loaded: il2cpp_runtime_object_init");
	*(void**)(&runtime_object_init_exception) = dlsym(imagehandle, "il2cpp_runtime_object_init_exception");
	log(INFO, "Loaded: il2cpp_runtime_object_init_exception");
	*(void**)(&runtime_unhandled_exception_policy_set) = dlsym(imagehandle, "il2cpp_runtime_unhandled_exception_policy_set");
	log(INFO, "Loaded: il2cpp_runtime_unhandled_exception_policy_set");
	*(void**)(&string_length) = dlsym(imagehandle, "il2cpp_string_length");
	log(INFO, "Loaded: il2cpp_string_length");
	*(void**)(&string_chars) = dlsym(imagehandle, "il2cpp_string_chars");
	log(INFO, "Loaded: il2cpp_string_chars");
	*(void**)(&string_new) = dlsym(imagehandle, "il2cpp_string_new");
	log(INFO, "Loaded: il2cpp_string_new");
	*(void**)(&string_new_len) = dlsym(imagehandle, "il2cpp_string_new_len");
	log(INFO, "Loaded: il2cpp_string_new_len");
	*(void**)(&string_new_utf16) = dlsym(imagehandle, "il2cpp_string_new_utf16");
	log(INFO, "Loaded: il2cpp_string_new_utf16");
	*(void**)(&string_new_wrapper) = dlsym(imagehandle, "il2cpp_string_new_wrapper");
	log(INFO, "Loaded: il2cpp_string_new_wrapper");
	*(void**)(&string_intern) = dlsym(imagehandle, "il2cpp_string_intern");
	log(INFO, "Loaded: il2cpp_string_intern");
	*(void**)(&string_is_interned) = dlsym(imagehandle, "il2cpp_string_is_interned");
	log(INFO, "Loaded: il2cpp_string_is_interned");
	*(void**)(&thread_current) = dlsym(imagehandle, "il2cpp_thread_current");
	log(INFO, "Loaded: il2cpp_thread_current");
	*(void**)(&thread_attach) = dlsym(imagehandle, "il2cpp_thread_attach");
	log(INFO, "Loaded: il2cpp_thread_attach");
	*(void**)(&thread_detach) = dlsym(imagehandle, "il2cpp_thread_detach");
	log(INFO, "Loaded: il2cpp_thread_detach");
	*(void**)(&thread_get_all_attached_threads) = dlsym(imagehandle, "il2cpp_thread_get_all_attached_threads");
	log(INFO, "Loaded: il2cpp_thread_get_all_attached_threads");
	*(void**)(&is_vm_thread) = dlsym(imagehandle, "il2cpp_is_vm_thread");
	log(INFO, "Loaded: il2cpp_is_vm_thread");
	*(void**)(&current_thread_walk_frame_stack) = dlsym(imagehandle, "il2cpp_current_thread_walk_frame_stack");
	log(INFO, "Loaded: il2cpp_current_thread_walk_frame_stack");
	*(void**)(&thread_walk_frame_stack) = dlsym(imagehandle, "il2cpp_thread_walk_frame_stack");
	log(INFO, "Loaded: il2cpp_thread_walk_frame_stack");
	*(void**)(&current_thread_get_top_frame) = dlsym(imagehandle, "il2cpp_current_thread_get_top_frame");
	log(INFO, "Loaded: il2cpp_current_thread_get_top_frame");
	*(void**)(&thread_get_top_frame) = dlsym(imagehandle, "il2cpp_thread_get_top_frame");
	log(INFO, "Loaded: il2cpp_thread_get_top_frame");
	*(void**)(&current_thread_get_frame_at) = dlsym(imagehandle, "il2cpp_current_thread_get_frame_at");
	log(INFO, "Loaded: il2cpp_current_thread_get_frame_at");
	*(void**)(&thread_get_frame_at) = dlsym(imagehandle, "il2cpp_thread_get_frame_at");
	log(INFO, "Loaded: il2cpp_thread_get_frame_at");
	*(void**)(&current_thread_get_stack_depth) = dlsym(imagehandle, "il2cpp_current_thread_get_stack_depth");
	log(INFO, "Loaded: il2cpp_current_thread_get_stack_depth");
	*(void**)(&thread_get_stack_depth) = dlsym(imagehandle, "il2cpp_thread_get_stack_depth");
	log(INFO, "Loaded: il2cpp_thread_get_stack_depth");
	*(void**)(&type_get_object) = dlsym(imagehandle, "il2cpp_type_get_object");
	log(INFO, "Loaded: il2cpp_type_get_object");
	*(void**)(&type_get_type) = dlsym(imagehandle, "il2cpp_type_get_type");
	log(INFO, "Loaded: il2cpp_type_get_type");
	*(void**)(&type_get_class_or_element_class) = dlsym(imagehandle, "il2cpp_type_get_class_or_element_class");
	log(INFO, "Loaded: il2cpp_type_get_class_or_element_class");
	*(void**)(&type_get_name) = dlsym(imagehandle, "il2cpp_type_get_name");
	log(INFO, "Loaded: il2cpp_type_get_name");
	*(void**)(&type_is_byref) = dlsym(imagehandle, "il2cpp_type_is_byref");
	log(INFO, "Loaded: il2cpp_type_is_byref");
	*(void**)(&type_get_attrs) = dlsym(imagehandle, "il2cpp_type_get_attrs");
	log(INFO, "Loaded: il2cpp_type_get_attrs");
	*(void**)(&type_equals) = dlsym(imagehandle, "il2cpp_type_equals");
	log(INFO, "Loaded: il2cpp_type_equals");
	*(void**)(&type_get_assembly_qualified_name) = dlsym(imagehandle, "il2cpp_type_get_assembly_qualified_name");
	log(INFO, "Loaded: il2cpp_type_get_assembly_qualified_name");
	*(void**)(&image_get_assembly) = dlsym(imagehandle, "il2cpp_image_get_assembly");
	log(INFO, "Loaded: il2cpp_image_get_assembly");
	*(void**)(&image_get_name) = dlsym(imagehandle, "il2cpp_image_get_name");
	log(INFO, "Loaded: il2cpp_image_get_name");
	*(void**)(&image_get_filename) = dlsym(imagehandle, "il2cpp_image_get_filename");
	log(INFO, "Loaded: il2cpp_image_get_filename");
	*(void**)(&image_get_entry_point) = dlsym(imagehandle, "il2cpp_image_get_entry_point");
	log(INFO, "Loaded: il2cpp_image_get_entry_point");
	*(void**)(&image_get_class_count) = dlsym(imagehandle, "il2cpp_image_get_class_count");
	log(INFO, "Loaded: il2cpp_image_get_class_count");
	*(void**)(&image_get_class) = dlsym(imagehandle, "il2cpp_image_get_class");
	log(INFO, "Loaded: il2cpp_image_get_class");
	*(void**)(&capture_memory_snapshot) = dlsym(imagehandle, "il2cpp_capture_memory_snapshot");
	log(INFO, "Loaded: il2cpp_capture_memory_snapshot");
	*(void**)(&free_captured_memory_snapshot) = dlsym(imagehandle, "il2cpp_free_captured_memory_snapshot");
	log(INFO, "Loaded: il2cpp_free_captured_memory_snapshot");
	*(void**)(&set_find_plugin_callback) = dlsym(imagehandle, "il2cpp_set_find_plugin_callback");
	log(INFO, "Loaded: il2cpp_set_find_plugin_callback");
	*(void**)(&register_log_callback) = dlsym(imagehandle, "il2cpp_register_log_callback");
	log(INFO, "Loaded: il2cpp_register_log_callback");
	*(void**)(&debugger_set_agent_options) = dlsym(imagehandle, "il2cpp_debugger_set_agent_options");
	log(INFO, "Loaded: il2cpp_debugger_set_agent_options");
	*(void**)(&is_debugger_attached) = dlsym(imagehandle, "il2cpp_is_debugger_attached");
	log(INFO, "Loaded: il2cpp_is_debugger_attached");
	*(void**)(&unity_install_unitytls_interface) = dlsym(imagehandle, "il2cpp_unity_install_unitytls_interface");
	log(INFO, "Loaded: il2cpp_unity_install_unitytls_interface");
	*(void**)(&custom_attrs_from_class) = dlsym(imagehandle, "il2cpp_custom_attrs_from_class");
	log(INFO, "Loaded: il2cpp_custom_attrs_from_class");
	*(void**)(&custom_attrs_from_method) = dlsym(imagehandle, "il2cpp_custom_attrs_from_method");
	log(INFO, "Loaded: il2cpp_custom_attrs_from_method");
	*(void**)(&custom_attrs_get_attr) = dlsym(imagehandle, "il2cpp_custom_attrs_get_attr");
	log(INFO, "Loaded: il2cpp_custom_attrs_get_attr");
	*(void**)(&custom_attrs_has_attr) = dlsym(imagehandle, "il2cpp_custom_attrs_has_attr");
	log(INFO, "Loaded: il2cpp_custom_attrs_has_attr");
	*(void**)(&custom_attrs_construct) = dlsym(imagehandle, "il2cpp_custom_attrs_construct");
	log(INFO, "Loaded: il2cpp_custom_attrs_construct");
	*(void**)(&custom_attrs_free) = dlsym(imagehandle, "il2cpp_custom_attrs_free");
	log(INFO, "Loaded: il2cpp_custom_attrs_free");

	// MANUALLY DEFINED CONST DEFINITIONS
	*(void**)(&class_get_type_const) = dlsym(imagehandle, "il2cpp_class_get_type");
	log(INFO, "Loaded: il2cpp_class_get_type CONST VERSION!");
	*(void**)(&class_get_name_const) = dlsym(imagehandle, "il2cpp_class_get_name");
	log(INFO, "Loaded: il2cpp_class_get_name CONST VERSION!");

	dlclose(imagehandle);
	initialized = true;
	log(INFO, "IL2CPP_Helper: Successfully loaded all il2cpp functions!");
}

Il2CppObject* IL2CPP_Helper::GetFieldObjectValue(Il2CppObject* instance, std::string_view fieldName) {
	Il2CppObject * out = nullptr;
	if (!instance) {
		log(ERROR, "IL2CPP_Helper: GetFieldValue: Null instance parameter!");
		return out;
	}
	auto klass = object_get_class(instance);
	if (!klass) {
		log(ERROR, "IL2CPP_Helper: GetFieldValue: Could not get object class!");
		return out;
	}
	auto field = class_get_field_from_name(klass, fieldName.data());
	if (!field) {
		log(ERROR, "IL2CPP_Helper: GetFieldValue: Could not find field %s in class %s (namespace '%s')!", fieldName.data(), class_get_name(klass), class_get_namespace(klass));
		return out;
	}
	return field_get_value_object(field, instance);
}

bool IL2CPP_Helper::SetFieldObjectValue(Il2CppObject* instance, std::string_view fieldName, Il2CppObject* value){
	if (!instance) {
		log(ERROR, "IL2CPP_Helper: SetFieldValue: Null instance parameter!");
		return false;
	}
	auto klass = object_get_class(instance);
	if (!klass) {
		log(ERROR, "IL2CPP_Helper: SetFieldValue: Could not get object class!");
		return false;
	}
	auto field = class_get_field_from_name(klass, fieldName.data());
	if (!field) {
		log(ERROR, "IL2CPP_Helper: SetFieldValue: Could not find field %s in class %s (namespace '%s')!", fieldName.data(), class_get_name(klass), class_get_namespace(klass));
		return false;
	}
	field_set_value_object(instance, field, value);
	return true;
}

bool IL2CPP_Helper::SetFieldValue(Il2CppObject* instance, std::string_view fieldName, void* value) {
	if (!instance) {
		log(ERROR, "IL2CPP_Helper: SetFieldValue: Null instance parameter!");
		return false;
	}
	auto klass = object_get_class(instance);
	if (!klass) {
		log(ERROR, "IL2CPP_Helper: SetFieldValue: Could not get object class!");
		return false;
	}
	auto field = class_get_field_from_name(klass, fieldName.data());
	if (!field) {
		log(ERROR, "IL2CPP_Helper: SetFieldValue: Could not find field %s in class %s (namespace '%s')!", fieldName.data(), class_get_name(klass), class_get_namespace(klass));
		return false;
	}
	field_set_value(instance, field, value);
	return true;
}

Il2CppClass* IL2CPP_Helper::GetClassFromName(const char* name_space, const char* type_name) {
	size_t assemb_count;
	const Il2CppAssembly** allAssemb = domain_get_assemblies(domain_get(), &assemb_count);
	// const Il2CppAssembly** allAssemb = il2cpp_domain_get_assemblies(il2cpp_domain_get(), &assemb_count);

	for (int i = 0; i < assemb_count; i++) {
		auto assemb = allAssemb[i];
		// auto img = il2cpp_assembly_get_image(assemb);
		// auto klass = il2cpp_class_from_name(img, name_space, type_name);
		auto img = assembly_get_image(assemb);
		if (!img) {
		    log(ERROR, "Assembly with name: %s has a null image!", assemb->aname.name);
		    continue;
		}
		auto klass = class_from_name(img, name_space, type_name);
		if (klass) {
		    return klass;
		}
	}
	log(ERROR, "IL2CPP_Helper: GetClassFromName: Could not find class with namepace: %s and name: %s", name_space, type_name);
	return nullptr;
}

Il2CppReflectionType* IL2CPP_Helper::MakeGenericType(Il2CppReflectionType* gt, Il2CppArray* types) {
	auto runtimeType = GetClassFromName("System", "RuntimeType");
	if (!runtimeType) {
		log(ERROR, "IL2CPP_Helper: MakeGenericType: Failed to get System.RuntimeType!");
		return nullptr;
	}
	auto makeGenericMethod = class_get_method_from_name(runtimeType, "MakeGenericType", 2);
	if (!makeGenericMethod) {
		log(ERROR, "IL2CPP_Helper: MakeGenericType: Failed to get RuntimeType.MakeGenericType(param1, param2) method!");
		return nullptr;
	}

	Il2CppException* exp = nullptr;
	void* params[] = {reinterpret_cast<void*>(gt), reinterpret_cast<void*>(types)};
	auto genericType = runtime_invoke(makeGenericMethod, nullptr, params, &exp);
	if (exp) {
		log(ERROR, "IL2CPP_Helper: MakeGenericType: Failed with exception: %s", ExceptionToString(exp).c_str());
		return nullptr;
	}
	return reinterpret_cast<Il2CppReflectionType*>(genericType);
}

Il2CppClass* IL2CPP_Helper::MakeGeneric(const Il2CppClass* klass, std::initializer_list<const Il2CppClass*> args) {
	auto typ = GetClassFromName("System", "Type");
	if (!typ) {
		return nullptr;
	}
	auto getType = class_get_method_from_name(typ, "GetType", 1);
	if (!getType) {
		log(ERROR, "IL2CPP_Helper: MakeGeneric: Failed to get System.Type.GetType(param1) method!");
		return nullptr;
	}
 
	auto klassType = type_get_object(class_get_type_const(klass));
	if (!klassType) {
		log(ERROR, "IL2CPP_Helper: MakeGeneric: Failed to get class type object!");
		return nullptr;
	}
 
	// Call Type.MakeGenericType on it
	auto a = array_new_specific(typ, args.size());
	if (!a) {
		log(ERROR, "IL2CPP_Helper: MakeGeneric: Failed to make new array with length: %zu", args.size());
		return nullptr;
	}
 
	int i = 0;
	for (auto arg : args) {
		auto t = class_get_type_const(arg);
		auto o = type_get_object(t);
		if (!o) {
		log(ERROR, "IL2CPP_Helper: MakeGeneric: Failed to get type for %s", class_get_name_const(arg));
		return nullptr;
		}
		il2cpp_array_set(a, void*, i, reinterpret_cast<void*>(o));
		i++;
	}

	auto reflection_type = MakeGenericType(reinterpret_cast<Il2CppReflectionType*>(klassType), a);
	if (!reflection_type) {
		log(ERROR, "IL2CPP_Helper: MakeGeneric: Failed to MakeGenericType from Il2CppReflectionType and Il2CppArray!");
		return nullptr;
	}

	auto ret = class_from_system_type(reinterpret_cast<Il2CppReflectionType*>(reflection_type));
	if (!ret) {
		log(ERROR, "IL2CPP_Helper: MakeGeneric: Failed to get class from Il2CppReflectionType!");
		return nullptr;
	}
	log(DEBUG, "IL2CPP_Helper: MakeGeneric: returning %s", class_get_name(ret));
	return ret;
}