#include <iostream>

using namespace std;

int N;

// 온도값 범위 변수
int min_temp;
int max_temp;

// 습도값 범위 변수
int min_humidity;
int max_humidity;

// 온/습도 변화량
int Temperature_diff[101];
int Humidity_diff[101];

// 온/습도 범위 초과 flag
int flag_control_temp;
int flag_control_humidity;

// 온/습도 초기 값
#define INIT_TEMPERATURE (20)
#define INIT_HUMIDITY (50)

int cur_temp = INIT_TEMPERATURE;	// 현재 온도 값
int cur_humidity = INIT_HUMIDITY;	// 현재 습도 값


int Check_Temp_and_Control(int diff)
{
	cur_temp += diff;

	if (cur_temp > max_temp || cur_temp < min_temp)
	{
		flag_control_temp = 1;
		return 1;
	}
	else return 0;
}

int Check_Humidity_and_Control(int diff)
{
	cur_humidity += diff;
	if (cur_humidity > max_humidity || cur_humidity < min_humidity)
	{		
		flag_control_humidity = 1;
		return 1;
	}
	else return 0;
}

void Reset_Flag(void)
{
	//  flag 초기화
	flag_control_humidity = 0;
	flag_control_temp = 0;
}

void Reset_value(int a)
{
	if(a == 1)
	 cur_temp = INIT_TEMPERATURE;
	else if(a == 2)
	 cur_humidity = INIT_HUMIDITY;
	else if(a == 3)
    {
	 cur_humidity = INIT_HUMIDITY;
	 cur_temp = INIT_TEMPERATURE;
	}
}

void Control_Temp_and_Humidity(void)
{
	int i;
	for (i = 1; i <= N; i++)
	{
		Reset_Flag();
		Check_Temp_and_Control(Temperature_diff[i]);
		Check_Humidity_and_Control(Humidity_diff[i]);
		// 온습도 범위 체크 및 제어
		
			if (flag_control_temp && flag_control_humidity) 
			{
			 Reset_value(3);
			 cout << 3 << endl;
			}
			else if (flag_control_temp)
			{
			 Reset_value(1);
			 cout << 1 << endl;
			}
			else if (flag_control_humidity)
			{
			 Reset_value(2);
			 cout << 2 << endl;
			}
			else cout << 0 << endl;
	}
}

void Input_Data(void)
{
	int i;
	
	// 전체 동작시간 , 온도/ 습도 범위값 입력
	cin >> N;
	cin >> min_temp >> max_temp;
	cin >> min_humidity >> max_humidity;

	// 온도 변화량 입력
	for (i = 1; i <= N; i++)
	{
		cin >> Temperature_diff[i];
	}
	
	// 습도 변화량 입력
	for (i = 1; i <= N; i++)
	{
		cin >> Humidity_diff[i];
	}
}

int main(void)
{
	Input_Data(); // 입력 data

	Control_Temp_and_Humidity(); // 온습도 제어 처리 함수

	return 0;
}
