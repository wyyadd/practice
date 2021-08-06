#include<unordered_set>
#include<unordered_map>
#include<iostream>
#include<stdio.h>

namespace {
	using std::string;
	std::unordered_set<int> map;
	std::unordered_map<std::string,int> map2;
	void Initial_Map() {
		map.insert(15);
		map.insert(16);
		map.insert(17);
		map.insert(18);
		map.insert(56);
		map.insert(57);
		map.insert(58);
		map.insert(66);
		map.insert(67);
		map.insert(68);
		map.insert(77);
		map.insert(78);
		map2.insert(std::make_pair("slash",1));
		map2.insert(std::make_pair("jink",2));
		map2.insert(std::make_pair("peach",3));
		map2.insert(std::make_pair("nullification",4));
		map2.insert(std::make_pair("snatch",5));
		map2.insert(std::make_pair("savage",6));
		map2.insert(std::make_pair("archery",7));
		map2.insert(std::make_pair("duel",8));
	}
} //namespace

int main(){
	int num;
	Initial_Map();
	scanf("%d",&num);
	for(int i = 0; i < num; ++i){
		string str1;
		string str2;
		std::cin>>str1;
		std::cin>>str2;
		int f1 = map2[str1];
		int f2 = map2[str2];
		if(map.find(f1*10+f2) != map.end())
			printf("YES\n");
		else
			printf("NO\n");
	}
}
