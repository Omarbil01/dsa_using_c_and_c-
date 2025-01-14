#include<iostream>
using namespace std;

class ldiag
{
private:
	int n;
	int *a;
public:
	ldiag()
	{
		n=2;
		a=new int[n*(n+1)/2];
	}

	ldiag(int n)
	{
		this->n=n;
		a=new int[n*(n+1)/2];
	}

	~ldiag()
	{
		delete []a;
	}

	void set(int i, int j, int x)
	{
		if(i>=j)
		{
			a[(i*(i+1)/2)+j]=x;
		}
	}

	void display()
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i>=j)
				{
					cout<<a[(i*(i+1)/2)+j]<<" ";
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
	ldiag d(y); //object of class

	cout<<"Enter the values: "<<endl;
	for(i=0;i<y;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(i >= j)
			{
				cin>>x;
				d.set(i,j,x);
			}
		}
	}

	d.display();

	return 0;
}