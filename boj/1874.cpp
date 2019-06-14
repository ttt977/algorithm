#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
stack<int> st;
vector<int> rst;
vector<string> rst_print;




int main(void)
{
	int no;
	
	cin >> N;

	for(int i=0;i<N;i++)
	{
		scanf("%d",&no);
		rst.push_back(no);				
	}	

	rst_print.clear();


	int stp = 1;

	for(int i=0;i<N;i++)
	{
		if(st.empty())
		{
			rst_print.push_back("+");
			st.push(stp++);
		}
		while(st.top() != rst[i])
		{
			if(stp > N)
			{
				cout << "NO" << endl;
				return 0;
			}
			rst_print.push_back("+");
			st.push(stp++);			
		}
		if(st.empty() == 1)
		{
			cout << "NO" << endl;
			return 0;
		}
		rst_print.push_back("-");
		st.pop();		
	}

	for(int i=0;i<rst_print.size();i++)
	{
		cout << rst_print[i] << "\n";
	}
	return 0;
}
