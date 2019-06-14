#include <iostream>
#include <memory.h>

#define MAX(a,b) ((a>b)?(a):(b))

using namespace std;

int cache[310];
int N;				//	����� ����
int P[310];		//	P[i]: i ����� ����� �� ��� ����


/*
n�� ° ����� ������ ��ƾ� �ϹǷ� n-1�� ������ ���� n-1�� ���� �ʰ� ���� ��찡 �ִ�.
n-1�� ���� ��� n-2�� �� ��� ������ n-3������ �ִ� ������
n-1�� ���� ���� ��� n-2������ �ִ� ������ ū ���� �����ϴ� ��ȭ��.
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
	
	InputData();					//	�Է� �Լ�
	memset(cache,-1,sizeof(cache));
	int sol = Solve(N);

	cout << sol << endl;		//	���� ���
	return 0;
}

