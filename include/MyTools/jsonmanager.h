//
// Created by Yoo Cherry on 24.09.24.
// This file is based on the json-library of niels lohmann abrv. nlohmann https://github.com/nlohmann/json
//

#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace MyTools {
    namespace JsonManager {
        // code
        json ReadFile(const std::string fileName);

    }
}
#endif //JSONMANAGER_H
