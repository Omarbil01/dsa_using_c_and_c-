#include<stdio.h>

int main()
{
	char s[50];
	printf("Enter the string: ");
	fgets(s,sizeof(s),stdin);
	//fgets used for taking string input 
	//as it can also scan for spces between 
	//strings

	int i;
	for(i=0;s[i] != '\0' ;i++) 
	//'\0' is a string termination char or end of the string char
	{
		// it has to remain empty because i will be returning length
	}
	printf("Length is %i",(i-1));

	return 0;
}
