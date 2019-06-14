#include <iostream>
#include <stack>

using namespace std;

int N;

int main(void)
{
	string str;
	int no;
	stack<int> st;

	cin >> N;

	for(int i=0;i<N;i++)
	{
		cin >> str;
		if(str == "push")
		{
			cin >> no;			
			st.push(no);
		}
		else
		{
			if(str == "pop")
			{
				if(st.empty())
					cout << -1 << endl;
				else
				{
				 cout << st.top() << endl;
				 st.pop();
				}
			}
			else if(str == "size")
				cout << st.size() << endl;
			else if(str ==  "empty")
			{
				if(st.empty())
					cout << 1 << endl;
				else
					cout << 0 << endl;
			}
			else if(str == "top")
			{
				if(st.empty())
					cout << -1 << endl;
				else
					cout << st.top() << endl;
			}
		}	
	}	
}
