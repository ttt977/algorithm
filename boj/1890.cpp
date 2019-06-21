//점프해서 갈 수 있는 경우의 수 계산 

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std; 
int N;
int map[110][110];

unsigned long long cache[110][110]; //답의 범위 주의 

unsigned long long getcnt(int i, int j) //i,j 위치에서 갈 수 있는 경우의 수 반환 
{
	unsigned long long down = 0;
	unsigned long long right = 0;

	//printf("getcnt %d %d \n",i,j);

	if(i==N-1 && j==N-1) //목적지에서 가는 방법은 한 가지. 
	 return 1;

	if(map[i][j] == 0) //***중요*** 점프 할 곳이 없으므로 0 
	 return 0;

	if(cache[i][j] != -1)
	 return cache[i][j];

	int jump = map[i][j]; //점프 크기 

	if(i+jump <= N-1) //아래로 점프시 범위 체크 
	 down = getcnt(i+jump,j); //아래로 점프해서 갈 수 있는 모든 경우의 수 

	if(j+jump <= N-1)
	 right = getcnt(i,j+jump); //오른쪽으로 점프해서 갈 수 있는 모든 경우의 수 

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
