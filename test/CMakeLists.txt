cmake_minimum_required(VERSION 3.0)
project(cmake_example CXX)

find_package(GTest REQUIRED)
set(CMAKE_CXX_FLAGS "-std=c++11")

file(GLOB allTestFile
  "*.cpp"
)

add_executable(libtest ${allTestFile})
target_link_libraries(libtest
  PRIVATE
    GTest::GTest
    GTest::Main
  )

