#include <iostream>

using namespace std;

int N;

// �µ��� ���� ����
int min_temp;
int max_temp;

// ������ ���� ����
int min_humidity;
int max_humidity;

// ��/���� ��ȭ��
int Temperature_diff[101];
int Humidity_diff[101];

// ��/���� ���� �ʰ� flag
int flag_control_temp;
int flag_control_humidity;

// ��/���� �ʱ� ��
#define INIT_TEMPERATURE (20)
#define INIT_HUMIDITY (50)

int cur_temp = INIT_TEMPERATURE;	// ���� �µ� ��
int cur_humidity = INIT_HUMIDITY;	// ���� ���� ��


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
	//  flag �ʱ�ȭ
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
		// �½��� ���� üũ �� ����
		
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
	
	// ��ü ���۽ð� , �µ�/ ���� ������ �Է�
	cin >> N;
	cin >> min_temp >> max_temp;
	cin >> min_humidity >> max_humidity;

	// �µ� ��ȭ�� �Է�
	for (i = 1; i <= N; i++)
	{
		cin >> Temperature_diff[i];
	}
	
	// ���� ��ȭ�� �Է�
	for (i = 1; i <= N; i++)
	{
		cin >> Humidity_diff[i];
	}
}

int main(void)
{
	Input_Data(); // �Է� data

	Control_Temp_and_Humidity(); // �½��� ���� ó�� �Լ�

	return 0;
}
