//�־��� �������� ���ӵ� ���� ���� ū ���� ����ϱ�
//n���� �����ϴ� ����� 2����.
// 1. �������� ���ؿԴ� ���� �ڽ��� ���ϱ�
// 2. �������� ���ؿԴ� �� ������ �ڽŸ� ���� 

#include <iostream>
#include <algorithm>

using namespace std;

#define INF -987654321

int number[100010];
int dp[100010];
int N;
int maxv;

int main(void)
{
	cin >> N;
	maxv = INF;

	for(int i=0;i<N;i++)
	{
	 scanf("%d",number+i);
	 dp[i] = INF;
	}

	dp[0] = number[0];

	for(int i=1;i<N;i++)
	{
		if(dp[i-1] + number[i] > number[i]) //���ݱ��� ���� ���� �ڽ��� ���� ���� �ڽź��� ũ��?
		 dp[i] = dp[i-1] + number[i];
		else //������ ���� ���� ���� �ʿ䰡 ����. 
		 dp[i] = number[i];
	}
	
	for(int i=0;i<N;i++) // ���� ū�� ã�� 
	{
		if(dp[i] > maxv)
		 maxv = dp[i];
	}
	 printf("%d ",maxv);
 
	return 0;
}
