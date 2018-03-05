//G.K.Viswak Hanumanth 1601CS48 11-04-2017
//Program to read inorder and postorder sequences of a BST from a file , create a BST and print the preorder sequence in a file;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct NODE
{
    char data;
    struct NODE* leftchild;
    struct NODE* rightchild;
    struct NODE* parent;
};
typedef struct NODE node;

node* root; 
FILE *ofp;
  
    
node* create(char* inorder,char* postorder)
{ 
  node* ptr=(node*)calloc(1,sizeof(node));
  int a=strlen(postorder);
  int i,j,count=0;
  char *il,*ir,*pl,*pr;
  for(i=0;i<a;i++)
  { 
    count++;
    {
     if(inorder[i]==postorder[a-1])
     { 
       ptr->data=inorder[i];
       if(a>2&&i>0)
       {
       pl=(char*)calloc(count-1+1,sizeof(char));
       il=(char*)calloc(count-1+1,sizeof(char));
       pr=(char*)calloc(a-count+1,sizeof(char));
       ir=(char*)calloc(a-count+1,sizeof(char));
       for(j=0;j<count-1;j++)
       {
         pl[j]=postorder[j];
         il[j]=inorder[j];
       }
       for(j=0;j<(a-count);j++)
       {  
          pr[j]=postorder[count+j-1];
          ir[j]=inorder[count+j];    
       }
       ptr->leftchild=create(il,pl);
       ptr->rightchild=create(ir,pr);
       ptr->leftchild->parent=ptr;
       ptr->rightchild->parent=ptr;
       return ptr;
       }
       else if(i==0&&a>=2)
       {
         pr=(char*)calloc(a-count+1,sizeof(char));
         ir=(char*)calloc(a-count+1,sizeof(char));
        for(j=0;j<(a-count);j++)
         {  
          pr[j]=postorder[count+j-1];
          ir[j]=inorder[count+j]; 
          }
         ptr->rightchild=create(ir,pr);
         ptr->rightchild->parent=ptr;
         return ptr;
       }
       else if(i==a-1&&a>=2)
       {
         pl=(char*)calloc(count-1+1,sizeof(char));
         il=(char*)calloc(count-1+1,sizeof(char));
         for(j=0;j<count-1;j++)
         {
         pl[j]=postorder[j];
         il[j]=inorder[j];
         }
       return ptr;
       }
       else
        return ptr;
     }
    }
  }
  return 0;
  
}

void preorder(node *root)
{
   node *ptr;
   ptr=root;
   fprintf(ofp,"%c ",(ptr->data));
   if(ptr->leftchild!=NULL)
   preorder(ptr->leftchild);
   if(ptr->rightchild!=NULL)
   preorder(ptr->rightchild);
}
   
int main()
{  
   int i,j,k;
   FILE *ifp;
   ifp=fopen("ipseq.txt","r");
   char inorder[100], postorder[100], input1[100],input2[100];
   fgets(input1,100+1,ifp);
   fgets(input2,100+1,ifp);
   input1[strlen(input1)-1]='\0';
   input2[strlen(input2)-1]='\0'; 
   for(i=0,j=0,k=0;i<strlen(input1);i++)
   {
   if(input1[i]!=' ')
     { 
      inorder[j]=input1[i];
      j++;
     }   
   if(input2[i]!=' ')
     {
      postorder[k]=input2[i];
      k++;
     }
   }

   postorder[strlen(postorder)-1]='\0';
   
   root=create(inorder,postorder);
   ofp=fopen("1601CS48.txt","w"); 
   preorder(root);
   printf("\n");
   
   return 0;
}
   
   
     

