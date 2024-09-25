#ifndef FILEPARSER_H

#define FILEPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>


// ---------------
    namespace MyTools::Fileparser{
    std::unordered_map<std::string, std::string> parseEnvFile(const std::string& filePath);
    std::string getValueByKey(const std::unordered_map<std::string, std::string>& envMap, const std::string& key);

    }

#endif //FILEPARSER_H
