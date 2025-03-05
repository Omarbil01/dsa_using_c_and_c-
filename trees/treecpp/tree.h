#ifndef treecpp_h
#define treecpp_h

#include<iostream>
using namespace std;

class node
{
public:
	node *lchild;
	int data;
	node *rchild;
};

class queue
{
private:
	int front;
	int rear;
	node **Q;
	int size;

public:
	queue()
	{
		front=-1;
		rear=-1;
		size=1;
		Q=new node*[size];
	}

	queue(int size)
	{
		front=-1;
		rear=-1;
		this->size=size;
		Q=new node*[size];
	}

	~queue()
	{
		delete[] Q;
	}

	void enqueue(node* x)
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

	node* dequeue()
	{
		node * x=NULL;
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

	/*void display()
	{

		for(int i=front + 1;i<=rear;i++)
		{
			cout<<" "<<Q[i];
		}	
		cout<<endl;
	}*/

	int isEmpty()
	{
		return front == rear;
	}
};

#endif