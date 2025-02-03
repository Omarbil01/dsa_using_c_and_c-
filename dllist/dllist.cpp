#include <iostream>
using namespace std;

class node
{
public:
	node *prev;
	int data;
	node *next;
};

class dllist
{
private:
	node *first;
public:
	dllist()
	{
		first=NULL;
	}

	dllist(int a[],int n)
	{
		node *t,*last;
		int i;

		first=new node;
		first->data=a[0];
		first->prev=first->next=NULL;
		last=first;

		for(i=1;i<n;i++)
		{
			t=new node;
			t->data=a[i];
			t->prev=last;
			t->next=NULL;

			last->next=t;
			last=t;
		}
	}

	~dllist()
	{
		node *q;
		node *p=first;

		while(p != NULL)
		{
			q=p;
			p=p->next;
			free(q);
		}
		first=NULL;
	}

	void display()
	{
		node *p=first;
		while(p!= NULL)
		{
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n");
	}

	int len()
	{
		node *p=first;
		int l=0;
		while(p != NULL)
		{
			l++;
			p=p->next;
		} 
		return l;
	}

	void insert(int index, int x)
	{
		node *p=first;
		node *t;
		int i;

		if(index < 0 || index > len())
		{
			return;
		}

		t=new node;
		t->data=x;

		if(index == 0)
		{
			t->prev=NULL;
			t->next=first;
			if(first != NULL)
			{
				first->prev=t;
			}
			first=t;
		}
		else
		{
			for(i=0; i<index-1; i++)
			{
				p=p->next;
			}		
			t->prev=p;
			t->next=p->next;
			if(p->next != NULL)
			{
				p->next->prev=t;
			}
			p->next=t;
		}
	}

	void delnode(int index)
	{
		node *p=first;
		node *t;
		int i,x;

		if(index<=0 || index>len())
		{
			return;
		}

		if(index == 1)
		{
			first=first->next;
			if(first != NULL)
			{
				first->prev=NULL;
			}
			x=p->data;
			delete p;
		}
		else
		{
			for(i=0;i<index-1;i++)
			{
				p=p->next;
			}
			p->prev->next=p->next;
			if(p->next != NULL)
			{
				p->next->prev=p->prev;
			}
			x=p->data;
			delete p;
		}	
	}
};

int main()
{
	int a[]={1,2,3,4,5};

	dllist d1(a,5);
	int ch;
	int x,y;

	cout<<"WELCOME TO DOUBLY LINKED LIST PROGRAM "<<endl;

	do
	{
		cout<<"1.Display linked list"<<endl;
		cout<<"2.Find length of the linked list"<<endl;
		cout<<"3.Insert new node at the list"<<endl;
		cout<<"4.Delete existing node"<<endl;
		cout<<"5.Exit"<<endl;

		cin>>ch;

		switch(ch)
		{
		case 1:
			d1.display();
			break;

		case 2:
			cout<<"The length is: "<<d1.len()<<endl;
			break;

		case 3:
			cout<<"Enter the index to add the node: ";
			cin>>x;
			cout<<"Enter the value of the node: ";
			cin>>y;

			d1.insert(x,y);
			break;

		case 4:
			cout<<"Enter the index you want to delete: ";
			cin>>x;
			d1.delnode(x);
			break;

		case 5:
			cout<<"Thank you for using the program";
			break;

		default:
			cout<<"Wrong choice entered"<<endl;
			break;
		}
	}while(ch != 5);

	cout<<endl;
	return 0;
}