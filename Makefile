all: main

main: main.cpp
	g++ main.cpp tree.cpp -o P0 -std=c++11
	
clean:
	rm kbs.fs19 P0
