BUILD_DIR ?= build

.PHONY: love
love: generate build install

.PHONY: generate
generate:
	cmake -B ${BUILD_DIR}

.PHONY: build
build:
	make -C ${BUILD_DIR}

.PHONY: install
install:
	make -C ${BUILD_DIR} install

.PHONY: clean
clean:
	rm -rf bin build
