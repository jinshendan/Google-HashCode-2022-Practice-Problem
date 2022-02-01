all: pizza greedy

pizza: pizza.cpp
	g++ -std=c++17 -Wall -o pizza pizza.cpp

greedy: greedy.cpp
	g++ -std=c++17 -Wall -o greedy greedy.cpp
run: pizza
	./pizza
clean:
	rm -rf *.o

