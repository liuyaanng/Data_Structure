# include public library

include_directories(${CMAKE_SOURCE_DIR}/Status)

# generate exec_program
add_executable(SqList_test SqList.c SqList.h SqList_test.c)

# link public library
target_link_libraries(SqList_test Scanf_lib)
