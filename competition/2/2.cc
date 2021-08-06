#include <iostream>
#include <vector>
#include <unordered_map>

struct Link{
	bool flag = false;
	std::vector<int> next;
};

int dfs(std::unordered_map<std::string, int> stu, Link *list, int i){
	if(list[i].flag)
		return 0;
	list[i].flag = true;	
	for(size_t j = 0; j<list[i].next.size(); ++j){
		if(!list[list[i].next[j]].flag){
			dfs(stu,list,list[i].next[j]);
		}
	}
	return 1;
}
int main(){
	int num,cp,zu=0;
	std::cin>>num>>cp;
	std::unordered_map<std::string, int> stu;
	Link* list = new Link[num];
	for(int i=0;i<num;++i){
		std::string temp;
		std::cin>>temp;
		stu.insert(std::make_pair(temp,i));	
	}
	for(int i=0; i<cp; ++i){
		std::string temp1,temp2;
		std::cin>>temp1>>temp2;
		auto t1 = stu.find(temp1);
		auto t2 = stu.find(temp2);
		list[t1->second].next.push_back(t2->second);
		list[t2->second].next.push_back(t1->second);
	}
	for(int i =0; i<num; ++i){
		if(dfs(stu,list,i))
			++zu;
	}
	std::cout<<zu<<std::endl;
}
