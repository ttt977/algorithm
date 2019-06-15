#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *sosu=NULL, sosu_cnt=0;

int is_sosu(int a)
{
	int i=0;
	
	if(a%2 == 0 && a!=2)
	 return 0;
	 
	for(i=0;i<=sosu_cnt;i++)
	{
		if(a == sosu[i])
		 return 1;		 
	}
	return 0;
}

int main()
{
	int i=0,j=0,k=0,tmp=0,n=0,tc=0,gold_cnt=0,tmp2=0;
	int *sosu_all,*gold;
	static gold_max = 10000;
	
	sosu_all = (int *)malloc(sizeof(int)*gold_max);
	memset(sosu_all,0,sizeof(sosu_all));
	
	for(i=2;i<=gold_max;i++)
	 sosu_all[i] = i;
	 
	for(i=2;i*i<=gold_max;i++)
	{
		if(sosu_all[i] != 0)
		{
			for(j=i*2;j<=gold_max;j+=i)
			{
			 sosu_all[j] = 0;			 
		    }
		}
	}
	
	for(i=0;i<=gold_max;i++)
	{
		if(sosu_all[i] != 0)
		 sosu_cnt++;
	}
	
	sosu=(int*)malloc(sizeof(int)*sosu_cnt);
	memset(sosu,0,sizeof(sosu));
	
	for(i=0;i<=gold_max;i++)
	{
		if(sosu_all[i] != 0)
		 sosu[tmp++] = sosu_all[i];
	}
		
	scanf("%d",&tc);
	
	for(j=0;j<tc;j++)
	{
		scanf("%d",&n);
		gold=(int*)malloc(sizeof(int)*sosu_cnt);
		memset(gold,0,sizeof(gold));
		tmp = 0;
		gold_cnt = 0;
		for(i=0;i<sosu_cnt;i++)
		{
			if(sosu[i] > n/2)
			 break;
						
			if(1 == is_sosu(n-sosu[i]))
			 gold[tmp++] = sosu[i];			
		}
		printf("%d %d\n",gold[tmp-1],n- gold[tmp-1]);
		free(gold);			
	}
}

