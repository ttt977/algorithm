#include <iostream>
#include <cstdlib>
#include <memory.h>

using namespace std;

#define INF 987654321
#define MIN(A,B) ((A<B)?(A):(B))

int N;
char map[110][110];
int pmap[110][110];
int cache[110][110];
int visited[110][110];


void Input_Data(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> map[i];
		for(int j=0;j<N;j++)
		{
			pmap[i][j] = map[i][j] - '0';
		//	cout << pmap[i][j] << " ";
		}
		//cout << endl;
	}	
}

int solve(int i, int j, int d)
{
  printf("solve %d %d %d \n",i,j,d);
  int L=0,T=0,R=0,D=0,min=0;
  
  if(i < 0 || i > N-1 || j < 0 || j > N-1)
   return INF;
  
  if(cache[i][j] != -1)
    return cache[i][j];	
      
  if(i == 0 && j == 0)
   return cache[i][j] = 0;
   
  if(i == 0 && j == 1)
   return cache[i][j] = pmap[i][j];
   
  if(i == 1 && j == 0)
   return cache[i][j] = pmap[i][j];
   
   if(i==N-1 && j==N-1)
   {
     return MIN(solve(i,j-1,3),solve(i-1,j,4)) + pmap[i][j];
   }
   
   if(d == 1)
   {
     L = INF;
	 T = solve(i-1,j,4);
	 R = solve(i,j+1,1);
	 D = solve(i+1,j,2);
   }
   else if(d == 2)
   {
	L = solve(i,j-1,3);
    T = INF;
    R = solve(i,j+1,1);
    D = solve(i+1,j,2);
   }
   else if(d == 3)
   {
	L = solve(i,j-1,3);
    T = solve(i-1,j,4);
    R = INF;
    D = solve(i+1,j,2);
   }
   else if(d == 4)
   {
    L = solve(i,j-1,3);
    T = solve(i-1,j,4);
    R = solve(i,j+1,1);
    D = INF;
   }
      
   printf("i=%d j=%d L=%d T=%d R=%d D=%d \n",i,j,L,T,R,D);
   return cache[i][j] = MIN(MIN(L,T),MIN(R,D)) + pmap[i][j];  
}

int main(){
	int ans = -1;
	Input_Data();
	memset(cache,-1,sizeof(cache));
	memset(visited,0,sizeof(visited));	
	cout << solve(N-1,N-1,0) << endl;
	return 0;
}

