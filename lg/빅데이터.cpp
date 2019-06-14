
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int N;
int s_index;

vector<pair<string,int> > vs,rst,findex;

int firstindex(string str)
{
	for(int i=0;i<findex.size();i++)
	{
		if(findex[i].first == str)
		 return findex[i].second;
	}
}
bool rstcomp(pair<string,int> &a, pair<string,int> &b)
{
	int a_tmp=0,b_tmp=0;
	if(a.second == b.second)
	 {
	  a_tmp = firstindex(a.first);
	  b_tmp = firstindex(b.first);
	  return a_tmp < b_tmp;
	 }
	return a.second > b.second;
}

void printrst(void)
{
	float acc = 0;
	int i = 0;
	
	while(i < rst.size())
	{
		if(acc < (float)N/2)
		{
			if(rst[i].second > 1)
			{
			  acc += (float)rst[i].second;
			  cout << rst[i].first << " ";
			  for(int k=0;k<N;k++)
			   {
				 if(vs[k].first == rst[i].first)
				  cout << vs[k].second+1 << " ";
			   }
			   cout << "\n";
			}
		}
		else
		 break;
		i++;
	}
}

void calcindex()
{
	int i = 0, k = 0;
	while(i < N)
	{
		findex.push_back(make_pair(vs[i].first,vs[i].second));
		i+=rst[k++].second;
	}
}

void Solve(){
	sort(vs.begin(),vs.end());

#if 0
	for(int i=0;i<vs.size();i++)
	 cout << vs[i].first << " " << vs[i].second << endl;	
#endif

	int tmp=1;
	bool unique = true;
	for(int i=1;i<vs.size();i++)
	{
	 if(vs[i].first == vs[i-1].first)
	 {
		unique = false;
		tmp++;
		if(i == vs.size()-1)
		 rst.push_back(make_pair(vs[i].first,tmp));
	 }
	 else
	 {
		if(tmp > 1)
		 rst.push_back(make_pair(vs[i-1].first,tmp));		
		tmp=1;
	 }
	}
	
	if(unique)
	{
	 cout << "unique" << endl;
	 return;
	}
	
	calcindex();
	sort(rst.begin(),rst.end(),rstcomp);

	printrst();
}

void InputData(){
	cin >> N;
	string str;
	for(int i=0 ; i<N ; i++){
		cin >> str;
		vs.push_back(make_pair(str,i));
	}
}

int main(){
	InputData();
	Solve();
	return 0;
}
