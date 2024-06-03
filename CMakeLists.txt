cmake_minimum_required(VERSION 3.5)

project(
    MyTools
    VERSION 1.0.1
    DESCRIPTION "static lib for own stuff to carry around"
    LANGUAGES CXX
)

# Das definiert verschiedene InstallPaths und Variablen die ich brauche
# wie z.B.: ${CMAKE_INSTALL_INCLUDEDIR}
include(GNUInstallDirs)

# Setzt die Variable 'Mytools_INSTALL_CMAKEDIR' auf 'cmake' und speichert sie im CMake-Cache.
# Der Typ der Variable ist 'PATH', was bedeutet, dass der Wert als Pfad interpretiert wird.
# Die Beschreibung "Installation directory for config-file package cmake files" erklärt, dass
# diese Variable das Installationsverzeichnis für CMake-Konfigurationsdateien des Pakets angibt.
set(MyTools_lib_INSTALL_CMAKEDIR cmake CACHE PATH "Installation directory for config-file package cmake files")

# Statische Bibliothek daraus bauen
add_library(MyTools_lib STATIC )

# Sources spezifizieren, alternative zu set(SOURCES)
target_sources(MyTools_lib PRIVATE src/mytools.cpp)



# Include-Directories spezifizieren, damit ich #include <header.h> nutzen kann
# Die Verzeichnisse sollen nur inkludiert werden, wenn gebaut wird, deswegen
# build_interface
target_include_directories(MyTools_lib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/MyTools/include>
)


# Alternative zu set (CMAKE_CXX_STANDARD 17) & set (CMAKE_CXX_STANDARD_REQUIRED ON) nur,
# dass es auf die Targets bezogen werden kann und ein one-liner ist
target_compile_features(MyTools_lib PUBLIC cxx_std_17)


# MyTools_lib installierbar machen -> nur der Output vom target wird installiert, also kontrolliert.
# EXPORT MyTools_lib_export: Dieser Parameter ordnet die installierten Dateien der angegebenen Targets
# (in diesem Fall MyTools_lib) einem Exportnamen (MyTools_lib_export) zu. Dies bedeutet,
# dass die Informationen über das Target MyTools_lib unter diesem Exportnamen gespeichert werden.
install(TARGETS MyTools_lib
        EXPORT MyTools_lib_export
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
# Ausgeben zu Debugzwecken
message(Füge diesen Pfad zu den INTERFACE_INCLUDE_DIRECTORIES hinzu: ${CMAKE_INSTALL_INCLUDEDIR})

# Headerfiles installieren
# Weil ich sie nicht in dem Output definiert habe, muss ich sie seperat installieren
install (
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)



# Generate the required import code for the content in <export name>
# into ch4_ex05_lib-config.cmake CMake file. Prefix all target names with
# ch4_05_lib:: while doing so (NAMESPACE). DESTINATION argument recommended to be a path
# that will be picked by find_package() by default ('cmake' in our example).
install(EXPORT MyTools_lib_export
        FILE MyTools_lib-config.cmake
        NAMESPACE MyTools_lib::
        DESTINATION ${MyTools_lib_INSTALL_CMAKEDIR}
)

# Defines write_basic_package_version_file
include(CMakePackageConfigHelpers)



write_basic_package_version_file(
  "MyTools_lib-config-version.cmake"
  # Package compatibility strategy. SameMajorVersion is essentially `semantic versioning`.
  COMPATIBILITY SameMajorVersion
)

# Steht zusammen mit dem MyTools_lib-config-version.cmake
install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/MyTools_lib-config-version.cmake"
  DESTINATION "${MyTools_lib_INSTALL_CMAKEDIR}"
)
