CC = clang++


all:
		mkdir out
		make build

build:
		$(CC) test.cpp base64cpp.cpp -o out/LibraryTest.exe
clean:
ifeq ($(OS),Windows_NT)
		rd /s /q out && mkdir out
else
		rm -rf out && mkdir out
endif