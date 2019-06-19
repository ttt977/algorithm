#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> v;
int N;

int main(void)
{
	string t_str;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> t_str;
		v.push_back(t_str);
	}
	sort(v.begin(),v.end());

	t_str = v[0];
	for(int i=1;i<N;i++)
	{
		if(i%2==1)
		 t_str = t_str + v[i];
		else
		 t_str = v[i] + t_str;		
	}
	int index = t_str.length()/3;

	cout << t_str[index] << endl;
	//cout << t_str << endl;	
}
