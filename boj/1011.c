#include <stdio.h>
#include <memory.h>

//int cache[1000000] = {0};

unsigned int getcnt(int start, int end)
{
	int half=0;
	int a=0,b=0;
	
	printf("getcnt %d %d \n",start,end);
	
	//if(cache[end-start] != -1)
	// return cache[end-start];
	 
	if(start == end)
	 //return cache[0] = 0;
	 return 0;
	 
	else if(end - start == 1)
	 //return cache[1] = 1;
	 return 1;
	 
	else if(end - start == 2)
	 //return cache[2] = 2;
	 return 2;
	 
	half = (end - start)/2;
	
	if(half%2 == 1)
	{
		a = getcnt(start+half+1,end);
		b = getcnt(start,start+half) + 1;
		return a+b;
	}	 
	else
	{
		a = getcnt(start+half+1,end);
		b = getcnt(start,start+half);
	}
	 
}

int main(void)
{
	int i=0,tc=0,x=0,y=0;
	unsigned int ans=0;
	
//	memset(cache,-1,sizeof(cache));
		
	scanf("%d",&tc);
	
	for(i=0;i<tc;i++)
	{
		scanf("%d %d",&x,&y);
		ans = getcnt(0,y-x);
		printf("%d\n",ans);
	}
}

