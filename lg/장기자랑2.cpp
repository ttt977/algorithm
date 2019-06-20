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

void solve(int index) //index ��ġ���� ����ڶ� ���� 
{

	if(man.empty()) //��� ����ڶ��� ���� ��� 
	{
		return;
	}
	if(index + M <= man.size()-1) //index�� �Ѿ�� ���� ��� 
	{		
		int tmp = 0;
		tmp = man[index+M-1];
		cout << tmp << " ";
		man.erase(man.begin() + index+M-1);
		solve(index+M-1);
	}
	else if(index + M > man.size()-1) //index�� �Ѿ�� 
	{
		int it = (index+M-1)%(man.size()); //index ��ġ �� ���� 
		cout << man[it] << " ";
		man.erase(man.begin()+it);
		if(it >= man.size())//���� �� ����Ű�� �ִ� ���� ���� ��� 
		 solve(0); //�ٽ� ó������ 
		else solve(it);
	}
}

int main(){
	InputData();
	solve(S-1);
	cout << "\n";
	return 0;
}
