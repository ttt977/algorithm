#include <stdio.h>
#include <string.h> //memset
#include <stdlib.h> //malloc

int main()
{
	int n=0, n2=0,i=0,j=0,cnt=0,answer=0;
	int *result = NULL;
	
	while(1)
	{
	 scanf("%d",&n);
	 
	 if(n == 0)
	  break;
	  
	 n2 = n*2;
	 cnt = n2 +1;
	 answer=0;
	 result = (int *)malloc(sizeof(int)*cnt);
	 memset(result,0,sizeof(result));
	 
	 for(i=2;i<=n2;i++)
	  result[i] = i;
	 
	 for(i=2;i*i<=n2;i++)
	 {
	 	if(result[i] != 0)
	 	{
		 	for(j=i*2;j<=n2;j+=i)
		 	{
		 		result[j] = 0;
		 	}
	 	}
	 }	
	 
	 for(i=0;i<=n2;i++)
	 {
	 	if(result[i] != 0 && i > n)
	 	 answer++;
	 }	 
	 printf("%d\n",answer);
	 free(result);
	}
	return 0;
}
