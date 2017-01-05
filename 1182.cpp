#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int N,S;
vector <int> v;
int arr[21];
int result=0;
bool checkSelection[21]={false};
void makeSubsetF(int count, int j)
{
	
	if(count==j)
	{
		//check vector elements sum
		int sum=0;
	
		for(int l=0;l<v.size(); l++)
		{
			sum+=arr[v[l]];
		}
		//printf("count: %d sum:%d   \n",count,sum);
		if(sum==S) result++;
		return;
	}
	for(int i=0; i<N; i++)
	{
		if(checkSelection[i]) continue; //실수1 checkSelection아님 
		if(v.size()>0)
			if(i < v.back()) continue;//실수 2 순서가 상관이 없으므로 중복이 생김
		v.push_back(i);//벡터에 인덱스를 넣음.
		checkSelection[i]=true;
		makeSubsetF(count+1,j);
		v.pop_back();
		checkSelection[i]=false;
	}
}
int main_1 (void)
{
	scanf("%d %d",&N,&S);
	for(int i=0; i<N; i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int j=1; j<=N; j++)
		makeSubsetF(0,j);
	printf("%d\n",result);
	return 0;
}