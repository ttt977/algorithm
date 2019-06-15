#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int N;							//	모델명의 개수
//char str[10010][21];	//	모델명 저장
vector<pair<string,int> > v_model;
vector<pair<string,int> > v_sorted;

bool uniquechk(void)
{
	for(int i=0;i<v_sorted.size();i++)
	{
		if(v_sorted[i].second > 1 )
		return false;
	}
	return true;
}

void printrst(string str_p)
{
	cout << str_p << " "; 
	for(int i=0;i<N;i++)
	{
		if(v_model[i].first == str_p)
		 cout << v_model[i].second+1 << " ";
	}
	cout << "\n";
}

int getfirstindex(string str)
{
	for(int i=0;i<v_sorted.size();i++)
	{
		if(v_model[i].first == str)
			return v_model[i].second;
	}	
}

bool comp(pair<string,int> &a, pair<string,int> &b)
{
	int a_first=0;
	int b_first=0;
	
	if(a.second == b.second)
	{
		a_first = getfirstindex(a.first);
		b_first = getfirstindex(b.first);
		return a_first < b_first;		
	}	
	else
	 return a.second > b.second;
}

void resort(void)
{
	#if 0
	cout << "before" << endl;
	for(int i = 0; i< v_sorted.size();i++)
	 cout << v_sorted[i].first << " " << v_sorted[i].second << endl;	
	#endif
	sort(v_sorted.begin(),v_sorted.end(),comp);
	#if 0
	cout << "after" << endl;
	for(int i = 0; i< v_sorted.size();i++)
	 cout << v_sorted[i].first << " " << v_sorted[i].second << endl;
	#endif
}

void Solve(){

	int t_cnt = 1;
	int acc=0;
	
	sort(v_model.begin(),v_model.end());	
	
	for(int i=1;i<N;i++)
	{
		if(v_model[i-1].first == v_model[i].first)
		{
		 t_cnt++;
		 if(i == N-1)
			 v_sorted.push_back(make_pair(v_model[i].first,t_cnt));
		}
		else
		{
			v_sorted.push_back(make_pair(v_model[i-1].first,t_cnt));
			t_cnt = 1;
			if(i == N-1)
			 v_sorted.push_back(make_pair(v_model[i].first,1));
		}		
	}
	
//	resort();
	
	for(int i=0;i<v_sorted.size();i++)
	{
		if(uniquechk())
		{
		 cout << "unique" << "\n";
		 return;
		}
		 
		if(N%2 == 0)
		{
			if(acc >= N/2)
			return;
		}	
		else
		{
			if(acc > N/2)
			return;
		}
		acc += v_sorted[i].second;
		 
		 
		if(v_sorted[i].second > 1)
		 printrst(v_sorted[i].first);
	}
}

void InputData(){
	cin >> N;
	string t_str;
	int t_no;
	
	for(int i=0 ; i<N ; i++){
		cin >> t_str;
		v_model.push_back(make_pair(t_str,i));
	}	
}

int main(){

	InputData();		//	입력 함수

	Solve();				//	문제 풀이

	return 0;
}

