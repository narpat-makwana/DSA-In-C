#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

void main()
{
    int ch,val;
    NODE *top,*temp;
    NODE * Init(NODE *);
    NODE * PUSH(NODE *,int);
    NODE * POP(NODE *);

    top=Init(top);

    do
    {
        printf("****Menu for Stack****\n");
        printf("1.Push into stack \n");
        printf("2.Pop from Stack \n");
        printf("3.Peak \n");
        printf("4.Display the stack\n");
        printf("5.Exit");

        printf("\n Enter your choice from above list: ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1: //Push:
                printf("\n Enter the value to be Push: ");
                scanf("%d",&val);
                top = PUSH(top, val);
                printf("\n The %d is Pushed Successfully..",val);

            break;
        
        case 2: //POP
                if(top == NULL)
                {
                    printf("\n Can't POP bcoz stack is Empty..Stack is Underflow..\n\n");

                }
                else
                {
                    top = POP(top);
                }
                break;
            
        case 3: //Peak
                if(top == NULL)
                {
                    printf("\n Stack is Empty..\n\n");

                }
                else
                {
                    printf("\n %d element is present at the top of the stack..\n\n",top->data);
                }
                break;

        case 4: //Display
                if(top == NULL)
                {
                    printf("\n Can't display... Stack is Empty..\n\n");

                }
                else
                {
                    for(temp = top;temp!=NULL ;temp=temp->next)
                    {
                        printf("\n %d",temp->data);
                    }     
                }   

        case 5: exit(0);
            break;
        
        default:
                printf("\n Enter the valid chice from above list!...\n\n");
            break;
        }        
    } while (ch!=5);
    
}

NODE * Init(NODE *top)
{
    top = NULL;
    return top;
}

NODE * PUSH(NODE *top, int val)
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = val;
    newnode->next = top;
    top  = newnode;
    return top;

}

NODE * POP(NODE *top)
{
    int val;
    NODE *temp;
    temp = top;
    val = temp ->data;
    top = top->next;
    printf("\n %d is Poped successfully...\n\n",val);
    
    free(temp);
    return top;
}