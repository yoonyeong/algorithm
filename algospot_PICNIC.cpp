#include <stdio.h>
int student,zzackNum;
int makeZzackF(int makeZzack[11],bool areFriends[][11],int count,bool checkSelection[11])
{
	int sum=0;
	if(count==student) return 1;
	for(int i=0; i<student; i++)//�Ǽ� i<=student�ƴ�
	{
		
		if(checkSelection[i]) continue;//already selected (mistake2)
		if(count != 0)
		{
			switch(count%2)
			{
			//count is even
			//making order to eliminate repetition
			case 0: if(i<makeZzack[count-2]) //�Ǽ�1 makeZzack[count]���� ���� ���� i��
						continue;
					else break;//�Ǽ�3 else break�� ����������
			//count is odd
			case 1: if(i<=makeZzack[count-1])
						continue; 
			}

			switch(count%2)
			{
			//count is odd
			//check friendship
			case 1: if(!areFriends[makeZzack[count-1]][i])
						continue; 
			default: break;
			}
		}
		makeZzack[count]=i;
		checkSelection[i]=true;
		//printf("\n%d�� �ִ´�! %d\n",i,count);
		sum+=makeZzackF(makeZzack,areFriends,count+1,checkSelection);
		checkSelection[i]=false;
		//printf("\n%d�� ����! %d\n",i,count);
	}
	return sum;
}
int main(void)
{
	int testcase;
	scanf("%d",&testcase);
	while(testcase>0)
	{
		bool areFriends[11][11]={false};//�Ǽ�3 ��ȣ�ȿ� false�Ƚ��ָ� ���� true�� �ʱ�ȭ��
		scanf("%d %d",&student,&zzackNum);
		for(int i=0; i<zzackNum; i++)
		{
			int row,col;
			scanf("%d %d",&row,&col);
			areFriends[row][col]=areFriends[col][row]=true;
		}
		int makeZzack[11];
		bool checkSelection[11]={false};//��ȣ�ȿ� false�Ƚ��ָ� ���� true�� �ʱ�ȭ��
		printf("%d\n",makeZzackF(makeZzack,areFriends,0,checkSelection));
		testcase--;
	
	}
	return 0;
}