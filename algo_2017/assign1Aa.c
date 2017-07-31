#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define MIN(a,b) (a)<(b)?(a):(b)
char names[100][20];
int n;
struct node // Structure for the nodes of the linked list used
{
   char name[20];
   struct node *next;
} *head,*rear;
void swap(struct node* prev,struct node* ptr,struct node* nxt) // Function to swap two consecutive nodes 
{                                                                // of a linked list
	if(prev==NULL)head=nxt;
	else prev->next=nxt;
	ptr->next=nxt->next;
	nxt->next=ptr;
}
void print()     // Function to print the final linked list after sorting
{
    int i,j;
	struct node* ptr= head;
	while(ptr!=NULL)
	{
		FOR0(i,n)
		{
			int count=0;
			FOR0(j,strlen(ptr->name))
			{if(names[i][j]==ptr->name[j])
				count++;
		    }
			   if(count==strlen(ptr->name))
				   printf("%s\n",names[i]);	
		}
		ptr=ptr->next;
	}
}
void sort()   // function to sort the linked list 
{
  struct node* ptr=head,*ptr2,*prev,*ptr1;
  while(ptr!=NULL)
  {
	  prev=NULL;
	  ptr1=head;
	  ptr2=ptr1->next;
	  while(ptr2!=NULL)
	  {
		  if(strcmp(ptr1->name,ptr2->name)==1)
			  swap(prev,ptr1,ptr2);
		  prev=ptr1;
		  ptr1=ptr2;
		  ptr2=ptr2->next;
		  
	  }
	  ptr=ptr->next;
  }
}
void insert(char *Name)  // function to insert a node at the end of the linked list
{
   struct node *new=(struct node*)malloc(sizeof(struct node));
  strcpy(new->name,Name);
  if(head==NULL)
  {
     head=new;
     new->next=NULL;
     rear=new;
  }
  else 
  {
     rear->next=new;
     rear=new;
  }
}
int main()   // Main function
{
    int i,j,k,l,flag; 
    printf("Enter the no. of students:");
    scanf("%d",&n);  
    printf("Enter the names of the students:\n");	
    FOR0(i,n)
    {
       scanf("%s",names[i]);
    }
    FOR0(i,n)
    {
      char curr[20]={};
      FOR0(k,strlen(names[i]))
      {
	
      curr[k]=names[i][k];
      FOR0(j,n)
      { if(j==i)continue;
         int count=0;
         int size=MIN(strlen(names[j]),strlen(curr));
         FOR0(l,size)
         { if(names[j][l]==curr[l])
             count++;
         }
         if(count==size)   
         {flag=0;break;}
         else flag =1;   
      }
      if(flag==1)
      {insert(curr);break;}
      
      }
    }
	sort();
	print();
	return 0;
    
}

