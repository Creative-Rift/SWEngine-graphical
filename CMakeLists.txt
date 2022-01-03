## CMAKE VAR
## <=====================================>
cmake_minimum_required( VERSION 3.18...3.22 )
set( CMAKE_BUILD_TYPE Release ) # Release / RelWithDebInfo / Debug
set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/ )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/ )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/ )
## <=====================================>

project( SWEngine-OpenGLModule
        VERSION
        0.1
        DESCRIPTION
        "Graphical module for ShipwreckEngine"
        )

if (WIN32)
    message("Windows system detected, prepare project...")
    include(.cmake_windows.cmake)
elseif(UNIX)
    message("Linux system detected, prepare project...")
    include(.cmake_windows.cmake)
else()
    message(FATAL_ERROR "System not supported!")
endif()