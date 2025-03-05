#include <iostream>
#include "tree.h"

using namespace std;

class tree
{
public:
	node * root;

	tree()
	{
		root=NULL;
	}

	void create()
	{
		node *p;
		node *r;
		int x;
		queue q(100);

		cout<<"Enter the value of the root: ";
		cin>>x;
		root=new node;
		root->data=x;
		root->lchild=NULL;
		root->rchild=NULL;
		q.enqueue(root);

		while(!q.isEmpty())
		{
			p=q.dequeue();
			cout<<"Enter the value of left child of " <<p->data<<" (Enter -1 if no value): ";
			cin>>x;

			if(x != -1)
			{
				r=new node;
				r->data=x;
				r->lchild=NULL;
				r->rchild=NULL;
				p->lchild=r;
				q.enqueue(r);
			}

			cout<<"Enter the value of right child of " <<p->data<<" (Enter -1 if no value): ";
			cin>>x;

			if(x != -1)
			{
				r=new node;
				r->data=x;
				r->lchild=NULL;
				r->rchild=NULL;
				p->rchild=r;
				q.enqueue(r);

			}
		}
	}

	~tree()
	{
		deletetree(root);
	}

	void deletetree(node *p)
	{
		if(p == NULL)
		{
			return;
		}
		deletetree(p->lchild);
		deletetree(p->rchild);
		delete p;
	}

	void preorder(node *p)
	{
    	if (p != NULL) 
    	{
        	cout << p->data << " ";
        	preorder(p->lchild);
        	preorder(p->rchild);
    	}
	}

	void preorder()
	{
		preorder(root);
	}

	void inorder(node *p)
	{
		if(p != NULL)
		{
			inorder(p->lchild);
			cout<<p->data<<" ";
			inorder(p->rchild);
		}
	}

	void inorder()
	{
		inorder(root);
	}

	void postorder(node *p)
	{
		if(p != NULL)
		{
			postorder(p->lchild);
			postorder(p->rchild);
			cout<<p->data<<" ";
		}
	}

	void postorder()
	{
		postorder(root);

	}

	int height(node *p)
	{
		int x=0;
		int y=0;

		if(p == 0)
		{
			return 0;
		}

		x=height(p->lchild);
		y=height(p->rchild);

		if(x>y)
		{
			return x + 1;
		}
		else
		{
			return y + 1;
		}
	}

	int height()
	{
		return height(root);
	}
	
};

int main()
{
	cout<<"WELCOME TO TREE PROGRAM"<<endl;
	int choice;
	int x;

	tree t;
	t.create();

	do
	{
		cout<<"1.Preorder Traversal"<<endl;
		cout<<"2.Inorder Traversal"<<endl;
		cout<<"3.Postorder Traversal"<<endl;
		cout<<"4.Height of the tree"<<endl;
		cout<<"5.Exit"<<endl;

		cout<<"Enter your choice: ";
		cin>>choice;

		switch(choice)
		{
		case 1:
			cout<<"Preorder traversal: "<<endl;
			t.preorder(t.root);
			cout<<endl;
			break;

		case 2:
			cout<<"Inorder traversal: "<<endl;
			t.inorder(t.root);
			cout<<endl;
			break;

		case 3:
			cout<<"Postorder traversal: "<<endl;
			t.postorder(t.root);
			cout<<endl;
			break;

		case 4:
			x=t.height(t.root);
			cout<<"Height is: "<<x<<endl;
			break;

		case 5:
			cout<<"Thank you"<<endl;
			break;

		default:
			cout<<"Enter a valid choice"<<endl;
			break;
		}
	}while(choice != 5);
	return 0;
}
