#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> rope;
int cache[1001];
unsigned long long ans;

bool comp(int a, int b)
{
	return a > b;
}

int main(void)
{
	int tmp;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> tmp;
		rope.push_back(tmp);
	}

	sort(rope.begin(),rope.end(),comp);
	
	ans = rope[0];
	for(int i=1;i<N;i++)
	{
		if(rope[i]*(i+1) > ans)
		 ans = rope[i]*(i+1);
	}
	cout << ans << endl;

	return 0;
}
