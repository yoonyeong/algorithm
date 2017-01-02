#include <stdio.h>
int maxf(int a, int b)
{
	return (a>b)? a: b;
}
int main_1(void)
{
	int N;
	int arr[1005];
	int result[1005]={1,};
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		scanf("%d", &arr[i]);
	}
	int max=0;
	for(int i=1; i<N; i++)
	{
		max=1;//실수1 max초기화필요 안그럼 두번째로
		//for문 들어올때 if문 실행 안되면 이전 max값이
		//넣어짐.
		for(int j=0; j<i; j++)
		{
			if(arr[j] < arr[i])
			{
				max=maxf(max,result[j]+1);
			}
		}
		result[i]=max;
		//printf("result[%d]: %d ",i,result[i]);
	}
	int final_result=result[0];//요기 위로 두기
	for(int j=1; j<N; j++)
	{
		//final_result=result[0]; 실수2 여기 두면
		//for문 돌때마다 0번이랑만 비교됨..ㅠ
		if(result[j]>final_result)
			final_result=result[j];
	}
	printf("%d\n",final_result);
	return 0;
}