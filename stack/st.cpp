#include<iostream>
using namespace std;

class stack
{
private:
	int *a;
	int top;
	int size;
public:
	stack()
	{
		top=-1;
		size=1;
		a=new int[size];
	}

	stack(int size)
	{
		this->size=size;
		top=-1;
		a=new int[size];
	}

	~stack()
	{
		delete[] a;
	}

	void display()
	{
		int i;
		for(i = top;i>=0;i--)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}

	void push(int x)
	{
		if(top >= size-1)
		{
			cout<<"Overflow"<<endl;
		}
		else
		{
			top++;
			a[top]=x;
		}
	}

	int pop()
	{
		int x=-1;

		if(top == -1)
		{
			cout<<"Underflow"<<endl;
		}
		else
		{
			x=a[top];
			top--;
		}
		return x;
	}

	int isEmpty()
	{
		if(top == -1)
		{
			return 1;
		}
		return 0;
	}

	int isFull()
	{
		return top == size - 1;
	}

	int peek()
	{
		if(!isEmpty())
		{
			return a[top];
		}
		return -1;
	}

};

int main()
{
	cout<<"Welcome to stack program"<<endl;

	int ch;
	int x,y;

	cout<<"Enter size of stack: "<<endl;
	cin>>y;

	stack s(y);

	do
	{
		cout<<"1.Push"<<endl;
		cout<<"2.Display"<<endl;
		cout<<"3.Pop"<<endl;
		cout<<"4.Peek"<<endl;
		cout<<"5.Is Empty"<<endl;
		cout<<"6.Is Full"<<endl;
		cout<<"7.Exit"<<endl;

		cin>>ch;

		switch(ch)
		{
		case 1:
			cout<<"Enter the value to push: "<<endl;
			cin>>x;
			s.push(x);
			break;
		case 2:
			cout<<"Stack is: "<<endl;
			s.display();
			break;
		case 3:
			x=s.pop();
			cout<<"Popped element: "<<x<<endl;
			break;
		case 4:
			x=s.peek();
			cout<<"Top element: "<<x<<endl;
			break;
		case 5:
			if(s.isEmpty() == 1)
			{
				cout<<"Stack is empty"<<endl;
			}
			else
			{
				cout<<"Stack is not empty"<<endl;
			}
			break;
		case 6:
			if(s.isFull() == 1)
			{
				cout<<"Stack is full"<<endl;
			}
			else
			{
				cout<<"Stack is not full"<<endl;
			}
			break;
		case 7:
			cout<<"Thank you"<<endl;
			break;
		default:
			cout<<"Choose correct choice"<<endl;
			break;
		}
	}while(ch != 7);

	return 0;
}