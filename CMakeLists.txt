cmake_minimum_required(VERSION 2.8)
project( demos )

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#PROJECT_SOURCE_DIR 变量为含project名的CMakeLists.txt文件所在的目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Default to release build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

aux_source_directory(./ sources)
foreach(src ${sources})
    string( REGEX REPLACE ".cpp$" "" bin ${src} )
    string( REGEX REPLACE "./." "" bin ${bin} )
    add_executable( ${bin} ${src} )
endforeach()


