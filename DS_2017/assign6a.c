//G.K.Viswak Hanumanth 1601cs48 14-02-17 
//Program to print the all possible words from the letters  of a given word.
#include<stdio.h>
void permute(char arr[],int used[],int order[],int l,int r,int x)  //The function to permute the letters into all possible combinations

{
	int i,j; 
	if(l==0||arr[l]!=arr[l-1])
	for(i=0;i<=r;i++)
	{
	if(used[i]!=1)
	{order[i]=l;
	   used[i]=1;
	    permute(arr,used,order,l+1,r,i);  //Recursive call
		used[i]=0;
	if(l==r)

		{for(j=0;j<=r;j++)
		printf("%c",arr[order[j]]);
		printf(" ");}
	}
}
else
	for(i=x+1;i<=r;i++)
	{
	if(used[i]!=1)
	{order[i]=l;
	   used[i]=1;
	    permute(arr,used,order,l+1,r,i);
		used[i]=0;
	if(l==r) // loop to print the new order of letters 

		{for(j=0;j<=r;j++)
		printf("%c",arr[order[j]]);
		printf(" ");}
	}
}

}
int main()
{
	int i,j; //Declaration of variables used as indices
	char temp; // Variable to hold a temporary value
	char arr[100];  //The array that stores the letters of the given word and later gets sorted according to similar elements
	int used[100] = {},order[100],n; // used- array to store if the particular position is used or not, order - to store if the order of the letters to be printed, n- to store the total no of letters in the word.
	printf("\nNumber of letters:");
	scanf("%d%*c",&n);  
        printf("\nEnter the letters(without any spaces inbetween them)):");     
         
         scanf("%s",arr);

	for(i=0;i<n;i++) // for loop to sort the letters in the given word such that similar elements are present next to each other
	{for(j=i+1;j<n;j++)
		if(arr[i]==arr[j])
		 { temp=arr[i+1];
		arr[i+1]=arr[j];
		arr[j]=temp;}
		}


	permute(arr,used,order,0,n-1,0); //Function call
        printf("\n");	
    return 0;
}
