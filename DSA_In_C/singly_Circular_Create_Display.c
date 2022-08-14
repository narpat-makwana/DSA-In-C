#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;
void main()
{
    NODE *CreateList(NODE *);
    void Display(NODE *);
    NODE *start = NULL;
    int Search(NODE *, int val);

    int ch,index,n;
    do
    {
        printf("\n\n***Perform Operation of Singly Circular List***");
        printf("\n 1. Create Linked List");
        printf("\n 2. Display");
        printf("\n 3. Search element");
        printf("\n 4. Exit");

        printf("\n\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: //create
            if (start == NULL)
            {
                start = CreateList(start);
                printf("\nSingly Circular Linked List created....\n");
            }
            else
                printf("\n Linked is already exist...\n");
            break;
        case 2: //display
            if (start == NULL)
            {
                printf("\nPlease create linked list first...\n");
            }
            else
                Display(start);
            break;

        case 3://searching
                printf("Enter element to search: ");
				scanf("%d", &n);
				index = Search(start, n);

				if (index == -1)
					printf("%d not found in list.\n", n);
				else 
                	printf("%d found at %d position.\n", n, (index + 1));
                break;
        case 4:
            exit(0);
            break;
        default:
            printf("\n Invalid Choice: \n");
        }
    } while (ch != 3);
}
NODE *CreateList(NODE *start)
{
    NODE *temp, *newnode;
    int i, n;
    printf("\n Enter how many node u want to create: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (NODE *)malloc(sizeof(NODE));
        printf("\n Enter data for node %d: ", i + 1);
        scanf("%d", &newnode->data);
        if (start == NULL)
        {
            start = temp = newnode;
            start->next = start;
        }
        else
        {
            newnode->next = start;
            temp->next = newnode;
            temp = newnode;
        }
    }
    return start;
}
void Display(NODE *start)
{
    NODE *temp = start;
    printf("\n Data of list is : ");
    do
    {
        printf("%3d", temp->data);
        temp = temp->next;
    } while (temp != start);
}

int Search(NODE *start, int val)
{
	int index = 0;
    struct node *current = start;

    do 
    {
		if (current == NULL)
			return;
		
		if (current->data == val)
			return index;

        current = current->next;
		index++;
    } while (current != val);
    
     return -1;
}
