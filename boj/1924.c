#include <stdio.h>



int get_sum(int m);
int printday(int tm);

int nmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int get_sum(int m)
{
	int tmp = 0, i = 0;
	for(i=0;i<m;i++)
	 tmp +=nmonth[i];
	return tmp;
}
int printday(int tm)
{
	switch(tm)
	{
		case 1:
			printf("MON\n");
			break;
		case 2:
			printf("TUE\n");
			break;
		case 3:
			printf("WED\n");
			break;
		case 4:
			printf("THU\n");
			break;
		case 5:
			printf("FRI\n");
			break;
		case 6:
			printf("SAT\n");
			break;
		case 0:
			printf("SUN\n");
			break;
		default:
			break;
	}
}

int main()
{

	int tmp_sum = 0, m = 0, n = 0;
	scanf("%d %d",&m,&n);
	m--;	
	tmp_sum = get_sum(m);
	tmp_sum += n;
	printday(tmp_sum%7);
	return 0;
}

