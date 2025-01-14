#include<iostream>
using namespace std;

class diag
{
private:
	int n;
	int *a;
public:
	diag()
	{
		n=2;
		a=new int[n];
	}

	diag(int n)
	{
		this->n=n;
		a=new int[n];
	}

	~diag()
	{
		delete []a;
	}

	void set(int i, int j, int x)
	{
		if(i==j)
		{
			a[i-1]=x;
		}
	}

	void display()
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
				{
					cout<<a[i]<<" ";
				}
				else
				{
					cout<<"0 ";
				}
			}
			cout<<endl;
		}

	}
};

int main()
{
	int i,j;
	int x,y;

	cout<<"Enter the size of the matrix: ";
	cin>>y;
	diag d(y); //object of class

	cout<<"Enter the values: "<<endl;
	for(i=1;i<=y;i++)
	{
		for(j=1;j<=y;j++)
		{
			if(i == j)
			{
				cin>>x;
				d.set(i,j,x);
			}
		}
	}

	d.display();

	return 0;
}