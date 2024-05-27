# How to install

```C++
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=../install
cmake --build .
cmake --install .

```

Anschließend ist sind die MyTools systemweit installiert und können via FindPackage()
in neue Projekte eingebunden werden.
Beachte, dass es sich um eine statisch gelinkte Bibliothek handelt.


Struktur:
```
NewProject/
├── CMakeLists.txt
└── main.cpp
```


Die CMakeLists.txt in dem neuen Projekt könnte wie folgt aussehen:

```CMake
cmake_minimum_required(VERSION 3.10)
project(NewProject LANGUAGES CXX)

# Find the installed MyTools package
find_package(MyTools REQUIRED)

add_executable(NewProject main.cpp)
target_link_libraries(NewProject MyTools::MyTools)

```
