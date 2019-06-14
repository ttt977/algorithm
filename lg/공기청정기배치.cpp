#include <iostream>
#include <memory.h>
using namespace std;

#define LEFT 1001
#define TOP 1002
#define RIGHT 1004
#define DOWN 1008

int H;		// 세로 크기
int W;		// 가로 크기
int map[50][50];	//지도
int room[50][50];
int room_no = 0;

int starti=0,startj=0;

struct ANS{
	int count;	// room 개수
	int area;		// 가장 넓은 room 넓이
};
ANS ans = {0, 0};

void InputData(){
	int i, j;
	cin >> H;
	cin >> W;
	for(i=0 ; i<H ; i++){
		for(j=0 ; j<W ; j++){
			cin >> map[i][j];
		}
	}
}

bool checkok(int i, int j, int d)
{
	switch(d)
	{
		case LEFT:
		if((map[i][j-1] & 0x4) == 0)
		return true;
		break;

		case TOP:
		if((map[i-1][j] & 0x8) == 0)
		return true;
		break;

		case RIGHT:
		if((map[i][j+1] & 0x1) == 0)
		return true;
		break;

		case DOWN:
		if((map[i+1][j] & 0x2) == 0)
		return true;
		break;
	}
	return false;
}

int solve(int i, int j)
{
	
//	cout << "solve " << i << " " << j << endl;

	if(room[i][j] != -1 )
	 return 0;

	if( map[i][j] == 0xF)
	{
		room[i][j] = room_no;
		return 0;
	}

	if((map[i][j] & 0x1) == 0)
	{
		room[i][j] = room_no;
		if(checkok(i,j,LEFT))
 		 solve(i,j-1);
	}

	if((map[i][j] & 0x2) == 0)
	{
		room[i][j] = room_no;
		if(checkok(i,j,TOP))
		 solve(i-1,j);
	}

	if((map[i][j] & 0x4) == 0)
	{
		room[i][j] = room_no;
		if(checkok(i,j,RIGHT))
		 solve(i,j+1);
	}

	if((map[i][j] & 0x8) == 0)
	{
		room[i][j] = room_no;
		if(checkok(i,j,DOWN))
		 solve(i+1,j);
	}
	return 0;
}

bool checkfinish()
{
	for(int a = 0; a<H ; a++)
	{
		for(int b = 0; b<W ; b++)
		{
			if(room[a][b] == -1)
			{
			 starti = a;
			 startj = b;
			 return false;
			}
		}
	}	
	return true;
}

int main(){
	
	int max=0;
	int ro_cnt[3000];
	
	InputData();	

	memset(room,-1,sizeof(room));
	memset(ro_cnt,0,sizeof(ro_cnt));

	while(checkfinish() == false)
	{
		room_no++;
		solve(starti,startj);		
	}

#if 0
	for(int a = 0; a<H ; a++)
	{
		for(int b=0; b<W ; b++)
		{
			cout << room[a][b] << " ";
		}
		cout << endl;
	}	
#endif

	for(int a = 0; a<H ; a++)
	{
		for(int b=0; b<W ; b++)
		{
			ro_cnt[room[a][b]]++;
		}
	}

	for(int k=1;k<=room_no;k++)
	{
		if(ro_cnt[k] > max)
			max = ro_cnt[k];
	}

	ans.count = room_no;
	ans.area = max;

	cout << ans.count << endl;	//	정답 출력
	cout << ans.area << endl;		//	정답 출력
	return 0;
}

