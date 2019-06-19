//���ͽ�Ʈ�� �˰��� Ȱ�� �ִܺ���� 

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,pair<int,int> > pii; //������� �Ÿ�,x,y ��ġ ���� 

int N;//���� ũ��
char map[110][110];//���� ����
int visited[110][110];//�湮����üũ 

void Input_Data(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> map[i];
	}
}

int bfs(int y, int x) //y,x ��ġ���� N-1,N-1 ��ġ������ �ִ� ��θ� ��ȯ
{
	int arri[4] = {0,-1,0,1}; //��/��/��/�� �湮 
	int arrj[4] = {-1,0,1,0};
	
	priority_queue<pii> q; //���� ��ġ���� ��/��/��/���� ����� ���� ���� �켱���� Ž���ϱ� ���� 
	q.push(make_pair(0,make_pair(y,x))); //�ʱ� �Ÿ�,��ġ q�� push 
	visited[y][x] = 1;
	
	while(!q.empty())
	{
		int cur_d = q.top().first;
		int cur_i = q.top().second.first;
		int cur_j = q.top().second.second;
		cur_d *= -1; //�� �� (-) �����Ƿ� ������ (-) �ʿ� 
		if(cur_i == N-1 && cur_j == N-1)
				return cur_d;
		q.pop();
		for(int k=0;k<4;k++)
		{
			int ni = cur_i + arri[k];
			int nj = cur_j + arrj[k];			
			int nd = 0;
			if(ni < 0 || nj < 0 || ni > N-1 || nj > N-1) //�����ʰ���? 
				continue;			
			if(visited[ni][nj] != 0) //�����湮�߳�? 
				continue;
			visited[ni][nj] = 1; //�湮üũ
			nd = cur_d + (map[ni][nj] - '0'); //�������湮�ߴ� ������ �Ÿ� + �� ��ġ�� �� ���ϱ� 
			nd *= -1;  //���� �� �������� �켱����ť���� �̾Ƴ��� ���� 
			q.push(make_pair(nd,make_pair(ni,nj)));						
		}
	}	
}

int main(){
	int ans = -1;
	Input_Data();
  	ans = bfs(0,0);
	cout << ans << endl;
	return 0;
}

