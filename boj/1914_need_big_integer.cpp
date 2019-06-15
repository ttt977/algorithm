#include <iostream>
#include <math.h>

using namespace std;
int N;

void hanoi(int n, int start, int tmp, int end)
{
	if(n == 1)
	{
		printf("%d %d\n",start, end);
		return;
	}	
	hanoi(n-1,start,end,tmp);
	hanoi(1,start,tmp,end);
	hanoi(n-1,tmp,start,end);
}

int main(void)
{
	unsigned long long ans=1,anst=0;
	cin >> N;
	ans = pow(2,N)-1;
	cout << ans << endl;
	if(N < 20)
	 hanoi(N,1,2,3);

 	return 0;
}
