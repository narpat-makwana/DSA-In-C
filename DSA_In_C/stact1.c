//WAP to implement stack using array(Static implementation)
#include<stdio.h>
#include<stdlib.h>
#define SIZE 3

typedef struct stack
 {
 int data[SIZE];
 int top;
 }STACK;
 
 void main()
 {
 	STACK s;
 	void InitStack(STACK *);
 	int IsFull(STACK *);
 	void Push(STACK *, int);
 	int IsEmpty(STACK *);
 	int Pop(STACK *);
 	int ch,val,i;
 	InitStack(&s); //intitialise top to -1
 	
 	do
 	{
 		printf("\n****** STACK OPERATION*****");
 		printf("\n 1. Push element in stack");
 		printf("\n 2. Pop element from stack");
 		printf("\n 3. Peek");
 		printf("\n 4. Display content of stack");
 		printf("\n 5. Exit");
 		printf("\n Enter your choice :");
 		scanf("%d",&ch);
 		
 		switch(ch)
 		{
 		
	 		case 1:// 
	 		Pushif(!IsFull(&s))
	 		{
	 			printf("\n Enter the value to be insert in stack: ");
	 			scanf("%d",&val);
	 			Push(&s, val);
	 		}
	 		else
	 		{
	 			printf("\nStack is full...\n");
	 		}break;
	 		
	 		case 2://
	 		Popif(!IsEmpty(&s))
	 		{
	 			val=Pop(&s);
	 			printf("\n %d element poped from the stack..\n",val);
	 		}
	 		
	 		else
	 		{
	 			printf("\n Stack is empty....\n");
	 		}
	 		break;
	 		
	 		case 3://
	 		Peek (top)if(!IsEmpty(&s))
	 		{
	 			printf("\n %d is present at the top of stack\n",s.data[s.top]);
	 		}
	 		else
	 		{
	 			printf("\nStack is empty...\n");
	 		}
	 		
	 		break;
	 		
	 		case 4://
	 		displayif(!IsEmpty(&s))
	 		{
	 			printf("\n Content of stack is:\n");
	 			
	 			for(i=s.top; i>=0 ;--i)
	 			{
	 				printf("\n %d",s.data[i]);
	 			}
	 		}
	 		
	 		else
	 		{
	 			printf("\n Stack is empty...\n");
			}
			break;
			
			case 5:
				 exit(0);
				 break;
			
			default :
				 printf("\n Invalid choice....\n");
		}
	}while(ch!=5);
	
}

	int Pop(STACK *s)
	{
		int val;
		val=s->data[s->top];
		s->top--;
		return val;//return(s->data[s->top--]);
	}
	
	void InitStack(STACK *s)
	{
		s->top = -1;
		
	}
	
	int IsFull(STACK *s)
	{
		return(s->top == SIZE -1); 
		
		/*if(s->top == SIZE -1)
		{
			return 1;
		}
		
		else
		{
			return 0;
		}*/
		
	}
	
	int IsEmpty(STACK *s)
	{
		return (s->top == -1);
		
		/*if(s->top == -1)
		{
		
			return 1;
		
		}
		
		else
		{
			return 0;
			
		}*/
	}
	
	void Push(STACK *s, int val)
	{
		s->top ++;
		s->data[s->top]=val;
		//s->data[++s->top]= val;
		printf("\n %d pushed in stack...\n",val);
	}
