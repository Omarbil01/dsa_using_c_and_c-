#include<stdio.h>

void perm(char s[],int k)
{
	static int a[10]={0};
	//static is available in every function call
	static char res[10];

	int i;

	if(s[k] == '\0')
	{
		res[k]='\0';
		printf("%s\n",res);
		//we have reached the end of the string
		//we will print all the permutations here
	}
	else
	{

		for(int i=0;s[i] != '\0';i++)
		{
			if(a[i] == 0)
			{
				res[k]=s[i];
				a[i]=1;
				perm(s,k+1);
				a[i]=0;
			}
			//we are using backtracking and using state
			//space tree. If there are chars in string
			//left, we will put that in result string.
			//a array will signify we have visited that
			//char and to ignore that
		}
	}
}

int main()
{
	char s[]="abc";
	perm(s,0);

	return 0;
}
