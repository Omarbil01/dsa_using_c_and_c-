#include<iostream>
using namespace std;

class node
{
private:
	node *lchild;
	int data;
	node *rchild;

public:
	node *root=NULL;

	void insert(int key)
	{
		node *t=root;
		node *r=NULL;
		node *p;

		p=new node;
		p->data=key;
		p->lchild=NULL;
		p->rchild=NULL;

		if(root == NULL)
		{
			root=p;
			return;
		}

		while(t != NULL)
		{
			r=t;

			if(key < t->data)
			{
				t=t->lchild;
			}

			else if(key > t->data)
			{
				t=t->rchild;
			}

			else
			{
				return;
			}
		}

		
			if(key < r->data)
			{
				r->lchild=p;
			}

			else
			{
				r->rchild=p;
			}
		
	}

	~node() 
	{    
        deleteSubtree(root);
    }

    void deleteSubtree(node* p) 
    {
        if (p != NULL) 
        {   
            deleteSubtree(p->lchild);
            deleteSubtree(p->rchild);
            delete p;
        }
    }

	void inorder(node *p)
	{
		//gives sorted order of element
		if(p != NULL)
		{
			inorder(p->lchild);
			cout<<p->data<<" ";
			inorder(p->rchild);
		}
	}

	node * search(int key)
	{
		node *p=root;

		while(p != NULL)
		{
			if (key == p->data)
			{
				return p;
			}

			else if(key<p->data)
			{
				p=p->lchild;
			}

			else
			{
				p=p->rchild;
			}
		}
		return NULL;
	}

	int height(node *p)
	{
		int x,y;
		if(p == NULL)
		{
			return 0;
		}

		x=height(p->lchild);
		y=height(p->rchild);

		if(x>y)
		{
			return x+1;
		}

		else
		{
			return y+1;
		}
	}


	node *inpre(node *p)
	{
		while(p != NULL && p->rchild != NULL)
		{
			p=p->rchild;
		}
		return p;
	}

	node *insuc(node *p)
	{
		while(p != NULL && p->lchild != NULL)
		{
			p=p->lchild;
		}
		return p;
	}

	node *del(node *p,int x)
	{
		node *q;
		if(p == NULL)
		{
			return NULL;
		}

		if(p->lchild == NULL && p->rchild == NULL)
		{
			if(p == root)
			{
				root = NULL;
			}
			free(p);
			return NULL;
		}

		if(x < p->data)
		{
			p->lchild=del(p->lchild,x);
		}

		else if(x > p->data)
		{
			p->rchild=del(p->rchild,x);
		}

		else
		{
			if(height(p->lchild)>height(p->rchild))
			{
				q=inpre(p->lchild);
				p->data=q->data;
				p->lchild=del(p->lchild,q->data);
			}

			else
			{
				q=insuc(p->rchild);
				p->data=q->data;
				p->rchild=del(p->rchild,q->data);

			}
		}
		return p;
	} 

	void deleteValue(int key)
    {
        root = del(root, key);
    }

};
 
int main()
{
	cout<<"WELCME TO BST PROGRAM "<<endl;
	int x;
	int choice;
	node tree;

	do
	{
		cout<<"1.Insert"<<endl;
		cout<<"2.Display"<<endl;
		cout<<"3.Search"<<endl;
		cout<<"4.Delete"<<endl;
		cout<<"5.Exit"<<endl;

		cout<<"Enter your choice: ";
		cin>>choice;

		switch(choice)
		{
		case 1:
			cout<<"Enter the value to insert: ";
			cin>>x;
			tree.insert(x);
			break;
		case 2:
			cout<<"Tree elements: "<<endl;
			tree.inorder(tree.root);
			break;
		case 3:
			cout<<"Enter the element to search: ";
			cin>>x;
			{
			node *ans=tree.search(x);
			if(ans == NULL)
			{
				cout<<"Element not found"<<endl;
			}
			else
			{
				cout<<"Element found"<<endl;
			}
			}
			cout<<endl;
			break;
		case 4:
			cout<<"Enter element to delete: ";
			cin>>x;
			tree.deleteValue(x);
			break;
		case 5:
			cout<<"Thank you"<<endl;
			break;
		default:
			cout<<"Enter correct choice"<<endl;
			break;
		}
	}while(choice != 5);

	return 0;
}