#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int *origin;

int mergesort(int *org, int n);

int mergesort(int *org, int n)
{
	int i = 0, lsize = 0, rsize = 0, tmp = 0, li = 0, ri=0;
	int *tmparr;
	
	if(n <= 1)
	 return 0;
	 
	lsize = n/2;
	rsize = n - lsize;
	
	li = 0;
	ri = lsize;
	
	mergesort(org,lsize);
	mergesort(org+lsize,rsize);
	
	tmparr = (int *)malloc(sizeof(int)*n);
	memcpy(tmparr,org,n*sizeof(int));
	
	//�̹� ���ĵǾ� �ִٰ� �����ؼ� �̷��� �߳�..
	// https://ehclub.co.kr/1551
	
	while(li < lsize && ri < n)
	{
		if(tmparr[li] > tmparr[ri])
		{
		 org[i] = tmparr[ri];
		 ri++;
		}
		 else
		{
		 org[i] = tmparr[li];
		 li++;
		}
		i++;
	}
	
	//�� while���� 2���� and �����̶� �Ʒ��� �ʿ�.. 
	while(li < lsize)
	{
	 org[i] = tmparr[li];
	 li++;
	 i++;
	}
	
	while(ri < n)
	{
		org[i] = tmparr[ri];
		ri++;
		i++;
	}
	
	free(tmparr);
}

int main()
{
	int i = 0, j = 0, N = 0, tmp = 0;
	scanf("%d",&N);
	origin = (int *)malloc(sizeof(int)*N);
	
	
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d",origin+i);
	}
	
	mergesort(origin,N);
	
	for(i = 0 ; i < N ; i++)
	printf("%d\n",origin[i]);	
}

