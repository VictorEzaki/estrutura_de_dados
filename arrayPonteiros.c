#include <stdio.h>

int main()
{
    int numbers[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        int *ptrI = &i;
        printf("%d\n", numbers[*ptrI]);
    }
    
}