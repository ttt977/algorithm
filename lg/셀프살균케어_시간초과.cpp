#include <iostream>
#include <algorithm>

using namespace std;

int y[110];		//	살균대상의 y 좌표 배열
int x[110];		//	살균대상의 x 좌표 배열
int N;				//	필터 한 변의 크기
int L;				//	LED의 범위(길이) 
int M;				//	살균대상의 개수
int sol;			//	정답
int mi = 10000;
int mj = 10000;
int ni = 0;
int nj = 0;

void Input(void){	
	cin >> N >> L >> M;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d",y+i,x+i);
		
		if(y[i] < mi)
		 mi = y[i];
		if(x[i]<mj)
		 mj = x[i];		

		if(y[i] > ni)
		 ni = y[i];
		if(x[i] > nj)
		 nj = x[i];
	}
}

void getcnt(int starti, int startj, int h, int w) //starti/startj 위치에서 세로h / 가로w 크기의 필터가 검출할 수 있는 살균대상의 수 반환 
{
	int cnt = 0;
	int toi = min(starti+h,ni);
	int toj = min(startj+w,nj);
	
	for(int i=0;i<M;i++)
	{
		if( (y[i] >= starti && y[i] <=toi) && (x[i] >= startj && x[i] <= toj) )
		cnt++;
	}
	if(cnt > sol)
	 sol = cnt;
}
 
int main(void){
	
	Input();
	int h=0,w=0;


	for(h=1;h<=L/2-1;h++)
	{
	  if(sol == M) break;
	  w=L/2-h;
	  for(int i=mi;i<=ni;i++)
	  {
		if(sol == M) break;
	    for(int j=mj;j<=nj;j++)
		{
	    if(sol == M) break;
		#if 0
		 getcnt(i,j,h,w);			
		#else
		//int toi = min(i+h,ni);
		//int toj = min(j+w,nj);
		int toi = i+h;
		int toj = j+w;
		int cnt = 0;
		for(int v=0;v<M;v++)
		{
		if( (y[v] >= i && y[v] <=toi) && (x[v] >= j && x[v] <= toj) )
		 cnt++;
		}
		if(cnt > sol)
	 	 sol = cnt;
		#endif
		}
 	  }		
	}
	printf("%d", sol);

	return 0;
}
