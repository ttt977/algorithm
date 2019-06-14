#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
#define MAX(a,b) ((a>b)?(a):(b))

int V=0,E=0;
vector<int> v[1001];

int getlength(int a)
{
//	cout << "getlength " << a << endl;
	int max = 0,tmp=0;
	
	if(v[a].size() == 0)
	 return 0;
	else if (v[a].size() == 1)
	 {
		if(v[v[a][0]].size() == 0)
		 return 1;
	}

	for(int i=0;i < v[a].size(); i++)
	{
		int child_node = v[a][i];
		tmp = getlength(child_node);
		if(tmp > max)
			max = tmp;						
	}	
	return 1+max;
}

int getshort(int a)
{
	int min = 0,tmp=0;
	
	if(v[a].size() == 0)
	 return 0;
	else if (v[a].size() == 1)
	 {
		if(v[v[a][0]].size() == 0)
		 return 1;
	}

	for(int i=0;i < v[a].size(); i++)
	{
		int child_node = v[a][i];
		tmp = getshort(child_node);
		if(tmp < min)
			min = tmp;						
	}	
	return min+1;	
}

int main() {
	int ans;
	int x=0,y=0;
	
	cin >> V >> E;
	
	int start=0,end=0;
	
	for(int i=0;i<E;i++)
	{
		cin >> start >> end;
		v[start].push_back(end);
	}
	x = getlength(0);
	y = getshort(0);
	
	ans = x-y;
	cout << ans << endl;
  	return 0;
}

