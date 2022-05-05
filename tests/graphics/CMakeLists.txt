add_executable(graphics_test tester.cpp)

target_include_directories(graphics_test PUBLIC ${PROJECT_BINARY_DIR})



target_include_directories(graphics_test 
    PUBLIC external/glfw/include
	${GLEW_INCLUDE_DIRS}
)

target_link_directories(graphics_test 
	PUBLIC external/glfw/src
)

target_link_libraries(graphics_test glfw ${GLEW_LIBRARIES} GL GLU)

target_link_libraries(graphics_test glfw)

add_test(NAME "GraphicsTest" COMMAND "graphics_test" arg1 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

install(TARGETS graphics_test DESTINATION bin)


