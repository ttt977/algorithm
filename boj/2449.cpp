#include <iostream> 
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int N,K;
vector<int> bulb;
int max_cnt;
int ans=0;
int cache[210][210];

int getcnt(int l, int r) //l ���� r ������ ���� ���� ��� ���� �ϴ�  �ּ� ���� ���� 
{	
	if(l == r)
	 return 0;

	if(l<0 || r<0)
	 return 0;

	if(r < l)
	 return 0;

	if(cache[l][r] != -1)
	 return cache[l][r];

	cache[l][r] = 987654321;

    for (int i = l; i < r; i++) //��� ���ҿ� ���ؼ� �ּҰ� ��� 
    {
        int tmp = bulb[l] != bulb[i + 1]? 1: 0; //ù ��° �׷�� �ι�° �׷��� ���� ���� ���� ���������� 1, �ƴϸ� 0 
        cache[l][r] = min(cache[l][r], getcnt(l, i) + getcnt(i + 1, r) + tmp);        
    }
    return cache[l][r];
}

int main(void)
{	
	int tmp;
	int index = 0;

	memset(cache,-1,sizeof(cache));

	cin >> N >> K;
	for(int i=0;i<N;i++)
	{
		cin >> tmp;
		bulb.push_back(tmp);
	}
	ans = getcnt(0,N-1);

	cout << ans << endl;
	
	return 0;
}
