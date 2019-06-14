#include <iostream>
using namespace std;

int N;
int h[31];
int sol;	

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> h[i];
	}
}

int main(){
	
	InputData();
	int day=0;

	for (int i = 0; i < N; i++){	
		day=0;
		if(h[i] >= 3 && h[i] <= 6)
		 day+=100;
		else if(h[i] > 6)
		{
		  day+=100;
		  day+=(h[i]-6)*50;
		}
		if(day > 500)
			day = 500;
		sol+=day;
	}
	if(sol >= 10000)
	 sol*=0.9;
	cout << sol << endl; 		// 정답 출력
	return 0;
}
