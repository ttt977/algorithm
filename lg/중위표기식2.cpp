//������ Ȱ���� ����ǥ��� ���� 

#include <iostream>
#include <stack>
#include <vector> 

using namespace std;

int N;

vector<int> v;
vector<char> op;

stack<int> st;

unsigned long long ans;

int main(void)
{
	int tmp_num=0;
	char tmp_op;

	cin >> N;

	cin >> tmp_num; //���� ���� �ϳ� �Է¹ޱ�
	v.push_back(tmp_num);

	for(int i=1;i<N;i++) //������/���� �Է¹ޱ� 
	{	
	 cin >> tmp_op;
	 cin >> tmp_num;	 
	 v.push_back(tmp_num);
	 op.push_back(tmp_op);
	}

	st.push(v[0]); //ù��° ���� ���ÿ� �ֱ� 

	for(int i=1;i<N;i++)
	{
		if(op[i-1] == '+') //���ϱ�� ���߿� ������ ���� ���ÿ� �ֱ� 
		 st.push(v[i]);
		else if(op[i-1] == '*')
		{
			int tm = st.top(); //���� ������ ���� ���ͼ� ���� �� �ٽ� ���ÿ� �ֱ� 
			st.pop();
			st.push( (tm*v[i]) % 10000 );
		}		 
	}
	for(int i=0;st.empty()!=1;i++)
	{
		ans += st.top();
		st.pop();
	}		

	cout << ans%10000 << endl;
	return 0;
} 
