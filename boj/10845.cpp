#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void)
{
	int N=0;
	int x=0;
	string str;
	queue<int> q;

	cin >> N;

	for(int i=0;i<N;i++)
	{
		cin >> str;
		if(str == "push")
		{
			cin >> x;
			q.push(x);
		}
		else if(str == "pop")
		{
			if(q.empty())
			 cout << "-1" << "\n";
			else
			 {
				cout << q.front() << "\n";
				q.pop();
			 }
		}
		else if (str == "size")
		{
			cout << q.size() << "\n";
		}
		else if (str == "empty")
		{
			cout << q.empty() << "\n";
		}
		else if(str == "front")
		{
			if(q.empty())
			 cout << "-1" << "\n";
			else
			 {
				cout << q.front() << "\n";		
			 }
		}
		else if(str == "back")
		{
			if(q.empty())
			 cout << "-1" << "\n";
			else
			 {
				cout << q.back() << "\n";		
			 }
		}		
	}
	return 0;
}
