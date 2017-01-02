#include <stdio.h>
#include <string.h>
int main(void)
{
	int row,col;
	char arr[11][11];
	char result[11][11];//실수5 기본 0넣어놓아야하는데 char라 그런지
	char temp;			//{'0'},{'0',} 가 다 안통하네..
	scanf("%d %d",&row,&col); //실수2 enter가 다음 scanf에 들어감
	scanf("%c",&temp);
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			scanf("%c",&arr[i][j]); //실수1 %d로 0111100 에서 0 하나만
			//printf("%c",arr[i][j]);     받아올 수는 없음 1111을 받을수도있고
			result[i][j]='0';
		}
		scanf("%c",&temp);
	}
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(arr[i][j]=='1') //실수2 ''붙여주기 실수3 char는 ==로 비교불가
			{					//실수4 이런식으로 하나씩 출력하고 바꾸면 
				//arr[i][j]='0'; //이미 출력된 부분이 1로 바뀌면 출력불가하고
				result[i][col-j-1]='1';//1로 바뀐 부분과 원래 1인게 구분 불가
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