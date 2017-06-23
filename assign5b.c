//G.K.Viswak Hanumanth 1601cs48 7-2-2017
/*Program to seat guests with unique id's in rows  , get unique id of a guest to be searched ,get details of
 new guest and seat him in the arrangement (etc)*/
#include<stdio.h>
 int main()
 {
	 int n=0,srch,new,temp,pos,ng,nb,npos;
	 int i,j,k;
	 int ar1[15],red[15],blue[15],male[15],female[15];
	 printf("Enter the unique id's of guests\n(Rules: \n*1.Add one by one.\n*2.Enter minimum 10 and maximum 15 ids \n*3.enter '0' after entering the last unique id):");
	 for(i=0;;)
	 {scanf("%d",&ar1[i]);
              i++;
           if(ar1[i-1]==0)
          break;
          }
 
 for(i=0;ar1[i]!=0;i++)
	 n++;
 
 if(n<10)
	 printf("\nThe number of ids entered are less than 10.");
 printf("\nEnter id to be searched for:");
 scanf("%d",&srch);
 printf("\nEnter the unique id of new guest:");
 scanf("%d",&new);
 
 for(i=0;i<n;i++)
 {for(j=i+1;j<n;j++)
	 {if(ar1[i]<ar1[j])
         temp=ar1[i];
	  ar1[i]=ar1[j];
	  ar1[j]=temp;
		 }	
 }
 
 printf("\nThe seating arrangement is:");
 for(i=0,j=1;i<n;i++,j++)
 {printf("%d ",ar1[i]);
   if(j==5)
   {printf("\n");
     j=1;}   
   }
   
   for(i=0;i<n;i++)
   { if(ar1[i]==srch)
	  pos=i+1;}
   printf("\n The guest with id %d is present in the party and is seated at position %d ",srch,pos);
   
   for(i=0,j=0,k=0,nb=0,ng=0;i<n;i++)
   {if(ar1[i]<0)
	   {male[j]=ar1[i];
       j++;
       nb++;}
   else 
   {    female[k]=ar1[i];
         k++;
         ng++;}
   }
   printf("There are %d males and %d females",nb,ng);
   
    printf("\nThe male guest id's are: ");
  for(i=0;i<nb;i++)
   printf("%d ",male[i]);

    printf("\nThe female guests id's are:");
	for(i=0;i<ng;i++)
		printf("%d ",female[i]);
	
	
   
   
  for(i=0,j=0,k=0;i<n;i++)
  {
	  if(ar1[i]%2==0)
	  { red[j]=i+1;
         j++;
	 }
       else
       {blue[k]=i+1;		   
        k++;
	   }
  }
  
  printf("\nThere are %d guests in red and %d guests in blue dress respectively",j+1,k+1);
 
   printf("\nThe seating positions of the guests in red dress are: ");
  for(i=0;i<=j;i++)
	  printf("%d ",red[i]);
  
  printf("\nThe seating positions of the guests in blue dress are: ");
  for(i=0;i<k;i++)
	  printf("%d ",blue[i]);
  
  for(i=0;i<n;i++)
  {
	  if(ar1[i]>new)
	  { npos=i;
	    break;
	  }		
      
  }
 for(i=n-1;i>=npos;i--)
 {
	
	 ar1[i+1]=ar1[i];
 }  
 ar1[npos]=new;
 
 printf("\nThe new seating arrangement is: ");
 
  printf("\nThe seating arrangement is:");
 for(i=0,j=1;i<n+1;i++,j++)
 {printf("%d ",ar1[i]);
   if(j==5)
   {printf("\n");
     j=1;}   
   }
   
   return 0;
 
  
} 
