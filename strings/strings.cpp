#include<iostream>
using namespace std;

void conv(char str[])
{
	int i;
	for(i=0; str[i] != '\0'; i++)
	{
		if(str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + 32;
		}

		else if(str[i] >= 97 && str[i] <= 122)
		{
			str[i] = str[i] - 32; 
		}
	}
	cout<<"Converted string is: "<<str<<endl;
}

void stcount(char str[])
{
	int count,count1,word;
	count=count1=0;
	word=1;
	int i;

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

	cout<<"Count of vowels: "<<count<<endl;
	cout<<"Count of consonants: "<<count1<<endl;
	cout<<"Number of words: "<<word<<endl;
}

int stlen(char str[])
{
	int i;
	for(i=0;str[i] != '\0' ;i++) 
	{
		// it has to remain empty because i will be returning length
	}
	return i;
}

int palin(char str[])
{
	int l=0;
	int r=stlen(str) -1;

	while(l<r)
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

void strrev(char str[])
{
	int l=0;
	int r=stlen(str) - 1;
	char temp;

	while(l<r)
	{
		temp=str[l];
		str[l]=str[r];
		str[r]=temp;

		l++;
		r--;
	}
	cout<<"Reversed string: "<<str<<endl;
}

void valid(char str[])
{
	int valid=1;
	int i;

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
		cout<<"String is valid"<<endl;
	}
	else
	{
		cout<<"String is not valid"<<endl;
	}

}

int main()
{
	char str[100];
	int a;
	int x;
	cout<<"Enter a string: ";
	cin.getline(str,100);

	do
	{
		cout<<"1.String conversion"<<endl;
		cout<<"2.String counting"<<endl;
		cout<<"3.Finding length of string"<<endl;
		cout<<"4.String palindrome"<<endl;
		cout<<"5.String reverse"<<endl;
		cout<<"6.Checking string validity"<<endl;
		cout<<"7.Exit"<<endl;

		cout<<"Enter your choice: ";
		cin>>a;

		switch(a)
		{
		case 1:
			conv(str);
			break;

		case 2:
			stcount(str);
			break;

		case 3:
			x=stlen(str);
			cout<<"Length of string: "<<x<<endl;
			break;

		case 4:
			x=palin(str);
			cout<<"0 if palindrome, 1 if not palindrome: "<<x<<endl;
			break;

		case 5:
			strrev(str);
			break;

		case 6:
			valid(str);
			break;

		case 7:
			cout<<"Thank you"<<endl;
			break;


		default:
			cout<<"Enter the correct choice: "<<endl;
			break;
		}
	}while(a != 7);

	return 0;
}