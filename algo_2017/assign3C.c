#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c)
int arr[100],n;
int MaxSubArraySum(int currsum,int index,int maxsum) // recursive function to calculate the maximum subarray sum 
{
	if(index==n)return maxsum;
	currsum+=arr[index];
	if(currsum<0)currsum=0;     // current sum is reset to  0, if it drops below 0 (main algotithm used here)
	else maxsum=MAX(currsum,maxsum);  // max sum is the maximum of the currentsum and the previous maximum sum
	return MaxSubArraySum(currsum,index+1,maxsum); //recursive call
}
int main() // main function
{
	int i,Max=-100000,flag;
	printf("Enter the no. of elements in the array: ");
	scanf("%d",&n);
	printf("Enter the elements (one by one):\n");
	FOR0(i,n)scanf("%d",&arr[i]);
	FOR0(i,n){                    //checking if all elements in the list are negative, if yes our answer is the largest negative element
		if(arr[i]>0)break;
 	     else Max=MAX(Max,arr[i]);    
		 }
    if(i==n)flag=1;
	if(flag==1)printf("The maximum subarray sum is: %d\n",Max);   //printing the largest negative elements ,in case all elements are negative
	else printf("The maximum subarray sum is: %d\n",MaxSubArraySum(0,0,0)); //function call
	return 0;
}