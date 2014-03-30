#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LENGTH 7

static void Rotate(void *front, void *middle, void *end)
{
    if (front == NULL || middle == NULL || end == NULL)
        return;

    unsigned int frontSize = (unsigned int)((char *)middle - (char *)front);
    unsigned int backSize = (unsigned int)((char *)end - (char *)middle);

    char *buffer = (char *)malloc(frontSize);
    if (buffer == NULL)
    {
        printf("malloc function failed\n!");
        return ;
    }

    memcpy(buffer, front, frontSize);
    memmove(front, middle, backSize);
    memcpy((char *)end - frontSize, buffer, frontSize);

    free(buffer);
}

int main(int argc, char const *argv[])
{
    int i = 0;
    int test[ARR_LENGTH] = {0};
    for (i = 0; i < ARR_LENGTH; i++)
    {
        test[i] = i + 1;
    }

    for (i = 0; i < ARR_LENGTH; i++)
    {
        printf("%d", test[i]);
    }
    printf("\n");

    Rotate(test, test + 2, test + 7);

    for (i = 0; i < ARR_LENGTH; i++)
    {
        printf("%d", test[i]);
    }
    printf("\n");

    return 0;
}

