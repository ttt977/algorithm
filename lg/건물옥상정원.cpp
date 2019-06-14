#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int H[80010];

void Input_Data(void){
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++){
		scanf("%d",H+i);
	}
}

long long solve(){	
   long long cnt=0;
   
   for(int i=0;i<N;i++)
   {
	for(int j=i+1;j<N;j++)
	{
	  if(H[j] >= H[i])
	   break;
	  else
	   cnt++;
	}
   }
	
}

int main(){	
	Input_Data();	
	cout << solve() << endl;
	return 0;
}
