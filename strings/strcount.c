#include<stdio.h>

int main()
{
	int i;
	int count = 0,count1=0;
	int word = 1;
	char str[50];

	printf("Enter the string: ");
	fgets(str,sizeof(str),stdin);

	for(i=0; str[i] != '\0'; i++)
	{
		if(str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
	}

	for(i=0 ; str[i] != '\0' ; i++)
	{
		if(str[i]=='a' ||str[i]=='e' ||str[i]=='i' ||str[i]=='o' ||str[i]=='u' ||str[i]=='A' ||str[i]=='E' ||str[i]=='I' ||str[i]=='O' ||str[i]=='U')
		{
			count += 1; 
		}
		else if((str[i] >= 65 && str[i]<= 90) || (str[i] >= 97 && str[i] <= 122))
		{
			count1 += 1;
		}
	}

	for(i=0 ; str[i] != '\0' ; i++)
	{
		if(str[i] == ' ' && str[i-1] != ' ')
		{
			word ++;
		}
	}

	printf("Vowels: %i and consonants: %i ",count,count1);
	printf("\n");
	printf("Total words: %i",word);
	printf("\n");

	return 0;
}