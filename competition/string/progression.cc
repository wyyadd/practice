#include <stdio.h>
#include <iostream>
namespace{
using std::cin;
using std::cout;
using std::endl;
class Solve{
 public:
	Solve(){}
	~Solve(){};
	void Get_Answer(){
		cin>>length_;
		int arr1,arr2;
		int sub1,sub2;
		int flag1 = 2, flag2 = 0, flag3 = 1, pre = 2, flag4 = 0;
		max_ = 2;
		cin>>arr1>>arr2;
		sub1 = arr1-arr2;
		arr1 = arr2;

		for(int i = 2; i < length_; ++i){
			cin>>arr2;
			sub2 = arr1-arr2;
			int temp = sub1 - sub2;
			if(temp == 0){
				flag4 = sub1;
				++flag1;
				max_ = std::max(flag1,max_);
				if(!flag3)
					++pre;
				else
					flag2= 0;
			}
			else{
				if(flag3){
					if(sub2+flag2 == 2*flag4){
						flag1+=2;
						max_ = std::max(flag1,max_);
						flag3 = 0;
					}
					flag2 = sub2;
					if(i == length_ - 1)
						max_ = std::max(++flag1,max_);
				}
				else{
					flag2 = temp;
					flag1 = pre;
					flag3 = 1;
					pre = 2;
				}
			}
			arr1 = arr2;
			sub1 = sub2;
		}
		cout<<max_<<endl;	
	}
		
 private: 
	long long int length_;
	int max_;
};
}//namespcae

int main(){
	int T;
	cin>>T;
	Solve* foo = new Solve[T];
	for(int i = 0; i < T; ++i){
		printf("Case #%d: ", i+1);
		foo[i].Get_Answer();
	}
	delete[] foo;
}
