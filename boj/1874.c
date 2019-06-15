#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int index = 0;
int *stack = NULL;

int push(int a)
{
	index++;
	stack[index] = a;
	printf("+\n");
}
int pop()
{
	int pop_value = 0;
	pop_value = stack[index];
	index--;
	printf("-\n");
	return pop_value;
}

int main()
{
	int n=0,i=0,j=0;
	int *number;
	
	scanf("%d",&n);
	number = (int *)malloc(sizeof(int)*n);
	stack = (int *)malloc(sizeof(int)*n);
	memset(stack,0,sizeof(stack));
	
	for(i=0;i<n;i++)
	 scanf("%d", number+i); //scanf 입력 시 주소로 받음 주의..(number[i] 안됨) 
	 
	for(i=0;i<n;i++)
	{
		if(number[i]==stack[index])
		 pop();
		else if(number[i] > stack[index])
		{
		}
	}	 	
}
