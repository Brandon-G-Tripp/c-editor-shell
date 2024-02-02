# Define build dir 
BUILD_DIR = build

# Makefile targets
.PHONY: all build clean test

# build library and executables

# Configure project
all: configure

configure:
	cmake -S . -B $(BUILD_DIR) -DUNIT_TESTING=ON

# Build library and executables
build: configure
	cmake --build $(BUILD_DIR) 


# clean build files
clean:
	rm -rf $(BUILD_DIR)

# Run all tests
test: build
	ctest --test-dir $(BUILD_DIR) --output-on-failure 

# Run specific test
test_%:
	ctest --output-on-failure -R $* -C $(BUILD_DIR)
