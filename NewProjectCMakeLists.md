Die CMakeLists.txt für das Projekt, was die MyTools Bibliothek als CMake-Paket hinzufügt.
Hierbei wird die dementsprechende Config-Datei verwendet. 

Besonders wichtig ist hier die Zeile:
`set(MyTools_lib_DIR "/tmp/install-test/cmake")` die auf das Verzeichnis zeigt
was die Config und cmake Files, die beim Installieren erzeugt worden sind.

```CMake
cmake_minimum_required(VERSION 3.5)

project(TestProjectForOwnPackage LANGUAGES CXX)

project(
  TestProjectForOwnPackage
  VERSION 1.0
  DESCRIPTION "Out ot project config-file package consumer"
  LANGUAGES CXX)

if(NOT PROJECT_IS_TOP_LEVEL)
  message(FATAL_ERROR "project is intended to be a standalone, top-level project. Do not vendor this directory.")
endif()

set(MyTools_lib_DIR "/tmp/install-test/cmake")
find_package(MyTools_lib 1 CONFIG REQUIRED)

add_executable(TestProjectForOwnPackage main.cpp)

target_compile_features(TestProjectForOwnPackage PRIVATE cxx_std_17 )

target_link_libraries(TestProjectForOwnPackage PRIVATE MyTools_lib::MyTools_lib)

```

