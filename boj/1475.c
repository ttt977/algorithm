#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)

int get_cnt(char a);

char inp[8];

int get_cnt(char a)
{
	int cnt = 0, i = 0;
	for(i = 0 ; i< strlen(inp) ; i++)
	{
		if(a == inp[i])
		cnt++;
	}
	
	return cnt;		
}

int main()
{
	int setnum = 0;
	int i = 0, j = 0, max = 0, db = 0, cnt6 = 0, cnt9 = 0;

	fgets(inp,8,stdin);
	
	max = get_cnt(inp[0]);
	
	for(i = 0 ; i < strlen(inp)-1 ; i++)
	{		
		if(get_cnt(inp[i]) > max)
		 max = get_cnt(inp[i]);
	}
	
	cnt6 = get_cnt('6');
	cnt9 = get_cnt('9');
	
	//printf("max = %d, cnt6 = %d, cnt9 = %d \n",max,cnt6,cnt9);
	
	if(max == MAX(cnt6,cnt9) && cnt6!=cnt9)
	{
		printf("%d\n",(cnt6+cnt9)/2 + (cnt6+cnt9)%2);		 
		return 0;
	}	
	printf("%d\n",max);
}

