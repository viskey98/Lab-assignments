#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define MIN(a,b) (a)<(b)?(a):(b)
int flag;
struct node // struct to be used as the nodes
{
   char letter;
   struct node *next;
} *head1,*rear1,*head2,*rear2,*chead;
int isvowel(char a) // function to check if the given character is a vowel
{
  if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
  return 1;
  else return 0;
}
int ispalin(char* arr) // function to check if the given character array is a palindrome
{
  int i, size=strlen(arr);
  FOR0(i,size)
  {
    if(arr[i]!=arr[size-i-1])break;
  }
  if(i==size)return 1 ;
  else return 0;
}
void insert2(char a) // function to insert at the end of the linked list 2
{
  struct node *new=(struct node*)malloc(sizeof(struct node));
  new->letter=a;
  if(head2==NULL)
  {
     head2=new;
     new->next=NULL;
     rear2=new;
  }
  else 
  {
     rear2->next=new;
     rear2=new;
  }
}
void insert1(char a) // function to insert at the end of the linked list 1
{
  struct node *new=(struct node*)malloc(sizeof(struct node));
  new->letter=a;
  if(head1==NULL)
  {
     head1=new;
     new->next=NULL;
     rear1=new;
  }
  else 
  {
     rear1->next=new;
     rear1=new;
  }
}
void swap(struct node* pprev ,struct node* prev,struct node* p) // function to swap two consecutive nodes of a linked list
{
  if(pprev==NULL)
  chead=p;
  else
  pprev->next=p;
  
  prev->next=p->next;
  p->next=prev;
}
void sort() // function to sort the linked list in the vowel and consonant order 
{
  struct node* ptr,*prev,*pprev;
  ptr=chead;
  prev=ptr;
  ptr=ptr->next;
  while(ptr!=NULL)
  {
    if(isvowel(ptr->letter)==1)
    {
      if(isvowel(prev->letter)!=1)
      swap(pprev,prev,ptr);
    }  
    pprev=prev;
    prev=ptr;
    ptr=ptr->next; 
  }
}
void checkpalin()  // function to check palindromes in the linked lists
{
  int i;
  struct node* ptr= chead,*ptr2;
  while(ptr!=NULL)
  {
    char temp[20]={};
    int k=1;
    temp[0]=ptr->letter;
    ptr2=ptr->next;
    while(ptr2!=NULL)
    {
      temp[k]=ptr2->letter;
      k++;
      if(ispalin(temp)==1)
       { flag=1;
       FOR0(i,strlen(temp))
       printf("%c->",temp[i]);
       printf("\b\b  \n");
       }
      ptr2=ptr2->next;
    }
    ptr=ptr->next;
  }
  
}
int main() // mainfunction
{
  int i,j,n,x,y;
  char temp[20]={};
  struct node* list1,list2;
  printf("Enter the no. of students:");
  scanf("%d",&n);
  x=n/2;y=n-n/2;
  printf("Enter the student names:\n");
  FOR0(i,x)
  {scanf("%s",temp);insert1(temp[0]);}
  FOR0(i,y)
  {scanf("%s",temp);insert2(temp[0]);}
  chead=head1;
  sort(); 
  head1=chead;
  chead=head2;
  sort();
  head2=chead;
  chead=head1;
  flag=0;
  checkpalin();
  if(flag==1)
  printf("are the palindromes in list1.\n");
  else printf("There are no palindromes in list1.\n");
  chead=head2;
  flag=0;
  checkpalin();
  if(flag==1)
    printf("are the palindromes in list2.\n");
  else printf("There are no palindromes in list2.\n");
  return 0;
}
