
void StarPat(int rows);
void StarRev(int rows);
//function Prototype:
#include <stdio.h>
int main()
{
    int rows, type;
    printf("\n Enter 0 for for starPattern or Enter 1 for ReverseStar: ");
    scanf("%d", &type);

    printf("\n Enter How many rows you want: ");
    scanf("%d", &rows);

    switch (type)
    {
    case 0:
        StarPat(rows);
        break;
    case 1:
        StarRev(rows);
        break;

    default:
        printf("\nEnter valid Number!!!\n");
        break;
    }
    return 0;
}

void StarPat(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void StarRev(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= rows-i-1; j++)
        {
            printf("*");
        }
        printf("\n");
    }    
}