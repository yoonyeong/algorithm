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
		max=1;//�Ǽ�1 max�ʱ�ȭ�ʿ� �ȱ׷� �ι�°��
		//for�� ���ö� if�� ���� �ȵǸ� ���� max����
		//�־���.
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
	int final_result=result[0];//��� ���� �α�
	for(int j=1; j<N; j++)
	{
		//final_result=result[0]; �Ǽ�2 ���� �θ�
		//for�� �������� 0���̶��� �񱳵�..��
		if(result[j]>final_result)
			final_result=result[j];
	}
	printf("%d\n",final_result);
	return 0;
}