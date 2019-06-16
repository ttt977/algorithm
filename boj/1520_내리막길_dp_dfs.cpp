//dp/dfs�� Ȱ���ؼ� ��� ��θ� ���ϴ� ����
//dfs�� Ȱ��� �ð��ʰ� �߻� 

#include <iostream>
#include <memory.h>

using namespace std;

int map[510][510];
int dp[510][510]; //y,x���� 0,0���� ���� ����� �� ��ȯ 
int M,N;
int ans;

int travel(int y, int x)
{
	int arr_i[4] = {0,-1,0,1};
	int arr_j[4] = {-1,0,1,0};
	int high = map[y][x];

	if(y==0 && x==0) //0,0���� 0,0���� ���� ����� �� ����. 
	{
	 return dp[y][x] = 1;	
	}

	if(dp[y][x] != -1)
	 return dp[y][x];
	else
	 dp[y][x] = 0; //�ʱ� ����� ������ ���� 

	for(int k=0;k<4;k++)
	{
		int cur_y = y+arr_i[k];
		int cur_x = x+arr_j[k];
		if(cur_y < 0 || cur_x < 0 || cur_y > M-1 || cur_x > N-1)
		 continue;
		if(high < map[cur_y][cur_x])//��/��/��/�� ���� ���� ���� ��ġ���� ���� ������ ���� �� Ȯ�� 
		{
			dp[y][x] = dp[y][x] + travel(cur_y,cur_x); //�ٽ�// �� ��ġ���� 0,0���� ���� ����� ���� �� ��/��/��/�� �� �������� �� �� �ִ� ����� ���� ��� ���� ����**
		}
	}	
	return dp[y][x];
}


int main(void)
{
	cin >> M >> N;
	for(int i=0;i<M;i++)
	{
	 for(int j=0;j<N;j++)
	 {
		int h=0;
		scanf("%d",&h);
		map[i][j] = h;
	 }
	}
	memset(dp,-1,sizeof(dp));

	travel(M-1,N-1);
	cout << dp[M-1][N-1] << endl;
	return 0;
} 
