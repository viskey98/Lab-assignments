#include<stdio.h>
#include<string.h>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
int n,box[100]; // integer array box[]- to store no.of chocolates in respective boxes
                        // n- to store the no. of boxes;
int table[100];  // DP table for memoization as this problem contains n distinct states.
int take(int type) // Recursive function to find the possible distinct states
{
	if(type>=n)return 0;
	if(table[type]!=-1)return table[type];
	
	return table[type]=MAX(box[type]+take(type+2),take(type+1));
}
int LargeDigit(int value) // Recursive function to find the largest digit in the answer found out.
{
	if(value==0)return 0;
	int x=value%10;
	return  MAX(x,LargeDigit(value/10));
}
int main() // main function
{
  int i,ans,ld;
  memset(table,-1,100);
  scanf("%d",&n);
  FOR0(i,n)
  scanf("%d",&box[i]);
  ans=take(0);
  printf("%d\n",ans);
  ld=LargeDigit(ans);
  printf("%d\n",ld);
  return 0;
}

