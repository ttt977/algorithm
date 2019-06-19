#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int N,Q,T;
int eng[5]; //자기 일이 끝나는 시간을 가지고 있음 
int ans;

vector<int> cust;

int main(void)
{
	cin >> N >> Q;
	memset(eng,-1,sizeof(eng));
	int cust_no = 0;

	for(int i=0;i<N;i++) //존재하는 엔지니어표시 
	 eng[i] = 0;

	for(int i=0;i<Q;i++)
	{
	 cin >> T;
	 cust.push_back(T);
	}

	//매 시간별로 모든 고객의 일이 끝날때까지 일을 할당 
	for(ans=0;;ans++)
	{
		//모든 고객이 할당되었을 때 모든 엔지니어들의 일이 끝나는 시간이 정답 
		if(cust_no == Q)
		{
		 bool fini = true;
		 for(int j=0;j<N;j++)
		 {
		  if(eng[j] > ans && eng[j]!=0) //엔지니어 일이 끝났냐 && 놀고있는엔지니어가 아니냐 
			fini = false;
		 }
		 if(fini)
		  break;//모든 엔지니어의 일이 끝났다 
		 else
		  continue; //모든 엔지니어 일이 끝날 때까지 ans(시간) 더해주기 위해서 
		}	
	
		for(int k=0;k<N;k++)
		{
			if(eng[k] <= ans && eng[k] != -1 && cust_no != Q) // 엔지니어 현재 하는일이 없냐 && 존재하는엔지니어냐 && 남은고객이없냐 
			 eng[k]=cust[cust_no++] + ans; //일을할당. (일이 끝나는 시간을 저장) 
			else
			 continue;//다음 엔지니어 
		}		
	}
	cout << ans << endl; 
	return 0;
}
