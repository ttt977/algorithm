#include <iostream>
using namespace std;

#define MAXTIME 50001

int N,Q;
int T[101];
int engineer[6];
int sol;

	
void Input_Data(void){	
	cin >> N >> Q;
	for(int i=1;i<=Q;i++){
		cin >> T[i];
	}
}

bool checkfinish(int t)
{
	for(int eno=0; eno < N; eno++)
	{
		if(engineer[eno] > t)					
		return false;
	}
	return true;
}

int solve()
{
	int q = 1;
	
	for(int t = 1 ; t< MAXTIME; t++)
	{
		if(q > Q)
		{
		 if(checkfinish(t) == true)
 		  return t;
		 else
		  continue;
		}
		
		for(int eno=0; eno < N; eno++)
		{
			if(t == 1)
			 engineer[eno] += T[q++];
			else if(engineer[eno] < t)
			 engineer[eno] += T[q++];
			//cout << "q " << q << " t " << t << " engineer " << eno << " " << engineer[eno] << endl;			
		}	
	}
}

int main(void){
	Input_Data();
	sol = solve();
	cout << sol << endl;
	return 0;
}
