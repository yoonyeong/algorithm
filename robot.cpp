#include <stdio.h>

bool checkInS()
{
	
}
void go(char * action,int argumentNum)
{
	
}
int main()
{
	int M,n;
	int flag=0;
	int argumentNum;
	char action [5];
	scanf("%d %d",&M,&n);
	for(int i=0; i<n; i++)
	{
		scanf("%s %d",action,argumentNum);  
		go(action,argumentNum);
		if(!checkInS()) {flag=1; break;} //outside of S
	}
	return 0;
}