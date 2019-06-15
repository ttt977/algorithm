#include <stdio.h>
#include <memory.h>

 
int is_so(int a)
{
	int i=0,so=0;
	
	if(a == 1)
	 return 0;
	else if(a == 2)
	 return 1;
	 
	for(i=2;i<a;i++)
	{
		if(a%i == 0)
		 so++;
	}
	if(so == 0)
	 return 1;
	else
	 return 0;
}

int main()
{
  int M=0,N=0,i=0,init=0,initv=0,sum=0;
  int *result;
  
  scanf("%d",&M);
  scanf("%d",&N);
  
  for(i=M;i<=N;i++)
  {
  	if(1==is_so(i))
  	{
  	 if(init==0)
  	 {
  	 	initv=i;
  	 	init=1;
  	 }
  	 sum+=i;
    }
  }
  
  if(init == 0)
   printf("-1\n");
  else
  {
   printf("%d\n",sum);
   printf("%d\n",initv);
  }
  return 0;
}

