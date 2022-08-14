#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

} NODE;
int n;

void main()
{
    int ch;
    NODE *start = NULL;

    NODE *CreateLL(NODE * start, int n);

    void DisplayLL(NODE * start);

    do
    {
        printf("\n\n\n****MENU****\n\n\n");
        printf("\n 1.Create List..");
        printf("\n 2.Display List");
        printf("\n 3.EXIT");

        printf("\n Enter your Choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1: //Creation of List
            printf("\n Enter how many nodes you want to create:");
            scanf("%d", &n);
            start = CreateLL(start, n);

            break;

        case 2: //Display List
            if (NULL == start)
            {
                printf("\n Create List first:");
            }

            else
            {
                printf("\n List is ...\n");
                DisplayLL(start);
            }
            break;
        default:
            printf("\n Invalid choice..");
            break;
        }
    } while (ch != 3);
}

NODE *CreateLL(NODE *start, int n)
{
    NODE *newnode, *temp;

    for (int i = 0; i < n; ++i)
    {
        newnode = (NODE *)malloc(sizeof(struct node));
        newnode->next = NULL;
        printf("\n Enter the data for %d Node", i + 1);
        scanf("%d", &newnode->data);

        if (NULL == start)
        {
            start = temp = newnode;
        }

        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
return start;
}

void DisplayLL(NODE *start)
{
    NODE *temp;
    for (temp = start; temp != NULL; temp = temp->next)
    {
        printf("\t%d", temp->data);
    }
}
