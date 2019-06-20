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

void solve(int index) //index 위치부터 장기자랑 시작 
{

	if(man.empty()) //모두 장기자랑을 했을 경우 
	{
		return;
	}
	if(index + M <= man.size()-1) //index가 넘어가지 않을 경우 
	{		
		int tmp = 0;
		tmp = man[index+M-1];
		cout << tmp << " ";
		man.erase(man.begin() + index+M-1);
		solve(index+M-1);
	}
	else if(index + M > man.size()-1) //index가 넘어가면 
	{
		int it = (index+M-1)%(man.size()); //index 위치 재 설정 
		cout << man[it] << " ";
		man.erase(man.begin()+it);
		if(it >= man.size())//삭제 후 가리키고 있는 값이 없을 경우 
		 solve(0); //다시 처음부터 
		else solve(it);
	}
}

int main(){
	InputData();
	solve(S-1);
	cout << "\n";
	return 0;
}
