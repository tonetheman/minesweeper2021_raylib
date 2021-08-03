


all : minesweeper

minesweeper : main.cpp b.cpp
	g++ -o minesweeper main.cpp b.cpp -lraylib

clean :
	rm -f minesweeper