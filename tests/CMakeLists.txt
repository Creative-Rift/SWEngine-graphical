set(PREFIX_MESSAGE "[SWEngine-tests] ")

# SOURCE FOLDERS
set( SRC_FOLDERS_T
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/script/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/Color/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/component/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/component/transform/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/template/scenes/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/fixture/

        ${CMAKE_CURRENT_SOURCE_DIR}/../module/sources/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/sources/components/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/sources/components/base/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/sources/components/transform/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/sources/event/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/sources/exception/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/sources/gameObject/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/sources/managers/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/sources/resources/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/sources/scenes_manager/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/sources/scenes_manager/scene/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/sources/utils/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/sources/utils/async/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/sources/window/
        )

# INCLUDE FOLDERS
set( INC_FOLDERS_T
        ${CMAKE_CURRENT_SOURCE_DIR}/../libraries/
        ${CMAKE_CURRENT_SOURCE_DIR}/../libraries/freetype/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/includes/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/includes/components/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/includes/components/base/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/includes/dependencies/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/includes/event/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/includes/exception/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/includes/gameObject/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/includes/managers/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/includes/managers/base/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/includes/resources/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/includes/scenes_manager/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/includes/scenes_manager/scene/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/includes/utils/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/includes/utils/async/
        ${CMAKE_CURRENT_SOURCE_DIR}/../module/includes/window/

        ${CMAKE_CURRENT_SOURCE_DIR}/includes/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/script/
        )

message(${PREFIX_MESSAGE} "Build type set to: " ${CMAKE_BUILD_TYPE})
message(${PREFIX_MESSAGE} "Current cmake location: " ${CMAKE_CURRENT_SOURCE_DIR})
message(${PREFIX_MESSAGE} "Project location: " ${CMAKE_SOURCE_DIR})

if (WIN32)
    message(${PREFIX_MESSAGE} "Windows system detected, prepare project...")
    include(.cmake_windows.cmake)
else()
    message(FATAL_ERROR "System not supported!")
endif()
