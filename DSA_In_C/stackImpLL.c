//WAP to implement stack dynamically
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

void main()
{
    int ch, val;
    NODE *top, *temp;
    NODE *Init(NODE *);      //declaration
    NODE *Push(NODE *, int); //declaration
    int IsEmpty(NODE *);     //declaration
    NODE *Pop(NODE *);       //declaration
    top = Init(top);         //call

    do
    {
        printf("\n\n********MENU for STACK *******");
        printf("\n 1. Push");
        printf("\n 2. Pop");
        printf("\n 3. Display");
        printf("\n 4. Peek");
        printf("\n 5. Exit");

        printf("\n\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: //Push
            printf("\n Enter value to be push in stack: ");
            scanf("%d", &val);
            top = Push(top, val); //call
            printf("\n%d element pushed in stack...\n", val);
            break;

        case 2: //Pop
            if (IsEmpty(top))
            {
                printf("\n Can't pop b'coz stackis empty..\n");
            }

            else
            {
                top = Pop(top); //call
            }
            break;

        case 3: //Display
            if (IsEmpty(top))
            {
                printf("\n Stack is empty...\n");
            }

            else
            {
                printf("\n Content of Stack: \n");
                for (temp = top; temp != NULL; temp = temp->next)
                {
                    printf("\n%d", temp->data);
                }
            }
            break;

        case 4: //Peek

            if (IsEmpty(top))
            {
                printf("\nStack is empty...\n");
            }
            else
            {
                printf("\n %d element present at top of the stack\n", top->data);
            }
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("\nInvalid choice....\n");
        }
    } while (ch != 5);
}

//defination of user defined functions
NODE *Init(NODE *top)
{
    top = NULL;
    return top;
}

NODE *Push(NODE *top, int val)
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
    return top;
}

int IsEmpty(NODE *top)
{
    return (top == NULL);
}

NODE *Pop(NODE *top)
{
    int val;
    NODE *temp;
    temp = top;
    val = temp->data;
    top = top->next;
    printf("\n %d element poped from the stack\n", val);
    free(temp);
    return top;
}
