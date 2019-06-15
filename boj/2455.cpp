#include <iostream>
#define MAX2(a,b) (a > b ? a : b)
#define MAX3(a,b,c) (MAX2(a,b) > c ? MAX2(a,b) : c)

using namespace std;

int main(void)
{
	int sta[4][2];
	int i=0,a=0,b=0,c=0;
	for(i=0;i<4;i++)
	{
		cin >> sta[i][0] >> sta[i][1];
	}
	a = sta[0][1];
	b = a - sta[1][0] + sta[1][1];
	c = b - sta[2][0] + sta[2][1];
	cout << MAX3(a,b,c) << endl;
}
