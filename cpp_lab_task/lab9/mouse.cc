#include "mouse.h"

#include "maze.h"
#include <iostream>
#include <stdio.h>

namespace mouse{
Mouse::Mouse(){
	x_ = 0;
	y_ = 0;
}
Mouse::~Mouse(){}

bool Mouse::Move_Up(){
	if(Reach_Wall(x_ - 1, y_))
		return 0;
	--x_;
	maze_.SetMaze(x_, y_);
	if(Get_Food(x_, y_))
		return 1;
	else
		return 0;
}

bool Mouse::Move_Down(){
	if(Reach_Wall(x_ + 1, y_))
		return 0;
	++x_;
	maze_.SetMaze(x_, y_);
	if(Get_Food(x_, y_))
		return 1;
	else
		return 0;
}

bool Mouse::Move_Left(){
	if(Reach_Wall(x_, y_ - 1))
		return 0;
	--y_;
	maze_.SetMaze(x_, y_);
	if(Get_Food(x_, y_))
		return 1;
	else
		return 0;
}

bool Mouse::Move_Right(){
	if(Reach_Wall(x_, y_ + 1))
		return 0;
	++y_;
	maze_.SetMaze(x_, y_);
	if(Get_Food(x_, y_))
		return 1;
	else
		return 0;
}

bool Mouse::Get_Food(int x, int y){
	if(x == maze_.Get_Row()- 1 && y == maze_.Get_Column()- 1)
		return 1;
	return 0;
}

bool Mouse::Reach_Wall(int x, int y){
	int** temp = maze_.Get_Map();
	if(x < 0 || y < 0 || x >= maze_.Get_Row() || y >= maze_.Get_Column())
		return 1;
	if(temp[x][y] == 1)
		return 1;
	return 0;
}

void Mouse::Reset(){
	x_ = 0;
	y_ = 0;
	maze_.SetMaze(x_,y_);
}
}//namespace mouse

