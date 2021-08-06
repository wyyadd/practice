#ifndef	LAB9_MAZE_MAZE_H_
#define LAB9_MAZE_MAZE_H_

namespace maze{
class Maze{
 public:
	Maze();
	~Maze();
	void InitMaze();
	void ShowMaze();
	void SetMaze(int, int);
	int Get_Row();
	int Get_Column();
	int** Get_Map();
 private:
	int row_;
	int column_;
	int **map_;
};
}//namespace maze

#endif //LAB9_MAZE_MAZE_H_
