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
   
  sq = sqrt(N);//�Ҽ� ���Ŀ� ����.. 
  
  //�����佺�׳׽��� ü 
  for(i=2;i<=sq;i++)
  {
    if(result[i] != 0)
	{  	
	    for(j=i*2;j<=sz;j+=i)
	  	{
	  	 //if(result[j] != i) //j�� i*2�̱� ������ �� �κ��� �ʿ� ����. 
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
