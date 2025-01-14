#include<iostream>
using namespace std;

class tdiag
{
private:
	int n;
	int *a;
public:
	tdiag()
	{
		n=2;
		a=new int[3*n-2];
	}

	tdiag(int n)
	{
		this->n=n;
		a=new int[3*n-2];
	}

	~tdiag()
	{
		delete []a;
	}

	void set(int i, int j, int x)
	{
		if(abs(i-j)<=1)
		{
			a[i*n +j]=x;
		}
	}

	void display()
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(abs(i-j)<=1)
				{
					cout<<a[i*n +j]<<" ";
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
	tdiag d(y); //object of class

	cout<<"Enter the values: "<<endl;
	for(i=0;i<y;i++)
	{
		for(j=0;j<y;j++)
		{
			if(abs(i-j) <= 1)
			{
				cin>>x;
				d.set(i,j,x);
			}
		}
	}

	d.display();

	return 0;
}