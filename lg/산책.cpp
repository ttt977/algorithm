#include <iostream>
#include <vector>
 
using namespace std;

int N;
int T;
int P[100000 + 10];//위치
int S[100000 + 10];//속도
int group = 1;

void InputData(){
	cin >> N >> T;
	for (int i = 0; i < N; i++){
		cin >> P[i] >> S[i];
	}
}

void checkgroup(int a, int b)
{
//	cout << "checkgroup " << a << " " << b << endl;

	int big = 0;

	if (a < 0)
	 return;

	if(S[a] > S[b])
	{
		int s_diff = S[a] - S[b];
		int p_diff = P[b] - P[a];
		int move = s_diff * T;

		if(move / T != s_diff)
		 big = 1;		

		if(big == 1)
		 checkgroup(a-1,b);
		else if(s_diff * T >= p_diff )
		{
			checkgroup(a-1,b);
		}
		else
		{	
			group++;
			checkgroup(a-1,a);
		}
	}
	else
	{
		group++;
		checkgroup(a-1,a);
	}
}

int main(){
	int ans = -1;

	InputData();		

	checkgroup(N-2,N-1);

	ans = group;	
	cout << ans << endl;
	return 0;
}

