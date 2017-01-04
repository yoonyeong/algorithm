#include <stdio.h>
int table[102][102];
int row,col;
int time=0,p=3;
void startClock(int y, int x, int behindPath);
void startClock2(int y, int x);
int countCheese();
bool checkCheese();
bool boundaryCheck(int y, int x);
bool changeTable();
bool exception(int y, int x);
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
	/*
	printf("--------------------------\n");
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			printf("%d ",table[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------\n");*/
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
void startClock(int y, int x, int behindPath)
{
	//base case
	//이미 와봤음
	//이런식은 중복체크 안됨 재귀부분에서 해줘야함
	//if(table[y][x]==-1 || table[y][x]==2) return; 
	//if(y==x==0 && (behindPath != 4 ))return;
	if(!boundaryCheck(y,x)) return;
	if(table[y][x]==2) return;
	if(table[y][x]==1)
	{
		table[y][x]=2;//넌 다음 사라질 타자
		return;
	}
	
	if(boundaryCheck(y-1,x) && table[y-1][x]==1) {
		table[y-1][x]=2;
		//return;
	}
	if(boundaryCheck( y+1,x) && table[y+1][x]==1) {
		 table[y+1][x]=2;
		//return;
	}
	if(boundaryCheck( y,x+1) && table[y][x+1]==1) {
		 table[y][x+1]=2;
		//return;
	}
	if(boundaryCheck( y,x-1) &&table[y][x-1]==1) {
		 table[y][x-1]=2;
		//return;
	}
	
	table[y][x]=p; //와봤다 표시. 함수 내 위치가 어딜까..
	for(int i=0;i<4; i++)
	{
		switch(behindPath)//실수2 재귀가 너무 도루묵 상황이
		{					//많이 되어 stack overflow 에러 발생
		case 0:
		case 2: if(i-behindPath==1) continue; break;
		case 1:
		case 3: if(behindPath-i==1) continue; break;
		default: break;
		}

		switch(i)
		{
		case 0: y=y-1; break;
		case 1: y=y+1; break;
		case 2: x=x-1; break;
		case 3: x=x+1; break;
		}
		if(table[y][x]!=p)
			startClock(y,x,i);

		//원상 복귀
		switch(i)
		{
		case 0: y=y+1; break;
		case 1: y=y-1; break;
		case 2: x=x+1; break;
		case 3: x=x-1; break;
		}
	}
	
}
bool exception(int y, int x)
{
	if(boundaryCheck(y-1,x) && table[y-1][x]==0) {
		table[y-1][x]=2;
		return true;
	}
	if(boundaryCheck( y+1,x) && table[y+1][x]==0) {
		 table[y+1][x]=2;
		return true;
	}
	if(boundaryCheck( y,x+1) && table[y][x+1]==0) {
		 table[y][x+1]=2;
		return true;
	}
	if(boundaryCheck( y,x-1) &&table[y][x-1]==0) {
		 table[y][x-1]=2;
		return true;
	}
	return false;
}
void startClock2(int y, int x)
{
	//base case
	//if(y==x==0 && (behindPath != 4 ))
	if(!boundaryCheck(y,x)) return;
	if(table[y][x]==1 || table[y][x]==2)
	{
		table[y][x]=2;//넌 다음 사라질 타자
		return;
	}
	for(int i=0;i<3; i=i+2)
	{
		/*switch(behindPath)//실수2 재귀가 너무 도루묵 상황이
		{					//많이 되어 stack overflow 에러 발생
		case 0:
		case 2: if(i-behindPath==1) continue; break;
		case 1:
		case 3: if(behindPath-i==1) continue; break;
		default: break;
		}*/
		switch(i)
		{
		case 0: y=y-1; break;
		//case 1: y=y+1; break;
		case 2: x=x-1; break;
		//case 3: x=x+1; break;
		}
		startClock2(y,x);//실수5 2 안붙임
		//원상 복귀
		switch(i)
		{
		case 0: y=y+1; break;
		//case 1: y=y-1; break;
		case 2: x=x+1; break;
		//case 3: x=x-1; break;
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
			scanf("%d",&table[i][j]);//실수1 & 붙여주기
		}

	}
	while(1)//실수 3 만들어놓은 함수 결합 안시킴
	{
		//startClock2(row-1,col-1);//실수4 아래 왼쪽 방향이 커버가 안됨
		startClock(0,0,4);
		
		if(changeTable()) break;
	}
	return 0;
}