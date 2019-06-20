//��� ���� ��� ���ϱ� : �÷��̵� �˰��� 

#include <iostream>
#include <algorithm>

using namespace std;

int dist[101][101];
const int INF = 987654321;

int N,M,A,B,D;
int maxd[101]; //�� ��ȣ�� ���忡 ����â�� ������ �� �ִ� �Ÿ��� ����

int main(void)
{
	cin >> N >> M;
	for(int i=0;i<101;i++)
	{
	 for(int j=0;j<101;j++)
	 {
	  if(i!=j)
	   dist[i][j] = INF; //�ڱ��ڽ������� ��� �����ϰ� ��� ���� ������ �ʱ�ȭ 
	 }
	}

	for(int i=0;i<M;i++)
	{
		cin >> A >> B >> D;
		dist[A][B] = D;		
		dist[B][A] = D; //����� ���̹Ƿ� �ʿ� 
	}

	//�÷��̵� �˰��� 
	for(int k=1;k<=N;k++) //K ������ ������ �� ��� �񱳸� ���� 
	{
	 for(int i=1;i<=N;i++)
	 {
	   for(int j=1;j<=N;j++)
		{
			int cur_d = dist[i][j]; //������� �˰��ִ� �ּҺ�� 
			int new_d = dist[i][k] + dist[k][j]; //K ������ ���İ� ���� �ּҺ�� 
			dist[i][j] = min(cur_d,new_d); //�� ���� ������ ������Ʈ 
		}
	 }
	}

	for(int i=1;i<=N;i++)
	 {
	   for(int j=1;j<=N;j++)
		{
			if( dist[i][j] > maxd[i] )
			 maxd[i] = dist[i][j]; //�� ���忡 ����â�� ������ ���� �ִ� ��� 
		}		
	 }
	cout << *min_element(maxd+1,maxd+N) << endl; //maxd[0]�� ���� �����Ƿ� 1���� �ּ� ��� ������ �� ��� 
} 
