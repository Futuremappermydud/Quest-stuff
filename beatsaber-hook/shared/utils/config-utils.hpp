#ifndef CONFIG_UTILS_H
#define CONFIG_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "rapidjson-utils.hpp"
#include "../../rapidjson/include/rapidjson/document.h"
#include "../../rapidjson/include/rapidjson/allocators.h"

// Provides helper functions for configuration.
typedef rapidjson::GenericDocument<rapidjson::UTF8<>, rapidjson::CrtAllocator> ConfigDocument;
typedef rapidjson::GenericValue<rapidjson::UTF8<>, rapidjson::CrtAllocator> ConfigValue;
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

#endif /* CONFIG_UTILS_H */
