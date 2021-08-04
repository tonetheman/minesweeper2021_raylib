


all : minesweeper

minesweeper : main.cpp b.cpp
	g++ -o minesweeper main.cpp b.cpp -lraylib

clean :
	rm -f minesweeper
	rm -f main.o
	rm -f b.o

RAYLIB_PATH=../raylibHTML5

web :
	emcc -c main.cpp b.cpp \
	-I $(RAYLIB_PATH)/src -D PLATFORM_WEB \
	-s USE_GLFW=3 -s ASYNCIFY -s TOTAL_MEMORY=67108864 \
	--shell-file $(RAYLIB_PATH)/src/shell.html \
	$(RAYLIB_PATH)/src/libraylib.a
