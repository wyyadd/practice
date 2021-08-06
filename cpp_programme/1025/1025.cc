#include <stdio.h>
#include <iostream>
namespace{

class Solve{
 public:
  void List(){
		int* map=new int[num_];
		for(int i = num_-1;i>=0;--i){
			int max=1;
			for(int j = i+1;j<num_;++j){
				if(arr_[i]<=arr_[j]){
					if(map[j]+1>max)
						max=map[j]+1;
				}
			}
		map[i]=max;
		}
		for(int i=0;i<num_;++i){
			if(map[i]>max_)
				max_=map[i];
		}
		delete[] map;
	}
	
	void Print(){
		List();
		printf("%d\n",max_);
	}
	
	void Initial(){
		scanf("%d",&num_);
		if(num_>10000)
			exit(1);
		max_=0;
		arr_ = new int[num_];
		for(int i=0;i<num_;++i)
			scanf("%d",arr_+i);
}

	Solve(){}
 
  ~Solve(){
		delete[] arr_;
	};

 private:
  int num_;
	int max_;
	int* arr_;
};
} // namespace

int main(){
	int num;
	scanf("%d",&num);
	if(num>10)
		exit(1);
	Solve* foo=new Solve[num];
	for(int i=0;i<num;++i)
		foo[i].Initial();
	for(int i=0;i<num;++i)
		foo[i].Print();
	delete[] foo;
}
