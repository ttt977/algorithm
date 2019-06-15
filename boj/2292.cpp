#include <iostream>
#include <cstring>

int cache[20001];

using namespace std;

//n단계 처음 시작되는 값 
int solve(int n)
{
	if(cache[n] != -1)
	 return cache[n];	 
	if(n==1)
	 return cache[1] = 1;
	else if(n==2)
	 return cache[n] = 2;
	else
	 return cache[n] = solve(n-1) + (n-2)*6;
}

int main(void)
{
	int N=0,j=0;
	
	for(int i=0;i<=20000;i++)
	 cache[i] = -1;	 
	 
	cin >> N;
	solve(20000);
	
//	for(int i=15000;i<N;i++)
//	cout << "cache[" << i << "] =" << cache[i] << endl;
	
	for(j=0;j<20000;j++)
	{
		if(N >= cache[j] && N < cache[j+1])
		 break;
	}
	cout << j << endl;
}
