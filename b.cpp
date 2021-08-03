#include <raylib.h>
#include "b.h"
#include <cstdio>

B::B(int rows, int cols) : rows(rows), cols(cols) {

    data = new int*[rows];
    for (int i=0;i<rows;i++) {
        data[i] = new int[cols];
    }
}

B::~B() {
    for (int i=0;i<rows;i++) {
        delete data[i];
    }
    delete []data;
}

int B::get(int r, int c) {
    return data[r][c];
}

void B::set(int r, int c, int val) {
    data[r][c] = val;
}

// will take the board and
// zero out anything not a bomb
// the compute the numbers
void B::score() {
    reset(); // sets zeros in non bombs
}

void B::clear() {
    for(int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            set(i,j,0);
        }
    }
}

void B::reset() {
    for(int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            if (!is_bomb(i,j)) {
                set(i,j,0);
            }   
        }
    }
}

bool B::is_bomb(int r, int c) {
    return get(r,c)==B_BOMB;
}


// init setup the board for a game
// called by user of this class
void B::init(int bomb_count) {
    clear();
    
    for(int i=0;i<bomb_count;i++) {
        int row = GetRandomValue(0,rows-1);
        int col = GetRandomValue(0,cols-1);
        printf("setting %d %d\n",row,col);
        set(row,col,B_BOMB);
    }
}

// render called by user of this class
void B::render() {
    for(int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            if (is_bomb(i,j)) {
                DrawRectangle(j*32,i*32,
                    31,31,RED);
            } else {
                DrawRectangle(j*32,
                    i*32,31,31,BLACK);
            }
        }
    }
}
