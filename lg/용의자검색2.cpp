#include <iostream>
#include <string>
#include <vector>

using namespace std;
string list;
vector<string> names;

int N;

int main(void)
{
	string t_str;
	string::size_type a;
	int max_cnt = 0;

	cin >> list;
	cin >> N;
	for(int i=0;i<N;i++)
	{
	 cin >> t_str;
	 names.push_back(t_str);
	}

	int cnt=0;

	for(int i=0;i<N;i++) //�� ������ �̸� ������ ���� Ȯ�� 
	{
	 cnt=0;
	 a = list.find(names[i]); //list���� ������ �̸��� ó�� ������ ��ġ ��ȯ 
	 while(a != string::npos) //������ �̸��� �ִٸ� 
	 { 
		a = list.find(names[i],a+1); // �� ���� ��ġ���� �ٽ� �˻� 
		cnt++; //���� ���� 
	 }
	 if(cnt > max_cnt) //�ִ� ���� Ȯ�� 
	 {
	   max_cnt = cnt;
	   t_str = names[i];
	 }
	}
	if(max_cnt == 0)
	 cout << "null" << endl;
	else
 	 cout << t_str << endl;
	return 0;
}
