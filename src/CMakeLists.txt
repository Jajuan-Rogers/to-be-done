cmake_minimum_required(VERSION 4.3.1)
project(To-Be-Done VERSION 1.0 LANGUAGES CXX)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(3rd_party/matplot)
add_subdirectory(3rd_party/SQLiteCpp)

add_executable(tbd 
  main.cpp
  widgets/GraphView.h
  widgets/GraphView.cpp
)

target_link_libraries(tbd
  PRIVATE
  notcurses++
  notcurses-core
  matplot
  SQLiteCpp
  pthread
  dl
)
