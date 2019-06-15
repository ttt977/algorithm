#include <iostream>

using namespace std;

int q[19][19];
int x=0,y=0;
int n=0;
int main(void)
{
	
	for(int i=0;i<19;i++)
	{
		for(int j=0;j<19;j++)
		{
			cin >> q[i][j];
		}
	}
	
	cin >> n;
	
	for(int z=0;z<n;z++)
	{
		cin >> x >> y;
		x--;
		y--;
		for(int a=0;a<19;a++)
		{
			if(q[a][x] == 0)
			 q[a][x] = 1;
			else
			 q[a][x] = 0;
		}
		for(int a=0;a<19;a++)
		{
			if(q[y][a] == 0)
			 q[y][a] = 1;
			else
			 q[y][a] = 0;
		}
	}
	
	for(int i=0;i<19;i++)
	{
		for(int j=0;j<19;j++)
		{
			cout << q[i][j] << " ";
		}
		cout << "\n";
	}
}
