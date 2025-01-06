//ASCII Codes
//for alphabets 
//starting from A-65 to Z-90
//from a-97 to z-122
//difference between both cases of same
//char is 32, which will be used in this 
//program

#include<stdio.h>

int main()
{
	char str[50];
	int i;
	printf("Enter the string: ");
	fgets(str,sizeof(str),stdin);

	for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '\n') 
        {
	        str[i] = '\0'; 
	        // fgets also takes newline character after 
	        // we hit enter, so we will convert '\n' to '\0'
            break;
        }
    }

	for(i=0;str[i] != '\0';i++)
	{
		if(str[i] >= 65 && str[i] <= 90)
		{
			str[i] += 32; // same as a[i] = a[i] + 32;
		}

		else if(str[i] >= 97 && str[i] <= 122)
		{
			str[i] -= 32; //same as a[i] = a[i] - 32; 
		}
		//useing if else if, will be converting
		//str[i] regardless of the case of the 
		//chars
	}
	printf("Converted string is: %s ",str);
	printf("\n");
	return 0;
} 