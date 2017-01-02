#include<algorithm>
#include<iostream>
using namespace std;
int n, m, ans;
bool areFight[11][11];
bool picked[11];
void bruteForce(int last, int num) {
    if (num == n) {
        ++ans;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (picked[i]) continue;
        if (areFight[last][i]) continue;
        picked[i] = true;
        bruteForce(i, num+1);
        picked[i] = false;
    }
}
int main_1() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        areFight[a][b] = areFight[b][a] = true;
    }
    bruteForce(0, 0);
    cout << ans;
	return 0;
}

/*
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
		for(p=0; p<v.size()-1; p++)//�Ǽ�2 v.size()-1������� -1
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
			if(checkSelection[j]) continue; //�Ǽ�1 �̰� for���� ���ǹ��� ���� ����
			if(print_count==2)
			{
				checkSelection[j]=TRUE;
				v.push_back(j);
			}
			printf("\n���ȣ�� printSequence(%d,%d)\n",j,print_count-1);
			printSequence(j,print_count-1);
			checkSelection[j]=FALSE;
	
		}
		v.pop_back();
		checkSelection[first_num]=FALSE;
	}

}
	}*/