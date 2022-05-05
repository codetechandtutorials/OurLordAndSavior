enable_testing()

if (TEST_GRAPHICS)
  add_subdirectory(graphics)
endif()

if (TEST_ADDER AND USE_ADDER)
  add_subdirectory(math)
endif()