//
// Created by Yoo Cherry on 24.09.24.
//
#include "../include/MyTools/jsonmanager.h"
#include <sstream>
#include <fstream>
#include <iostream>

namespace MyTools::JsonManager {
    // Reads a file from the given path and uses the returned stream to pollute a json-object with it
    json ReadFile(const std::string &fileName) {
        std::ifstream fileStream(fileName);
        if (!fileStream.is_open()) {
            throw std::runtime_error("Could not open file " + fileName);
        }

        json configData;
        try {
            fileStream >> configData;
        } catch (const json::parse_error &ex) {
            std::cerr << "Parse error at byte " << ex.byte << ": " << ex.what() << std::endl;
            throw;
        }
        // explicitly close the file stream
        fileStream.close();

        return configData;
    }

    // Returns a smaller json object from an array with an index
    json GetObjectFromArray(const json &config, const std::string &key, int index) {
        if (config.contains(key) && config[key].is_array() && config[key].size() > index) {
            return config[key][index];
        }
        std::cerr << "Error: '" << key << "' is missing or not an array." << std::endl;
        return json();
    }

    // Returns a simple value under the given key, defaultvalue is nothing, to make it expectable
    std::string GetStringValue(const json &jsonObj, const std::string &key, const std::string &defaultValue ){
        return jsonObj.value(key, defaultValue);
    }
}
