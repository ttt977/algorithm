#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int,int> pii;

int tc,N,M;
vector<pii> pv;

int main(void)
{
 cin >> tc;
 for(int i=0;i<tc;i++)
 {
	cin >> N >> M;

	//queue<pii> q;
	//priority_queue<pii> pq;
	pv.clear();

	for(int k=0;k<N;k++)
	{
		int prior;
		cin >> prior;
		//q.push(make_pair(prior,k));
		pv.push_back(make_pair(k,prior));
		//pq.push(make_pair(prior,k));
	}

	int index = 0;

	while(!pv.empty())
	{
	 //int qv = q.front().second;
	 //int pqv = pq.top().second;
	 int okpop = 1;
	 for(int a=1;a<pv.size();a++)
	 {
		//printf("compare %d < %d\n",pv[0].second,pv[a].second);
		if(pv[0].second < pv[a].second)
		{
		 okpop = 0;
		 break;
		}
	 }
	 if(okpop)
	 {
	  //printf("okpop 1\n");
	  index++;
	  if(pv[0].first == M)
 		break;
	  pv.erase(pv.begin() + 0);
	 }
	 else
	 {		
		int curr1 = pv[0].first;
		int curr2 = pv[0].second;
		//printf("okpop 0 curr1 : %d, curr2 : %d\n",curr1,curr2);
		pv.erase(pv.begin() + 0);
		pv.push_back(make_pair(curr1,curr2));		
	 } 	 
	}
	cout << index << endl;	
 }
 return 0;	
}
