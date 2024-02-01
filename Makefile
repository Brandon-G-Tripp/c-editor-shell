# Define build dir 
BUILD_DIR = build

# Makefile targets
.PHONY: all build clean test

# build library and executables
build:
	mkdir -p $(BUILD_DIR)
	cmake -S . -B $(BUILD_DIR)
	$(MAKE) -C $(BUILD_DIR)


# clean build files
clean:
	rm -rf $(BUILD_DIR)

# Run all tests
test:
	make build
	$(MAKE) -C $(BUILD_DIR) test

# Run specific test
test_%:
	$(MAKE) -C $(BUILD_DIR) test/$*
