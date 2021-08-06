#include <stdio.h>
#include <iostream>

namespace{
class Solve{
 public:
	Solve(){}
	~Solve(){}
	void Get_Answer(){
		char str1;
		char str2;
//		scanf("%lld",&length_);
//		scanf("%c",&str1);
		std::cin>>length_>>str1;
		int flag = 1;
		//printf("%d ",flag);
		std::cout<<flag<<' ';
		for(int i = 1; i < length_; ++i)	{
			//scanf("%c",&str2);
			std::cin>>str2;
			if(str2 > str1){
				++flag;
				//printf("%d ",flag);
				std::cout<<flag<<' ';
			}	
			else{
				flag = 1;
				//printf("%d ",flag);
				std::cout<<flag<<' ';
			}
			str1 = str2;
		}
		//printf("\n");
		std::cout<<std::endl;
	}
 private:
	long long int length_;
};
}//namespace

int main(){
	int num;
	scanf("%d",&num);
	Solve* foo = new Solve[num];
	for(int i = 0; i < num; ++i){
		printf("Case #%d: ", i+1);
		foo[i].Get_Answer();
	}
	delete[] foo;
}
