## CMAKE VAR
## <=====================================>
cmake_minimum_required( VERSION 3.18...3.20 )
set( CMAKE_BUILD_TYPE Debug ) # Release / RelWithDebInfo / Debug
set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/ )
set( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage --coverage -lgcov")
## <=====================================>


## PROJECT VAR
## <=====================================>
project( "SWEngine-OpenGLModule test"
        VERSION
        0.1
        DESCRIPTION
        "All test for a graphical module"
        )
set( EXEC test.out )
set( EXT cpp )

## SOURCE FOLDERS
set( SRC_FOLDERS
        ${CMAKE_SOURCE_DIR}/sources/Color/
        ${CMAKE_SOURCE_DIR}/sources/component/transform/
        ${CMAKE_SOURCE_DIR}/sources/template/scenes/
        ${CMAKE_SOURCE_DIR}/sources/fixture/
        ${CMAKE_SOURCE_DIR}/../sources/
        ${CMAKE_SOURCE_DIR}/../sources/components/
        ${CMAKE_SOURCE_DIR}/../sources/components/transform/
        ${CMAKE_SOURCE_DIR}/../sources/managers/
        ${CMAKE_SOURCE_DIR}/../sources/resources/
        ${CMAKE_SOURCE_DIR}/../sources/utils/
        ${CMAKE_SOURCE_DIR}/../sources/event/
        )
## INCLUDE FOLDERS
set( INC_FOLDERS
        ${CMAKE_SOURCE_DIR}/../libraries/
        ${CMAKE_SOURCE_DIR}/../libraries/core/
        ${CMAKE_SOURCE_DIR}/../libraries/freetype/
        ${CMAKE_SOURCE_DIR}/../includes/
        ${CMAKE_SOURCE_DIR}/../includes/components/
        ${CMAKE_SOURCE_DIR}/../includes/dependencies/
        ${CMAKE_SOURCE_DIR}/../includes/managers/
        ${CMAKE_SOURCE_DIR}/../includes/resources/
        ${CMAKE_SOURCE_DIR}/../includes/utils/
        ${CMAKE_SOURCE_DIR}/../includes/event/
        ${CMAKE_SOURCE_DIR}/includes/
        )
if (UNIX)
    ## IMPORTED SHARED LIBRARY NAME
    set( SHARED_LIB_NAME
            glfw3
            Jsnp
            SWEngine-Core
            )
    ## IMPORTED SHARED LIBRARY LOCATION

    set( SHARED_LIB_LOCATION
            ${CMAKE_SOURCE_DIR}/../libraries/libJsnp.so
            ${CMAKE_SOURCE_DIR}/../libraries/libSWEngine-Core.so
            ${CMAKE_SOURCE_DIR}/../libraries/libglfw.so
            )
elseif(WIN32)
    ## IMPORTED SHARED LIBRARY NAME
    set( SHARED_LIB_NAME
            glfw3
            Jsnp
            SWEngine-Cored
            freetype
            )
    ## IMPORTED SHARED LIBRARY LOCATION
    set( SHARED_LIB_LOCATION
            ${CMAKE_SOURCE_DIR}/../libraries/glfw3.dll
            ${CMAKE_SOURCE_DIR}/../libraries/Jsnp.dll
            ${CMAKE_SOURCE_DIR}/../libraries/core/SWEngine-Cored.dll
            ${CMAKE_SOURCE_DIR}/../libraries/core/freetype.dll
            )
    ## IMPORTED SHARED LIBRARY .lib file
    set( SHARED_LIB
            ${CMAKE_SOURCE_DIR}/../libraries/glfw3.lib
            ${CMAKE_SOURCE_DIR}/../libraries/Jsnp.lib
            ${CMAKE_SOURCE_DIR}/../libraries/SWEngine-Cored.lib
            ${CMAKE_SOURCE_DIR}/../libraries/freetype.lib
            )
endif()
## <=====================================>


## GET SOURCES
## <=====================================>
foreach(filePath ${SRC_FOLDERS})
    string(APPEND TMP "${filePath}*.${EXT};")
    string(APPEND TMP "${filePath}*.c;")
endforeach()
file(GLOB SRC ${TMP})
## <=====================================>


## OUTPUT
## <=====================================>
## EXECUTABLE
add_executable(${EXEC} ${SRC})

## or SHARED LIB
# add_library(${EXEC} SHARED ${SRC})

## or STATIC LIB
# add_library(${EXEC} STATIC ${SRC})
## <=====================================>


## ADD INCLUDES
## <=====================================>
target_include_directories(${EXEC} PRIVATE ${INC_FOLDERS})
## <=====================================>

## ADD PARAMETER
## <=====================================>
if (UNIX)
    target_compile_options(${EXEC} PRIVATE -g3)
endif (UNIX)
## <=====================================>


## SHARED LIBRARY LINKING
## <=====================================>
list(LENGTH SHARED_LIB_NAME  list_len)
math(EXPR LIST_LEN "${list_len} - 1")

foreach(ctr RANGE ${LIST_LEN})
    list(GET SHARED_LIB_NAME ${ctr} lib)
    list(GET SHARED_LIB_LOCATION ${ctr} loc)
    list(GET SHARED_LIB ${ctr} filelib)
    add_library(${lib} SHARED IMPORTED)
    if (UNIX)
        set_target_properties(${lib} PROPERTIES
            IMPORTED_LOCATION ${loc}
            )
    elseif(WIN32)
        set_target_properties(${lib} PROPERTIES
                IMPORTED_LOCATION ${loc}
                IMPORTED_IMPLIB ${filelib}
                )
    endif()
endforeach()
target_link_libraries(${EXEC}
        PUBLIC
        ${SHARED_LIB_NAME}
        )
## <=====================================>


## PACKAGE LINKING
## <=====================================>
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

target_link_libraries(${EXEC}
        PUBLIC
        gtest_main
        )

include(GoogleTest)
gtest_discover_tests(${EXEC})
## <=====================================>