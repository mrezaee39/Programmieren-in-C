add_library(test_util STATIC src/test.c test.h src/test.h)
target_compile_options(test_util PUBLIC -ffunction-sections -fdata-sections -O2)