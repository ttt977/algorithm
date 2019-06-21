//dfs
//��ǻ�� ��ȣ�� 1���� ���۵��� ����
//1���� ���ؼ� ������ ���� ���ϴ� ������ ���� 

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int N,M;

vector<int> com[101];
int visited[101];

void dfs(int no)
{
	if(com[no].size() == 0)
	 return;

	visited[no] = 1; //�湮ó�� 

	for(int i=0;i<com[no].size();i++) //�湮�� ��忡 ����� ���� �湮 
	{
		int cur_com = com[no][i];
		if(visited[cur_com] == -1) //�湮���� ���� ���̶�� 
		{
			dfs(cur_com); //�ٽ� �湮 
		}		
	}
}

int main(void)
{
	int start,end;
	int ans = 0;

	memset(visited,-1,sizeof(visited));

	cin >> N ;
	cin >> M;

	for(int i=0;i<M;i++)
	{
		cin >> start >> end;
		com[start].push_back(end);
		com[end].push_back(start);//������̹Ƿ� �ݴ��ʿ��� ���� ��ε� �߰� �ʿ� 
	}

	dfs(1); //1�� ��忡�� Ž�� ���� 
	
	for(int i=1;i<=N;i++)
	{
		if(visited[i] == 1)
		 ans++;
	}
	cout << ans-1 << endl; //1�� ��ǻ�ʹ� ����. 
	return 0;
} 
