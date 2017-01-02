#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int currX = 0, currY = 0;
int turn = 0;
int checkPosition(int m);
void movef(int d);
void turnf(int dir);

int checkPosition(int m)
{
	int check = 0;
	if (currX <= m && currX >= 0) check++;
	if (currY <= m && currY >= 0) check++; //0보다 큰지도 체크해줘야함.
	if (check == 2) return 0;
	else return 1;
}
void movef(int d)
{
	switch (turn)
	{
	case 0:
		currX += d;
		break;
	case 1:
		//printf("\nbefore:currY=%d d=%d",currY,d);
		currY += d;
		//printf("\nafter:currY=%d d=%d",currY,d);
		break;
	case 2:
		currX -= d;
		break;
	case 3:
		currY -= d;
		break;
	}
}
void turnf(int dir)
{
	if (dir == 0)  //{printf("\nbefore: turn:%d",turn);
		turn = (turn + 1) % 4;
	//printf("\nafter: turn:%d",turn);}
	if (dir == 1)// {printf("hi I am turnf dir=1");
		turn = (turn + 3) % 4; //}
}
int main()
{
	int i, M, n;
	char order[5];
	int orderArgument;
	turn = 0;
	scanf("%d %d", &M, &n);
	for (i = 0; i<n; i++)
	{
		scanf("%s %d", order, &orderArgument);
		if (!strcmp(order, "MOVE")) //	equals 는 c++만 되나봄 일단 c는 안됨.
		{
			//printf("hi my order is move\n");
			movef(orderArgument);
			if (checkPosition(M))
			{
				printf("-1");
				return 0;
			}
		}
		if (!strcmp(order, "TURN"))
		{
			//printf("hi my order is turn\n");
			turnf(orderArgument);
		}

	}
	printf("%d %d", currX, currY);
	return 0;
}
