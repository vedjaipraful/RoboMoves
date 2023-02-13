# RoboMoves

This is a simple program to write logic for movement of a robot based on its current position and facing direction.
The program is an executable built using the onlinegdb compiler.

This program contains the following files - 
    1. main.cpp
    2. Robot.h
    3. Robot.cpp
    4. Board.h
    5. Board.cpp
    6. TestRobot.h
    7. TestRobot.cpp

### Asumptions - 
    1. The robot position is initialized to 0, 0, NORTH
    2. Board size is currently fixed at 5x5
    3. There is a single robot on the board and all the operations are executed for this robot instance only
    4. The invalid operation is not allowed for the robot
        a. incorrect x coordinate (0 <= x < 5)
        b. incorrect y coordinate (0 <= y < 5)
        c. incorrect direction indicator (N, S, E, W are the ones allowed by user for the moment. Any other character is invalid.)

### Robot.h and Robot.cpp
    Robot class and the functionality.
    Robot has 5 functions - 
      1. Place(int x, int y, char direction)
        This will initialize the position of the robot on the imaginary board.
        Checks for x, y and direction constraints.
        If all okay, sets the information on the robot's data members
        If there is failure, then the robot remains where it was.
      2. Left()
        Updates robot data member representing direction by turning the direction in the counter-clockwise direction. 
        If the direction was NORTH, it will be updated to WEST now.
        If the direction was SOUTH, it will be updated to EAST now.
        If the direction was EAST, it will be updated to NORTH now.
        If the direction was WEST, it will be updated to SOUTH now.
      3. Right()
        Updates robot data member representing direction by turning the direction in the clockwise direction. 
        If the direction was NORTH, it will be updated to EAST now.
        If the direction was SOUTH, it will be updated to WEST now.
        If the direction was EAST, it will be updated to SOUTH now.
        If the direction was WEST, it will be updated to NORTH now.
      4. Move()
        Considers the one step move constraints for x or y and direction to move, and moves the robot one step only in the direction it is facing.
        if the move is not possible, there is a message printed and the operation is cancelled. Robot remains where it was.
      5. Report()
        This function prints the current x coordinate, y coordinate and the facing direction string to the output.

### main.cpp 
    Entry point to the program.
    It will show the list of commands that can be executed.
    The user can input a single character (upper case or lower case) to indicate the operation to be performed on the robot.
    The operations can be fired by the user each time. The details are captured on the Robot class.
    If an operation like Place() or Move() fails, there will be a message/trace shown on the console.
    There is a testmain() method in this file to run only the test cases. The user on the first choice of input for the robot command, could use the option 'T' or 't' to run the test cases. After the test cases are run, the program exits.

### TestRobot.h and TestRobot.cpp
    Simple test cases to check the various operations of Robot class.
	
### Board.h and Board.cpp
    Created this class to cater to the visual impact for the program, but did not implement the details.
    Currently it is holding 2 global variables to define the max size of the board. Currently set to 5 x 5
