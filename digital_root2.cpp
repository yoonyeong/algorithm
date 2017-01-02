#include <stdio.h>
//c++에선 gets가 안먹네..뭘로 해야하지?
void f2(int num)
{
	//printf("f2에 들어옴 %d \n",num);
			while(1)
			{
				int i,sum=0;
				if(num<10) 
				{ 
					printf("%d\n", num);
					break;
					return;
				}//9999 100
				
				for(i=10; num>=i*10; i=i*10){}
				for(;i!=0 && num!= 0;i=i/10)
				{
					sum+=num/i;
					num-=(num/i)*i;
				}
				num=sum;
				//printf("\n %d",num);
			}

	return;
	
}
//실수 1 문제 잘못 이해 1000자리까지 가능하다는게
//9999까지 가능하다는 것으로 잘못 이해함.
int main_3()
{
	char temp[1005];
	//int sum=0;//실수2 초기화 밑에
	while(1)
	{
		int sum=0;
		int i=0;
		gets(temp);
		if(temp[0]-'0'==0)	break;
		else
		{
			int intArr[1005];
			for(; temp[i]!='\0';i++)
			{
				intArr[i]=temp[i]-'0';
				sum+=intArr[i];
			}
			if(sum>9) f2(sum);
			else printf("%d\n",sum);

		}
	}
	return 0;
}