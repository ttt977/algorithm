#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a, const void *b)
{
	char *ch1 = (char *)a;
	char *ch2 = (char *)b;
	
	if(strlen(ch1) > strlen(ch2))
	 return 1;
	else if(strlen(ch1) < strlen(ch2))
	 return -1;
	else
	 return strcmp(ch1,ch2);	 	
}

int main()
{
	int N=0,i=0;
	char arr[20001][51];
		
	scanf("%d",&N);
	
	for(i=0;i<N;i++)
	{
		scanf("%s",arr[i]);		
	}
	
	qsort((void*)arr,N,sizeof(arr[0]),comp);
	
	printf("%s\n",arr[0]);
	
	for(i=1;i<N;i++)
	{		
		if(strcmp(arr[i],arr[i-1]) != 0)
		 printf("%s\n",arr[i]);		
	}
	
}
