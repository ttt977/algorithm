//�����˻�Ʈ�� ������ȸ�� ����� �־����� �� ������ȸ�� ��� ����ϱ�
//���� Ʈ���� �ٽ� �����ʿ�� ����. ��ȸ ������ ����ؼ� Ǯ���. 

#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int v[10010]; //vector�� Ǯ�� ���� �޸� �ʰ��� 

//start ~ end ���� ������ ������ �����ϴ� �Լ� 
void pretopost(int start, int end)
{
	int lend = INF;
#if 0 //base case�� �Ʒ��� ���� ���� �ʾƵ� ��..�ܼ� ũ�� �񱳸� �ص� ����. 
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

	//������ȸ�� ù��° ���Ҵ� root node��.(root ��� / ���ʼ���Ʈ�� / �����ʼ���Ʈ��)
 	//���ʼ���Ʈ�� ���������� ã��. 
	for(int i=start+1;i<=end;i++)
	{
		if(v[start] < v[i])
		{
			lend = i-1;
			break;
		}
	}
	if(lend == INF)
	 //root���� ū ��尡 ���� ��� �����ʼ���Ʈ���� �����ʿ� ����. 
	 pretopost(start+1,end);
	else
	{
	 pretopost(start+1,lend); //���ʼ���Ʈ���� ����->�������� 
	 pretopost(lend+1,end); //������ ����Ʈ���� ����->�������� 
	}
	printf("%d ",v[start]); //root ��� ��� 

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
