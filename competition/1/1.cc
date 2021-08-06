#include <iostream>
#include <stack>
#include <stdio.h>
int main(){
	int num;
	std::cin>>num;
	if(num<1 || num>100)
		std::exit(1);
	std::stack<std::string> *list = new std::stack<std::string> [num];
	std::cin.ignore();
	for(int i=0; i<num; ++i){
		std::string temp;
		std::getline(std::cin,temp);
		size_t position = temp.find(' ');
		while(position != std::string::npos){
			list[i].push(temp.substr(0,position));
			temp.erase(0,position+1);
		  position = temp.find(' ');
		}
		list[i].push(temp);
	}
	for(int i = 0; i<num; ++i){
		while(!list[i].empty()){
			std::cout<<list[i].top();
			list[i].pop();
			if(!list[i].empty())
			std::cout<<' ';
		}
		std::cout<<std::endl;
	}
	delete[] list;
}
