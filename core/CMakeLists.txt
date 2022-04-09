## CMAKE VAR
## <=====================================>
set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/ )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/ )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/ )
## <=====================================>


message( DEBUG "[SWEngine-Core] Build type set to ${CMAKE_BUILD_TYPE}")

if (WIN32)
    message("[SWEngine-Core] Windows system detected prepare project...")
    include(.cmake_windows.cmake)
elseif(UNIX)
    message("[SWEngine-Core] Unix system detected prepare project...")
    include(.cmake_linux.cmake)
endif()

if (${CMAKE_BUILD_TYPE} MATCHES Debug)
    set_target_properties(${EXEC} PROPERTIES
            DEBUG_POSTFIX "d")
endif()