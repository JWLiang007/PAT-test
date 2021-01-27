#include <stdio.h>
int main(){
	int num,cur=0,next,result=0;
	scanf("%d",&num);
	for (int i = 0; i < num; i++){
		scanf("%d",&next);
		if(next>cur){
			result += (next-cur)*6;
		}else{
			result += (cur-next)*4;
		}
		result+=5;
		cur = next;
	}
	printf("%d",result);
	return 0;
}