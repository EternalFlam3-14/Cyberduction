cmake_minimum_required(VERSION 3.0.0)
project(Engine VERSION 0.0.7)
set(CMAKE_CXX_STANDARD 20)

set(ITEM_DIR ${PROJECT_SOURCE_DIR}/item)
set(ITEM_HEADERS_DIR ${ITEM_DIR}/headers)
set(ITEM_SOURCE_DIR ${ITEM_DIR}/src)

set(UTILITY_DIR ${PROJECT_SOURCE_DIR}/utility)

link_directories(
    ${ITEM_HEADERS_DIR}
    ${UTILITY_DIR}
)

aux_source_directory(${ITEM_SOURCE_DIR} ITEMS_SRCS)

add_library(${PROJECT_NAME} STATIC ${ITEMS_SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${ITEM_HEADERS_DIR}
    ${CEREALIZE_HEADERS_DIR}
    ${UTILITY_DIR}
)
