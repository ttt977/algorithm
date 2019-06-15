##include <stdio.h>
#define MAX(a,b) (a)>(b)?(a):(b)

int fence[10] = {0};
int max=tmp=0;

int getmaxsize(int start, int end)
{
  if(start == end)
   return fence[start];
  else if(start > end)
   return 0;
  else if(fence[start] <= fence[start+1])
  {
   tmp = fence[start]*2;   
   if(tmp > max)
    max = tmp;
   getmaxsize(start+1,end);
  }
  else
  {
  	
  }
}

int main()
{
	printf("%d")
}
