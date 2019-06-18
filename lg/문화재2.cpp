#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

vector<pii> items;

int N,L,H;
int ans;

//���� �ε������� ���� ���� ��ȯ 
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
	//x��ġ ���� ���� ���� 
	sort(items.begin(),items.end());

	ans+=items[0].second;

	int cur_h = items[0].second;
	
	for(int i=1;i<N;i++)
	{		
		int next_h = items[i].second;
		if(next_h >= cur_h) // ���� ���̰� ���� ���̺��� ũ��? 
		{
		 ans = ans + (items[i].first - items[i-1].first-1)*cur_h + next_h; //���� ���̿� ���� ���� ���� ���� + ���� ���� 
		 cur_h = next_h; //���� ���̸� ������Ʈ		
		}
		else
		{	
			int lt = leasttop(i);		
			if(lt == next_h) //���� ���̰� �����ִ� �� �� ���� ū ���̳�? 
			{			 
			 ans = ans + (items[i].first - items[i-1].first-1)*next_h+ next_h;			 
			 cur_h = next_h;			
			}
			else if(lt < cur_h)// �����ִ� �� �� ���� ���� ���� ���� ���� ���� ����? 
			{
			 ans = ans + (items[i].first - items[i-1].first-1)*lt + lt;			 		 
			 cur_h = lt;			
			}
			else //�� �� 
			{
			 ans = ans + (items[i].first - items[i-1].first-1)*cur_h + cur_h;			 			
			}
		}		
	}
	cout << ans << "\n";


	return 0;
}
