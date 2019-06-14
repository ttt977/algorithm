#include <iostream>
#include <cmath>
using namespace std;

int N; 						// �̵������� ������ �����ϱ� ���� ����
double M; 				// ���͸� �뷮�� �����ϱ� ���� ����
int S[10010]; 			// �̵��ӵ��� �����ϱ� ���� �迭
double T[10010];	// �̵��ð��� �����ϱ� ���� �迭
int L[10010]; 			// �̵��Ÿ��� �����ϱ� ���� �迭
double P[10010];	// ���͸� �Ҹ��� �����ϱ� ���� �迭
double R;				// ���͸� �ܷ��� �����ϱ� ���� ����

void InputData(void){
	int i;

	// �̵������� ������ ���͸� �뷮�� �Է� �޴� �κ�
	cin >> N >> M;

	// N ���� �̵��ӵ��� �̵��ð��� �Է� �޴� �κ�
	for (i = 1; i <= N; i++) {
		cin >> S[i] >> T[i];
	}
}

int main(void){
	int i;
	
	InputData();
		
	// �̵��ӵ��� �̵��ð��� �̿��Ͽ� �̵��Ÿ��� ���
	for (i = 1; i <= N; i++) {
		L[i] = floor((S[i] * T[i])+0.5);
	}

	// �̵��Ÿ��� �ӵ����͸� �̿��Ͽ� ���͸� �Ҹ��� ���
	for (i = 1; i <= N; i++) {
		P[i] = (L[i] * (abs(S[i] - S[i - 1]) + 1)) / 2.0;
	}

	// ���͸� �Ҹ��� �̿��Ͽ� ���͸� �ܷ��� ��ȭ�� ���
	R = M;
	for (i = 1; i <= N; i++) {
		R -= P[i];
	}

	// ���͸� �ܷ��� �������� ���
	cout.setf(ios::fixed);
	cout.precision(1);
	cout << R << endl;

	return 0;
}
