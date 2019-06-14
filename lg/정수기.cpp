#include <iostream>
using namespace std;

int M;    // ������������ ũ��
int P;    // �Ҽ����������� ũ��
int SI;   // Ȯ�� ������ ���� ��
int SJ;   // Ȯ�� ������ ���� ��
int L;    // Ȯ�� ������ ũ��

int a[100][100]; // ���������� ����
int b[100][100]; // �Ҽ��������� ����
int sol;          // ����

int check_pattern(int si, int sj) {
	int i, j;

	// ���������Ϳ� �Ҽ��������͸� ��
	for (i = 1; i <=  P; i++) {
		for (j = 1; j <=  P; j++) {
			if (a[si + i-1][sj + j-1] != b[i][j]) return 0;
		}
	}

	return 1;
}

int main(void) {
	int i, j;

	// ���������� �б�
	cin >> M;
	for (i = 1; i <= M; i++) {
		for (j = 1; j <= M; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	// �Ҽ��������� �б�
	cin >> P;
	for (i = 1; i <= P; i++) {
		for (j = 1; j <= P; j++) {
			scanf("%1d", &b[i][j]);
		}
	}

	// Ȯ�뿵�� ���� �б�
	cin >> SI >> SJ >> L;

	// Ȯ�뿵�� ���� �Ҽ��� ���� ����
	for (i = SI; i <= SI + L - P ; i++) {
		for (j = SJ; j <= SJ + L - P; j++) {
			sol += check_pattern(i, j);
		}
	}

	// ���� ���
	cout << sol;

	return 0;
}
