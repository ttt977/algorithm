#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
 
using namespace std;

#define MAX 1000000001

int N;
vector<pair<int,int> > v;
int id_hslim[50010];
int id[50010];
int a = -1; // id count

bool isexistid(int x)
{
	for(int i=0;i<=a;i++)
	{
		if(id_hslim[i] == x)
			return true;
	}
	return false;
}


void InputData(){	
	cin >> N;
	int tmp1=0,tmp2=0;

	for (int i = 0; i < N; i++){
		cin >> tmp1 >> tmp2;
		v.push_back(pair<int,int>(tmp1,tmp2));
		if( false == isexistid(tmp2))
			{
				a++;
	 			id_hslim[a] = tmp2;
			}
	}
}

void idinit(void)
{
	for(int i=0;i<=a;i++)
	{
	 id[i] = id_hslim[i];
	 //cout << "id["<<i<<"] = "<< id[i] << endl;
	}
}

bool is_id_done(void)
{
	for(int i=0;i<=a;i++)
	{
		if(id[i] != 0)
		{
		// cout << "this id is not zero : " << id[i] << endl;
		 return false;
		}
	}
//	cout << "is_id_done : true "<< endl;
	return true;
}

void id_mark(int mark_id)
{
	//cout << "id_mark: " << mark_id << endl;

	for(int i=0;i<=a;i++)
	{
		if(id[i] == mark_id)
		{
		 //cout << "id_mark: " << id[i] << " to zero" << endl;		 
		 id[i] = 0;
		}
	}
}

int calrangefrom(int n)
{
 idinit();

 for (int i = n; i <=  N; i++)
 {
 	 if(false == is_id_done())
	 {
		id_mark(v[i].second);		
	 }
	 else
	 {
		return (v[i-1].first - v[n].first);		
	 }	 
 } 
 return MAX;
}

int calrangefromr(int n)
{
 idinit();

 for (int i = n; i > a; i--)
 {
 	 if(false == is_id_done())
	 {
		id_mark(v[i].second);		
	 }
	 else
	 {
		return (v[n].first - v[i+1].first);		
	 }	 
 } 
 return MAX;
}

int main(){
	int ans = 1000000001;
	int tmp=0;

	for(int j=0;j<50000;j++)
	{
 	 id_hslim[j] = -1;
	 id[j] = -1;
	}

	InputData();

#if 0
	cout << endl;
	for(int k=0;k<=a;k++)
	{
		cout << "id: " << id_hslim[k] << endl;
	}
	cout << endl;
#endif
 
	sort(v.begin(),v.end());

#if 0
	for (int i = 0; i < N; i++){
	//	cout << v[i].first << " " << v[i].second << " ";
	}
	cout << endl;
	cout << "a : " << a << endl;
#endif

#if 0
	for (int i = 0; i < N; i++){
		tmp = calrangefrom(i);
		//cout << "tmp = " << tmp << endl;
		if(tmp < ans)
		 ans = tmp;
	}
#endif

	for (int i = N-1; i > 0; i--){
		tmp = calrangefromr(i);
		//cout << "tmp = " << tmp << endl;
		if(tmp < ans)
		 ans = tmp;
	}

	cout << ans << endl;
	return 0;
}

