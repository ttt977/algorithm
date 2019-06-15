#include <stdio.h>
#include <memory.h>

int cache[6001];

int getsum(int n)
{
	int sum=0;
	
	if(cache[n] != -1)
	 return cache[n];
	
	if(n==1)
	 return cache[n] = 1;
	 
	return cache[n] = n + getsum(n-1);
}

int main(void)
{
	int n=0,i=0,mo=0,ja=0,diff=0;
	memset(cache,-1,sizeof(cache));
	cache[0] = 0;		
	scanf("%d",&n);
	getsum(6000);
	for(i=1;i<6000;i++)
	{
		if(n >= cache[i] && n <= cache[i+1])
		 break;
	}
	
	//printf("%d(i=%d) ~ %d(i=%d)\n",cache[i],i,cache[i+1],i+1);
	
	if(cache[i] == n)
	 printf("%d/1",i);
	else if(cache[i+1] == n)
	{
		if((i+1)%2 == 1)
		  printf("1/%d",i+1);
		else
		  printf("%d/1",i+1);
	}
	else if(i%2 == 0)
	{
		if(cache[i] + 1 == n)
		 printf("%d/1",i+1);
		else
		{
			diff = n-cache[i];
			ja = i - (diff -2);
			mo = diff;
			printf("%d/%d",ja,mo);
		}
	}
	else if(i%2 == 1)
	{
		if(cache[i] + 1 == n)
		 printf("1/%d",i+1);
		else
		{
			diff = n-cache[i];
			ja = diff;
			mo = i - (diff -2);
			printf("%d/%d",ja,mo);
		}
	}
	return 0;	 
}
