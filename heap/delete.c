#include <stdio.h>

void insert(int a[],int n)
{
    int i=n;
    int temp;
    temp=a[i];

    while(i>1 && temp>a[i/2])
    {
        a[i]=a[i/2];
        i /= 2;
    }   
    a[i]=temp;
}

int delete(int a[],int n)
{
    int i,j,x;
    int temp;
    int val=a[1];
    x=a[n];
    a[1]=a[n];
    a[n]=val;

    i=1;
    j=2*i;

    while(j<=n - 1)
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

int main()
{
    int a[]={0,10,20,30,25,5,40,35,0};

    for(int i=1;i<=7;i++)
    {
        insert(a,i);
    }

    printf("Displaying: \n");
    for(int i=1;i<=7;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    printf("Deleted value: %d\n",delete(a,7));

    return 0;
}