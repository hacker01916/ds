#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[30];
    char phone[15];
    struct node *left, *right;
};

struct node* insert(struct node *root, char name[], char phone[])
{
    if(root == NULL)
    {
        root = (struct node*)malloc(sizeof(struct node));

        strcpy(root->name, name);
        strcpy(root->phone, phone);

        root->left = root->right = NULL;
        return root;
    }

    if(strcmp(name, root->name) < 0)
        root->left = insert(root->left, name, phone);
    else
        root->right = insert(root->right, name, phone);

    return root;
}

void display(struct node *root)
{
    if(root != NULL)
    {
        display(root->left);
        printf("%s : %s\n", root->name, root->phone);
        display(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    int n, i;
    char name[30], phone[15];

    printf("Enter number of contacts: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter name and phone: ");
        scanf("%s %s", name, phone);

        root = insert(root, name, phone);
    }

    printf("\nPhonebook:\n");
    display(root);

    return 0;
}