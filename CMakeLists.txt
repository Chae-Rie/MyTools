cmake_minimum_required(VERSION 3.5)

project(
        MyTools
        VERSION 1.0.1
        DESCRIPTION "static lib for own stuff to carry around"
        LANGUAGES CXX
)

# Include standard installation directories
include(GNUInstallDirs)

# Define constants for magic strings to improve code readability and maintainability
set(LIB_DIR "lib")  # Directory for library files (though not used in this snippet)
set(CMAKE_DIR "cmake")  # Directory for CMake files

# Define the installation directory for CMake config files and store in cache
set(MYTOOLS_LIB_INSTALL_CMAKEDIR ${CMAKE_DIR} CACHE PATH "Installation directory for config-file package cmake files")

# resolve some important paths:
#       - Some of the packages are installed on my dev machine, like QT... I won't be setting them into the project
#       - Some of the packages are going to be resolved automatically, when I specify the vcpkg-toolchain
#       - Some of the packages are NOT going to be resolved automatically, so I just specify the path manually...
# ----------------------------------------------------------------------------------------------------------------------
# First get the vcpkg-toolchain file and use it for all the packages installed
set(CMAKE_TOOLCHAIN_FILE
        ${CMAKE_CURRENT_LIST_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING
        "Vcpkg toolchain file"
)

# the vcpkg_installed-directory is the one where installed packages in the manifest mode are going to be placed
# this is highly propretary because I hardcode the OS, but this will be a problem of another day. The share-directory
# is working fine.
set(nlohmann_json_DIR "${CMAKE_CURRENT_LIST_DIR}/vcpkg_installed/arm64-osx/share/nlohmann_json")

# Set the library name
set(LIB_NAME MyTools_lib)
# Debug message to display the name of the library
message("The name of the lib: ${LIB_NAME}")

# Add a static library with the specified name
add_library(${LIB_NAME} STATIC)

find_package(nlohmann_json CONFIG REQUIRED)

# Specify the source files for the library
target_sources(${LIB_NAME} PRIVATE
        src/fileparser.cpp
        src/jsonmanager.cpp
        src/misc.cpp
)

target_link_libraries(${LIB_NAME} PRIVATE nlohmann_json::nlohmann_json)

# Specify include directories for the library
target_include_directories(${LIB_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/MyTools/include>
)

# Specify C++ standard version for the library
target_compile_features(${LIB_NAME} PUBLIC cxx_std_17)

# Define a preprocessor macro with the source directory
add_compile_definitions(SOURCE_DIR="${CMAKE_SOURCE_DIR}")

# Installation rules for the library
install(TARGETS ${LIB_NAME}
        EXPORT MyTools_lib_export
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Install header files from the include directory
install(
        DIRECTORY ${PROJECT_SOURCE_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Export the library configuration
install(EXPORT MyTools_lib_export
        FILE MyTools_lib-config.cmake
        NAMESPACE MyTools_lib::
        DESTINATION ${MYTOOLS_LIB_INSTALL_CMAKEDIR}
)

# Include helper module for packaging config
include(CMakePackageConfigHelpers)

# Write package version file with compatibility set to the same major version
write_basic_package_version_file(
        "MyTools_lib-config-version.cmake"
        COMPATIBILITY SameMajorVersion
)

# Install the package version file
install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/MyTools_lib-config-version.cmake"
        DESTINATION "${MYTOOLS_LIB_INSTALL_CMAKEDIR}"
)