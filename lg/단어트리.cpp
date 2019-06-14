#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;


void solve() {
    int count = 0;
    int total_len = 0;
    vector<string> words;
	string tmp;
	string result;
	int length = 0;
	int index = 0;

	int N=0;

	cin >> N;

	for(int i=0;i<N;i++)
    {
		cin >> tmp;
		words.push_back(tmp);
	}	 
    sort (words.begin(), words.end());
	
	result = words[0];

	for(int i=1;i<words.size();i++)
	{
		if(i%2 == 1)
		 result = result + words[i];
		else
		 result = words[i] + result;
	}

	length = result.length();
	index = length/3;

//	cout << result << endl;

	cout << result[index] << endl;

}

int main() {
    solve();
    return 0;
}
