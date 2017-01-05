#include <stdio.h>
int main_1 (void)
{
	char string[105];
	int count=103;
	while(count>0)
	{
		fgets(string,102,stdin);
		printf("%s",string);
		string[0]='\0';//실수 비워줘야함 안그러면 컨트롤 씨 누르면 
		count--;     //버퍼에 있는게 또 출력되고 끝남.
	}
		return 0;
}