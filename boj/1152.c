#include <stdio.h>
#include <string.h>

char s[1000002];

int main(void)
{
	int i=0,cnt=0;
	fgets(s,1000001,stdin);
	
	while(s[i] != 0)
	{
		if(s[i++]==' ')
		{
		 cnt++;
		}		 	
	}
	
	if(s[0] == ' ')
	 cnt-=1;
	if(s[strlen(s)-2] == ' ' || s[strlen(s)-2] == '\n')
	 cnt-=1;
	 
	printf("%d\n",cnt+1);
}
