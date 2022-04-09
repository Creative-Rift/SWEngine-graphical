## CMAKE VAR
## <=====================================>
set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/ )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/ )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/ )
## <=====================================>

## SOURCE FOLDERS
set( SRC_FOLDERS
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/components/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/components/transform/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/managers/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/resources/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/utils/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/event/
        )
## INCLUDE FOLDERS
set( INC_FOLDERS
        ${CMAKE_SOURCE_DIR}/libraries/
        ${CMAKE_SOURCE_DIR}/libraries/core/
        ${CMAKE_SOURCE_DIR}/libraries/freetype/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/components/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/dependencies/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/managers/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/resources/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/utils/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/event/
        )

message( DEBUG "[SWEngine-OpenGL] Build type set to ${CMAKE_BUILD_TYPE}")


if (WIN32)
    message("[SWEngine-OpenGL] Windows system detected, prepare project...")
    include(.cmake_windows.cmake)
elseif(UNIX)
    message("[SWEngine-OpenGL] Linux system detected, prepare project...")
    include(.cmake_linux.cmake)
else()
    message(FATAL_ERROR "System not supported!")
endif()
