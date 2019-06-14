#include <iostream>
using namespace std;

const int MAX=50000;
const int MOD=10000;

class S{
	int sp;
	int data[MAX];
public:
	S(){
		sp = 0;
	}

	void Push(int d){
		if (sp >= MAX) return;
		data[sp++] = d;
	//	cout << "push " << data[sp-1] << endl;
	}

	int Pop(void){
		//	Pop�Լ��� �ϼ��ϼ���
		//	���ÿ��� �����͸� Pop�Ͽ� ����
		//	Pop ��ų �����Ͱ� ���� ��� -1�� ����
		if(sp == 0)
			return -1;
		else
			return data[--sp];
	}
};

class A{
	int N;
	int a[MAX];
	char op[MAX];

	public:
	void Input_Data(void){
		int i;
		cin >> N;
		cin >> a[0];
		for (i = 1; i < N; i++){
			cin >> op[i];
			cin >> a[i];
		}
	}
	int Multiply(int a, int b){
		//cout << "multi " << a << " " << b << endl;
		return (a*b) % MOD;
	}
	int Solve(void){
		int i, d,tmp=0;
		int sol = 0;
		S S;

		S.Push(a[0]);
		for (i = 1; i < N; i++){
			switch (op[i]){
			case '*':
				d = S.Pop();
				S.Push(Multiply(d, a[i]));
				break;
			case '+':
				S.Push(a[i]);
				break;
			}
		}

		while(1)
		{
			tmp = S.Pop();
		//	cout << "tmp " << tmp <<endl;
			if(tmp == -1)
				break;
			else
				sol+=tmp;
		}
		// ���� ��� ���� sol�� ����� �� �ֵ��� �ϼ��ϼ���.

		sol %= MOD;
		return sol;
	}
};

int main(){
	A aa;
	aa.Input_Data();
	cout << aa.Solve() << endl;
	return 0;
}
