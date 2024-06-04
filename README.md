# How to install

```C++
mkdir build
cmake -S . -B ./build
cmake --build ./build
```

Dann in einen eigenen Ordner installieren, wie z.B.: tmp/install auf macos
`--prefix` gibt an, dass wir in einen bestimmten Ordner installieren

```
cmake --install ./build  --prefix /tmp/install
```

Anschließend ist sind die MyTools systemweit installiert und können via FindPackage()
in neue Projekte eingebunden werden.
**ABER** weil Du das Projekt in einem best
Beachte, dass es sich um eine statisch gelinkte Bibliothek handelt.


Struktur:
```
NewProject/
├── CMakeLists.txt
└── main.cpp
```


Die CMakeLists.txt in dem neuen Projekt könnte wie folgt aussehen:


