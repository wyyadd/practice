#include <stdio.h>
#include<iostream>

namespace{
class Solve{
 public:
	Solve(){
		scanf("%d%d%d",&m_,&n_,&target_);
		matrix_ = new int*[m_];
		for(int i = 0; i < m_; ++i){
			matrix_[i] = new int[n_];		
		}
		for(int i = 0; i < m_; ++i){
			for(int j = 0; j < n_; ++j)
				scanf("%d",&matrix_[i][j]);
		}
		flag = false;
	}
	~Solve(){
		for(int i = 0; i < m_; ++i){
			delete[] matrix_[i];
		}
	}

	void Get_Answer(int h, int l){
		if(h < 0 || l == n_)
			return;
		if(matrix_[h][l] == target_){
			flag = true;
			return;
		}
		if(matrix_[h][l] < target_)
			Get_Answer(h,l+1);
		else
			Get_Answer(h-1,l);
	}

	void Print(){
		Get_Answer(m_-1,0);
		if(flag)
			printf("true\n");
		else
			printf("false\n");
	}
 private:
	int** matrix_;	
	int target_;
	int m_;
	int n_;
	bool flag;
};
}//namespace

int main(){
	int num;
	scanf("%d",&num);
	Solve* foo =new Solve[num];
	for(int i = 0; i < num; ++i){
		foo[i].Print();
	}
	delete []foo;
}

/*	void Get_Answer(int h, int l){
		int i,j;
		for(i = l; i < n_; ++i){
			if(matrix_[h][i] == target_){
				flag = true;
				return;
			}
			if(matrix_[h][i]>target_){
				if(i == 0){
					return;
				}
				for(j = h + 1; j < m_; ++j){
					if(matrix_[j][i-1] == target_){
						flag = true;
						return;
					}
					if(matrix_[j][i-1] > target_){
						if(i == 1)
							return;
						for(int k = i - 2; k >=0; --k){
							if(matrix_[j][k] == target_){
								flag = true;
								return;
							}
							if(matrix_[j][k] < target_){
								if(j == m_ - 1)
									return;
								Get_Answer(j+1,k);
								break;
							}
						}
					}
				}
			}
			if(i == n_-1 && target_ > matrix_[h][n_-1]){
				for(j = h; j < m_; ++j){
					if(matrix_[j][i] >= target_){
						if(matrix_[j][i] == target_){
							flag = true;
							break;
						}
						if(matrix_[j][i] > target_){
							if(i == 0)
								return;
							for(int k = i-1; k >=0; --k){
								if(matrix_[j][k] == target_){
									flag = true;
									break;
								}
								if(matrix_[j][k] < target_){
									if(j == m_ - 1)
										return;
									Get_Answer(j+1,k);
									break;
								}
							}
						}
					}
				}
			}
		}
	}
	*/
