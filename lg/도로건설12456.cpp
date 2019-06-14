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


void Input_Data(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> map[i];
		for(int j=0;j<N;j++)
		{
			pmap[i][j] = map[i][j] - '0';
		}
	}	
}


int mat(int i, int j){
    if(cache[i][j]!=-1) return cache[i][j];
    if(i==0&&j==0)
        cache[i][j] = pmap[i][j];
    else if(i==0)
        cache[i][j] = mat(i,j-1) + pmap[i][j];
    else if(j==0)
        cache[i][j] = mat(i-1,j) + pmap[i][j];
    else
        cache[i][j] = MIN(mat(i-1,j),mat(i,j-1))+pmap[i][j];                                               
    return cache[i][j];
}



int main(){
	int ans = -1;
	Input_Data();
	memset(cache,-1,sizeof(cache));
	cout << mat(N-1,N-1) << endl;
	return 0;
}

