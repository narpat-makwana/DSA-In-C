#include<stdio.h>
main()
{
    int a,b;
    printf("\n Enter the value for a & b : ");
    scanf("%d%d",&a,&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("\nAfter Swapping the value foe a & b :%a %b",a,b);
    

}