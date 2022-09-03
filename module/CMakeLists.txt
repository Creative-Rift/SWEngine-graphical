## CMAKE VAR
## <=====================================>
set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/ )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/ )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/ )
## <=====================================>

set(PREFIX_MESSAGE "[SWEngine-OpenGL] ")

## SOURCE FOLDERS
set( SRC_FOLDERS
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/components/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/components/base/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/components/transform/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/event/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/exception/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/gameObject/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/managers/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/resources/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/scenes_manager/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/scenes_manager/scene/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/utils/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/window/
        )
## INCLUDE FOLDERS
set( INC_FOLDERS
        ${CMAKE_SOURCE_DIR}/libraries/
        ${CMAKE_SOURCE_DIR}/libraries/freetype/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/components/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/components/base/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/dependencies/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/event/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/exception/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/gameObject/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/managers/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/managers/base/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/resources/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/scenes_manager/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/scenes_manager/scene/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/utils/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/window/
        )

message(${PREFIX_MESSAGE} "Build type set to: " ${CMAKE_BUILD_TYPE})
message(${PREFIX_MESSAGE} "Current cmake location: " ${CMAKE_CURRENT_SOURCE_DIR})
message(${PREFIX_MESSAGE} "Project location: " ${CMAKE_SOURCE_DIR})


if (WIN32)
    message(${PREFIX_MESSAGE} "Windows system detected, prepare project...")
    include(.cmake_windows.cmake)
elseif(UNIX)
    message(${PREFIX_MESSAGE} "Linux system detected, prepare project...")
    include(.cmake_linux.cmake)
else()
    message(FATAL_ERROR "System not supported!")
endif()
