#include<stdio.h>

int main()
{
	char a[]="finding";

	long int H=0;
	long int x=0;

	for(int i=0;a[i] != '\0';i++)
	{
		x=1;
		x=x<<(a[i]-97);
		//small charecters start from ascii code 97
		//we will subtract 97 from these letters
		//so that we can add numbers from 0 to 26
		//in bit h

		//first x will be one, depending on the ascii 
		//number, we will left shift x to that location

		//we will check if that bit in H is off or on by 
		//masking or ANDing

		if((x & H) > 0)
		{
			printf("%c is duplicate\n",a[i]);
		}

		else
		{
			//we will set h as 1 by masking
			//or ORing

			H = x | H;
		}

	}
}