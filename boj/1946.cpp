#include <iostream>
#include <vector>
#include <algorithm>

//���� �� �׸��� Ȱ��
 
using namespace std;
#define INF 987654321

int tc,n,ans;
typedef pair<int,int> pii;

int main(void)
{
 cin >> tc;
 int pivot;
 for(int test=0;test<tc;test++)
 { 
	ans = 0;
	cin >> n;
	vector<pii> pv;
	for(int i=1;i<=n;i++)
	{
		int ta,tb;
		scanf("%d %d",&ta,&tb);
		pv.push_back(make_pair(ta,tb));
	}
	//1�� ������ ���� 
	sort(pv.begin(),pv.end());

#if 0
	for(int i=0;i<n;i++)
	{
		cout << "sort " << pv[i].first << " " << pv[i].second << endl;
	}
#endif

	pivot = pv[0].second; //pivot�� 1�� 1���� 2�� ������ ���� 

	for(int i=1;i<n;i++)
	{
		if(pv[i].second < pivot) //1���� ������ 2���� �̰�� ������ �հ� 
		{
			ans++;
			pivot = pv[i].second; //pivot�� 2������ �̱� ���� ������ ������Ʈ. �׷��� for�� �Ѱ��� �ʿ�.(ó������ �ٽ� ���� �ʿ� ����) 
		}
	}		
	cout << ans+1 << "\n";
 } 
 return 0;
}
