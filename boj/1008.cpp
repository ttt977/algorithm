#include <iostream>

using namespace std;

int main(void)
{
	long double A=0,B=0;
	
	cin >> A >> B;
	//printf("%.19Lf\n",A/B);
	cout.precision(19);
	cout << A/B << endl;
	return 0;
}
