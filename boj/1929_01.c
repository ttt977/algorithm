#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <time.h>
 
int main()
{
  int M=0,N=0,i=0,j=0,total=0,sz=0,sq=0;
  int *result;
  time_t start=0,end=0;
  
  scanf("%d %d",&M,&N);
  
  start = clock();
  
  sz=N+1;
   
  result = (int *)malloc(sizeof(int)*sz);
  memset(result,0,sizeof(result));
    
  for(i=2;i<=sz;i++)
   result[i] = i;
   
  sq = sqrt(N);//소수 공식에 따름.. 
  
  //에라토스테네스의 체 
  for(i=2;i<=sq;i++)
  {
    if(result[i] != 0)
	{  	
	    for(j=i*2;j<=sz;j+=i)
	  	{
	  	 //if(result[j] != i) //j가 i*2이기 때문에 이 부분은 필요 없음. 
		   result[j] = 0;
	  	}
	}
  }  
  end=clock();
  printf("%f\n",(float)(end-start)/1000);
  
  for(i=0;i<sz;i++)
  {
  	if(result[i] != 0 && i>=M)
  	{
      total++;
//	  printf("%d\n",result[i]);
	}
  }  
  printf("total = %d\n", total);

  return 0;
}
