#include <stdio.h>
#include <string.h>
#include <memory.h>

int main()
{
	char *chr = (char *)malloc(sizeof(char)*100);
	int i=0,j=0;
	char ch_a = 'a';	
	scanf("%s",chr);
	
	for(i=0;i<26;i++)
	{				
		for(j=0;j<101;j++)
		{
			if(chr[j] == NULL)
			{
				printf("-1 ");
				break;
			}		 
			
			if(chr[j] == ch_a+i)
			{					
			 printf("%d ",j);
			 break;
			}			
		}
	}	
}
