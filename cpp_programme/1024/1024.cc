#include <iostream>
#include <stdio.h>
#include <queue>

namespace{
using std::priority_queue;

//present a node of the tree
struct link{
	double w;
	link *left;
	link *right;
};

class Solve{
 public:
	Solve(){
		scanf("%d", &N_);
		key_ = new link[N_];
		in_p_ = new link[N_];
		out_p_ = new link[N_ + 1];
		for(int i = 0; i < N_; ++i){
			scanf("%lf", key_ + i);
		}
		for(int i = 0; i < N_; ++i)
			scanf("%lf", key_ + i);
		for(int i = 0; i < N_ + 1; ++i)
			scanf("%lf", key_ + i);
	}
	~Solve(){
		delete []key_;
		delete []in_p_;
		delete []out_p_;
	}

	double cal_weight(){
		//dfs
	}

	void Get_Answer(){
		//heap
		
	}

	void Print(){
		printf("%lf\n",weight_);
	}
 private:
	int N_;
	link *key_;
	link *in_p_;
	link *out_p_;
	double weight_ = 0;
};
}//namespace


int main(){
	int num;
	scanf("%d", &num);
	Solve *foo = new Solve[num];
	for(int i = 0; i < num; ++i)
		foo[i].Print();
	delete foo;
}
