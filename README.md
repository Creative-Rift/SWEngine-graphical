<p align="center">
    <img src=".github/resources/images/logo.png"
        style="height: 200px">
</p>

# ShipWreck Engine OpenGLModule (Archived ⚓

## Important
This project is now archived. Why? because there are too mush architectural issue that affect the future update. \
This is **not** the end of the project you can follow the new version [here](https://github.com/Creative-Rift/SWEngine). \
This new project contain a better documentation, improved architecture for GameObject, Component, ... and now fully opensource.

## Description

ShipWreck Engine is based on [OpenGL](https://www.opengl.org/) 4.6 and [GLFW](https://www.glfw.org/). \
The goal is to provide several tools that allow to create easily games, animation, render, ... \
Check our [documentation](https://docs.creative-rift.com/) for more information.

## Compilation

To build the project simply use these commands:

```bash
mkdir build ; cd build
cmake -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=[Debug/Release] ..
cmake --build . --target SWEngine-OpenGLModule --config [Debug/Release]
```

The output program will be in `out/[Debug/Release]/SWEngine-OpenGLModule.dll`

## Documentation

You can visit our [documentation](https://docs.creative-rift.com/graphical-module/opengl) for more information.

## Example

We have one example with this Module check out [Incaribus](https://github.com/Creative-Rift/Incaribus)

## Author

Made on our ship with :heart: \
[Guillaume Soisson](https://github.com/Alvarwow69)
