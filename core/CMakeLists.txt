## CMAKE VAR
## <=====================================>
set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/ )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/ )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/ )
## <=====================================>

set(PREFIX_MESSAGE "[SWEngine-Core] ")

## SOURCE FOLDERS
set( SRC_FOLDERS
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/engine/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/event/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/scene/
        )
## INCLUDE FOLDERS
set( INC_FOLDERS
        ${CMAKE_SOURCE_DIR}/libraries/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/component/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/engine/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/entity/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/error/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/event/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/manager/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/module/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/resources/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/scene/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/utils/
        ${CMAKE_CURRENT_SOURCE_DIR}/
        )

message(${PREFIX_MESSAGE} "Build type set to: " ${CMAKE_BUILD_TYPE})

if (WIN32)
    message(${PREFIX_MESSAGE} "Windows system detected prepare project...")
    include(.cmake_windows.cmake)
elseif(UNIX)
    message(${PREFIX_MESSAGE} "Unix system detected prepare project...")
    include(.cmake_linux.cmake)
endif()

if (${CMAKE_BUILD_TYPE} MATCHES Debug)
    set_target_properties(${EXEC} PROPERTIES
            DEBUG_POSTFIX "d")
endif()