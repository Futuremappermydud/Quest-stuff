#ifndef CONFIG_UTILS_H
#define CONFIG_UTILS_H
// Provides helper functions for configuration.

#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils-functions.h"
#include "rapidjson-utils.hpp"

// typedef rapidjson::GenericDocument<rapidjson::UTF8<>, rapidjson::CrtAllocator> ConfigDocument;
// typedef rapidjson::GenericValue<rapidjson::UTF8<>, rapidjson::CrtAllocator> ConfigValue;
typedef rapidjson::Document ConfigDocument;
typedef rapidjson::Value ConfigValue;
// You are responsible for Loading and Writing to it as necessary.
class Configuration {
public:    
    static ConfigDocument config;
    // Loads JSON config
    static void Load();
    // Reloads JSON config
    static void Reload();
    // Writes JSON config
    static void Write();
};

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

#endif /* CONFIG_UTILS_H */
