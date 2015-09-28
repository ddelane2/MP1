//
//  MazeArray.cpp
//  MP1
//
//  Created by Erik on 9/24/15.
//  Copyright (c) 2015 Erik. All rights reserved.
//

#include "MazeArray.h"
using namespace std;





//NODE
Maze::Node::Node(int X, int Y, Maze * m, Node * p)
{
    locaction.x = X;
    locaction.y = Y;
    maze = m;
    parent = p;
}

Maze::Node::Node(xyCord loc, Maze * m, Node * p)
{
    locaction = loc;
    maze = m;;
    parent = p;
}


xyCord Maze::Node::getxyCord()
{
    return locaction;
}



//MAZE
Maze::Maze(string pathname)
{
    ifstream inFile(pathname);
    if(inFile.bad())
        return;
    
    string s;
    
    while(!inFile.eof() )
    {
        getline(inFile, s); // get row
        s.append("\n"); // add new line character
        cMap.push_back(s);
    }
    Xsize = (int)(cMap[0].size() - 1);
    Ysize = (int)cMap.size();
    
    inFile.close();

}


string Maze::PrintMaze()
{
    string s;
    for(int i = 0; i < cMap.size(); i++)
    {
        s += cMap[i];
    }
    return s;
}


char Maze::getChar(int x, int y)
{
    return cMap[y][x];
}


int Maze::getXsize()
{
    return Xsize;
}


int Maze::getYsize()
{
    return Ysize;
}


Maze::Node Maze::getStartNode()
{
    //error checking
    if((Xsize <= 0) || (Ysize<=0))
    {
        return Maze::Node (-1,-1,NULL, NULL);
    }
    
    for(int x = 0; x < Xsize; x++)
    {
        for(int y = 0; y < Ysize; y++)
        {
          if(cMap[y][x] == 'P')
              return Node(x,y,this, NULL);
        }
    }
    
    //if it gets here no "P" found so return error
    return Node (-1,-1,NULL,NULL);
}




//WORLD