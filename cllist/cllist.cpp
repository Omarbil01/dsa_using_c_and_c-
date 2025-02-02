#include<iostream>
using namespace std;

class node 
{
public:
    int data;
    node *next;
};

class cllist 
{
private:
    node *first;
public:
    cllist() 
    {
        first = NULL;
    }

    cllist(int a[], int n) 
    {
        int i;
        node *t, *last;

        first = new node;
        first->data = a[0];
        first->next = first;
        last = first;

        for (i = 1; i < n; i++) 
        {
            t = new node;
            t->data = a[i];
            t->next = last->next;
            last->next = t;
            last = t;
        }
    }

    ~cllist() 
    {
        if (first == NULL) 
        {
            return;
        }

        node *temp = first;
        do 
        {
            node *nn = temp->next;
            delete temp;
            temp = nn;
        } while (temp != first);

        first = NULL;
    }

    void display() 
    {
        if (first == NULL) 
        {
        	return;
        }
        
        node *p = first;
        do 
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != first);
        
        cout << endl;
    }

    int length() 
    {
        if (first == NULL)
        { 
        	return 0;
        }

        node *p = first;
        int len = 0;
        do 
        {
            len++;
            p = p->next;
        } while (p != first);
        
        return len;
    }

    void insert(int index, int x) 
    {
        if (index < 0 || index > length()) 
        {
            return;
        }

        node *t = new node;
        t->data = x;

        if (index == 0) 
        {
            if (first == NULL) 
            { 
                first = t;
                t->next = first;
            } 
            else 
            { 
                node *p = first;
                while (p->next != first) 
                {
                    p = p->next;
                }
                p->next = t;
                t->next = first;
                first = t;
            }
        } 
        else 
        { 
            node *p = first;
            for (int i = 0; i < index - 1; i++) 
            {
                p = p->next;
            }
            t->next = p->next;
            p->next = t;
        }
    }

    void delnode(int index) 
    {
        if (index <= 0 || index > length()) 
        {
            return;
        }

        node *p = first;
        if (index == 1) 
        {
            while (p->next != first) 
            {
                p = p->next;
            }
            if (first == p) 
            { 
                delete first;
                first = NULL;
            } 
            else 
            {
                p->next = first->next;
                delete first;
                first = p->next;
            }
        } 
        else 
        {
            node *q = NULL;
            for (int i = 0; i < index - 2; i++) 
            {
                p = p->next;
            }
            q = p->next;
            p->next = q->next;
            delete q;
        }
    }
};

int main() 
{
    int arr[] = {1, 2, 3, 4, 5};
    cllist cl(arr, 5);
    int ch;
    int x,y;

    cout<<"WELCOME TO CIRCULAR LINKED LIST PROGRAM "<<endl;

    do
    {
    	cout<<"1. Display "<<endl;
    	cout<<"2. Length of linked list "<<endl;
    	cout<<"3. Insert linked list "<<endl;
    	cout<<"4. Delete linked list "<<endl;
    	cout<<"5. Exit "<<endl;

    	cin>>ch;

    	switch(ch)
    	{
    	case 1:
    		cl.display();
    		break;
    	case 2:
    		cout<<"The length is: "<<cl.length()<<endl;
    		break;
    	case 3:
    		cout<<"Enter the element you want to insert: ";
			cin>>x;
			cout<<"Enter the index you want to insert it to: ";
			cin>>y;
			if(y == 0)
			{
				break;
			}
			cl.insert(y-1,x);
			break;
		case 4:
			cout<<"Enter the index you want to delete: ";
			cin>>x;
			cl.delnode(x);
			break;
		case 5:
			cout<<"Thnak you for using the program"<<endl;
			break;
		default:
			cout<<"Enter the correct choice "<<endl;
			break;
    	}
    }while(ch != 5);

    cout<<endl;
    return 0;
}
