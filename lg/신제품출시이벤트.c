#include <stdio.h>

int a[50+10];		//	ī��޸� ���ڸ� �����ϴ� �迭
int N;					//	ī�� ����
int M;					//	����ǰ�뷮
int sol;				//	����

int main(void){
	int i, j, k, l;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) scanf("%d", &a[i]);
	
	sol = 0;

	//	�Ʒ� �ڵ��� ������ �����ϼ���
	for (i = 0; i <=  N - 4; i++){
		for (j = i + 1; j <=  N - 3; j++){
			for (k = j + 1; k <=  N - 2; k++){
				for (l = k + 1; l <=  N - 1; l++){
					if ((a[i] + a[j] + a[k] + a[l]) == M) sol++;
				}
			}
		}
	}
	printf("%d", sol);	//	���� ���
	return 0;
}
