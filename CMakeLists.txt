cmake_minimum_required(VERSION 3.0.0)
project(Cyberduction VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Cyberduction)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/include)
set(ENGINE_DIR ${LIB_DIR}/engine)
set(UTILS_DIR ${LIB_DIR}/tools)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(CEREAL_DIR ${LIB_DIR}/cereal)

include_directories(
    ${LIB_DIR}
    ${CEREAL_DIR}
    ${ENGINE_DIR}
)

add_subdirectory(${ENGINE_DIR})

add_subdirectory(${UTILS_DIR})

aux_source_directory(${SOURCE_DIR}  DIR_SRCS)

add_executable(${PROJECT_NAME} ${DIR_SRCS})

target_link_libraries(${PROJECT_NAME} PUBLIC Engine)

if (NOT EXISTS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/saves)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory(${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/saves)
)
endif()

if (NOT EXISTS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/data)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory(${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/data)
)
endif()