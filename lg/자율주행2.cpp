#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>

using namespace std;
typedef pair<int,pair<int,int> > pii; //q�� �� ������ i,j ��ǥ �� ���� ����(�Ÿ�) 

int H;
int W;

char map[510][510];
char visited[510][510];

void input_data(){
	int i;
	cin >> H >> W;
	for(i=0 ; i<H ; i++){
		cin >> map[i];	
	}	
}

int bfs(int i, int j) //i,j ��ġ���� bfs 
{
	int arri[4] = {0,1,0,-1}; //��/��/��/�� ������ Ž�� 
	int arrj[4] = {-1,0,1,0};
	int level = 0;

	queue<pii> q;
	q.push(make_pair(i,make_pair(j,level))); //���� ��ġ q�� push 
	visited[0][0] = 1;

	while(!q.empty()) //q�� �� ������ 
	{
	  //q���� �� �������� 
	 int cur_i = q.front().first;
	 int cur_j = q.front().second.first;
	 int cur_lvl = q.front().second.second;
	 
	 //�� ���� 
	 q.pop();

	 for(int k=0;k<4;k++) //��/��/��/�� Ž�� 
	 {		
		int n_i = cur_i + arri[k]; //Ž�� ��ġ ���� 
		int n_j = cur_j + arrj[k];
		if(n_i < 0 || n_j < 0 || n_i > H-1 || n_j > W-1) //���� ����°� 
		 continue;

		if(visited[n_i][n_j] == 0 && map[n_i][n_j] != 'X') //�湮���� ���� ���̰� ������ �ƴϸ� 
		 {
			visited[n_i][n_j] = 1; //�湮ó�� 
			if(n_i == H-1 && n_j == W-1) //������ġ�� �ֳ�? 
 	  		 return cur_lvl+1;
			q.push(make_pair(n_i,make_pair(n_j,cur_lvl+1))); //�湮�� �ĺ��� q�� push 
		 }
	 }
	}
    return -1;
}

int main(){
	int ans = 0;
	input_data();
	memset(visited,0,sizeof(visited));
	ans = bfs(0,0);
	cout << ans << endl;
	return 0;
}
