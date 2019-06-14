#include <iostream>
#include <cstdio>
#include <queue> 
#include <algorithm>
#include <vector>

using namespace std;

#define INF 1000

typedef pair<int,int> pii;

int N, M;//공장 수, 도로 정보 수


vector<int> con[100], conv[100];
long d[100];
vector<int> maxlength;

void InputData(){
	int i;
	int A,B,D;

	cin >> N >> M;
	for (i = 1; i <= M; i++){
		 cin >> A >> B >> D;
		 con[A].push_back(B);
		 con[B].push_back(A);
		 conv[A].push_back(D);
		 conv[B].push_back(D);
	}
}

int dikst(int n)
{
	int max =0;
	int t=0,v=0;

	for(int i=1; i<= N ; i++)
	{
	     d[i]= INF;
	}

	priority_queue <pii> pq;
	d[n] = 0;
	pq.push(make_pair(0,n));
	
	while(!pq.empty())
	{
		int q = pq.top().second, dist = -pq.top().first;
	
		pq.pop();

		if(d[q] != dist) continue;

		for(int i = con[q].size() - 1; i>=0;i--)
		{
			int t = con[q][i], v = conv[q][i];
			if( d[t] > d[q] + v ){
				d[t] = d[q] + v;				
				pq.push(make_pair(-d[t],t));				
			}
		}
	}	
	for(int i=1; i<= N ; i++)
	{
	     if(d[i] > max)
			max = d[i];
	}
	return max;
}

int main(){
	int ans = -1,tmp=0,min=987654321;

	for(int i=1; i <= M ;i++)
	{
		con[i].clear();
		conv[i].clear();
	}

	InputData();
	for(int i=1;i<=N;i++)
	{
		tmp = dikst(i);
		if(tmp < min)
			min = tmp;
	}

	ans = min;		
	cout << ans << endl;
	return 0;
}
