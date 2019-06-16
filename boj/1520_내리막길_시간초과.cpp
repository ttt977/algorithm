#include <iostream>
#include <memory.h>

using namespace std;

int map[510][510];
int visited[510][510];
int M,N;
int ans;

int travel(int y, int x)
{
	int arr_i[4] = {0,-1,0,1};
	int arr_j[4] = {-1,0,1,0};

	int high = map[y][x];

	//printf("travel %d %d\n",y,x);

	//visited[y][x] = 1;

	if(y==M-1 && x==N-1)
	{
	 ans++;
	 return 1;
	}
	
	for(int k=0;k<4;k++)
	{
		int cur_y = y+arr_i[k];
		int cur_x = x+arr_j[k];
		if(cur_y < 0 || cur_x < 0 || cur_y > M-1 || cur_x > N-1)
		 continue;
		if(high > map[cur_y][cur_x] && visited[cur_y][cur_x] != 1)		
		{
			travel(cur_y,cur_x);
		}
	}
	return 0;	
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
	memset(visited,-1,sizeof(visited));

#if 0
	for(int i=0;i<M;i++)
	{
	 for(int j=0;j<N;j++)
	 {
	  printf("%d ",visited[i][j]);
	 }
	 printf("\n");
	}
#endif

	travel(0,0);



	cout << ans << endl;
	return 0;
} 
