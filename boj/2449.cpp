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

int getcnt(int l, int r) //l 부터 r 구간의 전구 색을 모두 같게 하는  최소 값을 리턴 
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

    for (int i = l; i < r; i++) //모든 분할에 대해서 최소값 계산 
    {
        int tmp = bulb[l] != bulb[i + 1]? 1: 0; //첫 번째 그룹과 두번째 그룹의 시작 전구 색이 같지않으면 1, 아니면 0 
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
