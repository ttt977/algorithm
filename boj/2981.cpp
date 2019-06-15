#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getgcd(int a, int b)
{
	int gcd = 0;
	
	if(a%b == 0)
	 gcd = b;
	else 
	 gcd = getgcd(b,a%b);
	 
//	 cout << "gcd = " << gcd << endl;
	 return gcd;
}

int main(void)
{
	int n=0,i=0,tmp=0,min=0;
	vector<int> nv,diff,gcd;
	vector<int>::iterator itr;	
	cin >> n;
	for(i=0;i<n;i++)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
	{
		cin >> tmp;
		nv.push_back(tmp);
	}
	sort(nv.begin(),nv.end());
	for(i=0;i<n-1;i++)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
	{
		diff.push_back(nv[i+1]-nv[i]);
		//cout << "diff = " << diff[i] << endl;
	}
	//cout << "diff size = " << diff.size() << endl;
	
	if(diff.size() == 1 )
		 gcd.push_back(diff[0]);
		 
	for(i=0;i<diff.size()-1;i++)
	{		
		if(diff[i] > diff[i+1])
		 gcd.push_back(getgcd(diff[i],diff[i+1]));
	 	else
	 	 gcd.push_back(getgcd(diff[i+1],diff[i]));
	}
	
	itr = min_element(gcd.begin(),gcd.end());
	min = *itr;
	
	for(i=2;i<=min/2;i++)
	{
		if(min%i == 0)
		 cout << i <<" ";
	}	
	cout << min << endl;
	
	return 0;
}
