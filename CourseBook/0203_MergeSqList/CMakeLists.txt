# include public library

include_directories(${CMAKE_SOURCE_DIR}/Status)

# generate exec_program
add_executable(MergeSqList_test MergeSqList.h MergeSqList.c MergeSqList_test.c SqList.c SqList.h)

# link public library
target_link_libraries(MergeSqList_test Scanf_lib)
