#include<stdio.h>

int main()
{
    
    int id[] = {1, 1, 9, 4, 9, 3, 3, 7};
    size_t id_len = sizeof(id) / sizeof(int);

    printf("initial: ");
    for (int i=0; i<id_len; i++)
    {
        printf("%d", id[i]);
    }

    printf("\ntranslated: ");

    for (int i=0; i < id_len; i++)
    {        
        if ( id[i] % 2 == 0)
        {
            id[i] = 0;
        }
        else
        {
            id[i] = 1;
        };

        printf("%d", id[i]);
    }

    printf("\n");
}
