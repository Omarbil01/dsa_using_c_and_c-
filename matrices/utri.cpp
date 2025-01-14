#include<iostream>
using namespace std;

class udiag
{
private:
	int n;
	int *a;
public:
	udiag()
	{
		n=2;
		a=new int[n*(n+1)/2];
	}

	udiag(int n)
	{
		this->n=n;
		a=new int[n*(n+1)/2];
	}

	~udiag()
	{
		delete []a;
	}

	void set(int i, int j, int x)
	{
		if(i<=j)
		{
			a[(i*n-(i*(i+1)/2))+(j-i)]=x;
		}
	}

	void display()
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i<=j)
				{
					cout<<a[(i*n-(i*(i+1)/2))+(j-i)]<<" ";
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
	udiag d(y); //object of class

	cout<<"Enter the values: "<<endl;
	for(i=0;i<y;i++)
	{
		for(j=i;j<y;j++)
		{
			if(i <= j)
			{
				cin>>x;
				d.set(i,j,x);
			}
		}
	}

	d.display();

	return 0;
}