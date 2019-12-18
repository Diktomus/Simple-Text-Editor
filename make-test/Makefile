CC = g++
INC = ../include
SRC_DIR = ../test ../src
ALL_CPP = $(wildcard $(addsuffix /*.cpp,$(SRC_DIR)))

all:
	$(CC) $(ALL_CPP) -o test-text-editor -I$(INC)
	test-text-editor

clean:
	rm test-text-editor