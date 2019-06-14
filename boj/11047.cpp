#include <iostream>
#include <vector>

using namespace std;

int N,K;
vector<int> val;
int cnt;

void calcnt(int k)
{
	for(int i=val.size()-1;i>=0;i--)
	{
		if(k == 0)
		 break;
		if(val[i]<=k)
		{
		 cnt+=K/val[i];
		 K%=val[i];	
		}
	}
}

int main(void)
{
	cin >> N >> K;
	int tmp;

	for(int i=0;i<N;i++)
	{
		cin >> tmp;		
		val.push_back(tmp);
	}
	calcnt(K);
	cout << cnt << endl;
}
