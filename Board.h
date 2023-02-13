#pragma once
using namespace std;

// currently using a global variable to define the max x and y.
const int BoardSizeX = 5;
const int BoardSizeY = 5; 

// can hold all configuration for the board. Will be useful for UI drawing
class Board
{
    private : 
        int _max_x;
        int _max_y;
    public :
    
        Board() {_max_x = 0; _max_y = 0;};
        ~Board();
        void setBoardSize(int x, int y) {
            _max_x = x;
            _max_y = y;
        };
        int getBoardMaxX() { return _max_x; };
        int getBoardMaxY() { return _max_y; };
};
