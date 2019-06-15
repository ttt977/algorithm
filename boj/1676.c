#include <stdio.h>
#define MIN(x,y) (x)<(y)?(x):(y)

//500*499*...각 수의 2/5 제곱 수를 모두 더해서 작은 값이 0의 갯수 

int cnt[501][2]={0};
 

int main()
{
	int i=0,j=0,tmp=0,cnt2=0,cnt5=0,N=0;

	scanf("%d",&N);

	cnt[0][0]=0;
	cnt[0][1]=0;
		  
	for(i=1;i<=500;i++)
	{
	 cnt2=cnt5=0;
	 tmp = i;
	 for(j=0;j*j<=i;j++)
	 {	
	  	if(tmp == 2)
	  	{
	  		cnt2++;	  
			break;			  		
		}
		else if(tmp == 5)
		{
			cnt5++;
			break;
		}				
	 	if(tmp%2 == 0)
	 	{
	 		cnt2++;
	 		tmp/=2;
		}
		else if(tmp%5 == 0)
		{
			cnt5++;
			tmp/=5;
		}
		else
		 break;
	 }
	 cnt[i][0] = cnt2;
	 cnt[i][1] = cnt5;
	}
	
	cnt2=cnt5=0;
	
	for(i=0;i<=N;i++)
	{
		cnt2+=cnt[i][0];
		cnt5+=cnt[i][1];
	}	
	printf("%d\n",MIN(cnt2,cnt5));	
}
