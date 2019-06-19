#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int V,E;
int ans1 = 0;//���� �� �� 
int ans2 = 987654321;//���� ª�� �� 

vector<int> v[1010];
int visited[1010]; //�湮���� �� ���� ���� Ȯ�� ��(0�̸� �湮���Ѱ�) 

void bfs() //��� 0���� ��� ��� �ʺ�켱Ž�� 
{
	queue<int> q;
	q.push(0); //��带 �ְ� 
	visited[0] = 0; 
	while(!q.empty())
	{
		int cur_v = q.front(); //q ���� ����ġ ��� �������� 
		q.pop(); //q���� ������ 
		for(int i=0;i<v[cur_v].size();i++) // ������ ���� ����� ��� �������� ���� 
		{
			int now_v = v[cur_v][i];
			if(visited[now_v] == 0) //�湮���� ���� ���̸� 
			{
			 visited[now_v] = visited[cur_v]+1; //�θ� ����� ���� �� +1 
			 q.push(now_v);//���⼭ ���� ����� ��� Ȯ���ϱ� ���� q�� �ֱ� 
			}
		}		
	}
	for(int i=1;i<V;i++) //�ִ� ���� �� Ȯ�� 
	{	 
	 if(visited[i] > ans1)
	  ans1 = visited[i];	 
	}	
}

int main(void)
{
	int start=0,end=0;
	
	cin >> V >> E;
	for(int i=0;i<E;i++)
	{
	 cin >> start >> end;
	 v[start].push_back(end); //start ��忡�� end ��� ������ ����Ȱ��ǥ�� 
	}
	bfs();
	for(int i=0;i<V;i++) //����� ��尡 ���� ��(leaf ���) �� �ּ� �� Ȯ�� 
	{
		if(v[i].size() != 0)
		 continue;
		if(visited[i] < ans2)
		 ans2 = visited[i];		
	}
	cout << ans1 - ans2 << endl;
	return 0;
}
