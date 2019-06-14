#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

stack<int> st;
vector<string> str;

int N;

int stclear(stack<int> &a)
{
	while(a.empty() == 0)
	 a.pop();
}

int main(void)
{
	string tmp;
	
	cin >> N;

	for(int i=0;i<N;i++)
	{
		cin >> tmp;
		str.push_back(tmp);
	}
	
	for(int i=0;i<N;i++)
	{
		bool yes = 1;
		stclear(st);
		string tmp_s;
		tmp_s = str[i];
		//cout << tmp_s.length() << endl;

		for(int k=0;k<tmp_s.length();k++)
		{
			if(tmp_s[k] == '(')
			{
				st.push(0);
				//printf("push i:%d k:%d\n",i,k);
			}
			else if(tmp_s[k] == ')')
			{
				//printf("pop i:%d k:%d\n",i,k);
				if(st.empty())
				{
					yes = 0;
					break;
				}
				st.pop();
			}	
		}
		if(st.empty()==0 || yes == 0)
		{
			cout << "NO" << endl;
		}		
		else 
		{			
			cout << "YES" << endl;
		}		
	}

	return 0;	
}
