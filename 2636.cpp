#include <stdio.h>
int table[102][102];
int row,col;
int time=0,p=3;
void startClock(int y, int x);
int countCheese();
bool checkCheese();
bool boundaryCheck(int y, int x);
bool changeTable();
int countCheese()
{
	int sum=0;
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(table[i][j]==2)
				sum++; //cheese exists
		}
	}
	return sum;
}
bool checkCheese()
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(table[i][j]==1)
				return true; //cheese exists
		}
	}
	return false;
}
bool changeTable()
{
	if(!checkCheese())
	{
		printf("%d\n",time+1);
		printf("%d\n",countCheese());
		return true;
	}
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(table[i][j]==2)
				table[i][j]=0;
		}
	}
	time++;
	p++;
	return false;
}
bool boundaryCheck(int y, int x)
{
	if(y<0 || y>row-1) return false;
	if(x<0 || x>col-1) return false;
	else return true;
}
void startClock(int y, int x)
{
	//base case
	if(!boundaryCheck(y,x)) return;
	if(table[y][x]==2) return;
	if(table[y][x]==1)
	{
		table[y][x]=2;//�� ���� ����� Ÿ��
		return;
	}	
	table[y][x]=p; //�ͺô� ǥ��. �Լ� �� ��ġ�� �����..
	for(int i=0;i<4; i++)
	{
		switch(i)
		{
		case 0: y=y-1; break;
		case 1: y=y+1; break;
		case 2: x=x-1; break;
		case 3: x=x+1; break;
		}
		if(table[y][x]!=p)
			startClock(y,x);
		//���� ����
		switch(i)
		{
		case 0: y=y+1; break;
		case 1: y=y-1; break;
		case 2: x=x+1; break;
		case 3: x=x-1; break;
		}
	}	
}
int main(void)
{
	scanf("%d %d",&row,&col);
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			scanf("%d",&table[i][j]);//�Ǽ�1 & �ٿ��ֱ�
		}
	}
	while(1)//�Ǽ� 3 �������� �Լ� ���� �Ƚ�Ŵ
	{
		startClock(0,0);
		if(changeTable()) break;
	}
	return 0;
}