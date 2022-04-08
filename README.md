<p align="center">
    <img src=".github/resources/images/logo.png"
        height="200">
</p>

# SWEngine-OpenGLModule ⚓

## Description

This module built with OpenGL and GLFW provide several components to build your graphical project.
OpenGLModule support Linux and Windows platform. To create a graphical project you have to link all required library
with this module and your project. Check our [documentation](https://docs.creative-rift.com/) for more information.

## Installation
Just clone the project, then do `./check_for_update -i` (only on Linux)

## Compilation

Linux :
* Do `./check_for_update -b`

Windows:
* `mkdir build`
* `cd build`
* `cmake -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Debug/Release ..`
* `cmake --build .`

The default output is in `out/`

## Documentation

You can visit our [documentation](https://docs.creative-rift.com/graphical-module/opengl) for more information.

## Example

We have one example with this Module check out [Icaribus](http://creative-rift.com/icaribus)

## Author

Made on out ship with :heart: \
[Guillaume Soisson](https://github.com/Alvarwow69) \
[Guillaume Debard](https://github.com/SheItoon)