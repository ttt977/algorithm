#include <iostream>

#define DIV 1000000000

using namespace std;
long long cache[11][101];


int getcntfromx(int x, int depth)
{
	if(cache[x][depth] != -1)
	 return cache[x][depth];
	 
	if(depth == 2)
	{
		if(x >=1 && x <= 8)
		 return cache[x][depth]=2;
		else return cache[x][depth]=1;
	}
	else if(depth == 1)
	{
		if(x >=1 && x <= 9)
		 return cache[x][depth]=1;		
	}
	else
	{		
		if(x == 0)
		 return cache[x][depth] = getcntfromx(1,depth-1)%DIV;
		else if(x == 9)
		 return cache[x][depth] = getcntfromx(8,depth-1)%DIV;
		else if(x >=1 && x <= 8)
		 return cache[x][depth] = getcntfromx(x-1,depth-1)%DIV + getcntfromx(x+1,depth-1)%DIV;
	}
	
}

int main(void)
{
	int n=0,i=0,j=0;
	long long ans =0, tmp=0;
	
	for(i=0;i<11;i++)
	{
		for(j=0;j<101;j++)
		 cache[i][j]=-1;
	}
	
	cin >> n;
	
	for(i=1;i<=9;i++)
	{
		tmp = getcntfromx(i,n);
	//	cout << "i=" << i << " tmp=" << tmp << endl;
		ans += tmp;
	}
	cout << ans%DIV << endl;	
}
