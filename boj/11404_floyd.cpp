//��� �ֿ� ���� �ּ� ��� ��� 

#include <iostream>

using namespace std;
#define INF 987654321

int n,m;
int adj[110][110];

int main(void)
{
	int from,to,exp;
	int k;

	//�ϴ� ��� ����� ����� INF�� ǥ��
	for(int i=0;i<110;i++)
	{
	 for(int j=0;j<110;j++)
	 {
	  if(i==j) // �ڱ��ڽ����� ���� ����� 0 
	   adj[i][j] = 0;
	  else
	   adj[i][j] = INF;
	 }
	}

	cin >> n;
	cin >> m;
	for(int i=0;i<m;i++)
	{
	  //����/��� �Է� 
	 scanf("%d %d %d",&from,&to,&exp);
	 if(adj[from][to] > exp) //������ ����ִ� ���� ���� �ԷµǴ� ��뺸�� Ŭ���� ������Ʈ 
	  adj[from][to] = exp;
	}

	for(int k=1;k<=n;k++) //�� ���İ��� ����(����) 
	{
	 for(int i=1;i<=n;i++)
	 {
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			 continue;
			int new_d = adj[i][k] + adj[k][j]; //���İ��� ����� �Ÿ� 
			if(adj[i][j] > new_d ) //���İ��� ��ΰ� ����� �� ������� ��ü 
			 adj[i][j] = new_d;
		}
	 }
	}

	for(int i=1;i<=n;i++)
	 {
		for(int j=1;j<=n;j++)
		{			
			if(adj[i][j] == INF )
			 printf("0 ");
			else
			 printf("%d ",adj[i][j]);
		}
		printf("\n");
	 }
		
	return 0;
} 
