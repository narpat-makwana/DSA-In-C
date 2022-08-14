//WAP to create and display doubly linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} NODE;
void main()
{
    int ch;
    NODE *start = NULL;
    NODE *CreateList(NODE *);
    void Display(NODE *);
    void FindLength(NODE *);
    do
    {
        printf("\n\n******MENU*****\n");
        printf("\n--------------------\n");
        printf("\n 1. Create Doubly Linked List");
        printf("\n 2. Display List");
        printf("\n 3. Length of list");
        printf("\n 4. Exit");
        printf("\n\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: //Create
            if (start == NULL)
            {
                start = CreateList(start);
                printf("\n List created successfully....");
            }
            else
            {
                printf("\n List is already exist....");
            }
            break;
        case 2: //display
            if (start == NULL)
            {
                printf("\n Create list first...");
            }
            else
            {
                Display(start);
            }
            break;
        case 3: //length
            if (start == NULL)
            {
                printf("\n Linked list is not created...");
            }
            else
            {
                FindLength(start);
            }
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\n Invalid choice....");
        }
    } while (ch != 4);
}
void FindLength(NODE *start)
{
    NODE *temp;
    int cnt;
    for (temp = start, cnt = 0; temp != NULL; temp = temp->next, cnt++)
        ;
    printf("\n Length of the linked list = %d", cnt);
}
NODE *CreateList(NODE *start)
{
    int i, n;
    NODE *temp, *newnode;
    printf("\n Enter how many node u want to create: ");
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        newnode = (NODE *)malloc(sizeof(NODE));
        newnode->next = NULL;
        newnode->prev = NULL;
        printf("\n Enter data for node %d: ", i + 1);
        scanf("%d", &newnode->data);
        if (start == NULL)
        {
            start = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    return start;
}
void Display(NODE *start)
{
    NODE *temp;
    printf("\n Data of doubly linked list is :");
    for (temp = start; temp != NULL; temp = temp->next)
    {
        printf("%3d", temp->data);
    }
}