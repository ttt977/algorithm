#include <iostream>
#include <math.h>

using namespace std;
int n;

void do_print(int a, int b)
{	
	//cout << a << " " << b << endl;
	printf("%d %d\n",a,b);
}

int hanoi(int p, int start, int tmp, int end)
{
	if(p == 1)
	{
     do_print(start,end);
	 return 1;
	}	
	return hanoi(p-1,start,end,tmp) + hanoi(1,start,tmp,end) + hanoi(p-1,tmp,start,end);	
}

int main(void)
{
	unsigned long long ans=0,ans1=0;
	cin >> n;
	
	cout << pow(2,n)-1 << endl;
	
	ans = (pow(2,n)-1) / 1000000000000000;
	ans1 = (pow(2,n)-1) - (((pow(2,n)-1) / 1000000000000000)*1000000000000000);
	if(ans != 0)
	 printf("%llu %llu\n",ans,ans1);
	else
	 cout << ans1 << endl;
	
	
	if(n <= 20)
	 hanoi(n,1,2,3);
	return 0;
}
