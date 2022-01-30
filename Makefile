all: pizza

pizza: pizza.cpp
	g++ -std=c++17 -Wall -o pizza pizza.cpp

run: pizza
	./pizza
clean:
	rm -rf *.o

