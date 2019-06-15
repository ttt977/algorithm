#include <iostream>
#include <memory.h>

using namespace std;

int getgcd(int A, int B)
{
	if(A==B)
	 return A;
	
	if(A%B == 0)
	 return B;
	else 
	 return getgcd(B,A%B);		
}

int main(void)
{
	int tc=0,A=0,B=0,gcd=0,lcm=0,i=0;
	cin >> tc;
	for(i=0;i<tc;i++)
	{
		cin >> A >> B;
		if(A>B)
		 gcd = getgcd(A,B);
		else
		 gcd = getgcd(B,A);
		
		lcm = (A*B)/gcd;
		
		cout << lcm << endl;
	}
	return 0;
}
