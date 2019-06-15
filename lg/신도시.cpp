#include <iostream>
#include <memory.h>
using namespace std;

int N;//���簢�� ���� ũ��
int X, Y;//������ ���޵Ǵ� ���� ��ǥ, ����, ����
int map[20][20];//���� ����
int dmap[20][20];
//water = 100
//no pipe = 200

#define L 4
#define R 2
#define T 1
#define D 3

void Input_Data(void){
	char str[20];
	cin >> N;
	cin >> X >> Y;
	for (int i = 0; i < N; i++){
		cin >> str;
		for(int j = 0; j < N; j++){
			if(str[j] < 'A') map[i][j] = str[j] - '0';
			else map[i][j] = str[j] - 'A' + 10;
		}
	}
}

/*
 1
2 4
 3
*/
bool flowchecker(int x, int y, int from)
{
	int pn = 0;
	
	pn = map[y][x];
		
	switch(pn)
	{
		case 1:
		if(from == 2 || from == 4)
		return true;
		break;	
		
		case 2:	
		if(from == 1 || from == 3)
		return true;	
		break;
		
		case 3:
		if(from == 4 || from == 3)
		return true;
		break;
		
		case 4:
		if(from == 2 || from == 3)
		return true;
		break;
		
		case 5:
		if(from == 1 || from == 2)
		return true;
		break;
		
		case 6:
		if(from == 1 || from == 4)
		return true;
		break;
		
		case 7:
		if(from != 2)
		return true;
		break;
		
		case 8:
		if(from != 1)
		return true;
		break;
		
		case 9:
		if(from != 4)
		return true;
		break;
		
		case 10:
		if(from != 3)
		return true;
		break;
		
		case 11:
		return true;
		break;
	}
//	printf("flowcheck fail x: %d y: %d from: %d pn: %d\n",x,y,from,pn);
	return false;
}

int solve(int x, int y)
{
	int pn = 0;
//	printf("solve x = %d, y = %d\n",x,y);
	
	if(dmap[y][x] != -1)
	 return 0;
	
	if(x >= N || x < 0 || y >= N || y < 0)
	{
		return 0;
	}
	pn = map[y][x];
//	printf("solve x = %d, y = %d pn = %d\n",x,y,pn);
	
	if(0 == pn)	
	 return dmap[y][x] = 200;
	else
	{
	 dmap[y][x] = 100;
	// printf("water x: %d, y: %d\n",x,y);
	}
/*
 1
2 4
 3
*/
	switch(pn)
	{
		case 1:
		if(flowchecker(x-1,y,L))
		solve(x-1,y);
		if(flowchecker(x+1,y,R))
		solve(x+1,y);
		break;	
		case 2:
		if(flowchecker(x,y-1,D))
		solve(x,y-1);
		if(flowchecker(x,y+1,T))
		solve(x,y+1);
		break;
		case 3:
		if(flowchecker(x+1,y,R))
		solve(x+1,y);
		if(flowchecker(x,y+1,T))
		solve(x,y+1);
		break;
		case 4:
		if(flowchecker(x-1,y,L))
		solve(x-1,y);
		if(flowchecker(x,y+1,T))
		solve(x,y+1);
		break;
		case 5:
		if(flowchecker(x,y-1,D))
		solve(x,y-1);
		if(flowchecker(x-1,y,L))
		solve(x-1,y);
		break;
		case 6:
		if(flowchecker(x,y-1,D))
		solve(x,y-1);
		if(flowchecker(x+1,y,R))
		solve(x+1,y);
		break;
		case 7:
		if(flowchecker(x,y-1,D))
		solve(x,y-1);
		if(flowchecker(x+1,y,T))
		solve(x,y+1);
		if(flowchecker(x+1,y,R))
		solve(x+1,y);
		break;
		case 8:
		if(flowchecker(x-1,y,L))
		solve(x-1,y);
		if(flowchecker(x+1,y,R))
		solve(x+1,y);
		if(flowchecker(x+1,y,T))
		solve(x,y+1);
		break;
		case 9:
		if(flowchecker(x,y-1,D))
		solve(x,y-1);
		if(flowchecker(x,y+1,T))
		solve(x,y+1);
		if(flowchecker(x-1,y,L))
		solve(x-1,y);
		break;
		case 10:
		if(flowchecker(x,y-1,D))
		solve(x,y-1);
		if(flowchecker(x-1,y,L))
		solve(x-1,y);
		if(flowchecker(x+1,y,R))
		solve(x+1,y);
		break;
		case 11:
		if(flowchecker(x,y-1,D))
		solve(x,y-1);
		if(flowchecker(x,y+1,T))
		solve(x,y+1);
		if(flowchecker(x-1,y,L))
		solve(x-1,y);
		if(flowchecker(x+1,y,R))
		solve(x+1,y);
		break;
	}
	return 0;
}

int main(){
	int ans = 0;
	Input_Data();		//	�Է� �Լ�
	
	memset(dmap,-1,sizeof(dmap));
	
	//	�ڵ带 �ۼ��ϼ���
#if 1
	solve(X,Y);
	
	for (int i = 0; i < N; i++){
		for(int j=0;j<N;j++)
		{
			if(map[i][j] == 0)
			{
				dmap[i][j] = 200;
			}
			if(dmap[i][j]==-1)
			{
		    //printf("no water : %d %d\n",j,i);
			ans++;
			}
		}
	}	
#endif
	cout << ans << endl;	//	���� ���
	return 0;
}

