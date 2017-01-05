#include <stdio.h>
int shape[4][3][2]={{{0,0},{0,1},{1,1}},
					{{0,0},{1,0},{1,1}},
					{{0,0},{0,1},{-1,1}},
					{{0,0},{1,0},{0,1}}}; //실수 5 -1이 아니라 +1
int H,W;
int boardCover(int inputArr[][25],int whiteNum)
{
	int i,j;
	int flag=0,ret=0;
	//base case
	if(whiteNum==0) return 1;
	if(whiteNum<3) return 0;
	//printf("재귀 white count: %d\n",whiteNum);
	//find first top white
	for(i=0; i<H; i++)
		{
			for(j=0; j<W; j++)
			{
				if(inputArr[i][j]!=0) continue;
				else 
				{
					flag=1;
					break;
				}
			}
			if(flag==1) break;
		}
		//printf("i: %d j: %d\n",i,j);
		//try fitting board 
		for(int k=0; k<4; k++)
		{
			//check one shape with three space
			int flag2=0;
			for(int l=1;l<3; l++)
			{
				int tempx=j,tempy=i;//실수 3 j와 i를 반대로 씀..
				tempx+=shape[k][l][0];
				tempy+=shape[k][l][1];
				//check overlapping
				if(inputArr[tempy][tempx]==1) {flag2=1; break;}//실수4 tempy tempx
				//check boundary
				if(tempx<0 || tempx >=W || tempy>= H) {flag2=1; break;}
			}
			//the shape is okay
			if(flag2==0)
			{
				for(int l=0;l<3; l++)
				{
					int tempx=j,tempy=i; //실수
					tempx+=shape[k][l][0];
					tempy+=shape[k][l][1];
					inputArr[tempy][tempx]=1;
				}
				/*printf("-----------\n");
				for(int i=0; i<H; i++)
				{
					for(int j=0; j<W; j++)
					{
						printf("%d ",inputArr[i][j]);
					}
					printf("\n");
				}
				printf("-----------\n");*/
				ret+=boardCover(inputArr,whiteNum-3);
				for(int l=0;l<3; l++)
				{
					int tempx=j,tempy=i;  //실수
					tempx+=shape[k][l][0];
					tempy+=shape[k][l][1];
					inputArr[tempy][tempx]=0;
				}
			}
		}
		return ret;
}
int main(void)
{
	int testcase;
	scanf("%d",&testcase);
	while(testcase>0)
	{
		int whiteNum=0;
		int inputArr[25][25];
		int k=0;
		
		scanf("%d %d",&H,&W);
		for(int i=0; i<H; i++)
		{
			for(int j=0; j<W; j++)
			{
				char temp;
				scanf("%c",&temp);
				while(temp != '.' && temp != '#') scanf("%c",&temp);
				inputArr[i][j]=(temp=='.')? 0:1; //white=1;//실수1 temp='.'아님
				if(temp=='.') whiteNum++;
			}
		}
		//printf("white count: %d\n",whiteNum);
		char trash='a';
		
		printf("%d\n",boardCover(inputArr,whiteNum));
		testcase--;
		
	}
}