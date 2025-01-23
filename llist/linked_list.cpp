#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node *next;
	//this class is equivalent to the struct we created 
	//in C program,its content are private as we will use 
	//this class in another class for linked list functions
};

class llist
{
	//this is the class where linked list
	//functions would take place
private:
	node *first;
public:
	llist()
	{
		first=NULL;
		//default constructor
	}

	llist(int a[],int n)
	{
		//parameterized constructor
		int i;
		node *t,*last;

		first=new node;
		first->data=a[0];
		first->next=NULL;
		last=first;

		for(i=1;i<n;i++)
		{
			t=new node;
			t->data=a[i];
			t->next=NULL;
			last->next=t;
			last =t;
		}
	}

	~llist()
	{
		node *p=first;
		while(first != NULL)
		{
			first=first->next;
			delete p;
			p=first;
		}
		//destructor
	}

	void display()
	{	
		node *p = first;
		while(p != NULL)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
	}

	int count()
	{
		node *p=first;
		int count = 0;
		while(p != NULL)
		{
			count ++;
			p= p->next;
		}
		return count;
	}

	void insert(int index,int x)
	{
		int i;
		node *t;
		node *p=first;
		if(index<0 || index>count())
		{
			return;
		}

		t=new node;
		t->data=x;
		t->next=NULL;

		if(index == 0)
		{
			t->next=first;
			first=t;
		}
		else
		{
			for(i=0;i<index-1;i++)
			{
				p=p->next;
			}
			t->next=p->next;
			p->next=t;
		}
	}

	void delnode(int y)
	{
		node *p=first;
		node *q=NULL;
		int i;
		int x=-1;

		if(y<1 || y>count())
		{
			return;
		}
		if(y == 1)
		{
			q=first;
			x=first->data;
			first=first->next;
			delete q;
		}
		else
		{
			for(i=0;i<y-1;i++)
			{
				q=p;
				p=p->next;
			}
			q->next=p->next;
			x=p->data;
			delete p;
		}
	}

};

int main()
{
	int a[]={1,2,3,4,5};
	llist l(a,5);
	int c;
	int x,y;

	cout<<"WELCOME TO LINKED LIST PROGRAM"<<endl;

	do
	{
		cout<<"1.Display the linked list"<<endl;
		cout<<"2.Count the number of elements"<<endl;
		cout<<"3.Inserting an element"<<endl;
		cout<<"4.Deleting an element"<<endl;
		cout<<"5.Exit"<<endl;

		cin>>c;
		switch(c)
		{
		case 1:
			l.display();
			break;
		case 2:
			cout<<"The count is: "<<l.count()<<endl;
			break;
		case 3:
			cout<<"Enter the element you want to display: ";
			cin>>x;
			cout<<"Enter the index you want to insert it to: ";
			cin>>y;
			if(y == 0)
			{
				break;
			}
			l.insert(y-1,x);
			break;
		case 4:
			cout<<"Enter the index you want to delete: ";
			cin>>x;
			l.delnode(x);
			break;
		case 5:
			cout<<"Thank you for using the program"<<endl;
			break;
		default:
			cout<<"Enter the correct choice"<<endl;
			break;
		}

	}while(c != 5);

	cout<<endl;
	return 0;
}