BUILD_DIR := build

.PHONY: init build run clean

init:
	cmake -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Debug

build:
	cmake --build $(BUILD_DIR)

run:
	./$(BUILD_DIR)/stdssg

clean:
	rm -rf $(BUILD_DIR)
