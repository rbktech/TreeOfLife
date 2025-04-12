cmake_minimum_required(VERSION 3.10)

file(STRINGS "version" VERSION)

project(wxTreeOfLife VERSION ${VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(wxWidgets_LIB_DIR $ENV{WXWIN}/lib/gcc_libx64)

find_package(wxWidgets 3.2.1 REQUIRED propgrid xml core base)

add_definitions(-DVERSION="${PROJECT_VERSION}")
add_definitions(-DHAVE_W32API_H)
add_definitions(-D__WXMSW__)
add_definitions(-D_UNICODE)

include_directories("src")
include_directories("${wxWidgets_INCLUDE_DIRS}")
include_directories("$ENV{RBKLib}/include")

add_link_options(-static-libgcc)
add_link_options(-static-libstdc++)

if(NOT CMAKE_BUILD_TYPE MATCHES Debug)
    add_link_options(-mwindows)
    add_link_options(-s)
endif()

link_directories(${wxWidgets_LIB_DIR})
link_directories("$ENV{RBKLib}/lib/gcc_libx64")

add_executable(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        OUTPUT_NAME ${PROJECT_NAME}-${CMAKE_BUILD_TYPE}-${PROJECT_VERSION}
)

target_sources(${PROJECT_NAME} PRIVATE src/main.cpp)
target_sources(${PROJECT_NAME} PRIVATE src/mainframe.cpp)
target_sources(${PROJECT_NAME} PRIVATE src/panel/feature.cpp)
target_sources(${PROJECT_NAME} PRIVATE src/plot/plot.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PRIVATE rbk)