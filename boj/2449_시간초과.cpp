#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int N,K;
vector<int> bulb,tv;
int max_cnt;
int ans=0;

int makeone()
{
	tv.clear();
	tv.push_back(bulb[0]);
	for(int i=1;i<bulb.size();i++)
	{
		if(bulb[i] != bulb[i-1])
		 tv.push_back(bulb[i]);		 
	}
	if(tv.size() != 1)
	{
	 bulb.clear();
	 for(int i=0;i<tv.size();i++)
	  bulb.push_back(tv[i]);
	 return bulb.size();
	}
	return -1;
} 

int findchange()
{
	for(int i=1;i<bulb.size()-1;i++)
	{
		if(bulb[i-1] == bulb[i+1])
		{
		 if(bulb[i] == bulb[i-1])
		 {
			continue;
		 }
		 else
		 {
		  bulb[i] = bulb[i-1];
		  ans++;
		  return i;
		 }
		}
	}		
	return -1;
}

int main(void)
{	
	int tmp;
	int index = 0;

	cin >> N >> K;
	for(int i=0;i<N;i++)
	{
		cin >> tmp;
		bulb.push_back(tmp);
	}

	while(1)
	{
	 index = makeone();
	 if( -1 == index)
	 {
	  break;
	 }
	 findchange();
	}	
	cout << ans << endl;
	
	return 0;
}
