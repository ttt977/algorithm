/*	다음프로그램의 오류를 정정하시오.	*/
#include <iostream>

using namespace std;

int main()
{
	int N=0;
	cin >> N;

	int a[N][N];	// 일별(행) 시간별(열) 미세먼지 변화량을 저장하기 위한 배

	// N일동안 N시간 마다 미세먼지 변화량을 입력 받는 부분
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}

	int max_row = 0;	// 미세먼지 변화량의 합계가 가장 컷던 날(행)을 저장하기 위한 변수
	int min_col = 0;	// 미세먼지 변화량의 합계가 가장 작았던 시간(열)을 저장하기 위한 변수

	long long sum = 0;		// 미세먼지 변화량의 합을 저장하기 위한 변수

	long long min_sum = 9876543210;	// 미세먼지 변화량의 가장 작은 합계를 저장하기 위한 변수

	// 어떤 시간대(열)가 가장 적은 미세먼지 변화량 합을 가지는지 계산하는 부분
	for (int j = 0; j < N; j++) {
	
		sum = 0;

		// j시간대(열)의 N일동안 미세먼지 변화량 합을 구함
		for (int i = 0; i < N; i++) {
			sum += a[i][j];
        }
		// 각 시간대(열)의 미세먼지 변화량 합이 가장 작은 시간(열)을 구하는 부분
		if (sum < min_sum){
			min_sum = sum;
			min_col = j;
		}
	}

	long long max_sum = -9876543210;	// 미세먼지 변화량의 가장 큰 합계를 저장하기 위한 변수

	sum = 0; 

	// 어떤 날(행)이 가장 많은 미세먼지 변화량 합을 가지는지 계산하는 부분
	for (int i = 0; i < N; i++)	{
	
		sum = 0;

		// i일(행)의 N시간 동안 미세먼지 변화량 합을 구함
		for (int j = 0; j < N; j++) {
			sum += a[i][j];
        }
		//cout << "sum " << sum << endl;

		// 각 일(행)의 미세먼지 변화량 합이 가장 큰 날(행)을 구하는 부분
		if (sum > max_sum) {
			max_sum = sum;
			max_row = i;
		}
	}

	cout << (max_row+1) << " " << (min_col+1) << endl;

	return 0;
}

