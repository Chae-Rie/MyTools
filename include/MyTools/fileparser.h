#ifndef FILEPARSER_H

#define FILEPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>


// ---------------
namespace MyTools{

    namespace Fileparser{

    // Nutze die in der CMakeLists.txt formulierte Info über das Source-Directory
    // trage das hier ein: add_compile_definitions(SOURCE_DIR="${CMAKE_SOURCE_DIR}"))
    inline std::string GetSourceDirPath(){return std::string(SOURCE_DIR);};
    std::unordered_map<std::string, std::string> parseEnvFile(const std::string& filePath);
    std::string getValueByKey(const std::unordered_map<std::string, std::string>& envMap, const std::string& key);

    }

}

#endif //FILEPARSER_H
