#include "maze.h"
#include "mouse.h"

#include <iostream>
#include <stdio.h>

namespace game{
class Game{
 public:
	Game(){}
	~Game(){}
	void PlayGame(){
		char choice;
		bool flag = true;
		mouse_.Reset();
		while(flag){
			//std::cin>>choice;
			choice = getchar();
			switch(choice){
				case 'W':
				case 'w':{ 
					flag = !mouse_.Move_Up();
				}break;
				case 'S':
				case 's':{ 
					flag = !mouse_.Move_Down();
				}break;
				case 'A':
				case 'a':{ 
					flag = !mouse_.Move_Left();
				}break;
				case 'D':
				case 'd':{ 
					flag = !mouse_.Move_Right();
				}break;
				case 'Q':
				case 'q':flag = false; break;
				case 'R':
				case 'r': mouse_.Reset(); break;
			}
		}
		printf("Congratulation!\n");
	}
 private:
	mouse::Mouse mouse_;
};
}//namespace game
int main(){
	game::Game play;
	play.PlayGame();
}
