#include <stdio.h>

int cycle=0;
int g_n=0;

void pluscycle(int n)
{
	int tmp=0,tmp2=0;	
	if(cycle !=0 && n==g_n)
	{
		return;
	}
	else
	{
		tmp = (n/10) + (n%10);
		tmp2 = (n%10)*10 + tmp%10;
		cycle++;
		pluscycle(tmp2);
	}	
}

int main()
{
	int N=0;
	scanf("%d", &N);
	g_n=N;
	pluscycle(N);
	printf("%d\n",cycle);
}
