#include <stdio.h>
//c++���� gets�� �ȸԳ�..���� �ؾ�����?
void f2(int num)
{
	//printf("f2�� ���� %d \n",num);
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
//�Ǽ� 1 ���� �߸� ���� 1000�ڸ����� �����ϴٴ°�
//9999���� �����ϴٴ� ������ �߸� ������.
int main_3()
{
	char temp[1005];
	//int sum=0;//�Ǽ�2 �ʱ�ȭ �ؿ�
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