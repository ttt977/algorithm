#include <iostream>
#include <vector>

using namespace std;

int N;
int S;
int M; //jump

vector<int> man; 

void InputData(){
	cin >> N >> S >> M;
	for(int i=1;i<=N;i++)
	 man.push_back(i);
}

void solve(int index)
{
//	cout << "solve " << index << endl;

	if(man.empty())
	{
		return;
	}
	if(index + M < man.size()-1)
	{
		cout << man[index+M-1] << " ";
		man.erase(man.begin() + index+M-1);
		solve(index+M-1);
	}
	else if(index + M == man.size()-1)
	{
		int tmp = 0;
		tmp = man[index+M-1];
		cout << tmp << " ";
		man.erase(man.begin() + index+M-1);
		solve(index+M-1);
	}
	else if(index + M > man.size()-1)
	{
		int it = (index+M-1)%(man.size());
		cout << man[it] << " ";
		man.erase(man.begin()+it);
		if(it >= man.size())
		 solve(0);
		else solve(it);
	}
}

int main(){
	InputData();
	solve(S-1);
	cout << "\n";
	return 0;
}
