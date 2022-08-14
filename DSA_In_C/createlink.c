#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkListTrav(struct Node *ptr);
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth =(struct Node *)malloc(sizeof(struct Node));

    //link 1st and 2nd nodes
    head->data = 7;
    head->next = second;

    //link 2nd and 3rd nodes
    second->data = 11;
    second->next = third;

    //link 3rd and 4th
    third->data = 41;
    third->next = fourth;

    //terminate list at 4th
    fourth->data = 66;
    fourth->next = NULL;

    linkListTrav(head);
    return 0;
}

void linkListTrav(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
/*
struct Node
{
    int data;
    struct Node *next;
};

void linkListTrav(struct Node *ptr);

int main()
{
    //declaration
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Nodn *fourth;

    //Memory Allocation

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    //linking Nodes
    head -> data = 11;
    head -> next = second;

    second -> data = 48;
    second -> next = third;

    third -> data = 55;
    third -> next = fourth;

    fourth -> data = 67;
    fourth -> next = NULL;

    linkListTrav(head);
    return 0;

}

void linkListTrav(struct Node * ptr)
{
    while(ptr!= NULL)
    {
        printf("Elements: %d\n",ptr -> data);
        ptr = ptr ->next;
    }
}
*/