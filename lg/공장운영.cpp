#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int N; //일
int S; //보관비용
int C[50010]; //가격
int Y[50010]; //용량

void Input_Data(void){
	int i;
	cin >> N >> S;
	for (int i = 0; i < N; i++){
		cin >> C[i] >> Y[i];
	}
}

/*
X일 미리 구입 여부 결정
N일/X일 구입 비교 계산
N = C[N];

N 보다 작은 모든 X에 대해서 아래 값 계산하여 가장 작은 값 선택
X = C[X] + (N-X)*S;

위 두 개중 작은 값의 날로 구매.

vector<int> xprice;
*/

int calprice(int day)
{
	int cur_min = 987654321;
	int dayprice = 987654321;
	int tmp = 0;
	
	dayprice = C[day];	
	for(int i=day-1; i>=0 ; i--)
	{
			if((day-i)*S > dayprice) //keypoint 보관 비용이 해당 일차의 비용보다 커질 경우 더이상 계산할 필요 없음. 
				break;
			tmp = C[i] + (day-i)*S;			
			if(dayprice > tmp )
			{
				if(cur_min > tmp)
					cur_min = tmp;
			}		
	}		
	if(cur_min == 987654321)
		return dayprice;
	else
		return cur_min;
}

int main(){
	long long ans = 0;
	Input_Data();		// 입력 함수
	
	ans += C[0] * Y[0];	
	for(int i=1;i<N;i++)
	{
		int tmp = 0;
		tmp = calprice(i);
		//cout << "tmp " << tmp << endl;
		ans += (tmp * Y[i]);
	}
	// TODO : 코드를 작성하세요
	cout << ans << endl;	// 정답 출력
	return 0;
}

