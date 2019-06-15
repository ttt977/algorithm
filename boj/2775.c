#include <stdio.h>

int main()
{
	int apt[15][15];
	int i = 0, x = 0, y = 0, k = 0, n = 0, tc = 0;
	
	scanf("%d",&tc);
	
	for(x = 0 ; x < 15; x++)
	{
		for(y = 0 ; y < 15; y++)
		{
			if(x == 0)
			 apt[x][y] = y+1;
			else if(y == 0)
			 apt[x][y] = 1;
			else
			 apt[x][y] = apt[x-1][y] + apt[x][y-1];
		}
	}
	
	for(i=0;i<tc;i++)
	{
	 scanf("%d",&k);
	 scanf("%d",&n);
	 n-=1;	
	 printf("%d\n",apt[k][n]);
	}
}
