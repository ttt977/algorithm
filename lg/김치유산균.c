#include <stdio.h>
#include <memory.h>
#include <string.h>

long long int cache[100000000] = {0,};

long long int kimchi(int n){
	if(cache[n] != -1)
		return cache[n];
	
	if (n <= 3)	
	{
		cache[n] = 1;
		return cache[n];
	}
	else if (n % 3 == 0)
	{
		cache[n] = 3 * kimchi(n - 1) - 2 * kimchi(n - 2) - kimchi(n - 3);
		return cache[n];
	}
	else if (n % 3 == 1)
	{
		cache[n] = 3 * kimchi(n - 1) - 2 * kimchi(n - 2) + kimchi(n - 3);
		return cache[n];
	}
	else 
	{
		cache[n] = 2 * kimchi(n - 1) - 2 * kimchi(n - 2) + kimchi(n - 3);
		return cache[n];
	}
}

int main(void){
	int T;
	long long int i = 0;
	for(i=0;i<100000000;i++)
	 cache[i] = -1;
	 
	scanf("%d", &T);
	printf("%lld", kimchi(T));
	return 0;
}
