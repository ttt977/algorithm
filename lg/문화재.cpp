#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<pair<int,int> > item;
vector<int> top;

int area;

void inputdata()
{
	int tmp_l=0,tmp_h=0;

	cin >> N;

	for(int i=0;i<N;i++)
	{
	 cin >> tmp_l >> tmp_h;
	 item.push_back(make_pair(tmp_l,tmp_h));	 
	}
}

bool itemsort(pair<int,int> &a, pair<int,int> &b)
{
	return a.first < b.first;	
}

bool checkleast(int n) //true면 n 보다 큰값없음. 
{
	for(int k=n+1;k<item.size();k++)
	{
		if(item[n].second < item[k].second)
		 return false;
	}
	return true;
}

int checkleasemax(int n)
{
	int max=0;
	for(int k=n+1;k<item.size();k++)
	{
		if(max < item[k].second)
		 max = item[k].second;
	}
	return max;	
}

void solve()
{
	int cur_top = 0;

	top.push_back(item[0].second);
//	cout << "top 0" << endl;
	cur_top = item[0].second;

	for(int i=0;i<N-1;i++)
	{
	 for(int j=0;j<item[i+1].first - item[i].first -1;j++)
	 {
	//	cout << "top 1" << endl;
		int max = checkleasemax(i);
		if(cur_top > max )
		{
		 top.push_back(max);
		 cur_top = max;				 
		}
		else
		 top.push_back(cur_top);
	 }
	 
	 if(item[i+1].second >= item[i].second)
 	 {	  
	  if(cur_top < item[i+1].second)
	  {
	   top.push_back(item[i+1].second);
	 //  cout << "top 2" << endl;
	   cur_top = item[i+1].second;	   
	  }
	  else
		{
	//	cout << "top 2-1" << endl;
 		top.push_back(cur_top);
		}
 	 }
	 else if(item[i+1].second < item[i].second)
	 {
		if(checkleast(i+1))
		{
		//	cout << "top 3 " << "cur_top " << cur_top << endl;
			int max = checkleasemax(i);
			if(cur_top > max)
			{
		//	 cout << "top 3-1" << endl;
			 top.push_back(max);
			 cur_top = max;				 
			}
			else
			{
		//	 cout << "top 3-2" << endl;
			 top.push_back(cur_top);
			}
		}
		else
		{
		//	cout << "top 4" << endl;
			int max = checkleasemax(i+1);
			if(cur_top > max )
			{
			 top.push_back(max);
			 cur_top = max;				 
			}
			else
			 top.push_back(cur_top);
		}
	 }
	}
	
//	cout << "===========================" << endl;
	for(int a=0;a<top.size();a++)
	{
	//	cout << "top " << top[a] << endl; 
		area+=top[a];
	}	
}

int main(void)
{
	inputdata();
	sort(item.begin(),item.end(),itemsort);
#if 0
	for(int i=0; i<N;i++)
	 cout << item[i].first << " " << item[i].second << endl;
#endif
	//solve(0);
	solve();

	cout << area << endl;
	return 0;
} 
