include_directories(${CMAKE_SOURCE_DIR}/Status)

add_executable(MergeLinkList_test MergeLinkList.h MergeLinkList.c LinkList.h LinkList.c MergeLinkList_test.c)

target_link_libraries(MergeLinkList_test Scanf_lib)
