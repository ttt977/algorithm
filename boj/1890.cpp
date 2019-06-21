//�����ؼ� �� �� �ִ� ����� �� ��� 

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std; 
int N;
int map[110][110];

unsigned long long cache[110][110]; //���� ���� ���� 

unsigned long long getcnt(int i, int j) //i,j ��ġ���� �� �� �ִ� ����� �� ��ȯ 
{
	unsigned long long down = 0;
	unsigned long long right = 0;

	//printf("getcnt %d %d \n",i,j);

	if(i==N-1 && j==N-1) //���������� ���� ����� �� ����. 
	 return 1;

	if(map[i][j] == 0) //***�߿�*** ���� �� ���� �����Ƿ� 0 
	 return 0;

	if(cache[i][j] != -1)
	 return cache[i][j];

	int jump = map[i][j]; //���� ũ�� 

	if(i+jump <= N-1) //�Ʒ��� ������ ���� üũ 
	 down = getcnt(i+jump,j); //�Ʒ��� �����ؼ� �� �� �ִ� ��� ����� �� 

	if(j+jump <= N-1)
	 right = getcnt(i,j+jump); //���������� �����ؼ� �� �� �ִ� ��� ����� �� 

	return cache[i][j] =  down + right; 
}

int main(void)
{
	cin >> N;
	int tmp;
	unsigned long long ans;

	memset(cache,-1,sizeof(cache));

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin >> tmp;
			map[i][j] = tmp;
		}
	}

	ans = getcnt(0,0);

	cout << ans;
		
	return 0;
}
