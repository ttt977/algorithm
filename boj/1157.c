#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

int sort(const void *a, const void *b)
{
	int aa = *(int *)a;
	int bb = *(int *)b;
	if(aa > bb)
	 return 1;
	else if(aa < bb)
	 return -1;
	else
	 return 0;
}

int main()
{
	int arr[26][2]={0};
	int tmp_arr[26];
	int i=0,j=0;
	char *str = (char *)malloc(sizeof(char)*1000001);
	char ch_a = 'a';
	char ch_A = 'A';	
	scanf("%s",str);
	
	for(i=0;i<26;i++)
	{
		arr[i][0] = i;
		
		for(j=0;j<=1000000;j++)
		{
			if(str[j] == NULL)
			 break;
			if(str[j] == ch_a+i || str[j] == ch_A+i)
			 arr[i][1]++;
		}
	}
	
	for(i=0;i<26;i++)
	{
		tmp_arr[i] = arr[i][1];
	}
	
	qsort(tmp_arr,26,sizeof(tmp_arr[0]),sort);	
		
	if(tmp_arr[25] == tmp_arr[24])
	 printf("?\n");
	else
	{
		for(i=0;i<26;i++)
		{
			if(tmp_arr[25] == arr[i][1])
			 printf("%c",ch_A + i);
		}
	}		
	free(str);	
	return 0;
}
