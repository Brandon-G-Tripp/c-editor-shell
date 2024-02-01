add_cmocka_test(test_list
                SOURCES test_list.c
                COMPILE_OPTIONS ${DEFAULT_C_COMPILE_FLAGS}
                LINK_LIBRARIES "${CMOCKA_LIBRARIES}")
add_cmocka_test_environment(test_list)
target_include_directories(test_list PUBLIC "${CMOCKA_INCLUDE_DIRS}")

add_cmocka_test(test_vector
                SOURCES test_vector.c
                COMPILE_OPTIONS ${DEFAULT_C_COMPILE_FLAGS}
                LINK_LIBRARIES "${CMOCKA_LIBRARIES}")
add_cmocka_test_environment(test_vector)
target_include_directories(test_vector PUBLIC "${CMOCKA_INCLUDE_DIRS}")

add_cmocka_test(test_map
                SOURCES test_map.c
                COMPILE_OPTIONS ${DEFAULT_C_COMPILE_FLAGS}
                LINK_LIBRARIES "${CMOCKA_LIBRARIES}")
add_cmocka_test_environment(test_map)
target_include_directories(test_map PUBLIC "${CMOCKA_INCLUDE_DIRS}")
