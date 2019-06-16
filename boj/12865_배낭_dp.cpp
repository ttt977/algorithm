#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef pair<int,int> pii;

int N,K;
vector<pii> pv;
int cache[100010][101];//남은 용량/ 아이템별 최대 가치를 저장 

//현재 남은 용량과 선택할 아이템이 주어졌을 때 최대 가치를 반환 
int backpack(int remain, int index)
{
	int tmp=0,tmp1=0;

	if(cache[remain][index] != -1)
	 return cache[remain][index];

	if(index > N-1)
	{
		return cache[remain][index] = 0;
	}	 

	if(remain <= 0)
	 return cache[remain][index] = 0;

	tmp = backpack(remain,index+1); //물건을 담지 않을 경우

	if(remain >= pv[index].first ) //남은 공간이 충분하면 
	 tmp1 = backpack(remain-pv[index].first,index+1)+pv[index].second; //물건을 담았을 경우의 최대 가치를 반환 

	return cache[remain][index] = max(tmp,tmp1); //담았을 경우랑 담지 않았을 경우 중 큰 값을 반환 
}

int main(void)
{
	memset(cache,-1,sizeof(cache));
	cin >> N >> K;
	for(int i=0;i<N;i++)
	{
		int w,v;
		cin >> w >> v;
		pv.push_back(make_pair(w,v));
	}
	cout << backpack(K,0) << endl;
	return 0;
}
