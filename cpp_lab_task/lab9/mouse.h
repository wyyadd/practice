#ifndef LAB9_MAZE_MOUSE_H_
#define LAB9_MAZE_MOUSE_H_

#include "maze.h"

namespace mouse{
class Mouse{
 public:
	Mouse();
	~Mouse();
	bool Move_Up();
	bool Move_Down();
	bool Move_Left();
	bool Move_Right();
	bool Get_Food(int,int);
	bool Reach_Wall(int,int);
	void Reset();
 private:
	int x_;
	int y_;
	maze::Maze maze_;
};
}//namespace mouse

#endif //LAB9_MAZE_MOUSE_H_
