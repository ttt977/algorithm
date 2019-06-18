#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

vector<pii> items;

int N,L,H;
int ans;

//현재 인덱스부터 가장 높이 반환 
int leasttop(int index)
{
	int top=0;
	for(int i=index; i< N ;i++)
	{
		int now_h = items[i].second;
		if(now_h > top)
		 top = now_h;
	}
	return top;
}

int main(void)
{
	cin >> N;
	
	for(int i=0;i<N;i++)
	{
		cin >> L >> H;
		items.push_back(make_pair(L,H));
	}
	//x위치 오름 차순 정렬 
	sort(items.begin(),items.end());

	ans+=items[0].second;

	int cur_h = items[0].second;
	
	for(int i=1;i<N;i++)
	{		
		int next_h = items[i].second;
		if(next_h >= cur_h) // 다음 높이가 현재 높이보다 크냐? 
		{
		 ans = ans + (items[i].first - items[i-1].first-1)*cur_h + next_h; //기존 높이와 현재 높이 사이 넓이 + 다음 높이 
		 cur_h = next_h; //현재 높이를 업데이트		
		}
		else
		{	
			int lt = leasttop(i);		
			if(lt == next_h) //다음 높이가 남아있는 것 중 가장 큰 값이냐? 
			{			 
			 ans = ans + (items[i].first - items[i-1].first-1)*next_h+ next_h;			 
			 cur_h = next_h;			
			}
			else if(lt < cur_h)// 남아있는 것 중 가장 높은 것이 현재 높이 보다 낮냐? 
			{
			 ans = ans + (items[i].first - items[i-1].first-1)*lt + lt;			 		 
			 cur_h = lt;			
			}
			else //그 외 
			{
			 ans = ans + (items[i].first - items[i-1].first-1)*cur_h + cur_h;			 			
			}
		}		
	}
	cout << ans << "\n";


	return 0;
}
