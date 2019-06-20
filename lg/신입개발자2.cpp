#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;
int     N;
int		cnt;

vector<pii> pjt; //pjt ������/������ �����ϴ� ���� 

void Data_Input(void) {
	cin >> N;
	int a=0,b=0;
	for (int i = 0; i<N; i++) {
		cin >> a >> b;
		pjt.push_back(make_pair(a,b));
	}
}

bool comp(pii a, pii b) //������ �������� ����. �������� ������ �������� ������ ������ ���� 
{
	if(a.second == b.second)
	 return a.first < b.first;
	else return a.second < b.second;
}

void solve()
{
	int pivot = pjt[0].second; //ù ������Ʈ�� ������ ���� ����. 
	cnt = 1;
	for(int i=1;i<N;i++)
	{
		if(pivot < pjt[i].first) //���� ������Ʈ �������� ���� ������Ʈ ������ �� �����̳�? 
		{
			cnt++; //������Ʈ �� + 1 
			pivot = pjt[i].second; //���� ���� 
		}
	}
}

int main(void) {
	Data_Input();
	sort(pjt.begin(),pjt.end(),comp);
	solve();
	cout << cnt << endl;
	return 0;
}
