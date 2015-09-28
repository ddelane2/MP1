//
//  MazeArray.h
//  MP1
//
//  Created by Erik on 9/24/15.
//  Copyright (c) 2015 Erik. All rights reserved.
//

#ifndef __MP1__MazeArray__
#define __MP1__MazeArray__

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


class xyCord
{
public:
    int x;
    int y;
    
private:
    
    
};






class Maze // needs copy constructor but that functionality will not be used so screw it
{
public:
    

    class Node// no copy consturctor or assignment operator needed becuase all attributs are assigend by value
    {           // all the pointers of the cildren will be copied aswell important to note
    public:
        Node(int x, int y, Maze * m, Node * p);
        Node(xyCord loc, Maze * m, Node * p);
        
        // gets cordinats of
        xyCord getxyCord();
        
        //expands the current node
        
    private:
        //pointer to associated maze
        Maze * maze;
        
        // x and y coords of the node
        xyCord locaction;
        
        //all pinters to nodes
        Node * parent;
        Node * NorhChild;
        Node * EastChild;
        Node * SouthChild;
        Node * WestChild;
        
        
        
    };
    
    

    
    Maze(string pathname);
    
    //returns values of X and Y sizes of the map
    int getXsize();
    int getYsize();
    
    //returns character located ay given x,y chord
    char getChar(int x, int y);
    
    /*returns a string of a copy of the maze*/
    string PrintMaze();
    
    
    //returns starting node
    Node getStartNode();
    
private:
    vector <string> cMap;
    int Xsize = 0;
    int Ysize = 0;
};






class World
{
public:
    
private:
    
    
};

#endif /* defined(__MP1__MazeArray__) */

