#include <stdio.h>

//처음에 이항계수에 낚였으나 단순 확률 문제임.
//종류별 옷의 종류의 갯수 카운트 + 1(안입는 경우)를 모두 곱한 후 벌거벗은 경우 -1. 

int getcomb(int n, int k)
{
	if(n == k || k == 0)
	 return 1;
	 
	else
	 return getcomb(n-1,k-1) + getcomb(n-1,k);
}

int order(const void *a, const void *b)
{
	return strcmp((char *)a,(char *)b);
}

int main()
{
	char cloth[31][21];
	char kind[31][21];
	int tc=0,n=0,i=0,j=0,k=0,m=0,combi=0;
	int kind_cnt[31] ={0};
	
	scanf("%d",&tc);
	
	for(i=0;i<tc;i++)
	{
		for(j=0;j<31;j++)
		{
			kind_cnt[j]=0;
		}
				
		scanf("%d",&n);
		combi=1;
		
		for(j=0;j<n;j++)
		{
			scanf("%s %s",cloth[j],kind[j]);
		}
				
		//옷 종류별로 문자 정렬 
		qsort((void*)kind,n,sizeof(kind[0]),order);	
		
		for(m=0;m<n;m++)
		{
			for(j=0;j<n;j++)
			{			
				if(strcmp(kind[m],kind[j]) == 0)
				 kind_cnt[m]++; //옷 종류가 같으면 cnt 증가 
			}
			m = m + kind_cnt[m] -1;//굳이 이렇게 넣을 필요 없었네.. 
		}
	#if 0	
		for(j=0;j<n;j++)
		{
			printf("kind_cnt : %d\n",kind_cnt[j]);
		}
	#endif
		
		for(j=0;j<n;j++)
		{
			if(kind_cnt[j]!=0)
			{
			 kind_cnt[j]++;
			 combi*=kind_cnt[j];
			}
		}
		printf("%d\n",combi-1);
	}
}
