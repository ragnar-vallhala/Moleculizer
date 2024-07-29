# Moleculizer
### Molecule Visualisation Tool 

This is a tool to open .xyz files and present them in 3D. You can translate, rotate and scale the model. The application holds the state that it was in the previous session. Hence, when you reopen it again it will be in same state.

## Language
__C++__ is used with OOP. The main reason to choose C++ is that it has all the necessary libraries and supports available.

## Dependencies
All the dependencies are built into separate libs and linked staticlly. _( __Except__: ImGui is directly integrated in the project files)_
- OpenGL _(for graphics rendering)_
- GLFW _(for window and input management)_
- ImGui _(for showing UI)_
- GLM _(for graphics mathematical calculations)

## Building the project
The repository comes with __CMake__ configured. Thus, you need CMake to build this project.

```shell
cmake -S . -B build
```
```shell
cmake --build build -j
```
```-j``` flag is given to build in parallel you can ommit it if you wish to. By default it utilizes 16 parallel jobs. You can change number by changing ```CMAKE_BUILD_PARALLEL_LEVEL``` variable in the _CMakeLists.txt_.\
Once built successfully you can run the executable as
```shell
cd build/Debug
./mol.exe
```
## Application
You can open new molecules from ```open``` option in the ```file``` menu.
![Screenshot of the application](res\Moleculizer.png)

## Note
The current version is built with 
1. ```CXX20``` using ```msbuild``` and ```Visual Studio 17 2022``` generator. 
2. ```CXX17``` using ```GNU``` and ```Unix Makefiles``` generator.
Kindly, check if it can be build by other configurations too.