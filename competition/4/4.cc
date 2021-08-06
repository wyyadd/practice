#include <stdio.h>
int main(){
	int num;
	scanf("%d",&num);
	for(int i = 0; i < num; ++i){
		float p1,p2,t1,t2;
		scanf("%f%f%f%f",&p1,&t1,&p2,&t2);
		float flag = t1/p1 + t2/p2;	
		if(flag <= 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

