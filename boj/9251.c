#include <stdio.h>
#include <string.h>
#define MAX(a,b) (a)>(b)?(a):(b)

char A[1001];
char B[1001];
int result[1001][1001];

int lcs(int i,int j)
{
	//printf("lcs %d %d\n",i,j);
	int tmp1=0,tmp2=0;
	
	if(result[i][j] != -1)
	 return result[i][j];
	 
	if(i == 0 || j == 0)
	{
		result[i][j] = 0;
		return result[i][j];
	}
	
	if(A[i-1] == B[j-1])
	{
		//printf("same %c %c\n",A[i],B[j]);
		result[i][j] = lcs(i-1,j-1) + 1;		
	}
	else
	{
		tmp1 = lcs(i-1,j);
		tmp2 = lcs(i,j-1);
		result[i][j] = MAX(tmp1,tmp2);
	}
	return result[i][j];	
}

int main()
{
	scanf("%s",A);
	scanf("%s",B);	
	memset(result,-1,sizeof(result));
	
	lcs(strlen(A),strlen(B));
	
	printf("%d\n",result[strlen(A)][strlen(B)]);
}


