# include public library

include_directories(${CMAKE_SOURCE_DIR}/Status)

# generate exec_program
add_executable(MergeList_test MergeList.h MergeList.c MergeList_test.c SqList.c SqList.h)

# link public library
target_link_libraries(MergeList_test Scanf_lib)
