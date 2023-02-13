#pragma once
#include <string>
#include <tuple>
using namespace std;

// facing directions
enum FacingDirection {NORTH, SOUTH, WEST, EAST};
static const char* FacingDirectionString[] = {"NORTH", "SOUTH", "WEST", "EAST"};

class Robot
{
    private : 
        int _x; // x position on board
        int _y; // y position on board
        FacingDirection _direction;

    public :
        Robot();
        ~Robot();
        Robot(int x, int y, FacingDirection direction);
        // get current position as a tuple
        tuple<int, int> getCurrentPosition();
        int getCurrentxPosition();
        int getCurrentyPosition();

        // set the current position
        void setCurrentPosition(int x, int y);

        // get the facing direction as enum value
        FacingDirection getCurrentFacingDirection();

        // get Facind direction as string
        const char* getCurrentFacingDirectionString();

        // set the facing direction
        void setCurrentFacingDirection(FacingDirection direction);

        // main commands on the robot
        void Left();
        void Right();
        bool Move();
        bool Place(int x, int y, char direction);
        bool Place(int x, int y, FacingDirection direction);
        void Report();
};
