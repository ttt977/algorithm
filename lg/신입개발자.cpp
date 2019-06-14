#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_PROJECT (15) 
typedef pair<int,int> pii;
int     N;
int		sol;

vector<pii> meet;

void Data_Input(void) {
	cin >> N;
	int a=0,b=0;
	for (int i = 0; i<N; i++) {
		cin >> a >> b;
		meet.push_back(make_pair(a,b));
	}
}

bool comp(pii &a, pii &b)
{
	if(a.second == b.second)
	 return a.first < b.first;
	else return a.second < b.second;
}

void solve(int start)
{
	int i=0;

	if( start >= meet[meet.size()-1].first)
	{
	 cout << sol << endl;
	 return;
	}

	if(start == 0)
	{
		sol++;
		solve(meet[0].second + 1);
	}
	else
	{
		for(i=0;i<N;i++)
		{
			if(start <= meet[i].first)
			{
				sol++;				
				break;
			}
		}
		if(i == N-1)
		{
			cout << sol << endl;
			return;
		}
		else
	 	 solve(meet[i].second + 1);		
	}	
}

int main(void) {
	Data_Input();
	sort(meet.begin(),meet.end(),comp);
	solve(0);
	return 0;
}
