#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int L,N;
vector<unsigned long long> ant;
unsigned long long ans_n,ans_m;

int main(void)
{	
	int tc;
	cin >> tc;

	while(tc--)
	{
	cin >> L >> N;
	int tmp;
	ant.clear();
	ans_n = 0;
	ans_m = 0;

	for(int i=0;i<N;i++)
	{
	 cin >> tmp;
	 ant.push_back(tmp);
	}
	sort(ant.begin(),ant.end());
	for(int i=0;i<N;i++)
	{
	  int t = 0;
	  if(ant[i] < L/2)
		t = ant[i];
 	  else
		t = L-ant[i];

	  if(t > ans_n)
		ans_n = t;
	}
	ans_m = max(L-ant.front(),ant.back());
//	ans_m = max(ans_m,(ant.back()-ant.front())); 
	cout << ans_n << ' ' << ans_m << endl;
	}
	return 0;
}
