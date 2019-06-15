#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <time.h>
 
int is_so(int a)
{
	int i=0,so=0,sq=0;
	
	if(a == 1)
	 return 0;
	else if(a == 2)
	 return 1;
	else if(a%2 == 0)
	 return 0;	 
 
 	sq=sqrt(a);
 	
	for(i=2;i<=sq;i++)
	{
		if(a%i == 0)
		 return 0;
	}	 
	
	return 1;	
}

int main()
{
  int M=0,N=0,i=0,j=0,init=0,initv=0,total=0, sz=0,sq=0,tmp=0;
  int *result;
  time_t start=0,end=0;
  
  scanf("%d %d",&M,&N);
  
  start = clock();
  
  initv = 2;
   
  sz=N+1;
   
  result = (int *)malloc(sizeof(int)*sz);
    
  for(i=0;i<=sz;i++)
   result[i] = i;
   
  //sq = sqrt(N);
  
  result[0] = 0;
  result[1] = 0;
  
  for(i=2;i*i<=N;i++)
  {
    if(result[i] != 0)
	{  	
	    for(j=i*2;j<=sz;j+=i)
	  	{
	  	 if(result[j] != i)
		   result[j] = 0;
	  	}
	}
  }  
  
  for(i=0;i<sz;i++)
  {
  	if(result[i] != 0 && i>=M)
  	{
      total++;
	  printf("%d\n",result[i]);
	}
  }

  end=clock();
  
 // printf("%f\n",(float)(end-start)/1000);
 // printf("total = %d\n", total);
  
  return 0;
}
