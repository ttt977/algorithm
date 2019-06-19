//스택을 활용한 중위표기식 구현 

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

	cin >> tmp_num; //숫자 먼저 하나 입력받기
	v.push_back(tmp_num);

	for(int i=1;i<N;i++) //연산자/숫자 입력받기 
	{	
	 cin >> tmp_op;
	 cin >> tmp_num;	 
	 v.push_back(tmp_num);
	 op.push_back(tmp_op);
	}

	st.push(v[0]); //첫번째 숫자 스택에 넣기 

	for(int i=1;i<N;i++)
	{
		if(op[i-1] == '+') //더하기면 나중에 연산을 위해 스택에 넣기 
		 st.push(v[i]);
		else if(op[i-1] == '*')
		{
			int tm = st.top(); //스택 맨위에 숫자 빼와서 곱한 후 다시 스택에 넣기 
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
