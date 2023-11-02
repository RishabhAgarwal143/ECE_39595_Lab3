CC=g++
C_FLAGS=-g -std=c++17 -Wall

SRC_FILES=$(filter-out $(wildcard main.cc),$(wildcard *.cc))
APP=chess

custom_tests:
	$(CC) $(C_FLAGS) $(SRC_FILES) main.cc -o $(APP)

test1: custom_tests
	./chess test_files/part3_8x8_10.txt

test2: custom_tests
	./chess test_files/part3_4x4_3.txt

valgrind:
	valgrind --leak-check=full ./$(APP) $(TEST)

