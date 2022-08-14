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

    int ch, ich, pos;
    NODE *start = NULL;
    NODE *CreateList(NODE *, int n);
    void Display(NODE *);
    NODE *InsertNode(NODE *, int pos);

    do
    {
        printf("\n\n *****MENU*****\n\n");
        printf("\n 1.Create List");
        printf("\n 2.Display List");
        printf("\n 3.Insert node into SLL");
        printf("\n 4.Exit");

        printf("\n\n Enter your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1: //Create List
            printf("\n Enter how many Nodes You want to create:");
            scanf("%d", &n);

            start = CreateList(start, n);
            break;

        case 2: //Display List
            if (NULL == start)
            {
                printf("\n Plz Create List First !!..");
            }

            else
            {
                printf("\n\n List is ...  ");
                Display(start);
            }
            break;

        case 3: //insert
            if (NULL == start)
            {
                printf("\n Create list first...");
            }
            else
            {
                printf("\n\n ****Select Position for Insert****\n\n");
                printf("\n 1.In The Begining..");
                printf("\n 2.At The End");
                printf("\n 3.In Between");

                printf("\n Enter your from above Menu..");
                scanf("%d", &ich);

                switch (ich)
                {
                case 1: //In the begining
                    start = InsertNode(start, 1);
                    break;

                case 2: //End
                    start = InsertNode(start, n + 1);
                    break;
                case 3: //In Between
                    printf("\n Enter the position for Insert...");
                    scanf("%d", &pos);

                    if (pos > n + 1)
                    {
                        printf("\n Position is out of range..");
                    }
                    else
                    {
                        start = InsertNode(start, pos);
                    }
                    break;

                default:
                    printf("\n Invalid Choice for insert of node...");
                    break;
                }
            }
            break;
        case 4:
            exit(0);

        default:
            printf("\n Invalid Choice..Plz Enter Valid choice from above Menu..");

            break;
        }

    } while (ch != 4);
}

NODE *CreateList(NODE *start, int n)
{
    NODE *temp, *newnode;

    for (int i = 0; i < n; ++i)
    {
        newnode = (NODE *)malloc(sizeof(struct node));
        newnode->next = NULL;
        printf("\nEnter data for %d node:", i + 1);
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

void Display(NODE *start)
{
    NODE *temp;

    for (temp = start; temp != NULL; temp = temp->next)
    {
        printf("%4d", temp->data);
    }
}

NODE *InsertNode(NODE *start, int pos)
{
    int i;
    NODE *newnode, *temp;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->next = NULL;
    printf("\n Enter the data for the new node: ");
    scanf("%d", &newnode->data);

    if (pos == 1) //Begining
    {
        newnode->next = start;
        start = newnode;
    }

    else if (pos == n + 1) //End
    {
        for (temp = start; temp->next != NULL; temp = temp->next)
            ;
        temp->next = newnode;
    }

    else //I between
    {
        for (i = 1, temp = start; i < pos - 1; i++,temp = temp->next)
            ;
        newnode->next = temp->next;
        temp->next = newnode;
    }
    n++;
    printf("\n Node Inserted successfully...");
    return start;
}
