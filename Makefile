.PHONY: build

all: build compile

build:
	cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release

compile:
	cmake --build build
