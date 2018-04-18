CC=g++
GTEST_DIR=gtest/googletest/ gtest/googletest/include/ gtest/googlemock/ gtest/googlemock/include/
GTEST_LIB=gtest/../libgtest.a

string:
	$(CC) -o testString.exe gtestString.cpp $(GTEST_DIR:%=-I%) $(GTEST_LIB) -lpthread -std=c++11

vector:
	$(CC) -o testVector.exe gtestVector.cpp $(GTEST_DIR:%=-I%) $(GTEST_LIB) -lpthread -std=c++11

map:
	$(CC) -o testMap.exe gtestMap.cpp $(GTEST_DIR:%=-I%) $(GTEST_LIB) -lpthread -std=c++11

set:
	$(CC) -o testSet.exe gtestSet.cpp $(GTEST_DIR:%=-I%) $(GTEST_LIB) -lpthread -std=c++11

all: string vector map set

clean:
	rm *.exe

.PHONY : all string vector map set
