#include <stdio.h>

int cache[10001];

int getd(int n)
{
	int sum=0,tmp=0;
	tmp=n;
	if(tmp/1000 != 0)
	{
		sum += tmp + tmp/1000;
		tmp = tmp%1000;
		sum += tmp/100;
		tmp = tmp%100;
		sum += tmp/10;
		tmp = tmp%10;
		sum+=tmp;			
		return sum;
	}
	
	if(tmp/100 != 0)
	{
		sum += tmp + tmp/100;
		tmp = tmp%100;
		sum += tmp/10;
		tmp = tmp%10;
		sum+=tmp;	
		return sum;
	}
	
	if(tmp/10 != 0)
	{
		sum += tmp + tmp/10;
		tmp = tmp%10;
		sum+=tmp;	
		return sum;
	}	
	
	sum=tmp+n;
	return sum;
}

int main(void)
{
	int i=0,tmp=0;
	memset(cache,-1,sizeof(cache));
	
	for(i=1;i<=10000;i++)
	{
		tmp = getd(i);
		if(tmp <= 10000)
		 cache[tmp] = 0;
	}
	
	for(i=1;i<=10000;i++)
	{
		if(cache[i] == -1)
		{
			printf("%d\n",i);
		}		
	}	
}
