#include<stdio.h>

int main()
{
    int age, marks;
    printf("\n Enter your age:");
    scanf("%d",&age);

    printf("\n Enter Your Marks");
    scanf("\n %d",&marks);

    switch (age)
    {
    case 3:
        printf("\n The age is 3");
        switch (marks)
        {
        case 45:
            printf("\n Your Marks are 45");
            break;
        
        default:
            printf("\n Your marks is 45");
            break;
        }
        break;
    case 12:    
            printf("\n Your age is 12");
            break;
    
    default:
            printf("\n Your age is not 45 or 12");
        break;
    }
}