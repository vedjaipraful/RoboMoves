/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include "Robot.h"
#include "Board.h"
#include "TestRobot.h"
#include <cassert>

using namespace std;

// test function
int testmain();

// Main Controls
int main()
{
    cout << "Welcome to RoboWorld !" << endl;
    cout << "   Commands : " << endl;
    cout << "      Help   ('H' or 'h')" << endl;
    cout << "      Place  ('P' or 'p')" << endl;
    cout << "      Move   ('M' or 'm')" << endl;
    cout << "      Left   ('L' or 'l')" << endl;
    cout << "      Right  ('R' or 'r')" << endl;
    cout << "      Report ('O' or 'o')" << endl;
    cout << "      Exit   ('E' or 'e')" << endl;
    cout << "      Test   ('T' or 't')" << endl;
    cout << "Enter Robo command - " << endl;

    char option = ' ';
    cin >> option;
    
    if(option == 'T' || option =='t') {
        testmain();
        return 0;
    }
    
    Robot* robot = new Robot(0, 0, FacingDirection::NORTH);
    
    // keep running until Exit command is requested
    while(option != 'E' && option != 'e') {
        //cout << "option = " << option << endl;

        switch(option) {
            // to be implemented
            case 'H' :
            case 'h' :
                cout << "Help commands - Exit (E or e), Place (P or p), M (M or m), Left (L or l), Right (R or r), Report (O or o)" << endl;
                break;
            case 'P' :
            case 'p' :
            {
                // take the input x, y and direction values
                // cout << "Place" << endl;
                int x = 0;
                int y = 0;
                cout << "x = ";
                cin >> x;
                cout << "y = ";
                cin >> y;
                char direction;
                cout << "direction (N, S, E, W) = ";
                cin >> direction;
                bool ret = robot->Place(x, y, direction);
                // in case of failure, showing a simple warning to indicate something wrong
                if(ret == false)
                {
                    cout << "Place is not possible - One or more of the input values are out of bounds" << endl;
                }
                break;
            }
            case 'M' :
            case 'm' :
            {
                // move one step in the direction in which the robot is currently facing
                //cout << "Move" << endl;
                bool ret = robot->Move();
                if(ret == false)
                {
                    cout << "Move is not possible - Either change direction or run new place command" << endl;
                }
                break;
            }
            case 'L' :
            case 'l' :
            {
                // turn the facing direction conter-clockwise
                //cout << "Left" << endl;
                robot->Left();
                break;
            }
            case 'R' :
            case 'r' :
            {
                // turn the facing direction clockwise
                //cout << "Right" << endl;
                robot->Right();
                break;
            }
            case 'O' :
            case 'o' :
            {
                // show the current location and facing direction of the robot
                //cout << "Report" << endl;
                robot->Report();
                break;
            }
            default :
                cout << "Incorrect command, Try Again !" << endl;
                break;
        }
        cout << "Enter the next command for the robot - " << endl;
        cin >> option;
        //cout << option << endl;
    }
    if(robot)
        delete robot;

    return 0;
}

int testmain()
{
    TestRobot testrobot;
    bool ret = testrobot.testRobotPlace();
    assert(ret == true);
    cout << "Place() test OK" << endl;
    ret = testrobot.testRobotMove();
    assert(ret == true);
    cout << "Move() test OK" << endl;
    ret = testrobot.testRobotLeft();
    assert(ret == true);
    cout << "Left() test OK" << endl;
    ret = testrobot.testRobotRight();
    assert(ret == true);
    cout << "Right() test OK" << endl;
    return 0;
}