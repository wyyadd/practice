#include <iostream>
#include <stdio.h>
#include <vector>

namespace{
using std::vector;

struct Edge{
 vector<int> next_;
};

class Tree{
 public:
	Tree(){}
	~Tree(){
		delete[] head_;
	}

	void Initial(){
		scanf("%d",&num_);
		head_ = new Edge[num_+1];
		for(int i = 1; i< num_; ++i){
			int a,b;
			scanf("%d %d", &a, &b);
			head_[a].next_.push_back(b);
			head_[b].next_.push_back(a);
		}
		max_ = Get_Answer(1,0);
	}

	int Get_Answer(int po, int former_po){
		if(head_[po].next_.size() == 1 && po != 1)
			return 1;
		int temp_max_1 = 0;
		int temp_max_2 = 1;
		for(int i = 0; i < (int)head_[po].next_.size(); ++i){
			int new_po = head_[po].next_[i];
			if(new_po != former_po)
				temp_max_1 += Get_Answer(new_po,po); 
			else 
				continue;
			for(int j = 0; j < (int)head_[new_po].next_.size(); ++j){
				int new_new_po = head_[new_po].next_[j];
				if(new_new_po != po)
					temp_max_2 += Get_Answer(new_new_po,new_po);
			}
		}
		return std::max(temp_max_1, temp_max_2);
	}
			
	void Print(){
		printf("%d\n",max_);
	}

 private:
	int num_;
	Edge* head_;
	int max_;
};
}//namespace

int main(){
	int t;
	scanf("%d",&t);
	Tree* foo = new Tree[t];
	for(int i = 0; i < t; ++i)
		foo[i].Initial();
	for(int i = 0; i < t; ++i)
		foo[i].Print();
	delete[] foo;
}
