CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

project(cpp-conf)

file(GLOB Source
  "src/*.cxx"
)

include_directories(include)

add_library(CppConf SHARED ${Source})

add_executable(demo example/main.cxx)

target_link_libraries(demo CppConf)
