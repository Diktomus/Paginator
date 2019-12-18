CC = g++
INC = ../include
SRC_DIR = ../test
ALL_CPP = $(wildcard $(addsuffix /*.cpp,$(SRC_DIR)))

all:
	$(CC) $(ALL_CPP) -o test-paginator -I$(INC) -std=c++1z

clean:
	rm test-paginator