#include <iostream>
#include <algorithm>

using namespace std;

int N;
int S[100000 + 10];
int rst[100000 + 10];

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> S[i];
	}
}

int main(){
	int ans = -1;
	int tmp = 0;
	InputData();
	int k=0;

	//�ʱ� ������ ������ rst �迭�� ���� 
	for(int i=0;i<N-1;i++)
	{
		if(S[i] != S[i+1]) tmp++;
		else
		{
		  rst[k++] = tmp +1;
		  tmp = 0;
		}
	}
	rst[k++] = tmp +1;

	if(k == 1)
	 cout << rst[0] << endl;
	else if (k == 2)
	 cout << rst[0] + rst[1] << endl; // 2�� �� �ϳ��� ������Ű�� ����ǹǷ�.. 
	else if (k == 3)
	 cout << rst[0] + rst[1] + rst[2]<< endl; // ��� rst[1]�� ������Ű�� rst[0], rst[2]�� ����� 

	ans = rst[0] + rst[1] + rst[2];

	for(int i=3;i<k;i++)
	{
		ans = max(ans,rst[i-1] + rst[i] + rst[i+1] ); //rst �迭 ���������� �̵��ϸ鼭 max �� ���ϱ�. 
	}
	 
	cout << ans << endl;
}
