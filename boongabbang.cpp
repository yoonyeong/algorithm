#include <stdio.h>
#include <string.h>
int main(void)
{
	int row,col;
	char arr[11][11];
	char result[11][11];//�Ǽ�5 �⺻ 0�־���ƾ��ϴµ� char�� �׷���
	char temp;			//{'0'},{'0',} �� �� �����ϳ�..
	scanf("%d %d",&row,&col); //�Ǽ�2 enter�� ���� scanf�� ��
	scanf("%c",&temp);
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			scanf("%c",&arr[i][j]); //�Ǽ�1 %d�� 0111100 ���� 0 �ϳ���
			//printf("%c",arr[i][j]);     �޾ƿ� ���� ���� 1111�� ���������ְ�
			result[i][j]='0';
		}
		scanf("%c",&temp);
	}
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(arr[i][j]=='1') //�Ǽ�2 ''�ٿ��ֱ� �Ǽ�3 char�� ==�� �񱳺Ұ�
			{					//�Ǽ�4 �̷������� �ϳ��� ����ϰ� �ٲٸ� 
				//arr[i][j]='0'; //�̹� ��µ� �κ��� 1�� �ٲ�� ��ºҰ��ϰ�
				result[i][col-j-1]='1';//1�� �ٲ� �κа� ���� 1�ΰ� ���� �Ұ�
			}
			
			//printf("%c",arr[i][j]);
		}
		//printf("\n");
	}
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			printf("%c",result[i][j]);
		}
		printf("\n");
	}
	return 0;
}