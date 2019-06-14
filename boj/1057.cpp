#include <iostream>
#include <math.h>
#define MAX(a,b) (a>b?a:b)

using namespace std;

int n=0,a=0,b=0;
int group[20] = {0};
int ga=0,gb=0;

int getgroup(int a, int b)
{
	int i=0,ans=0;
	
	if(a==1)
	 ga = 0;
	else if(a==2)
	 ga = 1;
	 
	if(b==1)
	 gb = 0;
	else if(b==2)
	 gb = 1;
	 
	for(i=2;i<20;i++)
	{
		if(a > group[i-1] && a <= group[i])
		 ga = i;
		if(b > group[i-1] && a <= group[i])
		 gb = i;
	}
	//cout << ga << " " << gb << endl;
	if(ga != gb)
	{
		ans = MAX(ga,gb);
		if(group[ans] <= n)
		{
		 cout << ans << endl;
		 return 0;
		}
	}
				
	if(a > b)
	{
	 if(a-b == 1)
	 {
	   cout << 1 << endl;
	   return 0;
	 }
	 getgroup(1,a-b+1);
	}
	else
	{
	 if(b-a == 1)
	 {
	  cout << 1 << endl;
	  return 0;
	 }
	 getgroup(1,b-a+1);
	}
}

int main(void)
{
	int i=0;
	
	cin >> n >> a >> b;
	
	for(i=0;i<20;i++)
	{
		group[i]=(int)pow(2,i);
		//cout << group[i] << endl;
	}
	getgroup(a,b);	
}

