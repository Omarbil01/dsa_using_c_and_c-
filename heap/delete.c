#include <stdio.h>

void insert(int a[], int *n, int key)
{
    int i = *n;
    a[i] = key;
    (*n)++;

    while(i >= 1 && a[i] > a[(i-1)/2])
    {
        int temp = a[i];
        a[i] = a[(i-1)/2];
        a[(i-1)/2] = temp;

        i = (i-1)/2;
    }   
}

int delete(int a[], int n)
{
    int i, j, x, temp, val;
    val = a[1];  
    x = a[n];   
    a[i] = a[n]; 

    i = 1;
    j = i * 2;

    while(j < n-1)
    {
        if(a[j+1] > a[j])
        {
            j = j+1;
        }

        if(a[i] < a[j])
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
        {
            break;
        }
    }
    return val;
}

void display(int a[], int n)
{
    printf("Max heap: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[] = {0, 2, 5, 8, 9, 4, 10, 7};
    int n = 8;

    int key = 48;
    insert(a, &n, key);

    printf("Deleted value is %d\n", delete(a, 8));

    printf("Displaying: \n");
    display(a, n);
    
    return 0;
}