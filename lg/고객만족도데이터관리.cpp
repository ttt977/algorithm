#include <iostream>
#include <string>
using namespace std;

int M;					// 반복 인정 회수
char S[100000 + 10];	// 조사 문자열

int main(void)
{
	int i;			// 문자열 S의 어떤 문자를 지시
	int len;		// 문자열 S의 길이
	char r_char;	// 반복되는 문자
	int r_cnt;		// 반복 회수

	// 데이터 읽기
	cin >> M;
	cin >> S;

	// 코드 구현 및 결과 출력
	i = 0;
	r_cnt = 1;
	while(S[i] != '\0')
	{
		r_char = S[i];
		if(r_char == S[i+1])
		{
			r_char = S[i];
			r_cnt++;
		}
		else
		{
			if(r_cnt >= M)
			{
				printf("%c(%d)",r_char,r_cnt);
				r_cnt = 1;
			}
			else
			{
				for(int k=0;k<r_cnt;k++)
				printf("%c",r_char);
				r_cnt = 1;
			}
		}
		i++;
	}

	return 0;
}

