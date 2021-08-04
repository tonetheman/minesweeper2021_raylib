

# minesweepr

Really bad but hopefully working version of minesweeper, using raylib.

I started trying to compile for HTML5. So I made some source changes
in main.cpp to support this.

Need to read how to pass Makefile variables a little more.

## links and stuff I did

### compile for web with raylib
https://github.com/raysan5/raylib/wiki/Working-for-Web-(HTML5)

### suggested main loop
https://github.com/raysan5/raylib/blob/master/examples/core/core_basic_window_web.c

### installing emsdk
https://emscripten.org/docs/getting_started/downloads.html

### mostly working suggestions on how to recompile raylib with emcc
https://emscripten.org/docs/getting_started/downloads.html

I had to change my Makefile differently than suggested but not by much.

Error messages document referenced during adjustments to makefile
https://www.gnu.org/software/make/manual/html_node/Error-Messages.html

### and finally how to pass variables to makefile
This is prob dead easy. I have not done it in a while and make is picky

https://stackoverflow.com/questions/2826029/passing-additional-variables-from-command-line-to-make



