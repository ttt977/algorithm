//BFS�� �̷� ���� �ִܰŸ� ���ϱ�

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
#include <queue>

using namespace std;

//����/����/����(�ִ� �Ÿ��� ���ϱ� ����) 
typedef pair<int,pair<int,int> > pii;

int N,M;
int adj[110][110];
int level=0;
queue<pii> q;


 
//���� �湮���� ���� ����/��/������/�Ʒ� �湮 �� queue�� �ֱ� 
void do_visit(int y, int x, int lv)
{
	int arr_i[4] = {0,-1,0,1};
	int arr_j[4] = {-1,0,1,0};

	adj[y][x] = lv;

	for(int k=0;k<4;k++)
	{
		int tmp_i = y+arr_i[k];
		int tmp_j = x+arr_j[k];

		if(tmp_i <1 || tmp_j <1 || tmp_i > N || tmp_j > M)
		 continue;

		if(adj[tmp_i][tmp_j] == 1) //�湮�����ϸ�
		{
			adj[tmp_i][tmp_j] = lv+1; //�ٽ� �湮���� �ʰ� �������� �־�д� 
			q.push(make_pair(tmp_i,make_pair(tmp_j,lv+1))); //���⼭���� �ٽ� Ž���� ���� ť�� ���� 
		}
	}
}

int main(void)
{
	string str;
	cin >> N >> M;
	for(int i=1;i<=N;i++)
	{
		cin >> str;
		for(int j=1;j<=M;j++)
		{
			adj[i][j] = str[j-1]-'0';
		}
	}
#if 0
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=M;j++)
		{
			cout << adj[i][j] << " ";
		}
		cout << "\n";
	}
#endif
	//���� ��ġ ť�� �ִ´�.	
	q.push(make_pair(1,make_pair(1,1)));

	while(!q.empty())
	{
		int curi = q.front().first;
		int curj = q.front().second.first;
		int lvl = q.front().second.second;
		q.pop();
		//�� ��ġ���� ���� �湮 
		do_visit(curi,curj,lvl);
	}

#if 0
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=M;j++)
		{
			cout << adj[i][j] << " ";
		}
		cout << "\n";
	}
#endif	
	cout << adj[N][M] << endl;
	return 0;
}
