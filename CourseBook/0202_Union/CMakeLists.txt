# include public library

include_directories(${CMAKE_SOURCE_DIR}/Status)

# generate exec_program
add_executable(Union_test Union.h Union.c SqList.c SqList.h Union_test.c)

# link public library
target_link_libraries(Union_test Scanf_lib)
