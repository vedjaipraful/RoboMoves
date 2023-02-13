#include <iostream>
#include "TestRobot.h"
#include <cassert>

bool TestRobot::testRobotPlace() {
    Robot robot;
    
    // Test correct placement
    bool ret = robot.Place(0, 0, 'N');
    assert(ret == true);
    int x_pos = robot.getCurrentxPosition();
    int y_pos = robot.getCurrentyPosition();
    assert(x_pos == 0);
    assert(y_pos == 0);
    FacingDirection dir = robot.getCurrentFacingDirection();
    assert(dir == FacingDirection::NORTH);
    cout << "Test correct placement 1 OK" << endl;

    ret = robot.Place(3, 4, 'E');
    assert(ret == true);
    x_pos = robot.getCurrentxPosition();
    y_pos = robot.getCurrentyPosition();
    assert(x_pos == 3);
    assert(y_pos == 4);
    dir = robot.getCurrentFacingDirection();
    assert(dir == FacingDirection::EAST);
    cout << "Test correct placement 2 OK" << endl;

    // Test out of bound x 
    ret = robot.Place(5, 0, 'N');
    assert(ret == false);
    x_pos = robot.getCurrentxPosition();
    y_pos = robot.getCurrentyPosition();
    assert(x_pos == 3);
    assert(y_pos == 4);
    dir = robot.getCurrentFacingDirection();
    assert(dir == FacingDirection::EAST);
    cout << "Test incorrect x OK" << endl;

    // Test out of bound y
    ret = robot.Place(1, 6, 'N');
    assert(ret == false);
    x_pos = robot.getCurrentxPosition();
    y_pos = robot.getCurrentyPosition();
    assert(x_pos == 3);
    assert(y_pos == 4);
    dir = robot.getCurrentFacingDirection();
    assert(dir == FacingDirection::EAST);
    cout << "Test incorrect y OK" << endl;
    
    // Test incorrect direction
    
    return true;
}

bool TestRobot::testRobotMove() {
    // test correct move
    Robot robot;
    
    bool ret = robot.Place(0, 0, 'N');
    assert(ret == true);
    // move 1 North
    ret = robot.Move();
    assert(ret == true);
    // move 1 North
    ret = robot.Move();
    assert(ret == true);
    
    int x_pos = robot.getCurrentxPosition();
    int y_pos = robot.getCurrentyPosition();
    assert(x_pos == 0);
    assert(y_pos == 2);
    FacingDirection dir = robot.getCurrentFacingDirection();
    assert(dir == FacingDirection::NORTH);
    cout << "Test correct y move 1 OK" << endl;
    
    // Incorrect x move
    ret = robot.Place(4, 0, 'E');
    assert(ret == true);
    // move 1 EAST
    ret = robot.Move();
    assert(ret == false);
    x_pos = robot.getCurrentxPosition();
    y_pos = robot.getCurrentyPosition();
    assert(x_pos == 4);
    assert(y_pos == 0);
    dir = robot.getCurrentFacingDirection();
    assert(dir == FacingDirection::EAST);
    cout << "Test incorrect x move 2 OK" << endl;

    // incorrect y move 
    ret = robot.Place(3, 3, 'S');
    assert(ret == true);
    // move 1 SOUTH
    ret = robot.Move();
    assert(ret == true);
    // move 1 SOUTH
    ret = robot.Move();
    assert(ret == true);
    // move 1 SOUTH
    ret = robot.Move();
    assert(ret == true);
    // move 1 SOUTH
    ret = robot.Move();
    assert(ret == false);
    x_pos = robot.getCurrentxPosition();
    y_pos = robot.getCurrentyPosition();
    assert(x_pos == 3);
    assert(y_pos == 0);
    dir = robot.getCurrentFacingDirection();
    assert(dir == FacingDirection::SOUTH);
    cout << "Test incorrect y move 3 OK" << endl;
    
    return true;
}

bool TestRobot::testRobotLeft() {
    // check direction update for left operations
    Robot robot;
    
    bool ret = robot.Place(0, 0, 'N');
    assert(ret == true);
    // left 
    robot.Left();
    
    // Left again
    robot.Left();
    
    FacingDirection dir = robot.getCurrentFacingDirection();
    assert(dir == FacingDirection::SOUTH);
    cout << "Test correct 2 lefts OK" << endl;
    
    // left 
    robot.Left();
    // Left again
    robot.Left();
    
    dir = robot.getCurrentFacingDirection();
    assert(dir == FacingDirection::NORTH);
    cout << "Test correct 2 more lefts OK" << endl;

    return true;
}

bool TestRobot::testRobotRight() {
    // check direction update for right operations
    Robot robot;
    
    bool ret = robot.Place(3, 3, 'E');
    assert(ret == true);
    // left 
    robot.Right();
    
    // Left again
    robot.Right();
    
    FacingDirection dir = robot.getCurrentFacingDirection();
    assert(dir == FacingDirection::WEST);
    cout << "Test correct 2 rights OK" << endl;
    
    // left 
    robot.Right();
    // Left again
    robot.Right();
    
    dir = robot.getCurrentFacingDirection();
    assert(dir == FacingDirection::EAST);
    cout << "Test correct 2 more rights OK" << endl;

    return true;
}

bool TestRobot::testRobotReport() {
    return false;
}
