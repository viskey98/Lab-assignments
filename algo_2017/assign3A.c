#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
int find_median(int *arr,int pos,int offset,int size) // recursive function to find the median 
{	
	int i,less[100],great[100],size1=0,size2=0;
	srand(time(NULL));  // randomizing based on time
	int r=rand()%size; // generating random number between 0 and size-1
	FOR0(i,size)   // loop to create 2 arrays holding elements less than and greater than the pivot respectively
	{
		if(i==r)continue;
		if(arr[i]<arr[r])less[size1++]=arr[i];
		else great[size2++]=arr[i];
	}
	if(pos==size1+offset)return arr[r]; 
	else if(pos<size1+offset)return find_median(less,pos,offset,size1);  //recursive call
	else return find_median(great,pos,offset+size1+1,size2); //recursive call
}
int main() // main function
{
	int n,i,ans,pos,arr[100]	;
    printf("Enter the no. of elements in the array: ");
	scanf("%d",&n);
	printf("Enter the elements :\n");
	FOR0(i,n)scanf("%d",&arr[i]);
	if(n%2==0)pos=(n/2);  //finding position of the median
	else pos=(n+1)/2;
	ans=find_median(arr,pos-1,0,n); //function call
	printf("%d\n",ans);
	return 0;
	
}