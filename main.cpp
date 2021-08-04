#include <cstdio>
#include <raylib.h>
#include "b.h"

#ifdef PLATFORM_WEB
#include <emscripten/emscripten.h>
#endif

const int W = 400;
const int H = 400;
#define SIZE 10

B board(10,10);

void UpdateAndDraw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    board.render();


    EndDrawing();
}

int main() {

    //B board(10,10);
    board.init(5);
    board.score();
    board.repr();
    
    InitWindow(W,H,"minesweeper");
#ifdef PLATFORM_WEB
    emscripten_set_main_loop(UpdateAndDraw,0,1);
#else
    SetTargetFPS(30);

    while (!WindowShouldClose()) {
        UpdateAndDraw();
    }
#endif
    CloseWindow();

    return 0;
}
