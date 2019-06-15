#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> vn;
	vector<int>::iterator iter=vn.begin();	
	int n=0,i=0,tmp=0;
	long double sum = 0,max = 0;
	
	cin >> n;
	
	for(i=0;i<n;i++)
	{
		cin >> tmp;
		vn.push_back(tmp);
	}
	
	iter = max_element(vn.begin(),vn.end());
	max = *iter;
	
	for(iter=vn.begin();iter!=vn.end();++iter)
	{
		sum+=(*iter/max)*100;
	}
	
	cout.precision(6);
	cout << sum/n << endl;
	
	return 0;
}
