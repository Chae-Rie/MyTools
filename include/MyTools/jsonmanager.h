//
// Created by Yoo Cherry on 24.09.24.
// This file is based on the json-library of niels lohmann abrv. nlohmann https://github.com/nlohmann/json
//

#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <nlohmann/json.hpp>
#include <string>
using json = nlohmann::json;

    namespace MyTools::JsonManager {
        json ReadFile(const std::string& fileName);
        json GetObjectFromArray(const json& config, const std::string& key, int index = 0);
        std::string GetStringValue(const json& jsonObj, const std::string& key, const std::string& defaultValue = "");
    }

#endif //JSONMANAGER_H
