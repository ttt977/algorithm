#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

int main()
{
 int tc=0,i=0,R=0,j=0,k=0;
 char *S = (char *)malloc(sizeof(char)*21);
 scanf("%d",&tc);
 for(i=0;i<tc;i++)
 {
 	scanf("%d %s",&R,S);
 	for(j=0;j<=20;j++)
 	{
 		if(S[j] == NULL)
 		{
 			printf("\n");
 			break;
		}
		for(k=0;k<R;k++)
		 printf("%c",S[j]);		 
	}
 }
 free(S);
}
