# How to install

```C++
mkdir build
cd build
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


