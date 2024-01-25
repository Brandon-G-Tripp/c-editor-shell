# add_executable(test_list test_list.c)
# target_link_libraries(test_list cmocka)

# add_executable(test_vector test_vector.c)
# target_link_libraries(test_vector cmocka)

# add_executable(test_map test_map.c)
# target_link_libraries(test_map cmocka)

# add_test(NAME test_list COMMAND test_list)
# add_test(NAME test_vector COMMAND test_vector)
# add_test(NAME test_map COMMAND test_map)
# set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../include")
install(FILES ${INCLUDE_DIRS}/data_structures.h DESTINATION include)

add_cmocka_test(test_list
                SOURCES test_list.c
                COMPILE_OPTIONS ${DEFAULT_C_COMPILE_FLAGS}
                LINK_LIBRARIES "${CMOCKA_LIBRARIES}")
add_cmocka_test_environment(test_list)
target_include_directories(test_list PUBLIC "${CMOCKA_INCLUDE_DIRS}")
target_include_directories(test_list PUBLIC "${INCLUDE_DIR}")
message("Includes: ${test_list_INCLUDE_DIRS}")
