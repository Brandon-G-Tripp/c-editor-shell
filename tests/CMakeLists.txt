# enable_testing()

# include_directories(extern/cmocka/include)
# link_directories(extern/cmocka/lib)



# example code 
find_package(NCurses 
    PATH_SUFFIXES "share/cmake/ncurses")

add_cmocka_test(simple_test
                SOURCES simple_test.c
                COMPILE_OPTIONS ${DEFAULT_C_COMPILE_FLAGS}
                LINK_LIBRARIES "${CMOCKA_LIBRARIES}")
add_cmocka_test_environment(simple_test)
target_include_directories(simple_test PUBLIC "${CMOCKA_INCLUDE_DIRS}")

add_cmocka_test(test_io
                SOURCES test_io.c ${CMAKE_CURRENT_SOURCE_DIR}/../src/io.c
                COMPILE_OPTIONS ${DEFAULT_C_COMPILE_FLAGS}
                LINK_LIBRARIES "${CMOCKA_LIBRARIES}")
add_cmocka_test_environment(test_io)
target_include_directories(test_io PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/../include"
    "${CMOCKA_INCLUDE_DIRS}"
)

add_cmocka_test(test_terminal
                SOURCES test_terminal.c ${CMAKE_CURRENT_SOURCE_DIR}/../src/terminal.c
                COMPILE_OPTIONS ${DEFAULT_C_COMPILE_FLAGS}
                LINK_LIBRARIES "${CMOCKA_LIBRARIES}")
add_cmocka_test_environment(test_terminal)
target_include_directories(test_terminal PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/../include"
    "${CMOCKA_INCLUDE_DIRS}"
)

add_subdirectory(data_structures)
add_subdirectory(utils)
