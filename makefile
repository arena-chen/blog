CC=g++
GTEST_ROOT=../gtest
GTEST_DIR=$(GTEST_ROOT)/googletest/ $(GTEST_ROOT)/googletest/include/ $(GTEST_ROOT)/googlemock/ $(GTEST_ROOT)/googlemock/include/
GTEST_LIB=$(GTEST_ROOT)/lib/libgtest.a

string:
	$(CC) -o testString.exe main.cpp gtestString.cpp $(GTEST_DIR:%=-I%) $(GTEST_LIB) -lpthread -std=c++11

vector:
	$(CC) -o testVector.exe main.cpp gtestVector.cpp $(GTEST_DIR:%=-I%) $(GTEST_LIB) -lpthread -std=c++11

map:
	$(CC) -o testMap.exe main.cpp gtestMap.cpp $(GTEST_DIR:%=-I%) $(GTEST_LIB) -lpthread -std=c++11

set:
	$(CC) -o testSet.exe main.cpp gtestSet.cpp $(GTEST_DIR:%=-I%) $(GTEST_LIB) -lpthread -std=c++11

queue:
	$(CC) -o testQueue.exe main.cpp gtestQueue.cpp $(GTEST_DIR:%=-I%) $(GTEST_LIB) -lpthread -std=c++11

all: string vector map set queue

clean:
	rm *.exe

.PHONY : all string vector map set queue
