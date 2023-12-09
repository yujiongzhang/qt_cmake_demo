cmake_minimum_required(VERSION 3.5)

project(qt_cmake_demo LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}
)

#由于采用set(CMAKE_AUTOUIC ON)的方式处理ui文件，编译时会报错找不到ui文件。
#需要将ui文件夹加入AUTOUIC的搜索目录，这样AUTOUIC处理时才能找到ui文件。
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/ui)

file(GLOB PRO_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB PRO_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB PRO_UI ${CMAKE_CURRENT_SOURCE_DIR}/ui/*.ui)
file(GLOB PRO_RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/resource/*.qrc)

add_executable(qt_cmake_demo
${PRO_SRC}
${PRO_INCLUDE}
${PRO_UI}
${PRO_RESOURCES}
)


target_link_libraries(qt_cmake_demo PRIVATE Qt5::Widgets)
