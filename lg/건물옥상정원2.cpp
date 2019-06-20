//문제 정의 변경 
//각 건물 옥상에서 볼 수 있는 정원 수 합계 카운트 -> 각 건물의 정원을 볼 수 있는 건물이 몇 개인지 카운트
//알고리즘 : monotone stack 

#include <iostream>
#include <stack>

using namespace std;

int N;//건물 수
int H[80010];//건물 높이

stack<int> st;
 
void Input_Data(void){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> H[i];
	}
}

long long solve(){
	long long sum = 0;

	st.push(H[0]); //제일 처음 빌딩 높이 스택 초기값으로 삽입 

	for(int i=1;i<N;i++)
	{	
		if(H[i] >= st.top()) //현재 높이가 스택 맨위의 높이와 같거나 더 높을 경우 
		{		 
		 while(H[i] >= st.top()) //현재 높이가 스택 맨위 높이보다 작아질 때까지.
		 {		  
		  st.pop(); //스택에서 계속 꺼낸다. (스택은 항상 순차적 내림차순을 유지해야 하기 때문) 
		  if(st.empty())
		   break;		  
		 }
		 sum+=st.size(); //현재 건물 정원을 볼 수 있는 건물 수 = 스택의 크기(현재 건물보다 높은 건물만 스택에 들어 있으므로) 
		 st.push(H[i]); //제 위치에 넣기 
		}
		else //현재 높이가 스택 맨위의 높이보다 낮을 경우
		{
		 sum+=st.size(); //현재 건물 정원을 볼 수 있는 건물 수 = 스택의 크기(현재 건물보다 높은 건물만 스택에 들어 있으므로)
		 st.push(H[i]);	
		}
	}
	return sum;
}

int main(){
	long long ans = -1;
	Input_Data();
	ans = solve();
	cout << ans << endl;
	return 0;
}
