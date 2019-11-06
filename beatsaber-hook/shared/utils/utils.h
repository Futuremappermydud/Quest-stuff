#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "typedefs.h"
#include "config-utils.hpp"
#include "rapidjson-utils.hpp"
#include "il2cpp-helper.hpp"
#include "utils-functions.h"
#include "../inline-hook/And64InlineHook.hpp"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

long long getRealOffset(void* offset);
long long baseAddr(const char *soname);
long long FindPattern(long long dwAddress, long long dwLen, char* pattern);
#define MAKE_HOOK(name, addr, retval, ...) \
void* addr_ ## name = (void*) addr; \
retval (*name)(__VA_ARGS__) = NULL; \
retval hook_ ## name(__VA_ARGS__) 

#define MAKE_HOOK_OFFSETLESS(name, retval, ...) \
retval (*name)(__VA_ARGS__) = NULL; \
retval hook_ ## name(__VA_ARGS__)

#define MAKE_HOOK_NAT(name, addr, retval, ...) \
void* addr_ ## name = (void*) addr; \
retval (*name)(__VA_ARGS__) = NULL; \
retval hook_ ## name(__VA_ARGS__) 

#ifdef __aarch64__

#define INSTALL_HOOK(name) \
log(INFO, "Installing 64 bit hook!"); \
A64HookFunction((void*)getRealOffset(addr_ ## name),(void*) hook_ ## name, (void**)&name); \

#define INSTALL_HOOK_DIRECT(name, addr) \
log(INFO, "Installing 64 bit direct hook!"); \
A64HookFunction(reinterpret_cast<void*>(addr),(void*) hook_ ## name, (void**)&name); \

#define INSTALL_HOOK_OFFSETLESS(name, methodInfo) \
log(INFO, "Installing 64 bit offsetless hook!"); \
A64HookFunction((void*)methodInfo->methodPointer,(void*) hook_ ## name, (void**)&name); \

#define INSTALL_HOOK_NAT(name) \
A64HookFunction((void*)(addr_ ## name),(void*) hook_ ## name, (void**)&name); \


#else

#define INSTALL_HOOK(name) \
log(INFO, "Installing 32 bit hook!");\
registerInlineHook((uint32_t)getRealOffset(addr_ ## name), (uint32_t)hook_ ## name, (uint32_t **)&name);\
inlineHook((uint32_t)getRealOffset(addr_ ## name));\

#define INSTALL_HOOK_OFFSETLESS(name, methodInfo) \
log(INFO, "Installing 32 bit offsetless hook!");\
registerInlineHook((uint32_t)methodInfo->methodPointer, (uint32_t)hook_ ## name, (uint32_t **)&name);\
inlineHook((uint32_t)methodInfo->methodPointer);\

#define INSTALL_HOOK_NAT(name) \
registerInlineHook((uint32_t)(addr_ ## name), (uint32_t)hook_ ## name, (uint32_t **)&name);\
inlineHook((uint32_t)(addr_ ## name));\

#endif

// OFFSETS

// DEPRECATED
// // Create an object using il2cpp_object_new offset
// #define OBJ_CREATOR_OFFSET 0x308740
// // GameObject.ctor() offset
// #define GO_CTOR_OFFSET 0xC86558
// // GameObject type offset
// #define GO_TYPE_OFFSET 0x19C7998
// // System.GetType(string typeName) offset
// #define GET_TYPE_OFFSET 0x104B254
// // System.String.Concat(cs_string* left, cs_string* right) offset
// #define CONCAT_STRING_OFFSET 0x972F2C
// // System.String.CreateString(char* array, int start, int length) offset
// #define CREATE_STRING_OFFSET 0x9831BC
// // System.String.FastAllocateString(int length) offset
// #define ALLOCATE_STRING_OFFSET 0x97A704
// // System.String.Substring(cs_string* this, int start, int length) offset
// #define SUBSTRING_OFFSET 0x96EBEC
// // System.String.Replace(cs_string* original, cs_string* old, cs_string* new) offset
// #define STRING_REPLACE_OFFSET 0x97FF04

// SETTINGS

// ParseError is thrown when failing to parse a JSON file
typedef enum ParseError {
    PARSE_ERROR_FILE_DOES_NOT_EXIST = -1
} ParseError_t;

// WriteError is thrown when failing to create a file
typedef enum WriteError {
    WRITE_ERROR_COULD_NOT_MAKE_FILE = -1
} WriteError_t;

// JSON Parse Errors
typedef enum JsonParseError {
    JSON_PARSE_ERROR = -1
} JsonParseError_t;

// CONFIG

#define CONFIG_PATH "/sdcard/Android/data/com.beatgames.beatsaber/files/mod_cfgs/"

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* UTILS_H_INCLUDED */