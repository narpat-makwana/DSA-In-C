#include <stdio.h>
#include <string.h>
struct employee
{
    int eid;
    char enm[20];
} emp[10];

void main()
{
    FILE *fp;
    struct employee temp;
    int i = 0, j, size, flag = 0;

    fp = fopen("emp.txt", "r");
    if (fp == NULL)
    {
        printf("\n File creation error...");
        return;
    }
    while (!feof(fp))
    {
        fscanf(fp, "%d%s", &emp[i].eid, emp[i].enm);
        i++;
    }
    size = i - 1;
    for (i = 0; i < size - 1; ++i)
    {
        for (j = 0, flag = 0; j < size - 1 - i; ++j)
        {
            if (strcmp(emp[j].enm, emp[j + 1].enm) > 0)
            {
                flag = 1;
                temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    fp = fopen("empSorted.txt", "w");
    if (fp == NULL)
    {
        printf("n File creation error...");
        return;
    }
    for (i = 0; i < size; i++)
    {
        fprintf(fp, "%d %s\n", emp[i].eid, emp[i].enm);
    }
    printf("\nfile sorted...and stored in empSorted.txt\n");
}