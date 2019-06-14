#include <iostream>
using namespace std;

#define MAX_N (95)
int matrix[MAX_N][MAX_N];
int N;
int i,j;

void Make_Magic_Square(int n)
{
	if(n > N*N)
	 return;

	if(n == 1)
	{
		i=0,j=(N-1)/2;
		matrix[i][j]=n;
	//	cout << "dbg " << i << " " << j << " " << n << endl;
		Make_Magic_Square(n+1);
	}
	else if((n-1)%N == 0)
	{
		if(i == N-1)
		{
			i=0;
			j=j;
			matrix[i][j]=n;
		//	cout << "dbg " << i << " " << j << " " << n << endl;
			Make_Magic_Square(n+1);
		}
		else
		{
			i++;
			j=j;
			matrix[i][j]=n;
	//		cout << "dbg " << i << " " << j << " " << n << endl;
			Make_Magic_Square(n+1);
		}		
	}
	else
	{
		if(i == 0)
		 i = N-1;
		else
		 i--;

		if(j == 0)
		 j = N-1;
		else
		 j--;

		matrix[i][j]=n;
	//	cout << "dbg " << i << " " << j << " " << n << endl;
		Make_Magic_Square(n+1);
	}
}

void Print_Complete_Matrix(int N)
{
	int r, c;
	for (r=0;r<N;r++)
	{
		for (c=0;c<N;c++)
		{
			cout << matrix[r][c] << " ";
		}
		cout << endl;
	}
}

int main(void)
{
	cin >> N;

	Make_Magic_Square(1);

	Print_Complete_Matrix(N);
	
	return 0;
}
