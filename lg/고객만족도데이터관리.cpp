#include <iostream>
#include <string>
using namespace std;

int M;					// �ݺ� ���� ȸ��
char S[100000 + 10];	// ���� ���ڿ�

int main(void)
{
	int i;			// ���ڿ� S�� � ���ڸ� ����
	int len;		// ���ڿ� S�� ����
	char r_char;	// �ݺ��Ǵ� ����
	int r_cnt;		// �ݺ� ȸ��

	// ������ �б�
	cin >> M;
	cin >> S;

	// �ڵ� ���� �� ��� ���
	i = 0;
	r_cnt = 1;
	while(S[i] != '\0')
	{
		r_char = S[i];
		if(r_char == S[i+1])
		{
			r_char = S[i];
			r_cnt++;
		}
		else
		{
			if(r_cnt >= M)
			{
				printf("%c(%d)",r_char,r_cnt);
				r_cnt = 1;
			}
			else
			{
				for(int k=0;k<r_cnt;k++)
				printf("%c",r_char);
				r_cnt = 1;
			}
		}
		i++;
	}

	return 0;
}

