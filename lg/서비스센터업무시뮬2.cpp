#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int N,Q,T;
int eng[5]; //�ڱ� ���� ������ �ð��� ������ ���� 
int ans;

vector<int> cust;

int main(void)
{
	cin >> N >> Q;
	memset(eng,-1,sizeof(eng));
	int cust_no = 0;

	for(int i=0;i<N;i++) //�����ϴ� �����Ͼ�ǥ�� 
	 eng[i] = 0;

	for(int i=0;i<Q;i++)
	{
	 cin >> T;
	 cust.push_back(T);
	}

	//�� �ð����� ��� ���� ���� ���������� ���� �Ҵ� 
	for(ans=0;;ans++)
	{
		//��� ���� �Ҵ�Ǿ��� �� ��� �����Ͼ���� ���� ������ �ð��� ���� 
		if(cust_no == Q)
		{
		 bool fini = true;
		 for(int j=0;j<N;j++)
		 {
		  if(eng[j] > ans && eng[j]!=0) //�����Ͼ� ���� ������ && ����ִ¿����Ͼ �ƴϳ� 
			fini = false;
		 }
		 if(fini)
		  break;//��� �����Ͼ��� ���� ������ 
		 else
		  continue; //��� �����Ͼ� ���� ���� ������ ans(�ð�) �����ֱ� ���ؼ� 
		}	
	
		for(int k=0;k<N;k++)
		{
			if(eng[k] <= ans && eng[k] != -1 && cust_no != Q) // �����Ͼ� ���� �ϴ����� ���� && �����ϴ¿����Ͼ�� && �������̾��� 
			 eng[k]=cust[cust_no++] + ans; //�����Ҵ�. (���� ������ �ð��� ����) 
			else
			 continue;//���� �����Ͼ� 
		}		
	}
	cout << ans << endl; 
	return 0;
}
