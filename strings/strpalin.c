#include<stdio.h>

int palin(char str[])
{
	int length = 0;
	int i;

	for(i=0; str[i] != '\0'; i++)
	{
		if(str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
		length++;
	}

	int l=0;
	int r=length - 1;

	while(l < r)
	{
		if(str[l] != str[r])
		{
			return 1;
		}
		l++;
		r--;

	}
	return 0;
}

int main()
{
	char str[50];

	printf("Enter the string: ");
	fgets(str,sizeof(str),stdin);

	int x=palin(str);

	printf("0 is palindrome and 1 is not: %i\n",x);

	return 0;
}