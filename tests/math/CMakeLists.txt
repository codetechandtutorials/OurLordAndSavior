add_executable(math_test tester.cpp)

target_include_directories(math_test 
    PUBLIC ${EXTRA_INCLUDE_DIRS}
)

target_link_directories(math_test 
	PUBLIC ${EXTRA_LIB_DIRS}
)

target_link_libraries(math_test PUBLIC ${EXTRA_LINKS})

add_test(NAME "MathTest1" COMMAND "math_test" 1 6 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
add_test(NAME "MathTest2" COMMAND "math_test" 2 8 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
add_test(NAME "MathTest3" COMMAND "math_test" 3 2 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
add_test(NAME "MathTest4" COMMAND "math_test" 4 92 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

install(TARGETS math_test DESTINATION bin)
