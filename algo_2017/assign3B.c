#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
int count(char a,int i,char* word) // recursive function to find the no. of times a character 'a' appears in the string word
{
	if(i==strlen(word))return 0;
	if(a==word[i])return 1+count(a,i+1,word); // recursive call 
	else return count(a,i+1,word); // recursive call 
}
void Remove(char a,char* word,char* temp,int i) // recursive fucntion to remove all the instances of a character 'a' appearing in the string word
{
	
	if(i==strlen(word)){return;}
	int j=strlen(temp);
	if(word[i]!=a)temp[j]=word[i];
	Remove(a,word,temp,i+1); // recursive call 
}
bool isEvenWord(char *word) // recursive function to check if a word is an even word 
{
	char temp[100]={};
	if(strcmp(word,"")==0)return true;
	if(count(word[0],0,word)%2!=0)return false;
	Remove(word[0],word,temp,0);
	return isEvenWord(temp); // recursive call 
	
}
int main() // main function
{
	char word[100]={};
	printf("Enter the word : ");
	scanf("%s",word);
	if(isEvenWord(word))printf("The enterd word is an even word.\n"); // function call
		else printf("The Entered word is not an even word.\n");
	return 0;
}