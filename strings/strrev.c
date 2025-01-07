#include<stdio.h>

void rstr(char str[])
{
	int length = 0; 
	//first we will assume length
	//of the string as 0
	for(int i=0; str[i] != '\0'; i++)
		{
			if(str[i] == '\n')
			{
				str[i] = '\0';
				break;
			}
			length ++;
			//at the end of the loop
			//we will find actual length
		}

	int l=0, r=length-1;
	//l is 0th array,r is array before 
	//'\0'
	char temp;

	while(l < r)
	{
		temp = str[l];
		str[l] = str[r];
		str[r] =temp;

		l++;
		r--;
	}
	//while loop helps in swapping last 
	//and first arr elements till l<r
	printf("Reversed string is: %s\n",str);
}

int main()
{
	char str[50];
	
	printf("Enter the string: ");
	fgets(str,sizeof(str),stdin);

	rstr(str);

	return 0;
}