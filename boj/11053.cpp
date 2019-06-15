
//LIS(Longegst Increasing Subsequence)

#include<iostream>

using namespace std;

int map[1001];
int dp[1001];

int main(void)
{
    int max = 1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> map[i];
    }

	//i 값 이전 인덱스의 값이면서 값이 i보다 작은 것을 찾는다.
    // 그 값의 lis 값에 1(현재 i 고려) 더한 값이 i가 갖고 있는 lis 보다 클 경우 i의 lis 값 업데이트
	// i 전에 오는 인덱스들의 lis는 i보다 클 수 없기 때문에.. 
	// 당연한 것인데 몰랐네...-_-;;;; 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (map[j] < map[i])
			{
             if (dp[i] <= dp[j] + 1)
			 {
               dp[i] = dp[j] + 1;
               if (max < dp[i])
               {
                 max = dp[i];
               }
             }
            }
        }
    }
    cout << max;
	return 0;
}
