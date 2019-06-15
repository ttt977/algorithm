#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
double avg=0;

int moreavg(double po)
{
	if(po > avg)
	 return 1;
	else
	 return 0;
}

int main(void)
{
	int tc=0,n=0,tmp=0,i=0;
	double sum=0;
	
	vector<int> vn;
	vector<int>::iterator itr = vn.begin();
	
	cin >> tc;
	while(tc-- > 0)
	{
		cin >> n;
		sum=0;
		avg=0;
		for(i=0;i<n;i++)
		{
			cin >> tmp;
			vn.push_back(tmp);
		}
		for(itr=vn.begin();itr!=vn.end();++itr)
		{
			sum+=*itr;
		}
		avg = sum/n;
		//cout << "avg : " << avg << endl;
		
		cout << fixed;		
		cout.precision(3);
		cout << (double)count_if(vn.begin(),vn.end(),moreavg)/(double)n*100 << "%" << endl;		
		vn.erase(vn.begin(),vn.begin()+n);
	}
	return 0;
}
