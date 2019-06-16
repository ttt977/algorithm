//주어진 수열에서 연속된 함중 가장 큰 값을 출력하기
//n에서 선택하는 방법은 2가지.
// 1. 기존까지 더해왔던 값에 자신을 더하기
// 2. 기존까지 더해왔던 값 버리고 자신만 선택 

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
		if(dp[i-1] + number[i] > number[i]) //지금까지 더한 값에 자신을 더한 값이 자신보다 크냐?
		 dp[i] = dp[i-1] + number[i];
		else //작으면 기존 값을 더할 필요가 없음. 
		 dp[i] = number[i];
	}
	
	for(int i=0;i<N;i++) // 가장 큰값 찾기 
	{
		if(dp[i] > maxv)
		 maxv = dp[i];
	}
	 printf("%d ",maxv);
 
	return 0;
}
