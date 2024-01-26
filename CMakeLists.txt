cmake_minimum_required(VERSION 3.17)
project(c-text-editor-shell)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(c-text-editor-shell src/main.c)

find_path(CMOCKA_INCLUDE_DIR
    NAMES 
    cmocka.h
    PATHS
    ${CMOCKA_ROOT_DIR}/include
    )

find_library(CMOCKA_LIBRARY
    NAMES
    cmocka cmocka_shared
    PATHS
    ${CMOCKA_ROOT_DIR}/include
    )

if (CMOCKA_LIBRARY)
    set(CMOCKA_LIBRARIES
        ${CMOCKA_LIBRARIES}
        ${CMOCKA_LIBRARY}
        )
endif (CMOCKA_LIBRARY)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMOCKA_INCLUDE_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMOCKA_LIBRARIES})
# add_subdirectory(src)

# # Add CMocka CMake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmocka)

if (UNIT_TESTING)
    find_package(CMocka REQUIRED)
    include(AddCMockaTest)
    add_subdirectory(tests)
endif()


# include_directories(extern/cmocka-1.1.7/include)


# Options

# Link libraries etc

# install targets

# configure and build 

# Run test

