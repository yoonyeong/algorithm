#include <stdio.h>
#include <string.h>
int max=0;
int T,W;
int arr[1005];
int cache[3][35][1005]={-1};
int maxf(int a, int b){if(a>b) return a; else return b;}
int f( int treeNum,int changeNum,int time)
{
	int count=0;
	int & ret= cache[treeNum][changeNum][time];
	//printf("f호출  %d %d %d %d\n",treeNum,changeNum,time,count);
	//base case 
	if(time==T+1) {
		return 0;
	}
	//printf("time: %d, treeNum:%d count:%d changeNum:%d \n",time,treeNum,count,changeNum);
	if(changeNum>W) return 0;

	if(ret != -1) {/*printf("cache 사용!\n");*/return ret;}
	if(arr[time]==treeNum) {
		count++;
	}
	
	count+=maxf(f(treeNum,changeNum,time+1),f(3-treeNum,changeNum+1,time+1));//바꾼 것
	ret=count;
	return count;
}
int main(void)
{
	scanf("%d %d",&T,&W);
	for(int i=1; i<=T; i++)
	{
		scanf("%d",&arr[i]);
	}
	memset(cache,-1,sizeof(cache));
	printf("%d",f(1,0,0));
	return 0;
}