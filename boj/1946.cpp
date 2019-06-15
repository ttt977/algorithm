#include <iostream>
#include <vector>
#include <algorithm>

//정렬 후 그리디 활용
 
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
	//1차 순위로 정렬 
	sort(pv.begin(),pv.end());

#if 0
	for(int i=0;i<n;i++)
	{
		cout << "sort " << pv[i].first << " " << pv[i].second << endl;
	}
#endif

	pivot = pv[0].second; //pivot에 1차 1등의 2차 점수를 넣음 

	for(int i=1;i<n;i++)
	{
		if(pv[i].second < pivot) //1차는 졌지만 2차를 이겼기 때문에 합격 
		{
			ans++;
			pivot = pv[i].second; //pivot을 2차에서 이긴 넘의 점수로 업데이트. 그래야 for문 한개만 필요.(처음부터 다시 비교할 필요 없음) 
		}
	}		
	cout << ans+1 << "\n";
 } 
 return 0;
}
