//Write menu driven program to insert node in the linked list
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
    int ch, pos, ichoice;
    NODE *start = NULL;
    NODE *CreateList(NODE *, int n);
    void Display(NODE *);
    NODE *InsertNode(NODE *, int pos);
   
    do
    {
        printf("\n\n**********MENU*********\n\n");
        printf("\n 1. Create List");
        printf("\n 2. Display");
        printf("\n 3. Insert Node");
        printf("\n 4. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch)
        {
            case 1: //create List
            printf("\n Enter how many node u want to create:");
            scanf("%d", &n);
            start = CreateList(start,n);
            break;

            case 2 : //Display
            if(NULL == start)
            {
                printf("\n Please Create List first....");
            }   
            else
            {
                printf("\n\nList is : ");
                Display(start);
            }
            break; 

            case 3 ://insert node
            if(NULL == start)
            {
                printf("\n Please Create List first....");
            }
            else
            {
                printf("\n****** Positions for Insert*****\n");
                printf("\n 1. Insert node at the begining");
                printf("\n 2. Insert node at the end ");
                printf("\n 3. Insert node in between the list");
                printf("\n Enter your choice for insert: ");
                scanf("%d",&ichoice);
            
                switch(ichoice)
                {
                    case 1: //insert at the start
                        start = InsertNode(start, 1);
                        break;

                    case 2: // insert at the end
                        start = InsertNode(start, n + 1);
                        break;

                    case 3: //insert in between
                    printf("\n Enter the position where you have to insert the node: ");
                    scanf("%d",&pos);
                
                    if(pos >n+1)
                    {
                        printf("\n position out of range....");
                    }

                    else
                    {
                        start = InsertNode(start, pos);
                    }
                    break;
                    default : printf("\n Invalid choice for insert node operation");
                }
            }
            break;       
            
            case 4 :exit(0);
            default: printf("\n Invalid choice....");
        }
    } while (ch != 4);
}


NODE *InsertNode(NODE *start, int pos)
{
    int i;
    NODE *newnode, *temp;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->next = NULL;
    printf("\n Enter data for newnode :");
    scanf("%d", &newnode->data);
    
    if (pos == 1) //begining
    {
        newnode->next = start;
        start = newnode;
    }
    
    else if (pos == n + 1) //end
    {
        for (temp = start; temp->next != NULL; temp = temp->next)
        temp->next = newnode;
    }
    
    else //in between
    {
        for (i = 1, temp = start; i < pos - 1; i++, temp = temp->next)
        newnode->next = temp->next;
        temp->next = newnode;
    }
    n++;
    printf("\n Node inserted successfully....");
    return start;
}


NODE *CreateList(NODE *start, int n)
{
    struct node *temp, *newnode;
    int i;
    for (i = 0; i < n; ++i)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        printf("\n Enter data for %d node: ", i + 1);
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