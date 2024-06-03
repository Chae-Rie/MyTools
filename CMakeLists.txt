cmake_minimum_required(VERSION 3.14)

project(MyTools LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header Files

# Veraltet
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCES
    src/mytools.cpp
)

# Erstellen der statisch gelinkten Bibliothek
add_library(MyTools STATIC ${SOURCES})


# Installation rules
install(TARGETS MyTools
        EXPORT MyToolsTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin)


install(DIRECTORY include/ DESTINATION include)


install(EXPORT MyToolsTargets
        FILE MyToolsTargets.cmake
        DESTINATION lib/cmake/MyTools)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/MyToolsConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/MyToolsConfig.cmake
    INSTALL_DESTINATION lib/cmake/MyTools
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/MyToolsConfig.cmake
    DESTINATION lib/cmake/MyTools
)

#target_compile_definitions(MyTools PRIVATE MYTOOLS_LIBRARY)
