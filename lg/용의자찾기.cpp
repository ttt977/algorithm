#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
string list;
vector<string> str;
vector<int> cnt;

int main(void) 
{
	string tmp;
	cin >> list;
	cin >> N;
	string::size_type n;
	int tcnt=0;
	int min=-1,min_index=0;
	
	for(int i=0;i<N;i++)
	{
		cin >> tmp;
		str.push_back(tmp);	
	}

	for(int i=0;i<N;i++)
	{
		n = 0;
		tcnt=0;
		while(n != string::npos)		
		{
			n = list.find(str[i],n);						
			if(n != string::npos )
			{
			 n++;
			 tcnt++;
			}
		}
		cnt.push_back(tcnt);
	}	

	for(int i=0;i<N;i++)
	{
		if(min < cnt[i])
		{	
			min = cnt[i];
			min_index = i;
		}
	}

	if(min == 0)
	 cout << "null" << endl;
	else
	 cout << str[min_index] << endl;


	return 0;
}
