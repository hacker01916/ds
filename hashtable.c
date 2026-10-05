#include <stdio.h>

#define SIZE 10

int hash[SIZE];

void insert(int key)
{
    int index, i;

    index = key % SIZE;

    for(i = 0; i < SIZE; i++)
    {
        int pos = (index + i * i) % SIZE;

        if(hash[pos] == -1)
        {
            hash[pos] = key;
            printf("Key inserted\n");
            return;
        }
    }

    printf("Hash table is full\n");
}

void search(int key)
{
    int index, i;

    index = key % SIZE;

    for(i = 0; i < SIZE; i++)
    {
        int pos = (index + i * i) % SIZE;

        if(hash[pos] == key)
        {
            printf("Key found at index %d\n", pos);
            return;
        }

        if(hash[pos] == -1)
            break;
    }

    printf("Key not found\n");
}

void display()
{
    int i;

    printf("\nHash Table:\n");

    for(i = 0; i < SIZE; i++)
        printf("%d : %d\n", i, hash[i]);
}

int main()
{
    int choice, key, i;

    for(i = 0; i < SIZE; i++)
        hash[i] = -1;

    while(1)
    {
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice");
        }
    }
}