#include <iostream>
#include <memory.h>

#define MAX(a,b) ((a>b)?(a):(b))

using namespace std;

int cache[310];
int N;				//	계단의 개수
int P[310];		//	P[i]: i 계단을 밟았을 때 얻는 점수


/*
n번 째 계단은 무조건 밟아야 하므로 n-1을 밟고오는 경우와 n-1를 밟지 않고 오는 경우가 있다.
n-1를 밟을 경우 n-2는 못 밟기 때문에 n-3까지의 최대 점수와
n-1를 밟지 않을 경우 n-2까지의 최대 점수중 큰 것을 선택하는 점화식.
*/
int Solve(int n){
	
	if(cache[n] != -1)
		return cache[n];
	
	if(n == 1)
		return cache[n] = P[n];
	else if(n == 2)
		return cache[n] = P[1]+P[2];	
	else if (n == 0)
		return cache[n] = 0;
	return cache[n] = MAX((Solve(n-3) + P[n-1] + P[n]), (Solve(n-2) + P[n]));
}

void InputData(){
	cin >> N;
	for(int i=1 ; i<=N ; i++){
		cin >> P[i];
	}
}

int main(){
	
	InputData();					//	입력 함수
	memset(cache,-1,sizeof(cache));
	int sol = Solve(N);

	cout << sol << endl;		//	정답 출력
	return 0;
}

