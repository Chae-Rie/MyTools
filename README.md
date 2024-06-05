# Purpose of this repo
MyTools soll eine Ansammlung an einfachen Hilfsfunktionen beinhalten, die ich mit 
CMake einfach hinzufügen kann.

Im Idealfall reicht ein Call auf `find_package()`, `target_link_libraries()` in Kombination mit
einem `set(MyTools_lib_DIR <path>)`-Call um die Bibliothek zu nutzen.

# How to install

```C++
mkdir build
cmake -S . -B ./build
cmake --build ./build
```

Dann in einen eigenen Ordner installieren, wie z.B.: tmp/install auf macos
`--prefix` gibt an, dass wir in einen bestimmten Ordner installieren

```
cmake --install ./build  --prefix /Users/yoocherry/dev/thirdparty/cmake_packages/MyTools-install
```


Anschließend sind die MyTools in dem jeweiligen Verzeichnis installiert und können via FindPackage()
in neue Projekte eingebunden werden.

Beachte, dass es sich um eine statisch gelinkte Bibliothek handelt.


Struktur:
```
NewProject/
├── CMakeLists.txt
└── main.cpp
```

Siehe `NewProjectCMakeLists.md` für ein Beispiel wie die dementsprechende CMakeLists.txt
im neuen Projekt aussehen könnte.


# Additional Infos
