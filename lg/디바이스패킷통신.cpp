#include <cstring>
#include <iostream>
using namespace std;

// ��Ŷ Ÿ���� ���� ����
#define TYPE_START 0
#define TYPE_DATA 1
#define TYPE_END 2

int N; // ���ڿ��� ����
int M; // �������� �ִ� ����
unsigned char str[10 + 10][64 + 10]; // ���ڿ����� ������ �迭
unsigned char pkt[4 + 64 + 10]; // ��Ŷ �迭
int sol; // ���۵� ��� ��Ŷ���� ����Ʈ ������ ���� ��

// ��Ŷ�� �����ϴ� �Լ�
// ���� ������ �̷������ �ʰ� ��� ��Ŷ�� �� ����Ʈ�� ���� ���� ��� �� ������
// len�� ������ ��Ŷ�� ����
int send_pkt(int len)
{
	int i;
	int sum = 0;

//	cout << "send_pkt ";

	for (i = 0; i < len; i++) {
		sum += pkt[i];
	//	printf("0x%x ",pkt[i]);
	}
//	cout << endl;

	return sum;
}

// ��Ŷ�� ����� �Լ�
// type�� ��Ŷ Ÿ��
// num�� ���ڿ��� ��ȣ
int make_pkt(int type, int num)
{
	int i;
	int idx = 3; // ��Ŷ �迭�� ��� ��ȣ
	int len; // ���� ���ڿ��� ����
	int len2; // 4�� ����� ������ ���ڿ��� ����
	static int seq; // ��Ŷ ��ȣ

	pkt[1] = type; // ��Ŷ Ÿ��
	//pkt[3] = 0; // RSV

	idx = 4;

	switch (type) {
	case TYPE_START:
		seq = 0; // ��Ŷ ��ȣ �ʱ�ȭ
		pkt[2] = 0; // ������ ����: ������ 0
		pkt[3] = 0; // RSV
		break;

	case TYPE_DATA:
		seq++; // ��Ŷ ��ȣ ����
		len = strlen((char *)str[num]); // ������ ���� = ���ڿ��� ����
		if(len%4 != 0)
		{
			if ( M < (len + (4-(len%4))))
			 pkt[2] = M;
			else pkt[2] = len + (4-(len%4));
		}
		else
		{
			if(len > M)
	 		 pkt[2] = M;
			else
			 pkt[2] = len;
		}

		// ���ڿ� ����
		for (i = 0; i < pkt[2]; i++) {
			if(str[num][i] == '*' || str[num][i] == NULL)
			 pkt[idx++] = 0xff;
			else
 			 pkt[idx++] = str[num][i];
		}
		pkt[idx] = 0; //reserved
		break;

	case TYPE_END:
		seq++; // ��Ŷ ��ȣ ����
		pkt[2] = 0; // ������ ����: ������ 0
		pkt[3] = 0; // RSV
		break;

	default:
		break;
	}

	pkt[0] = seq; // ��Ŷ ��ȣ

	return idx; // ��Ŷ ���� ����
}

// ��Ŷ�� ����� �����ϴ� �Լ�
int handle_pkt(void)
{
	int i;
	int len;
	int sum;

	// START ��Ŷ
	len = make_pkt(TYPE_START, 0);
	sum = send_pkt(len);

	// DATA ��Ŷ
	for (i = 0; i < N; i++) {
		len = make_pkt(TYPE_DATA, i);
		sum += send_pkt(len);
	}

	// END ��Ŷ
	len = make_pkt(TYPE_END, 0);
	sum += send_pkt(len);

	return sum;
}

int main(void)
{
	int i;

	cin >> N >> M;

	for(int a=0;a<20;a++)
	{
		for(int b=0;b<74;b++)
		str[a][b] = '*';
	}

	for (i = 0; i < N; i++) {
		cin >> str[i];
	}

	sol = handle_pkt();


	cout << "0x" << hex << sol;
	
	return 0;
}

