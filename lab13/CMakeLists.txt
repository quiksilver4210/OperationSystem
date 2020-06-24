
project(lab13)

find_package (Threads)

add_executable(${PROJECT_NAME}-queue src/queue.c src/utils.c src/test.h)
add_executable(${PROJECT_NAME}-queue-mutex src/queue_mutex.c src/utils.c src/test.h)
add_executable(${PROJECT_NAME}-queue-cond src/queue_cond.c src/utils.c src/test.h)

target_link_libraries (${PROJECT_NAME}-queue ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (${PROJECT_NAME}-queue-mutex ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (${PROJECT_NAME}-queue-cond ${CMAKE_THREAD_LIBS_INIT})