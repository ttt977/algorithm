#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,pair<int,int> > pi;

vector<pi> v;

int n,id,s,r;

//comp vector로 사용 시 실제 구성되어 있는 data structure가 들어가야 함. 
bool comp(pi &a, pi &b)
{
	if(a.second.first == b.second.first && a.second.second == b.second.second)
	{
		return a.first > b.first;
	}
	else if(a.second.first == b.second.first)
	{
		return a.second.second > b.second.second;
	}
	else return a.second.first > b.second.first;
}

int main(void)
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> id >> s >> r;
		v.push_back(make_pair(id,make_pair(s,r)));
	}
	sort(v.begin(),v.end(),comp);

	for(int i=0;i<n;i++)
	{
		printf("%d ",v[i].first);
	}

	return 0;
}

