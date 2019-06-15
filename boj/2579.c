#include <stdio.h>
#define MAX(a,b) ((a)>(b)?(a):(b))

int number=0;
int steps[301]={0};
int step_max[301]={0};

int maxstep(int n)
{
	int tmp=0;
	int i=0;

	step_max[0] = 0;	
	step_max[1] = steps[1];
	step_max[2] = steps[2] + steps[1];
	step_max[3] = steps[3] + MAX(steps[2],steps[1]);		

	for(i=4;i<=n;i++)
	{
		step_max[i]=steps[i] + MAX(steps[i-1]+step_max[i-3],step_max[i-2]); 	
	}	
}

int main()
{
	int i=0;
	scanf("%d",&number);
	for(i=1;i<=number;i++)
	{
		scanf("%d",&(steps[i]));		
	}
	maxstep(number);	
	printf("%d\n",step_max[number]);
}


