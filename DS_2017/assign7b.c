//G.K.Viswak Hanumanth 1601cs48 07.03.2017
//Program to take in 'n' no. of strings  and prints the strings in their dictionary  order 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
  char *string[100],temp[100];  // Declaration of variables : string- array of strings to hold the input strings; temp-  A temporary string;
  int i,n,j;                           // n- to hold the no of strings to get as input ; i and j - variables used as indices in the loops  
  scanf("%d",&n);
  if(n<0)
  {printf("Negative no. of strings is not possible.");
   return 0;
  }
  for(i=0;i<n;i++)                     // for loop to get input strings 
  {scanf("%s",temp);
   string[i]=(char *)malloc((strlen(temp)+1)*sizeof(char));
    strcpy(string[i],temp);}
  for(i=0;i<n;i++)                     // for loop to sort the strings in dictionary order , using strcmp function
  for(j=i+1;j<n;j++)
  {
   if(strcasecmp(string[j],string[i])<0)
    { strcpy(temp,string[i]);
      strcpy(string[i],string[j]);
      strcpy(string[j],temp);
    }
  }
  printf("\n");

  for(i=0;i<n;i++)                    //for loop to print the strings in dictionary order 
  printf("%s\n",string[i]);
  return 0;
}

