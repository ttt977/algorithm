#include <iostream>

using namespace std;
#define MAX(a,b) ((a > b)?(a):(b))

typedef pair<int,int> pii;

int M,N;

int tomato[1010][1010];

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
  
  tomato[y][x] = d+1;
  
  for(int k=0;k<4;k++)
  {
    int i = y+arri[k];
	int j = x+arrj[k];
	if(i < 0 || i >= N || j < 0 || j >= M)
	 continue;
	if(tomato[i][j] != -1 && tomato[i][j] == 0)
 	 tomato[i][j] = d+1;
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
		}
	}
#if 0	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			cout << tomato[i][j] << " ";
		}
		cout << "\n";
	}
#endif

	if(checkdone())
	 cout << 0 << endl;
	else
	{
		for(int day=1; day < M*N ; day++)
		{
			for(int i=0;i<N;i++)
			{		
				for(int j=0;j<M;j++)
				{				 
				 if(tomato[i][j] == day)
				 {					
					makedone(i,j,day);					
				 }
				}
			}
			if(checkdone())
			{
				 #if 0					
				for(int i=0;i<N;i++)
				{
				for(int j=0;j<M;j++)
				{
				cout << tomato[i][j] << " ";
				}
				cout << "\n";
				}
				#endif
			 cout << day << endl;
			 return 0;
		    }
		}
		#if 0	
		 for(int i=0;i<N;i++)
		 {
		 	for(int j=0;j<M;j++)
		 	{
		 		cout << tomato[i][j] << " ";
		 	}
		 	cout << "\n";
		 }
		#endif
		cout << -1 << endl;
	}			
	return 0;
}

