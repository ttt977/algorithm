//이진검색트리 전위순회한 결과가 주어졌을 때 후위순회한 결과 출력하기
//굳이 트리를 다시 만들필요는 없다. 순회 순서만 고민해서 풀면됨. 

#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int v[10010]; //vector로 풀면 제한 메모리 초과됨 

//start ~ end 까지 전위를 후위로 변경하는 함수 
void pretopost(int start, int end)
{
	int lend = INF;
#if 0 //base case를 아래와 같이 하지 않아도 됨..단순 크기 비교만 해도 정답. 
	if(start == end)
	{
		printf("%d ",v[start]);
		return;
	}
	else if(end -start == 1)
	{
		printf("%d %d ",v[end],v[start]);
		return;
	}
#else
	if(start > end)
	 return;
#endif

	//전위순회의 첫번째 원소는 root node다.(root 노드 / 왼쪽서브트리 / 오른쪽서브트리)
 	//왼쪽서브트리 마지막까지 찾기. 
	for(int i=start+1;i<=end;i++)
	{
		if(v[start] < v[i])
		{
			lend = i-1;
			break;
		}
	}
	if(lend == INF)
	 //root보다 큰 노드가 없을 경우 오른쪽서브트리는 구할필요 없음. 
	 pretopost(start+1,end);
	else
	{
	 pretopost(start+1,lend); //왼쪽서브트리를 전위->후위변경 
	 pretopost(lend+1,end); //오른쪽 서브트리를 전위->후위변경 
	}
	printf("%d ",v[start]); //root 노드 출력 

}


int main(void)
{
	int x,i=0;
	while(cin >> x)
	{
		v[i++] = x;
	}	
	pretopost(0,i-1);
	return 0;
}
