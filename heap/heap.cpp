#include <iostream>
using namespace std;


void swap(int a[], int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

void heapify(int a[], int n)
{
    for(int i=(n/2)-1; i>=0; i--) 
    {
        int j=2*i+1; 
        while(j<n)
        {
            if(j+1<n && a[j]<a[j+1])
            {
                j += 1; 
            }

            if(a[i]<a[j])
            {
                swap(a,i,j);
                i=j;
                j=2*i+1;
            }
            else
            {
                break;
            }
        }
    }
}

int remove(int a[], int n)
{
	int i,j,x,temp,val;
	val=a[1];
	x=a[n];
	a[1]=a[n];
	a[n]=val;

	i=1;
	j=i*2;

	while(j<=n-1)
	{
		if(j<n-1 && a[j+1]>a[j])
		{
			j=j+1;
	   	}
		if(a[i]<a[j])
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i=j;
			j=2*j;
		}
		else
		{
			break;
		}
	}
		return val;

	}

	void print(int a[],int n)
	{
		cout<<"Heap array: ";
		for(int i=0;i<n;i++)
		{
			cout<< a[i] << " ";
		}
		cout<<endl;
	}


int main()
{
	cout<<"WELCOME TO HEAP PROGRAM"<<endl;
	int a[20]={5,10,30,20,35,40,15};
	int n=7;
	int x;

	heapify(a,n);

	cout<<"After creation: "<<endl;
	print(a,n);
	cout<<endl;

	remove(a,n);

	cout<<"After removing: "<<endl;
	print(a,n);
	cout<<endl;

	return 0;
}