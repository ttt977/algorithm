#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;

int N;
int x,id;
int k = 1; //id count
int ans = 987654321;
vector<pii> items; //x, id

int ids[50010][2];

bool compid(pii a, pii b)
{
	return a.second < b.second;	
}

bool compx(pii a, pii b)
{
	return a.first < b.first;	
}

void initidtable()
{
	for(int i=0;i<k;i++)
	 ids[i][1] = 0;
}

bool isallchecked()
{
	for(int i=0;i<k;i++)
	{
	 if(ids[i][1] == 0)
	  return false;
	}
	return true;
}
void idcheck(int id)
{
	for(int i=0;i<k;i++)
	{
	 if(ids[i][0] == id)
	 {
	   ids[i][1] = 1;
	   break;
	 }
	}
}

int main(void)
{
	cin >> N;
	int prevalue = 0;

	for(int i=0;i<N;i++)
	{
	 cin >> x >> id;
	 items.push_back(make_pair(x,id));	
	}

	//To get id list
	sort(items.begin(),items.end(),compid);	
	ids[0][0] = items[0].second;
	for(int i=1;i<N;i++)
	{
		if(items[i-1].second != items[i].second )
		 ids[k++][0] = items[i].second;
	}

	//sort by x
	sort(items.begin(),items.end(),compx);	

	int tmp_size=0;
	int start_x = 0;

	for(int i=0;i<N-k;i++)
	{
		tmp_size = 0;
		start_x = items[i].first;
		initidtable();
		idcheck(items[i].second);
#if 0
		if(i > 0)
		{
		 if(items[i].second == items[i-1].second)
		  {
			tmp_size = prevalue - (items[i].first - items[i-1].first);
			if(tmp_size < ans)
			 ans = tmp_size;
			prevalue = tmp_size;
			continue;
		  }
		}
#endif
		for(int j=i+1;j<N;j++)
		{
		  idcheck(items[j].second);
		  if(isallchecked())
		  {
			tmp_size = items[j].first - start_x;
			prevalue = tmp_size;
			if(tmp_size < ans)
			 ans = tmp_size;		
		    break;
		  }		  
		}		
	}

#if 0
	cout <<"\n";	
	for(int i=0;i<N;i++)
	{
	  cout << items[i].first << ' ' << items[i].second << "\n";
	} 

	for(int i=0;i<k;i++)
	{
		cout << ids[i][0] << "\n";
	}
	cout <<"\n";	
#endif	
	
	cout << ans << endl;

	return 0;
}
