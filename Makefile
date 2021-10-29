CFLAGS =-Wall -Werror -std=c++11 -O0
CXX = g++


all: main.o
	$(CXX) -o cpp_output_formatting main.o $(CFLAGS)

main.o: main.cpp
	$(CXX) -c main.cpp $(CFLAGS)

.PHONY: clean
clean:
	rm *.o
	rm memory_sample