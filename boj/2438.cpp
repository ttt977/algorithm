#include <iostream>

using namespace std;

int main(void)
{
	int n=0,i=0,j=0;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
