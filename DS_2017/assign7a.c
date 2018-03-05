//G.K.Viswak Hanumanth 1601cs48 8.03.17 
//Program to take in a matrix of order nxm ,print its inverse if it exists, check if its square matrix and print the highest minor element's position.
#include<stdio.h>
#include<stdlib.h>
int det(int**ar,int m );                    /* Declaration of functions  det- to find determinant of the given matrix;                              
int** minr(int**ar,int m);                       minr- to find the minor of the given matrix;
int** adj(int** ar,int m);                       adj- to find the adjoint of the given matrix;
void inverse(int** ar,int der,int m);            inverse - to find the inverse of the given matrix and print the inverse; */
int det(int **ar,int m)                 //Definition of the det function -which uses recursion to find the determinant of the given matrix.                                                                              
{
        int sum=0,x,p,q,y,k,j;          // Declaration of variables to be used in the function
        if(m!=2)
        { int **temp=(int**)malloc((m-1)*sizeof(int*));  //Dynamically allocating a ptr to ptr temp- which is to be used as 2d array.
         for(k=0;k<m-1;k++)
                temp[k]=(int*)malloc((m-1)*sizeof(int));

        for(j=0;j<m;j++)
        {


    for(x=0,p=0;x<m;x++)  // for loop to create submatrix of the given matrix and find their determinants by recursion.
                for(y=0,q=0;y<m;y++)
                { if(x!=0&&y!=j)
                 { temp[p][q]=ar[x][y];
                q++;
                if(q==m-1)
                  p++;
                  }
                }
                         if(j%2==0)
                          sum+=ar[0][j]*det(temp,m-1);
                         else
                          sum-=ar[0][j]*det(temp,m-1);
        }
        }
        else{
                sum=(ar[0][0]*ar[1][1])-(ar[0][1]*ar[1][0]);
        }
        return sum;
}

int ** minr(int** ar,int m)  // Funtion minr to find the minor of the given matrix .
{ int i,j,p,q,x,y;           //Declaration of variables to be used in this function.
  int **temp=(int**)calloc(m-1,sizeof(int*));   //Dynamically allocating a ptr to ptr temp- which is to be used as 2d array.
   int **out=(int**)calloc(m,sizeof(int*));     //Dynamically allocating a ptr to ptr out- which is to be used as 2d array.

  for(i=0;i<m;i++)
          out[i]=(int*)calloc(m,sizeof(int*));

  for(i=0;i<m-1;i++)
          temp[i]=(int*)calloc(m-1,sizeof(int));
  if(m!=2)
  {
  for(i=0;i<m;i++)   // for loop that creates the dynamically allocated out(minor) matrix by calling the det function.
          for(j=0;j<m;j++)
          {  for(x=0,p=0;x<m;x++)
                for(y=0,q=0;y<m;y++)
                { if(x!=i&&y!=j)
                 { temp[p][q]=ar[x][y];
                q++;
                if(q==m-1)
                  p++;
                  }
                }
        out[i][j]=det(temp,m-1);
                }
  }
  else
  { out[0][0]=ar[1][1];
        out[1][1]=ar[0][0];
    out[1][0]=ar[0][1];
    out[0][1]=ar[1][0];
  }
 return out;
}

int  ** adj(int** ar,int m) // Definition of function adj which creates the adjoint matrix of a given matrix.
{
        int i,j;            // Declaration of variables to be used in the function.
         int ** out=(int**)calloc(m,sizeof(int*));   //Dynamically allocating a ptr to ptr out- which is to be used as 2d array.
        int ** temp=(int**)calloc(m,sizeof(int*));   //Dynamically allocating a ptr to ptr temp- which is to be used as 2d array.
        for(i=0;i<m;i++)
        {       out[i]=(int*)calloc(m,sizeof(int*));
            temp[i]=(int*)calloc(m,sizeof(int));
        }
        temp= minr(ar,m);    // This function calls mirn function.
        for(i=0;i<m;i++)
                for(j=0;j<m;j++)
                        if((i+j)%2==0)
                                out[i][j]=temp[j][i];
                        else
                                out[i][j]=-temp[j][i];
        return out;
}
	

void inverse(int** ar,int det,int m)  // Definition of function inverse which finds the inverse of the given matrix.
{
        int i,j;  // Declaration of variables to be used in the function.
        int **temp=(int**)calloc(m,sizeof(int*)); //Dynamically allocating a ptr to ptr temp- which is to be used as 2d array.
        for(i=0;i<m;i++)
                temp[i]=(int*)calloc(m,sizeof(int));
        temp=adj(ar,m);  // Calling adj function.
        for(i=0;i<m;i++)   // For loop to print the inverse matrix in adj/det form .
        {for(j=0;j<m;j++)
                {
			          printf("%d/%d ",temp[i][j],det);    
						
                }
     printf("\n");
        }
}


int main()

{
int **ar,**mi;  /* Declaration of double pointers ar and mi , ar-to store the input matrix;
                   mi- to store the minor of the input matrix;*/
int i,j,n,m,max,maxi,maxj,x,y; /* Declaration of variables, n,m-to store the size of input matrix in the order nxm;
                              i,j,x,y-variables used as indices in loops;max-to store the maximum value of minor;
							  maxi,maxj-to store the i and j index of maximum minor respectively; */ 
printf("\nEnter the size of the matrix (nxm)(separated by spaces) = ");
scanf("%d%d",&n,&m);
ar=(int**)calloc(n,sizeof(int*));
for(i=0;i<n;i++)
ar[i]=(int*)calloc(m,sizeof(int));
for(i=0;i<n;i++)       // for loop to get the input matrix;
{printf("\nEnter the elements of row %d (separated by spaces)= ",i+1);
        for(j=0;j<n;j++)
                scanf("%d",&ar[i][j]);
}
if(n==m)  // checking if the given matrix is square matrix.
{   mi= (int**)calloc(n,sizeof(int*));
    for(i=0;i<n;i++)
    mi[i]=(int*)calloc(n,sizeof(int));		
     if(det(ar,n)!=0)
	{printf("\nThe entered matrix is invertible. The inverse matrix is:\n");
	inverse(ar,det(ar,n),n);}     // calling inverse function, to find the inverse of the input matrix.
	else 
		printf("\nThe entered matrix is not invertible.\nThe entered matrix is a square matrix.");
        mi=minr(ar,n);      // calling minr function, to find the minor of the input matrix.
	max=mi[0][0];
	for(x=0;x<n;x++)
	{	for(y=0;y<n;y++)
			if(max<mi[x][y])
			{	max=mi[x][y];
		                maxi=x+1;
				maxj=y+1;
			}
        }
        if(max==mi[0][0])
         {maxi=1;
          maxj=1;
         } 
    
    printf("\nThe entered matrix is a square matrix.\nThe position of the element with highest minor is i=%d j=%d\n",maxi,maxj);			
	
   }
   else printf("\nThe entered matrix is not a square matrix.\nThus the inverse and highest minor cannot be found.\n");
   



 return 0;
}

	
