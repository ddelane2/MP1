//
//  main.cpp
//  MP1
//
//  Created by Erik on 9/24/15.
//  Copyright (c) 2015 Erik. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "MazeArray.h"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    Maze temp("/Users/Erik/Documents/School/AI/MP1/MP1/input.txt");

    cout << temp.PrintMaze() << endl;
    cout << temp.getXsize() << "x dimmension" << endl;
    cout << temp.getYsize() << "y dimmension" << endl;
    Maze::Node start = temp.getStartNode();
    cout << start.getxyCord().x << " "<< start.getxyCord().y << " Starting Position" << endl ;
    
    return 0;
    
}
