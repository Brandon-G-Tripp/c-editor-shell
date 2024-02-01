add_cmocka_test(test_string_utils
                SOURCES test_string_utils.c
                COMPILE_OPTIONS ${DEFAULT_C_COMPILE_FLAGS}
                LINK_LIBRARIES "${CMOCKA_LIBRARIES}")
add_cmocka_test_environment(test_string_utils)
target_include_directories(test_string_utils PUBLIC "${CMOCKA_INCLUDE_DIRS}")
