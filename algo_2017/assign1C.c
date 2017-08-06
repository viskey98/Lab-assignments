#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define MIN(a,b) (a)<(b)?(a):(b)
struct book  // Structure of the nodes to be used in the linked list
{
	int sno;
	char title[30], Author[30], is[30];
	struct book* next;
}*head,temp;
void insert(struct book tmp) // function to insert nodes in front of the linked list
{
	struct book *new=(struct book*)malloc(sizeof(struct book));
	new->sno=temp.sno;
	strcpy(new->title,temp.title);
	strcpy(new->Author,temp.Author);
	strcpy(new->is,temp.is);
	if(head==NULL)
	  {head=new;
       new->next=NULL;
	  }
	else 
	  {new->next=head;
       head=new;
	  }
	  
}
void getline(char *a) // function to get char array uptill newline is detected
{
	int i=0;
	char b;
	while(1)
	{
	b=getchar();
	if(b=='\n')break;
	else {a[i]=b;i++;}
	}
}
void viewdetails(struct book * ptr) // function to view the details of a book pointed by ptr
{
	printf("Sno:%d\nTitle:%s\nAuthor:%s\nIssue status:%s\n",ptr->sno,ptr->title,
	          ptr->Author,ptr->is);
}
int main()  // main function
{
	char option,option2,flag1,flag;
	struct book *ptr;
	while(1)
	{
		flag1=0;
		memset(temp.title,'\0',29);
		printf("Choose any of the following options:\n");
	     printf("a. Make a new entry of book\nb. View Details of a book\nc. Show list of available books\nd. Issue a book\ne. Return a book\nf. Exit\n");
	     scanf("%c",&option);
	switch(option)  // switch statement for main menu 
	{
		case 'a':  printf("Enter the following details for the new book:\n");
		           printf("Sno:");scanf("%d",&temp.sno);getchar();
		           printf("\nTitle:");getline(temp.title);
				   printf("\nAuthor:");getline(temp.Author);
				   strcpy(temp.is,"Not issued");
				   insert(temp);
				   printf("New entry added sucessfully.\n");
				   break;
				   
		case 'b': printf("Choose any of the following options:\n");
		          printf("a. By serial no.\n");
				  printf("b. By title.\n");
				  printf("c. By author.\n");
				  getchar();
				  scanf("%c",&option2);
				  
				  switch(option2)  // switch statement for the menu inside case 'b' of main menu
				  {
					  case 'a': printf("Enter serial no:");
					            scanf("%d",&temp.sno);
								getchar();
								ptr=head;
								 flag =0;
								while(ptr!=NULL)
								{
									if(ptr->sno==temp.sno)
									{viewdetails(ptr); flag=1;break;}
									ptr=ptr->next;
								}
								if(flag==0)printf("Sorry,this serial no. doesn't exist.\n ");
								break;
							
			          case 'b': printf("Enter Title of the book:");
					            getchar();
					            getline(temp.title);
								flag=0;
								ptr=head;
								while(ptr!=NULL)
								{
									if(strcmp(temp.title,ptr->title)==0)
									{viewdetails(ptr); flag=1;break;}
									ptr=ptr->next;
								}
								if(flag==0)printf("Sorry,this title of the book doesn't exist.\n ");
								break;
					 case 'c': printf("Enter Author name of the book:");
					           getchar();
                               getline(temp.Author);
							   flag=0;
								ptr=head;
								while(ptr!=NULL)
								{
									if(strcmp(temp.Author,ptr->Author)==0)
									{viewdetails(ptr);printf("\n"); flag=1;}
									ptr=ptr->next;
								}
								if(flag==0)printf("Sorry,books written by this Author don't exist.\n ");
								break;
							   
					 default : printf("Please enter a valid option.\n");break;		
				  }
				     break;
		case 'c':    ptr=head;flag=0;
		             while(ptr!=NULL)
					 {
						 if(ptr->is[0]=='N')
						 {viewdetails(ptr);printf("\n");flag=1;}
					     ptr=ptr->next;
					 }
					 if(flag==0)printf("Sorry, there are no available books.\n");
					 getchar();
					 break;
		case 'd':  printf("Enter the serial no. of the book to be issued:");
		           scanf("%d",&temp.sno);
				   getchar();
				   flag=0;
				   ptr=head;
		             while(ptr!=NULL)
					 {
						 if(temp.sno==ptr->sno)
						 { if(ptr->is[0]=='I')
							 {printf("Sorry,this book has already been issued.\n"); flag=1;}
							else { strcpy(ptr->is,"Issued");flag=1;break;}
						 }
						 ptr=ptr->next;
					 }
					 if(flag==0)printf("Sorry,this serial no. don't exist.\n ");
						break;
		case 'e':  printf("Enter the serial no. of the book to be returned:");
		           scanf("%d",&temp.sno);
				   getchar();
				   flag=0;
				   ptr=head;
		             while(ptr!=NULL)
					 {
						 if(temp.sno==ptr->sno)
						 { if(ptr->is[0]=='N')
							 {printf("Sorry,this book is not issued.\n"); flag=1;}
							else { strcpy(ptr->is,"Not Issued");flag=1;break;}
						 }
						 ptr=ptr->next;
					 }
					 if(flag==0)printf("Sorry,this serial no. don't exist.\n ");
						break;
		case 'f': flag1=1;
		          break;
		default: printf("Please enter a valid option.\n");break;
	}
	if(flag1==1)break;
	}return 0;
}