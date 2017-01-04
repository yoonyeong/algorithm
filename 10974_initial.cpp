
void printSequence(int first_num , int print_count)
{
	if(print_count==1)
	{
		for(int l=1; l<=N; l++)
			{
				if(!checkSelection[l])
				{
					v.push_back(l);
				}
			}
		int p;
		for(p=0; p<v.size()-1; p++)//실수2 v.size()-1해줘야함 -1
		{
			printf("%d",v[p]);
			printf(" ");
		}
		printf("%d\n",v[p]);
		v.pop_back();
		v.pop_back();
		return;
	}
	for(;first_num<=N; first_num++)
	{
		checkSelection[first_num]=TRUE;
		v.push_back(first_num);
		for(int j=1;j<=N ; j++)
		{
			if(checkSelection[j]) continue; //실수1 이걸 for문의 조건문에 넣지 말기
			if(print_count==2)
			{
				checkSelection[j]=TRUE;
				v.push_back(j);
			}
			printf("\n재귀호출 printSequence(%d,%d)\n",j,print_count-1);
			printSequence(j,print_count-1);
			checkSelection[j]=FALSE;
	
		}
		v.pop_back();
		checkSelection[first_num]=FALSE;
	}

}
	
