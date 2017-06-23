//G.K.Viswak Hanumanth 1601cs48 17.02.17
//Program to create the bowling strategy for iitp cricket team.
//Note : This program doesnt use a 'unique' function ,as it is made in such a way it only produces unique combinations.
#include<stdio.h>
void strategy(int over,int m,int nb,int l,int comb[]) //The function to create the strategy for dividing the no.of overs to the bowlers.
{
int x,j,i,k;                                          //Declaration of  variables that store indices and temporary values
if(m!=0)
x=over/m;
else
x=0;

for(j=x;over>0&&j>=0;j--)
{
{for(i=0,k=l;i<j;i++,k++)
if(k<nb)
	comb[k]=m;
else 
return;}
strategy(over-(j*m),m-1,nb,l+i,comb); //Recursive call of the function

}
if(over==0&&m!=0)
comb[l]=0;

if(l>=(nb-1)&&(over)==0)
{for(i=0;i<nb;i++)     // For loop that prints the combination of overs amongst the bowlers
   printf("%d ",comb[i]);
   printf("\n");}
}


int main()
{int over, m,nb,l,comb[100];  /* Declaration of variables:
                                 over- to store the total no.of overs; m- to store the max no. of overs that a bowler can bowl;
                                 l- to store the index of the current bowler; comb- integer array to store the combinations of the overs amongst the bowlers; */
printf("\nTotal overs :");
scanf("%d",&over);
printf("\nMaximum number of overs of one bowler:");
scanf("%d",&m);
printf("\nNumber of bowlers:");
scanf("%d",&nb);
strategy(over,m,nb,0,comb);  //Function call
return 0;
}
