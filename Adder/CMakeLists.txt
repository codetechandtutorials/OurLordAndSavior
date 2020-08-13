add_library(adder adder.cpp adder.h)

install(TARGETS adder DESTINATION lib)
install(FILES adder.h DESTINATION include)
