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
    Maze::Node * start = temp.getStartNode();
    cout << start->getxyCord().x << " "<< start->getxyCord().y << " Starting Position" << endl <<endl;
    
    for(int y = 0; y < temp.getYsize(); y++)
    {
        for(int x = 0; x <= temp.getXsize(); x++)
        {
            cout <<temp.getChar(x,y);
        }
    }
    
    cout << endl;
    
    
    Maze::Node * pointer;
    
    start->expandNode();
    
    cout << endl <<start->getNorhChild()<< endl << start->getEastChild() << endl << start->getSouthChild() << endl << start->getWestChild() << endl << "a!!!!!!!!!!!!!!!!!!!!!!!!" << endl<< temp.getChar(20,20)<<endl;
    
    
    pointer = start->getWestChild();
    cout << "Pointer location "<< pointer->getxyCord().x << " " << pointer->getxyCord().y;
    
    cout << "char above " << temp.getChar(pointer->getxyCord().x, pointer->getxyCord().y +1) <<endl ;
    pointer->expandNode();
    cout <<endl << endl <<pointer->getNorhChild()<< endl << pointer->getEastChild() << endl << pointer->getSouthChild() << endl << pointer->getWestChild() << endl;
    /*
    for(int i = 0; i < 4; i++)
    {
        cout << pointer->getxyCord().x << "," << pointer->getxyCord().y << endl;
        pointer->expandNode();
        pointer = pointer->getNorhChild();

    }
    
    */
    return 0;
    
}
