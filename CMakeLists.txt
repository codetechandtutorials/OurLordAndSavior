cmake_minimum_required(VERSION 3.13.4)

project(OLAS VERSION 1.1)

find_package(GLEW REQUIRED)

# get glfw from github
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

#           CHECK ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

add_subdirectory(external/glfw)


# adder use logic
option(USE_ADDER "A simple library for adding 2 floats." ON)
option(TEST_ADDER "Test library for adding 2 floats." ON)
option(TEST_GRAPHICS "Test launching opengl with glfw window." ON)

if(TEST_ADDER)
	add_subdirectory(Adder)
	list(APPEND EXTRA_LIB_DIRS "Adder")
	list(APPEND EXTRA_INCLUDE_DIRS "Adder")
	list(APPEND EXTRA_LINKS adder)
endif()

configure_file(OLASConfig.h.in OLASConfig.h)

install(FILES "${PROJECT_BINARY_DIR}/OLASConfig.h" DESTINATION include)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include(CPack)

if(TEST_ADDER OR TEST_GRAPHICS)
  add_subdirectory(tests)
endif()
