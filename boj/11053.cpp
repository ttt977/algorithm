
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

	//i �� ���� �ε����� ���̸鼭 ���� i���� ���� ���� ã�´�.
    // �� ���� lis ���� 1(���� i ���) ���� ���� i�� ���� �ִ� lis ���� Ŭ ��� i�� lis �� ������Ʈ
	// i ���� ���� �ε������� lis�� i���� Ŭ �� ���� ������.. 
	// �翬�� ���ε� ������...-_-;;;; 
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
