#include <iostream>
#include <list>

using namespace std;
list<int> lt;
list<int>::iterator ilt;

int N,K;

int main(void)
{
	int kill_cnt;
	cin >> N >> K;

	for(int i=1;i<=N;i++)
	lt.push_back(i);
	ilt = lt.begin();

	cout << "<";
	while(!lt.empty())
	{
		for(int i=0;i<K-1;i++)
		{
			++ilt;		 
			if(ilt == lt.end())
			 ilt = lt.begin();			
		}
		if(lt.size() == 1)
		 cout << *ilt;
		else
		cout << *ilt << ", ";
		ilt = lt.erase(ilt);
		if(ilt == lt.end())
			 ilt = lt.begin();	
	}
	cout << ">" <<endl;

	return 0;
}

