project(DivideAndConquer)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${PARENT_DIR}/${PROJECT_NAME})
file(GLOB SRC_FILES *.c *.cpp)

foreach(source_file ${SRC_FILES})
    get_filename_component(BINARY_NAME ${source_file} NAME_WE)
    add_executable(${BINARY_NAME} ${source_file})
endforeach(source_file ${SRC_FILES})