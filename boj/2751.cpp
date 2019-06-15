#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int N=0;
	int tmp=0;
	vector<int> number;
	
	cin >> N;
	
	for(int i=0;i<N;i++)
	{
		cin >> tmp;
		number.push_back(tmp);
	}
		
	sort(number.begin(),number.end());
	
	for(int i = 0;i<N;i++)
	 printf("%d\n",number[i]);
	 
	return 0;
}
