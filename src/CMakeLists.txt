add_executable(main main.c)

target_link_libraries(main data_structures utils)

set_target_properties(main PROPERTIES 
  EXPORT_NAME ${PROJECT_NAME}_targets) 

add_library(data_structures 
    data_structures/list.c 
    data_structures/vector.c 
    data_structures/map.c)

add_library(utils
    utils/string_utils.c
    utils/common_utils.c)

