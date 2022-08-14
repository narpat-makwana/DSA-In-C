#include <stdio.h>
#include <string.h>
struct person
{
    int pid;
    int age;
} per[10];

void main()
{
    FILE *fp;
    struct person temp;
    int i = 0, j, size;

    fp = fopen("person.txt", "r");
    if (fp == NULL)
    {
        printf("\n File creation error...");
        return;
    }
    while (!feof(fp))
    {
        fscanf(fp, "%d %d", &per[i].pid, &per[i].age);
        i++;
    }
    size = i - 1;

    for (i = 1; i < size; ++i)
    {
        temp = per[i];
        j = i - 1;

        while (j >= 0 && per[j].age > temp.age)
        {
            per[j + 1] = per[j];
            j--;
        }
        per[j + 1] = temp;
    }

    fp = fopen("personSorted.txt", "w");
    if (fp == NULL)
    {
        printf("n File creation error...");
        return;
    }
    for (i = 0; i < size; i++)
    {
        fprintf(fp, "%d %d\n", per[i].pid, per[i].age);
    }
    printf("\nfile sorted...and stored in personSorted.txt\n");
}