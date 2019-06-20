//���� ���� ���� 
//�� �ǹ� ���󿡼� �� �� �ִ� ���� �� �հ� ī��Ʈ -> �� �ǹ��� ������ �� �� �ִ� �ǹ��� �� ������ ī��Ʈ
//�˰��� : monotone stack 

#include <iostream>
#include <stack>

using namespace std;

int N;//�ǹ� ��
int H[80010];//�ǹ� ����

stack<int> st;
 
void Input_Data(void){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> H[i];
	}
}

long long solve(){
	long long sum = 0;

	st.push(H[0]); //���� ó�� ���� ���� ���� �ʱⰪ���� ���� 

	for(int i=1;i<N;i++)
	{	
		if(H[i] >= st.top()) //���� ���̰� ���� ������ ���̿� ���ų� �� ���� ��� 
		{		 
		 while(H[i] >= st.top()) //���� ���̰� ���� ���� ���̺��� �۾��� ������.
		 {		  
		  st.pop(); //���ÿ��� ��� ������. (������ �׻� ������ ���������� �����ؾ� �ϱ� ����) 
		  if(st.empty())
		   break;		  
		 }
		 sum+=st.size(); //���� �ǹ� ������ �� �� �ִ� �ǹ� �� = ������ ũ��(���� �ǹ����� ���� �ǹ��� ���ÿ� ��� �����Ƿ�) 
		 st.push(H[i]); //�� ��ġ�� �ֱ� 
		}
		else //���� ���̰� ���� ������ ���̺��� ���� ���
		{
		 sum+=st.size(); //���� �ǹ� ������ �� �� �ִ� �ǹ� �� = ������ ũ��(���� �ǹ����� ���� �ǹ��� ���ÿ� ��� �����Ƿ�)
		 st.push(H[i]);	
		}
	}
	return sum;
}

int main(){
	long long ans = -1;
	Input_Data();
	ans = solve();
	cout << ans << endl;
	return 0;
}
