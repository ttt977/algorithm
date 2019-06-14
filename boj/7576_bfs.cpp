#include <iostream>
#include <queue>

using namespace std;
#define MAX(a,b) ((a > b)?(a):(b))

typedef pair<int,pair<int,int> > pii;

int M,N;
int day = 0;

queue<pii> q;

int tomato[1010][1010];
int visited[1010][1010];

bool checkdone()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(tomato[i][j] == 0)
				return false;
		}
	}
	return true;
}

void makedone(int y, int x, int d)
{
  int arri[4] = {0,-1,0,1};
  int arrj[4] = {-1,0,1,0};

//  printf("makedone %d %d\n",y,x);

  visited[y][x] = 1;

  for(int k=0;k<4;k++)
  {
    int i = y+arri[k];
	int j = x+arrj[k];
	if(i < 0 || i >= N || j < 0 || j >= M)
	 continue;
	if(tomato[i][j] == 0 && visited[i][j] == 0)
	 {
 	  tomato[i][j] = 1;
	  q.push(make_pair(i,make_pair(j,d+1)));
	 }
  }  
}

int main(void)
{
	cin >> M >> N;
	int tmp = 0;	

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			cin >> tmp;
			tomato[i][j] = tmp;
			if(tmp == 1)
			 q.push(make_pair(i,make_pair(j,1)));
		}
	}

	while(!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second.first;
		day = q.front().second.second;		
		q.pop();
		if(visited[y][x] == 0)
		 makedone(y,x,day);		
	}
	if(checkdone())
	{
		cout << day-1 << endl;
	}
	else
	 cout << -1 << endl;

	return 0;
}

