#include<iostream>
using namespace std;

template<class T>

class arr
{
private:
	T *a;
	int length;
	int size;
public:
	arr()
	{
		a = nullptr;
		size=0;
		length=0;
	}
	void constructarray(int s,int l)
	{
		length=l;
		size=s;
		if(length>size)
		{
			return;
		}
		else
		{
		a=new T[size];
		}
}

	~arr()
	{
		delete []a;
	}

	void display()
	{
		cout<<"Elements are: ";
		for(int i=0;i<length;i++)
		{
			cout<< a[i] <<" ";
		}

		cout<<endl;
	}

	void append(T x)
	{
		if(length<size)
		{
			a[length++]=x;
		}
	}

	void insert(int index,T x)
	{
		int i;
		if(index>=0 && index <length)
		{
			for(i=length;i>index;i--)
			{
				a[i]=a[i-1];
			}
			a[index]=x;
			length ++;
		}
	}

	void setElement(int index, T value)
    {
        if(index >= 0 && index < length)
        {
            a[index] = value;
        }
    }

    T del(int index)
    {
    	T x=0;
		if(index>=0 && index <length)
		{
			x=a[index];
			for(int i=index;i<length-1;i++)
			{
				a[i]=a[i+1];
			}
			length --;
		}
		return x;
    }

    T getElement(int index)
    {
    	if(index>=0 && index <length)
    	{	
    		return a[index];
    	}
    	return -1;
    }

    int linsearch(int key)
    {
    	int i;
		for(i=0;i<length;i++)
	{
		if(key==a[i])
		{
			return i;
		}
	}
	return -1;
    }

    T Max()
	{
		T max=a[0];
		int i;
		for(i=1;i<length;i++)
		{
			if(a[i]>max)
			{
				max=a[i];
			}
	}
	return max;
	}

	T Min()
	{
		T min=a[0];
		int i;
		for(i=1;i<length;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
		}
	}
		return min;
	}

	T sum()
	{
		T count=0;
		int i;
		for(i=0;i<length;i++)
	{
		count=count + a[i];
	}
	return count;
	}

	float avg()
	{
		return ((float)sum()/length);
	}

};

int main()
{
	arr<int> a1;
	int x,y,z;
	int value;
	int a,q;
	float c;

	cout<<"Enter size of the array: ";
	cin>>x;

	cout<<"Enter the length of the array: ";
	cin>>y;

	a1.constructarray(x,y);
	cout<<"Enter elements of array: ";
	for (int i = 0; i < y; i++) 
	{
        cin >> value;
        a1.setElement(i,value);
    }

    do
    {
    	cout<<"1. Display"<<endl;
    	cout<<"2. Append"<<endl;
    	cout<<"3. Insert"<<endl;
    	cout<<"4. Set element at a given index"<<endl;
    	cout<<"5. Delete element at a given index"<<endl;
    	cout<<"6. get element at a given index"<<endl;
    	cout<<"7. Linear Search"<<endl;
    	cout<<"8. Max,Min,Count and Average"<<endl;
    	cout<<"9. Exit"<<endl;

    	cout<<endl;

    	cout<<"Enter your choice: ";
    	cin>>a;
    	switch(a)
    	{
    	case 1:
    		a1.display();
    		break;
    	case 2:
    		cout<<"Enter the element to append: ";
    		cin>> q;
    		a1.append(q);
    		break;
    	case 3:
    		cout<<"Enter the index the value should be inserted on: ";
    		cin>>q;
    		cout<<"Enter the value to be inserted in that index: ";
    		cin>>value; 
    		a1.insert(q,value);
    		break;
    	case 4:
    		cout<<"Enter the index the value should be set on: ";
    		cin>>q;
    		cout<<"Enter the value of the index: ";
    		cin>>value;
    		a1.setElement(q,value);
    		break;
    	case 5:
    		cout<<"Enter the index the value should be deleted from: ";
    		cin>>q;
    		x=a1.del(q);
    		cout<<"Value "<<x<<" is deleted";
    		break;
    	case 6:
    		cout<<"Enter the index the we should get the value from: ";
    		cin>>q;
    		x=a1.getElement(q);
    		cout<<"The element is: "<<x<<endl;
    		break;
    	case 7:
    		cout<<"Enter the key to be found: ";
    		cin>>q;
    		x=a1.linsearch(q);
    		cout<<"Element found at index "<<x<<endl;
    		break;
    	case 8:
    		z=a1.Max();
    		x=a1.Min();
    		y=a1.sum();
    		c=a1.avg();
    		cout<<"Sum is: "<<y<<endl;
    		cout<<"Max element is: "<<z<<endl;
    		cout<<"Min element is: "<<x<<endl;
    		cout<<"Average of the array: "<<c<<endl;
    		break;
	case 9:
		cout<<"Exiting"<<endl;
		break;
    	default:
    		cout<<"Wrong choice entered";
    		break;
    	}
    }while(a != 9);
	
	return 0;
}
