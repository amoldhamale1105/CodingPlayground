project(Creational)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${PARENT_DIR}/${PROJECT_NAME})
file(GLOB SRC_FILES *.c *.cpp)
find_package(Threads REQUIRED)

foreach(source_file ${SRC_FILES})
    get_filename_component(BINARY_NAME ${source_file} NAME_WE)
    add_executable(${BINARY_NAME} ${source_file})
    target_link_libraries(${BINARY_NAME} ${CMAKE_THREAD_LIBS_INIT})
endforeach(source_file ${SRC_FILES})