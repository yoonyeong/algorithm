#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
int N;
int checkSelection[9]={0,};

void putInVector(int count)
{
	int i;
	//base
	if(count==N)//출력하기
	{
		int p;
		for(p=0; p<v.size()-1; p++)//실수2 v.size()-1해줘야함 -1
		{
			printf("%d",v[p]);
			printf(" ");
		}
		printf("%d\n",v[p]);
	}
	for(i=1; i<=N ; i++)
	{
		if(checkSelection[i]) continue;
		else 
		{
			v.push_back(i);	
			checkSelection[i]=1;
			putInVector(count+1);
			v.pop_back();
			checkSelection[i]=0;
		}
	}
}
int main (void)
{
	scanf("%d",&N);
	putInVector(0);
	return 0;
}