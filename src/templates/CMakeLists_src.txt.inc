R"delim(find_package(FMT REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main
  PRIVATE fmt::fmt main_project)
)delim"