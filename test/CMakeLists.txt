enable_testing()

function(ADD_LOG_TEST TEST_SRC_FILE CPP_STARDARD)
    get_filename_component(EXE_NAME ${TEST_SRC_FILE} NAME_WE)
    add_executable(${EXE_NAME} ${TEST_SRC_FILE})
    target_include_directories(${EXE_NAME} PRIVATE ${CMAKE_SOURCE_DIR})
    set_target_properties(${EXE_NAME} PROPERTIES CXX_STANDARD ${CPP_STARDARD})
    add_test(NAME ${EXE_NAME} COMMAND "$<TARGET_FILE:${EXE_NAME}>")
endfunction()

ADD_LOG_TEST(./cpp17_test.cpp 17)
ADD_LOG_TEST(./cpp17_target_test.cpp 17)
ADD_LOG_TEST(./cpp20_test.cpp 20)
ADD_LOG_TEST(./cpp20_target_test.cpp 20)
