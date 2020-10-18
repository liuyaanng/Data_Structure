include_directories(${CMAKE_SOURCE_DIR}/Status)

add_executable(LinkList_test LinkList.h LinkList.c LinkList_test.c)

target_link_libraries(LinkList_test Scanf_lib)
