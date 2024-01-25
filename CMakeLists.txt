cmake_minimum_required(VERSION 3.12)
project(c-text-editor-shell)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(src)

# Add CMocka CMake modules
set(CMOCKA_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmocka)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmocka)

if (UNIT_TESTING)
    find_package(cmocka 1.1.7 REQUIRED)
    include(AddCMockaTest)
    add_subdirectory(tests)
endif()


# include_directories(extern/cmocka-1.1.7/include)


# Options

# Link libraries etc

# install targets

# configure and build 

# Run test

