#include <iostream>
#include <algorithm>

using namespace std;

int h[9];
int rst[7];

int main(void)
{
	int tsum=0;
	int sum=0;
	int indexa=100,indexb=100;
	for(int i=0;i<9;i++)
	{
		scanf("%d",h+i);
		tsum+=h[i];
	}
	sum = tsum - 100;

	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(h[i]+h[j] == sum && i!=j)
			{
				indexa = i;
				indexb = j;
				break;
			}			
		}
	}

//	printf("i=%d, j=%d\n",indexa,indexb);

	int k=0;

	for(int i=0;i<9;i++)
	{
		if(i != indexa && i != indexb)
		 rst[k++] = h[i];
	}

	sort(rst,rst+7);

	for(int i=0;i<7;i++)
	{
		printf("%d\n",rst[i]);
	}
	return 0;
}
