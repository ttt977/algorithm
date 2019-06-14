#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int N; //��
int S; //�������
int C[50010]; //����
int Y[50010]; //�뷮

void Input_Data(void){
	int i;
	cin >> N >> S;
	for (int i = 0; i < N; i++){
		cin >> C[i] >> Y[i];
	}
}

/*
X�� �̸� ���� ���� ����
N��/X�� ���� �� ���
N = C[N];

N ���� ���� ��� X�� ���ؼ� �Ʒ� �� ����Ͽ� ���� ���� �� ����
X = C[X] + (N-X)*S;

�� �� ���� ���� ���� ���� ����.

vector<int> xprice;
*/

int calprice(int day)
{
	int cur_min = 987654321;
	int dayprice = 987654321;
	int tmp = 0;
	
	dayprice = C[day];	
	for(int i=day-1; i>=0 ; i--)
	{
			if((day-i)*S > dayprice) //keypoint ���� ����� �ش� ������ ��뺸�� Ŀ�� ��� ���̻� ����� �ʿ� ����. 
				break;
			tmp = C[i] + (day-i)*S;			
			if(dayprice > tmp )
			{
				if(cur_min > tmp)
					cur_min = tmp;
			}		
	}		
	if(cur_min == 987654321)
		return dayprice;
	else
		return cur_min;
}

int main(){
	long long ans = 0;
	Input_Data();		// �Է� �Լ�
	
	ans += C[0] * Y[0];	
	for(int i=1;i<N;i++)
	{
		int tmp = 0;
		tmp = calprice(i);
		//cout << "tmp " << tmp << endl;
		ans += (tmp * Y[i]);
	}
	// TODO : �ڵ带 �ۼ��ϼ���
	cout << ans << endl;	// ���� ���
	return 0;
}

