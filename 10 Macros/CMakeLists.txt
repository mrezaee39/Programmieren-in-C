add_compile_definitions(DEBUG_LEVEL=DEBUG_LEVEL_ERROR)
add_compile_options(-Wall -Werror=return-type -Werror=incompatible-pointer-types)
add_executable(10_Macros main.c debug.h)
target_link_libraries(10_Macros test_util)
