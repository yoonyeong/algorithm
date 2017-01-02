#include <stdio.h>
void f(int num);
void f(int num)
{
	if(num<10) 
	{ 
		printf("%d\n", num);
		return;
	}//9999 100
	int i,sum=0;
	for(i=10; num>=i*10; i=i*10){}
	for(;i!=0 && num!= 0;i=i/10)
	{
		sum+=num/i;
		num-=(num/i)*i;
	}
	f(sum);
	
}
int main_2()
{
	int temp;
	while(1)
	{
		scanf("%d",&temp);
		if(temp==0)	break;
		else f(temp);
	}
	return 0;
}