#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	int a=0,b=0,c=0,rst=0,i=0,j=0,tmp=0;
	char istr[100] = {0};
	char num[1];
	
	memset(istr,-1,sizeof(istr));
	
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	
	rst = a*b*c;
	snprintf(istr,sizeof(istr),"%d",rst);
	//itoa(rst,istr,10);
		
	for(i=0;i<10;i++)
	{
		tmp=0;
		for(j=0;istr[j] != NULL;j++)
		{
			num[0] = istr[j];
			if(i == atoi(num))
			 tmp++;
		}
		printf("%d\n",tmp);
	}	
}

