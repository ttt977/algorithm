#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getgcd(int a, int b)
{
	int gcd = 0;
	
	if(a%b == 0)
	 gcd = b;
	else 
	 gcd = getgcd(b,a%b);
	 
//	 cout << "gcd = " << gcd << endl;
	 return gcd;
}

int main(void)
{
	int a=0,b=0,gcd=0,lcm=0;
	cin >> a >> b;
	gcd = getgcd(a,b);
	lcm = (a*b)/gcd;
	cout << gcd << endl;
	cout << lcm << endl;	
	return 0;
}
