#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

#define INF 987654321
#define MIN(A,B) ((A<B)?(A):(B))

int N;
char map[110][110];
int pmap[110][110];
int cache[110][110];
int visited[110][110];

typedef pair<int,int> pii;
int iarr[4] = {0,-1,0,1};
int jarr[4] = {-1,0,1,0};


void Input_Data(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> map[i];
		for(int j=0;j<N;j++)
		{
			pmap[i][j] = map[i][j] - '0';
		}
	}	
}


int solve(){
    queue<pii> qii;
	cache[0][0] = 0;	
	qii.push(make_pair(0,0));
	while(!qii.empty())
	{
		pii cur;
		cur.first = qii.front().first;
		cur.second = qii.front().second;
		qii.pop();
		for(int i= 0;i<4;i++)
		{
			int ti = cur.first+iarr[i];
			int tj = cur.second+jarr[i];

			if(ti < 0 || ti > N-1 || tj < 0 || tj > N-1)
			 continue;

			int curval = cache[ti][tj];
			int newval = cache[cur.first][cur.second] + pmap[ti][tj];

			if(curval != -1)
			{
				if(curval > newval)
				{
					cache[ti][tj] = newval;
					qii.push(make_pair(ti,tj));//이 부분 필요없는줄 알았는데 최저값 갱신하고 다시 큐에 넣어줘야 10개 모두 정답(아님 5개 오답) 
				}
			}
			else
			{
				cache[ti][tj] = newval;
				qii.push(make_pair(ti,tj));								
				
			}
		}
		
	}
}



int main(){
	int ans = -1;
	Input_Data();
	memset(cache,-1,sizeof(cache));	
	solve();
#if 0
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		cout << cache[i][j] << " ";

		cout << endl;
	}
#endif
	cout << cache[N-1][N-1] << endl;
	return 0;
}

