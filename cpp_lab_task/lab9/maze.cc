#include "maze.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>

namespace maze{
Maze::Maze(){
	row_ = 9;
	column_ = 9;
	map_ = new int* [row_];
	for(int i = 0; i < row_; ++i)
		map_[i] = new int[column_];
	InitMaze();
}

Maze::~Maze(){
	for(int i = 0; i < row_; ++i)
		delete[] map_[i];
}

void Maze::InitMaze(){
	int map[9][9] = {
		{0, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 0, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 0}
	};
	for(int i = 0; i < row_; ++i)
		for(int j = 0; j < column_; ++j)
			map_[i][j] = map[i][j];
}

void Maze::ShowMaze(){
	system("clear");
	for(int i = 0; i < row_; ++i){
		for(int j = 0; j < column_; ++j){
			if(map_[i][j] == 1)
				printf(" %c ", '&');
			if(map_[i][j] == 0)
				printf(" %c ", ' ');
			if(map_[i][j] == 2)
				printf(" %c ", '*');
			}
			printf("\n");
		}
	printf("\n w:up, s:down, a:left, d:right, q:quit, r:restart\n");
}

void Maze::SetMaze(int x, int y){
	map_[x][y] = 2;
	ShowMaze();
	map_[x][y] = 0;
}

int Maze::Get_Row(){
	return row_;
}

int Maze::Get_Column(){
	return column_;
}

int** Maze::Get_Map(){
	return map_;
}
}//namespace maze
