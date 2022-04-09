## PROJECT VAR
## <=====================================>
set( EXEC SWEngine-Core )
set( EXT cpp )

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
## IMPORTED SHARED LIBRARY NAME
set( SHARED_LIB_NAME
        Jsnp
        yaml-cppd
)
## IMPORTED SHARED LIBRARY LOCATION
set( SHARED_LIB_LOCATION
        ${CMAKE_SOURCE_DIR}/libraries/Jsnp.dll
        ${CMAKE_SOURCE_DIR}/libraries/yaml-cppd.dll
        )
## IMPORTED SHARED LIBRARY .lib file
set( SHARED_LIB
        ${CMAKE_SOURCE_DIR}/libraries/Jsnp.lib
        ${CMAKE_SOURCE_DIR}/libraries/yaml-cppd.lib
        )
## <=====================================>


## GET SOURCES
## <=====================================>
foreach(filePath ${SRC_FOLDERS})
    string(APPEND TMP "${filePath}*.${EXT};")
endforeach()
file(GLOB SRC ${TMP})
## <=====================================>


## OUTPUT
## <=====================================>
## EXECUTABLE
# add_executable(${EXEC} ${SRC})

## or SHARED LIB
add_library(${EXEC} SHARED ${SRC})

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
    set_target_properties(${lib} PROPERTIES
            IMPORTED_LOCATION ${loc}
            IMPORTED_IMPLIB ${filelib}
            )
endforeach()
target_link_libraries(${EXEC}
        PUBLIC
        ${SHARED_LIB_NAME}
        )
## <=====================================>