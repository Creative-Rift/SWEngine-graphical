cmake_minimum_required( VERSION 3.20...3.22 )

project( "ShipWreck Engine"
        VERSION
        0.5
        DESCRIPTION
        "Graphical Engine written in c++ with openGL for Windows."
        )

set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/${CMAKE_PROJECT_VERSION} )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/${CMAKE_PROJECT_VERSION} )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/${CMAKE_PROJECT_VERSION} )
#set( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage --coverage -lgcov") #TODO fix args

add_subdirectory(module/)
add_subdirectory(tests/)