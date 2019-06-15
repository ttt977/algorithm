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
  int i=0,n=0,result=0;
  int *N = NULL;

  scanf("%d",&n);
  N = (int *)malloc(sizeof(int)*n);
  
  if(N==NULL)
   printf("return with null\n");
  
  for(i=0;i<n;i++)
  {
   scanf("%d",N+i);
  }
  
  for(i=0;i<n;i++)
  {
   if(1 == is_so(N[i]))
    result++;
  }
  printf("%d\n",result);
  return 0;
}

