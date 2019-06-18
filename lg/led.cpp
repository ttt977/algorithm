#include <iostream>
#include <algorithm>

using namespace std;

int N;
int S[100000 + 10];
int rst[100000 + 10];

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> S[i];
	}
}

int main(){
	int ans = -1;
	int tmp = 0;
	InputData();
	int k=0;

	//초기 패턴의 갯수를 rst 배열에 저장 
	for(int i=0;i<N-1;i++)
	{
		if(S[i] != S[i+1]) tmp++;
		else
		{
		  rst[k++] = tmp +1;
		  tmp = 0;
		}
	}
	rst[k++] = tmp +1;

	if(k == 1)
	 cout << rst[0] << endl;
	else if (k == 2)
	 cout << rst[0] + rst[1] << endl; // 2개 중 하나를 반전시키면 연결되므로.. 
	else if (k == 3)
	 cout << rst[0] + rst[1] + rst[2]<< endl; // 가운데 rst[1]을 반전시키면 rst[0], rst[2]가 연결됨 

	ans = rst[0] + rst[1] + rst[2];

	for(int i=3;i<k;i++)
	{
		ans = max(ans,rst[i-1] + rst[i] + rst[i+1] ); //rst 배열 오른쪽으로 이동하면서 max 값 구하기. 
	}
	 
	cout << ans << endl;
}
