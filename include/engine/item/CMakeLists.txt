cmake_minimum_required(VERSION 3.0.0)
project(Item VERSION 0.0.5)
set(CMAKE_CXX_STANDARD 20)

set(ITEM_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

set(ITEM_FACTORY_DIR ${PROJECT_SOURCE_DIR}/factory)
set(ITEM_LOADER_DIR ${PROJECT_SOURCE_DIR}/loader)
set(ITEM_TEST_DIR ${PROJECT_SOURCE_DIR}/test)

add_subdirectory(${ITEM_FACTORY_DIR})

add_subdirectory(${ITEM_LOADER_DIR})


aux_source_directory(${ITEM_SOURCE_DIR} ITEMS_SRCS)

add_library(${PROJECT_NAME} STATIC ${ITEMS_SRCS})

target_link_directories(${PROJECT_NAME} PUBLIC
    ${ITEM_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    ItemLoader
    ItemFactory
)
