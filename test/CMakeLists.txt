enable_testing()

add_executable(cpp17_test cpp17_test.cpp)
target_include_directories(cpp17_test PRIVATE ${CMAKE_SOURCE_DIR})
set_target_properties(cpp17_test PROPERTIES CXX_STANDARD 17)
add_test(NAME cpp17_test COMMAND ./cpp17_test)

add_executable(cpp20_test cpp20_test.cpp)
target_include_directories(cpp20_test PRIVATE ${CMAKE_SOURCE_DIR})
set_target_properties(cpp20_test PROPERTIES CXX_STANDARD 20)
add_test(NAME cpp20_test COMMAND ./cpp20_test)
