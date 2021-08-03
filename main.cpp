#include <cstdio>
#include <raylib.h>
#include "b.h"

const int W = 400;
const int H = 400;
#define SIZE 10

int main() {

    B board(10,10);
    board.init(5);
    
    InitWindow(W,H,"minesweeper");
    SetTargetFPS(30);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        board.render();


        EndDrawing();
    }

    CloseWindow();

    return 0;
}
