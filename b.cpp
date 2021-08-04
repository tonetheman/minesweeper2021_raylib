#include <raylib.h>
#include "b.h"
#include <cstdio>

const int FONTSIZE = 16;

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

bool B::is_valid_row_col(int r, int c) {
    if (r<0) {
        return false;
    }
    if (c<0) {
        return false;
    }
    if (r>=rows) {
        return false;
    }
    if (c>=cols) {
        return false;
    }
    return true;
}

// PRIVATE
void B::countbombs(int r, int c) {
    // dont update the bombs
    if (is_bomb(r,c)) { return; }

    int counter = 0;
    for (int i=-1;i<2;i++) {
        for (int j=-1;j<2;j++) {
            int cur_row = r + i;
            int cur_col = c + j;
            if (is_valid_row_col(cur_row,cur_col)) {
                if (is_bomb(cur_row,cur_col)) {
                    counter++;
                }
            }
        }
    }
    set(r,c,counter);
}

// PRIVATE
void B::score_a_bomb(int r, int c) {
    for (int i=-1;i<2;i++) {
        for (int j=-1;j<2;j++) {
            int cur_row = r + i;
            int cur_col = c + j;
            if (is_valid_row_col(cur_row,cur_col)) {

                // now we have a valid row and col
                // need to compute the number of
                // bombs touching
                countbombs(cur_row,cur_col);

            }
        }
    }    

}

// will take the board and
// zero out anything not a bomb
// the compute the numbers
// PRIVATE
void B::score() {
    reset(); // sets zeros in non bombs
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            if (is_bomb(i,j)) {
                score_a_bomb(i,j);
            }
        }
    }
}

void B::clear() {
    // set everything to zero
    // THIS REMOVES BOMBS
    for(int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            set(i,j,0);
        }
    }
}

void B::reset() {
    // set counters to zero
    // LEAVE BOMBS
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
                int val = get(i,j);
                if (val==0) {
                    // empty
                    DrawRectangle(j*32,
                        i*32,31,31,BLACK);
                } else {
                    // put counter on screen
                    DrawText(TextFormat("%i",val),
                        j*32+12,i*32+12,FONTSIZE,MAROON);
                }
            }
        }
    }
}

void B::repr() {
    for(int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            int val = get(i,j);
            printf("%d ",val);
        }
        printf("\n");
    }
}