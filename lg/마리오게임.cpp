
#include <iostream>
using namespace std;

int N;
int P[150000 + 10];

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> P[i];
	}
}

int main(){
	int ans = 0;

	InputData();	
	ans = P[0];
	for(int i=1;i<N;i++)
	{
		if(P[i-1] < P[i])
		 ans = ans + P[i] - P[i-1];
	}
	cout << ans << endl;
	return 0;
}

