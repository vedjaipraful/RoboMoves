#include <iostream>
#include "Robot.h"
#include "Board.h"

//default constructor - default starting position
Robot::Robot() {
    _x = 0;
    _y = 0;
    _direction = FacingDirection::NORTH;
}

Robot::~Robot() {
    
}

Robot::Robot(int x, int y, FacingDirection direction) {
    _x = x;
    _y = y;
    _direction = direction;
    
}

tuple<int, int> Robot::getCurrentPosition() {
    return make_tuple(_x, _y);
}
int Robot::getCurrentxPosition() {
    return _x;
}
int Robot::getCurrentyPosition() {
    return _y;
}

void Robot::setCurrentPosition(int x, int y) {
    _x = x;
    _y = y;
}

FacingDirection Robot::getCurrentFacingDirection() {
    return _direction;    
}

const char* Robot::getCurrentFacingDirectionString() {
    return FacingDirectionString[_direction];    
}

void Robot::setCurrentFacingDirection(FacingDirection direction) {
    _direction = direction;
}

// turn left
void Robot::Left() {
    switch(_direction) {
        case FacingDirection::NORTH :
            _direction = FacingDirection::WEST;
            break;
        case FacingDirection::SOUTH :
            _direction = FacingDirection::EAST;
            break;
        case FacingDirection::EAST :
            _direction = FacingDirection::NORTH;
            break;
        case FacingDirection::WEST :
            _direction = FacingDirection::SOUTH;
            break;
    }    
}

// turn right
void Robot::Right() {
    switch(_direction) {
        case FacingDirection::NORTH :
            _direction = FacingDirection::EAST;
            break;
        case FacingDirection::SOUTH :
            _direction = FacingDirection::WEST;
            break;
        case FacingDirection::EAST :
            _direction = FacingDirection::SOUTH;
            break;
        case FacingDirection::WEST :
            _direction = FacingDirection::NORTH;
            break;
    }    
}

// move only one step in the facing direction
bool Robot::Move() {
    bool ret = false;
    
    // check if move is possible and then only move
    if(_direction == FacingDirection::NORTH && _y + 1 < BoardSizeY) {
        _y += 1;
    }
    else if(_direction == FacingDirection::SOUTH && _y - 1 > -1) {
        _y -= 1;
    }
    else if(_direction == FacingDirection::EAST && _x + 1 < BoardSizeX) {
        _x += 1;
    }
    else if(_direction == FacingDirection::WEST && _x - 1 > -1) {
        _x -= 1;
    }
    else {
        cout << "Spill over ! Cannot move because x = " << _x << " y = " << _y << " direction is " << getCurrentFacingDirectionString() << endl; 
        return ret;
    }
    ret = true;
    return ret;
}

// place the robot at the desired location and direction
bool Robot::Place(int x, int y, char direction) {
    FacingDirection direction2;
    switch(direction) {
        case 'N':
            direction2 = FacingDirection::NORTH;
            break;
        case 'S':
            direction2 = FacingDirection::SOUTH;
            break;
        case 'E':
            direction2 = FacingDirection::EAST;
            break;
        case 'W':
            direction2 = FacingDirection::WEST;
            break;
        default :
            return false;
    }
    return Place(x, y, direction2);
}

bool Robot::Place(int x, int y, FacingDirection direction) {
    bool ret = false;
    if(x < 0 || x >= BoardSizeX || y < 0 || y >= BoardSizeY) {
        cout << "Placement out of bounds" << endl;
        return ret;
    }
    if( direction != FacingDirection::NORTH && 
        direction != FacingDirection::SOUTH &&
        direction != FacingDirection::EAST &&
        direction != FacingDirection::WEST ) {
        cout << "Incorrect Direction" << endl;
        return ret;
    }

    _x = x;
    _y = y;
    _direction = direction;
    ret = true;
    return ret;
}

// report in the string format
void Robot::Report() {
    cout << "Output - " << endl;
    cout << _x << " " << _y << " " << getCurrentFacingDirectionString() << endl;
}

