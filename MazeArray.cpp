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
    location.x = X;
    location.y = Y;
    maze = m;
    parent = p;
}

Maze::Node::Node(xyCord loc, Maze * m, Node * p)
{
    location = loc;
    maze = m;;
    parent = p;
}


xyCord Maze::Node::getxyCord()
{
    return location;
}

void Maze::Node::expandNode()
{
    //all children initialy set to null so only add the ones that need it
    
    //make sure inside of maze
    if((location.x < 0)||(location.x >= maze->getXsize() )||(location.y < 0 )||(location.y >= maze->getYsize() ))
        return;
    
    //get north child
    if( ((location.y -1) >= 0) ) // check if in bounds
    {
        if(maze->getChar(location.x, location.y-1) == ' ' )// if there is a space add child
        {
    
            if(parent == NULL)// if no parent add child
                NorhChild = new Node(location.x,location.y-1, maze, this);
            
            else if((parent->location.x == location.x ) && (parent->location.y == location.y-1)  )//if node matches parent dont add
                NorhChild = NULL;
            
            else
                NorhChild =new Node(location.x,location.y-1, maze, this);
        }
    }
    
    
    //get east child
    if((location.x +1) < maze->getXsize() )
    {
        if(maze->getChar(location.x+1, location.y) == ' ' )// if there is a space add child
        {
            if(parent == NULL)
                EastChild = new Node(location.x+1, location.y, maze, this );
        
            else if( (parent->location.x == location.x+1 ) && (parent->location.y == location.y)  )
                EastChild = NULL;
            
            else
                EastChild = new Node(location.x+1, location.y, maze, this );
        }
    }
    
    
    //get south child
    if((location.y + 1) < maze->getYsize() )
    {
        if(maze->getChar(location.x, location.y+1) == ' ' )// if there is a space add child
        {
            if(parent == NULL)
                SouthChild = new Node (location.x, location.y +1, maze, this);
        
            else if((parent->location.x == location.x ) && (parent->location.y == location.y + 1))
                SouthChild = NULL;
        
            else
                SouthChild = new Node (location.x, location.y +1, maze, this);
        }

    }
    
    //get west child
    if((location.x -1) >= 0)
    {
        if(maze->getChar(location.x-1, location.y) == ' ' )// if there is a space add child
        {
            if(parent == NULL)
                WestChild = new Node(location.x -1,location.y, maze,this);
        
            else if((parent->location.x == location.x - 1) && (parent->location.y == location.y))
                WestChild = NULL;
        
            else
                WestChild = new Node(location.x -1,location.y, maze,this);
        }
        
        
    }
    
    
}



Maze::Node * Maze::Node::getParent()
{
    return parent;
}
Maze::Node * Maze::Node::getNorhChild()
{
    return NorhChild;
}
Maze::Node * Maze::Node::getEastChild()
{
    return EastChild;
}
Maze::Node * Maze::Node::getSouthChild()
{
    return SouthChild;
}
Maze::Node * Maze::Node::getWestChild()
{
    return WestChild;
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


Maze::Node * Maze::getStartNode()
{
    //error checking
    if((Xsize <= 0) || (Ysize<=0))
    {
        return NULL;
    }
    
    for(int x = 0; x < Xsize; x++)
    {
        for(int y = 0; y < Ysize; y++)
        {
          if(cMap[y][x] == 'P')
              return new Node(x,y,this, NULL);
        }
    }
    
    //if it gets here no "P" found so return error
    return NULL;
}




//WORLD