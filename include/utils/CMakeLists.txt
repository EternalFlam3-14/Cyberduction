cmake_minimum_required(VERSION 3.0.0)
project(ItemForge VERSION 0.0.5)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Cyberduction/tools)
set(ITEMFORGE_HEADERS_DIR headers)
set(ITEMFORGE_SRC_DIR src)

include_directories(
    ${ITEMFORGE_HEADERS_DIR}
)

aux_source_directory(${ITEMFORGE_SRC_DIR} ITEMFORGE_SRCS)

add_executable(${PROJECT_NAME} ${ITEMFORGE_SRCS})

 target_link_libraries(${PROJECT_NAME} PUBLIC
    Engine
 )
