#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;
int     N;
int		cnt;

vector<pii> pjt; //pjt 시작일/종료일 저장하는 벡터 

void Data_Input(void) {
	cin >> N;
	int a=0,b=0;
	for (int i = 0; i<N; i++) {
		cin >> a >> b;
		pjt.push_back(make_pair(a,b));
	}
}

bool comp(pii a, pii b) //종료일 기준으로 정렬. 종료일이 같으면 시작일이 먼저인 순서로 정렬 
{
	if(a.second == b.second)
	 return a.first < b.first;
	else return a.second < b.second;
}

void solve()
{
	int pivot = pjt[0].second; //첫 프로젝트가 끝나는 날을 기준. 
	cnt = 1;
	for(int i=1;i<N;i++)
	{
		if(pivot < pjt[i].first) //다음 프로젝트 시작일이 이전 프로젝트 끝나는 일 다음이냐? 
		{
			cnt++; //프로젝트 수 + 1 
			pivot = pjt[i].second; //기준 변경 
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
