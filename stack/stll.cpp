#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node *next;
};

class stack
{
private:
	node *top;

public:
	stack()
	{
		top=NULL;
	}

	void push(int x)
	{
		node *t=new node;
		if(t==NULL)
		{
			cout<<"Stack is full"<<endl;
		}
		else
		{
			t->data=x;
			t->next=top;
			top=t;
		}
	}

	int pop()
	{
		int x=-1;
		if(top == NULL)
		{
			cout<<"Stack is empty";
		}

		else
		{
			x=top->data;
			node *t=top;
			top=top->next;
			delete t;

		}
		return x;

	}

	void display()
	{
		node *p=top;
		while(p != NULL)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;

	}
};


int main()
{
	cout<<"WELCOME TO STACK PROGRAM"<<endl;
	int x,choice;

	stack s;

	do
	{
		cout<<"1.Push"<<endl;
		cout<<"2.Pop"<<endl;
		cout<<"3.Display"<<endl;
		cout<<"4.Exit"<<endl;

		cout<<"Enter a choice: ";
		cin>>choice;

		switch(choice)
		{
		case 1:
			cout<<"Enter the value: ";
			cin>>x;
			s.push(x);
			break;
		case 2:
			x=s.pop();
			cout<<"Popped element: "<<x<<endl;
			break;
		case 3:
			cout<<"Displayed elements: "<<endl;
			s.display();
			break;

		case 4:
			cout<<"Thank you for using the program"<<endl;
			break;
		default:
			cout<<"Enter a valid choice"<<endl;
			break;

		}
	}while(choice != 4);
	return 0;
}


