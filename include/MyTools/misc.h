//
// Created by Yoo Cherry on 25.09.24.
//

#ifndef MISC_H
#define MISC_H
#include <string>


namespace MyTools::Misc {

    // Getting the source directory provided by the CMakeLists.txt
    inline std::string GetSourceDir(){return {SOURCE_DIR};};

}

#endif //MISC_H
