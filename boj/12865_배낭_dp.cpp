#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef pair<int,int> pii;

int N,K;
vector<pii> pv;
int cache[100010][101];//���� �뷮/ �����ۺ� �ִ� ��ġ�� ���� 

//���� ���� �뷮�� ������ �������� �־����� �� �ִ� ��ġ�� ��ȯ 
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

	tmp = backpack(remain,index+1); //������ ���� ���� ���

	if(remain >= pv[index].first ) //���� ������ ����ϸ� 
	 tmp1 = backpack(remain-pv[index].first,index+1)+pv[index].second; //������ ����� ����� �ִ� ��ġ�� ��ȯ 

	return cache[remain][index] = max(tmp,tmp1); //����� ���� ���� �ʾ��� ��� �� ū ���� ��ȯ 
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
