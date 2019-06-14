#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int,int> pii;

int N;
vector<pii> v;
int ans;

bool comp(pii &a, pii &b)
{
	if(a.second == b.second)
	 return a.first < b.first;
	else return a.second < b.second;
}

int main(void)
{
	int start=0,end=0;

	cin >> N;

	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&start,&end);
		v.push_back(make_pair(start,end));	
	}

	sort(v.begin(),v.end(),comp);

	int end_t = v[0].second;

	for(int i=1;i<N;i++)
	{
		if(end_t <= v[i].first)
		{
		 end_t = v[i].second;
		 ans++;
		}
	}

	printf("%d\n",ans+1);
	
	return 0;
}

