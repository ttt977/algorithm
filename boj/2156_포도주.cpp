#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int N;
int p[10002];
unsigned long long cache[10002];

unsigned long long solve(int n)
{
	if(cache[n] != -1)
	 return cache[n];

	if(n == 1)
	 return cache[n] = p[1];
	else if(n == 2)
	 return cache[n] = p[1] + p[2];
	else if(n == 3)
	{
		return cache[n] = max(max((p[1]+p[2]),(p[1]+p[3])) ,(p[2]+p[3]));		
	}
	else if(n == 0)
	 return cache[n] = 0;
	else
	{
		int case1 = p[n] + p[n-1] + solve(n-3);
		int case2 = p[n] + solve(n-2);
		int case3 = p[n-1] + p[n-2] + solve(n-4);
		return cache[n] = max(max(case1,case2),case3);		
	}
	
}

int main(void)
{
	//n 마실때/안마실때
	//n을 마실 경우
	//p[n] + solve(n-2) or p[n]+p[n-1]+solve(n-3)
	//n을 못마실 경우
	//p[n-1] + p[n-2] + solve(n-4)
	memset(cache,-1,sizeof(cache));

	cin >> N;
	for(int i=1;i<=N;i++)
 	 scanf("%d",p+i);

	cout << solve(N) << endl;
 
	return 0;
}
