#include<iostream>
using namespace std;

class queue
{
private:
	int front;
	int rear;
	int *Q;
	int size;

public:
	queue()
	{
		front=-1;
		rear=-1;
		size=1;
		Q=new int[size];
	}

	queue(int size)
	{
		front=-1;
		rear=-1;
		this->size=size;
		Q=new int[size];
	}

	~queue()
	{
		delete[] Q;
	}

	void enqueue(int x)
	{
		if(rear==size-1)
		{
			cout<<"Queue is full."<<endl;
			return;
		}
		else
		{
			rear++;
			Q[rear]=x;
		}
	}

	int dequeue()
	{
		int x=-1;
		if(front==rear)
		{
			//cout<<"Queue is empty"<<endl;
			return x;
		}
		else
		{
			front++;
			x=Q[front];
			return x;
		}
	}

	void display()
	{

		for(int i=front + 1;i<=rear;i++)
		{
			cout<<" "<<Q[i];
		}	
		cout<<endl;
	}
};

int main()
{
	int size;
	int choice;
	int x;
	cout<<"WELCOME TO QUEUE PROGRAM"<<endl;

	cout<<"Enter size of the queue: ";
	cin>>size;

	queue q(size);

	do
	{
		cout<<"1.Enqueue"<<endl;
		cout<<"2.Dequeue"<<endl;
		cout<<"3.Display"<<endl;
		cout<<"4.Exit"<<endl;

		cout<<"Enter your choice: ";
		cin>>choice;

		switch(choice)
		{
		case 1:
			cout<<"Enter the value: ";
			cin>>x;
			q.enqueue(x);
			break;
		case 2:
			x=q.dequeue();
			if(x == -1)
			{
				cout<<"Queue is empty"<<endl;
			}
			else
			{
			cout<<"Dequeued element is: "<<x<<endl;
			}
			break;
		case 3:
			cout<<"Elements are: "<<endl;
			q.display();
			break;
		case 4:
			cout<<"Thank you for using the program"<<endl;
			break;
		default:
			cout<<"Enter valid choice"<<endl;
			break;
		}
	}while(choice != 4);


	return 0;
}