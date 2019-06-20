#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> p;
int cache[1001];
unsigned long long ans;

int main(void)
{
	int tmp;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> tmp;
		p.push_back(tmp);
	}
	sort(p.begin(),p.end());

	cache[0] = p[0];
	ans = cache[0];
	for(int i=1;i<N;i++)
	{
		cache[i] = cache[i-1] + p[i];
		ans+=cache[i];
	}

	cout << ans << endl;

	return 0;
}
