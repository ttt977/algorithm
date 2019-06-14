#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

typedef pair<int,int> pii;

int main() {
	int N,tmp;
	vector<pii> pv;

	cin >> N;
	
	for(int i=0;i<N;i++)
	{
		cin >> tmp;
		pv.push_back(make_pair(tmp,i));
	}

	sort(pv.begin(),pv.end());

	for(int i=0;i<N;i++)
	{
		cout << pv[i].second << " ";
	}

  return 0;
}

