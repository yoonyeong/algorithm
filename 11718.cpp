#include <stdio.h>
int main_1 (void)
{
	char string[105];
	int count=103;
	while(count>0)
	{
		fgets(string,102,stdin);
		printf("%s",string);
		string[0]='\0';//�Ǽ� �������� �ȱ׷��� ��Ʈ�� �� ������ 
		count--;     //���ۿ� �ִ°� �� ��µǰ� ����.
	}
		return 0;
}