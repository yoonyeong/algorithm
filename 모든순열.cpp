//#include <stdio.h>
//#include <iostream>
//#include <vector>
//using namespace std;
//#define TRUE 1
//#define FALSE 0
//int i=1,k,N,chk=0;
//int checkSelection[9]={0,};
//vector <int> v;
//int minf(int a, int b) { return (a>b)? b: a;}
//void printSequence(int first_num , int print_count)
//{
//	if(print_count==1)
//	{
//		for(int l=1; l<=N; l++)
//			{
//				if(!checkSelection[l])
//				{
//					v.push_back(l);
//				}
//			}
//		int p;
//		for(p=0; p<v.size()-1; p++)//실수2 v.size()-1해줘야함 -1
//		{
//			printf("%d",v[p]);
//			printf(" ");
//		}
//		printf("%d\n",v[p]);
//		v.pop_back();
//		return;
//	}
//	for(;first_num<=N; first_num++)
//	{
//		checkSelection[first_num]=TRUE;
//		v.push_back(first_num);
//		if(print_count>2)
//		{
//			int j1;
//			for(j1=1;j1<=N ; j1++)
//			{
//				if(checkSelection[j1]) continue;
//				else break;
//			}
//			printSequence(j1,print_count-1);
//			v.pop_back();
//			checkSelection[first_num]=FALSE;
//			continue;
//		}
//		for(int j=1;j<=N ; j++)
//		{
//			if(checkSelection[j]) continue; //실수1 이걸 for문의 조건문에 넣지 말기
//			if(print_count==2)
//			{
//				checkSelection[j]=TRUE;
//				v.push_back(j);
//			}
//			printf("\n재귀호출 printSequence(%d,%d)\n",j,print_count-1);
//			printSequence(j,print_count-1);
//			v.pop_back();
//			checkSelection[j]=FALSE;
//	
//		}
//		v.pop_back();
//		checkSelection[first_num]=FALSE;
//	}
//	
//
//}
//int main_2(void)
//{
//	
//	scanf("%d",&N);
//	//for(int i=1; i<=N; i++)
//	//{
//		//v.push_back(i);
//		printSequence(1,N-1);
//		//v.pop_back();
//	//}
//	return 0;
//}