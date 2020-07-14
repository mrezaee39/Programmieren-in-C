add_library(12_SerializeObjects json.c json.h linked_list.h file_writer.c writer.c writer_private.h)
add_executable(12_JsonTest test/json_test.c json.c)
target_link_libraries(12_JsonTest unity)
