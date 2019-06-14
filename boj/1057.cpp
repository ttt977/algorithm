#include <iostream>

using namespace std;

int round;
int N,A,B;

int main(void)
{
	int tmpa=0,tmpb=0;
	cin >> N >> A >> B;
	while(A!=B)
	{
		round++;
		tmpa=A/2 + A%2;
		tmpb=B/2 + B%2;
		A=tmpa;
		B=tmpb;
	}
	cout << round <<endl;
	return 0;
}

