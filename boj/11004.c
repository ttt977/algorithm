#include <stdio.h>
#include <string.h>

int A[5000001];

int sort(const void *a, const void *b)
{
	int x=*(int*)a;
	int y=*(int*)b;
	
	if(x>y)
	 return 1;
	else if(y>x)
	 return -1;
	else
	 return 0;
}

int main(void)
{
	int i=0,N=0,K=0;
	
	scanf("%d %d",&N,&K);
	for(i=0;i<N;i++)
	{
		scanf("%d",A+i);
	}	
	qsort(A,N,sizeof(int),sort);
	printf("%d\n",A[K-1]);
}
