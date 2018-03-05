//G.K.Viswak Hanumanth 1601cs48	7-2-2017
/*Program based on participants of anwesha , finding no. of people who can see the stage and finding whether its a boy's or girl's party based on the theorem
 given by  a bored participant who cudnt see the stage*/
 #include<stdio.h>
int main()
{
int count=0,n;        /* count- stores the count of people who cannot see (to find the  no of people who can see 
                     ,we can subtract it from the total no of participants)
			          n- stores the total no of participants */
int max;                // Variable to store the maximum height in a row(just a temporary variable)
int flag;		// Variable that turns to 1 when it's a boy's party and 0 otherwise		
int ar1[100],ar2[100];   //ar1-Array to store heights of students, ar2-Array to store dress code of participants
int i,j;
printf("Enter the number of students participated: ");
scanf("%d",&n);
printf("\nEnter their heights(one by one):");
for(i=0;i<n;i++)
scanf("%d",&ar1[i]);
printf("\nEnter the color of robes denoted by integers (one by one):");
for(i=0;i<n;i++)  // for loop to calculate the no of people who cannot see the stage and store it in count 
scanf("%d",&ar2[i]);
max=ar1[0];
for(i=1;i<n;i++)
{if(max>ar1[i])
 count++;
 else 
 max=ar1[i];
 }
for(i=0;i<n;i++) // for loop to check if the party is boy's or girl's based on the algorithm given by the bored participant
{for(j=i+1;j<n;j++)
 {if(ar2[i]==ar2[j])
 {flag=1;
 break;}
}
if(flag==1)
break;

}
printf("\nNo. of students can see the stage:%d",n-count);
if(flag==1)
printf("\nIt is a BOYS party.\n");
else 
printf("\nIt is a GIRLS party.\n");
return 0;
}
