#include <stdio.h>
#include <string.h>

int main(void)
{
	char word[101];
	int i=0;
	scanf("%s",word);
	for(i=0;i<strlen(word);i++)
	{
		printf("%c",word[i]);
		if(i%10 == 9)
		 printf("\n");
	}
}
