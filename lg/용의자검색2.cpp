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

	for(int i=0;i<N;i++) //각 용의자 이름 나오는 갯수 확인 
	{
	 cnt=0;
	 a = list.find(names[i]); //list에서 용의자 이름이 처음 나오는 위치 반환 
	 while(a != string::npos) //용의자 이름이 있다면 
	 { 
		a = list.find(names[i],a+1); // 그 다음 위치부터 다시 검색 
		cnt++; //갯수 증가 
	 }
	 if(cnt > max_cnt) //최대 갯수 확인 
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
