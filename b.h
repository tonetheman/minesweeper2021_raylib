#ifndef B_H_
#define B_H_


const int B_BOMB = -1;


struct B {
    int rows, cols;
    int ** data;

    B(int,int);
    ~B();


    int get(int r, int c);
    void set(int r, int c, int val);
    void score();
    void clear();
    void reset();
    bool is_bomb(int r, int c);

    void repr();    
    void init(int bomb_count);
    void render();

    private:
    void score_a_bomb(int r, int c);
    bool is_valid_row_col(int r, int c);
    void countbombs(int r, int c);
};

#endif