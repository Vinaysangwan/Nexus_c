.PHONY: build

all: build compile

build:
	cmake -S . -B build -G Ninja

compile:
	cmake --build build
