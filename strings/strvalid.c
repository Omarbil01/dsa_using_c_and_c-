#include<stdio.h>

int main()
{
	char str[50];
	int i , valid =1;

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
		if(!(str[i] >= 65 && str[i]<= 90) && !(str[i] >= 97 && str[i] <= 122) && !(str[i] >=48 && str[i] <= 57))
		{
			valid = 0;
			break;
		}		
	}

	if(valid)
	{
		printf("String is valid");
	}
	else
	{
		printf("String is not valid");
	}
	printf("\n");
	return 0;
}