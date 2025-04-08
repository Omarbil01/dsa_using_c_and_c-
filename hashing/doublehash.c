#include <stdio.h>
#define SIZE 10
#define PRIME 7

int hash(int key)
{
    return key % SIZE;
}

int primehash(int key)
{
    return PRIME - (key % PRIME);
}

int doublehash(int h[], int key)
{
    int a = hash(key);
    int i = 0;
    while(h[(a + i * primehash(key)) % SIZE] != 0)
    {
        i++;
        if(i >= SIZE) 
        { 
            return -1;
        }
    }
    return (a + i * primehash(key)) % SIZE;
}

void insert(int h[], int key)
{
    int a = hash(key);
    if(h[a] != 0)
    {
        a = doublehash(h, key);
        if(a == -1) 
        {
            printf("Hash table is full, cannot insert %d\n", key);
            return;
        }
    }
    h[a] = key;
}

int search(int h[], int key)
{
    int a = hash(key);
    int i = 0;
    
    while(i < SIZE) 
    {
        int index = (a + i * primehash(key)) % SIZE;
        if(h[index] == 0) 
        {
            return -1;
        }
        if(h[index] == key)
        {  
            return index;
        }
        i++;
    }
    return -1; 
}

int main()
{
    int h[10] = {0};
    insert(h, 5);
    insert(h, 25);
    insert(h, 15);
    insert(h, 35);
    insert(h, 95);
    
    int ans = search(h, 35);
    if(ans != -1)
    {
        printf("Key found at index %d\n", ans);
    }

    else
    {
        printf("Key not found\n");
    }
        
    return 0;
}