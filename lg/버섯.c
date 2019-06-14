#include <stdio.h>

int main()
{
	int p[101] = {0};
	int rst[501]={0};
	int i=0,j=0,N=0,tmp=0,minus=0,ttmp=0;
	scanf("%d",&N);
	
	for(i=0;i<N;i++)
	{
		scanf("%d",p+i);
	}
	
	for(i=1;i<=500;i++)
	{
		minus=0;
		tmp=0;
		for(j=0;j<N;j++)
		{					
			if(p[j] >= i && minus==0)
			{
			 tmp+=p[j];
			 minus=1;			 
			}
			else if(minus == 1 && p[j] < i)
			{
				ttmp = p[j];
				if(p[j+1] < i)
				 continue;
			    else 
			    {
			      tmp-=p[j];
				  minus=0;				
				}
			}
			else
			 continue;
			 
		}
		rst[i] = tmp;
	}
	
	for(i=0;i<=500;i++)
	{
		if(rst[i] != 0)
		 printf("%d\n",rst[i]);
	}
	
}

