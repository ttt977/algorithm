//모든 쌍의 비용 구하기 : 플로이드 알고리즘 

#include <iostream>
#include <algorithm>

using namespace std;

int dist[101][101];
const int INF = 987654321;

int N,M,A,B,D;
int maxd[101]; //각 번호의 공장에 물류창고를 지었을 때 최대 거리를 저장

int main(void)
{
	cin >> N >> M;
	for(int i=0;i<101;i++)
	{
	 for(int j=0;j<101;j++)
	 {
	  if(i!=j)
	   dist[i][j] = INF; //자기자신으로의 비용 제외하고 모두 무한 값으로 초기화 
	 }
	}

	for(int i=0;i<M;i++)
	{
		cin >> A >> B >> D;
		dist[A][B] = D;		
		dist[B][A] = D; //양방향 길이므로 필요 
	}

	//플로이드 알고리즘 
	for(int k=1;k<=N;k++) //K 공장을 거져갈 때 비용 비교를 위함 
	{
	 for(int i=1;i<=N;i++)
	 {
	   for(int j=1;j<=N;j++)
		{
			int cur_d = dist[i][j]; //현재까지 알고있는 최소비용 
			int new_d = dist[i][k] + dist[k][j]; //K 공장을 거쳐갈 때의 최소비용 
			dist[i][j] = min(cur_d,new_d); //더 작은 값으로 업데이트 
		}
	 }
	}

	for(int i=1;i<=N;i++)
	 {
	   for(int j=1;j<=N;j++)
		{
			if( dist[i][j] > maxd[i] )
			 maxd[i] = dist[i][j]; //각 공장에 물류창고 지었을 때의 최대 비용 
		}		
	 }
	cout << *min_element(maxd+1,maxd+N) << endl; //maxd[0]은 값이 없으므로 1부터 최소 비용 가지는 값 출력 
} 
