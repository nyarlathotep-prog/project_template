#include "template_files.hpp"

std::string CMakeListsSrcFile() {
  return R"delim(#add_library(project_library )
)delim";
}

std::string CMakeListsRootFile(const std::string name) {
  return R"delim(cmake_minimum_required(VERSION 3.8)

#Using c++17 for all personal projects
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#Output compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Add warnings
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything")
endif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

#Change project name here
set(PROJECT_NAME )delim" +
         name + R"delim()
#Where to build the files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

project(${PROJECT_NAME})

#Uncomment for most used Boost libraries
#find_package(Boost REQUIRED COMPONENTS system filesystem program_options)

include_directories(include)

#Assumes a library called project_library is defined there
add_subdirectory(src)

add_executable(main src/main.cpp)
#target_link_libraries(main project_library)
#target_link_libraries(main ${Boost_LIBRARIES})
)delim";
}

std::string ProjectileFile() {
  return R"delim(-/bin
-/build
)delim";
}

std::string MainFile() {
  return R"delim(#include <iostream>

int main(int argc, char *argv[]) {

  return 0;
}
)delim";
}
