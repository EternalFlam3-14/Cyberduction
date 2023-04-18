cmake_minimum_required(VERSION 3.0.0)
project(Cyberduction VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Cyberduction)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/include)
set(ENGINE_ITEM_DIR ${LIB_DIR}/engine/item)
set(MODS_DIR ${LIB_DIR}/mods)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(CEREAL_DIR ${LIB_DIR}/cereal)

include_directories(
    ${LIB_DIR}
    ${CEREAL_DIR}
    ${MODS_DIR}
    ${ENGINE_ITEM_DIR}
)

add_subdirectory(${CEREAL_DIR})
add_subdirectory(${ENGINE_ITEM_DIR})

aux_source_directory(${SOURCE_DIR}  DIR_SRCS)

add_executable(${PROJECT_NAME} ${DIR_SRCS})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${MODS_DIR} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/config
            )

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E make_directory
                   ${MODS_DIR} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/saves 
            )