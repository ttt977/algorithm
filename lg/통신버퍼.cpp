#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
 
int N;

vector<pair<int,int> > v;

bool comp(pair<int,int> &a, pair<int,int> &b)
{
	if(a.second == b.second)
      return a.first < b.first;
	else return a.second < b.second;
}

int main(void)
{
	int no=0,level=0;

	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> no >> level;
		v.push_back(pair<int,int>(no,level));
	}
	sort(v.begin(), v.end(), comp);

	for(int i=0;i<v.size();i++)
	{
		cout << v[i].first << " ";
	}
	return 0;
}

