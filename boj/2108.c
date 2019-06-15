#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

int mergesort(int *arr, int n)
{
	int li=0,ri=0,lsize=0,rsize=0,i=0;
	int *tmparr = NULL;
		
	if(n <= 1)
	 return 0;
	 
	lsize = n/2;
	rsize = n - lsize;
	li = 0;
	ri = lsize;
	
	mergesort(arr,lsize);
	mergesort(arr+lsize,rsize);	
	
	tmparr = (int *)malloc(sizeof(int)*n);
	memcpy(tmparr,arr,sizeof(int)*n);
	
	while(li < lsize && ri < n)
	{
		if(tmparr[li] <= tmparr[ri])
		{
		 arr[i] = tmparr[li];
		 li++;
		}
		else if(tmparr[li] > tmparr[ri])
		{
		 arr[i] = tmparr[ri];
		 ri++;
		}
		i++;
	}
	
	while(li<lsize)
	{
		arr[i] = tmparr[li];
		li++;
		i++;
	}
	
	while(ri<rsize)
	{
		arr[i] = tmparr[ri];
		ri++;
		i++;
	}
	free(tmparr);
	
}

int main()
{
	int N=0;
	int i=0,j=0,tmp=0,mfreq=0,mcount=0,davg=0;
	int *numbers = NULL;
	int mvalue[8001] = {0};
	float avg=0.0f;
		
	scanf("%d",&N);
	numbers = (int *)malloc(sizeof(int)*N);
	memset(mvalue,0,sizeof(mvalue));
	
	
	for(i=0;i<N;i++)
	 scanf("%d",numbers+i);
	 
	for(i=0;i<N;i++)
	 tmp+=numbers[i];
	 
	avg = (float)tmp/(float)N;
	
	if(fabs(avg) -  (float)(abs(tmp/N)) >= 0.5)
	{
	 if(tmp/N < 0)
	  davg = tmp/N - 1;
	 else
	  davg = tmp/N + 1;	  
	}
	else
	 davg = tmp/N;
	 
	printf("%d\n",davg);
	 
	mergesort(numbers,N);
	
	#if 0
	printf("==========\n");
	for(i=0;i<N;i++)
	 printf("%d ",numbers[i]);
	printf("==========\n"); 
	#endif
	
	printf("%d\n",numbers[N/2]);
	
	tmp = 0;
	
	for(i=1;i<N;i++)
	{
		if(numbers[i-1] == numbers[i]){
			tmp++;
			if(tmp == mcount){
				mvalue[j] = numbers[i];
				mcount = tmp;
				j++;
			}
			else if(tmp > mcount)
			{
				j=0;
				memset(mvalue,0,sizeof(mvalue));
				mvalue[j] = numbers[i];
				mcount=tmp;
				j++;
			}
		}
		else {
			tmp = 0;
			if(mcount==0)
			{
			 mvalue[j] = numbers[i-1];
			 j++;
			}
		}
	}
	#if 0
	for(i=0;i<N;i++)
	{
		if(mvalue[i] == 0)
		 break;
		else
		 printf("* %d\n",mvalue[i]);
	}
	#endif
	
	if(N==1)
	 printf("%d\n",numbers[0]);
	else
	{
	if(mvalue[1] == 0)
	 printf("%d\n",mvalue[0]);
	else
	 printf("%d\n",mvalue[1]);
	}
	
	printf("%d\n",numbers[N-1]-numbers[0]);			
}

