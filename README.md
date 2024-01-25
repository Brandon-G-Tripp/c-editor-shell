

$ cmake -S . -B build -DUNIT_TESTING=ON - this will configure and generate build files 
$ cmake --build build  - this will actually build the files and compile

$ ctest --test-dir build  - will run all of the tests with ctest 

