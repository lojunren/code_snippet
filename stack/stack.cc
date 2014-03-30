#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void stack_init(Stack *s, unsigned int elemSize, void (*pFunc)(void *))
{
    if (s == NULL || elemSize == 0)
    {
        printf("invalid parameters!\n");
        return ;
    }

    s->allocLength = 8;
    s->logLength = 0;
    s->elemSize = elemSize;
    s->freefunc = pFunc;
    s->elemS = malloc(4 * elemSize);
    if (s->elemS == NULL)
    {
        printf("malloc function failed!\n");
        return ;
    }
}

void stack_dispose(Stack *s)
{
    if (s == NULL)
    {
        printf("invalid parameters!\n");
        return ;
    }

    if (s->freefunc != NULL)
    {
        for (unsigned int i = 0; i < s->logLength; i++)
        {
            s->freefunc((char *)s->elemS + (i * s->elemSize));
        }
    }

    free(s->elemS);
}

void stack_push(Stack *s, void *elemAddr)
{
    if (s == NULL || elemAddr == NULL)
    {
        printf("invalid parameters!\n");
        return ;
    }

    if (s->logLength == s->allocLength)
    {
        s->allocLength *= 2;
        s->elemS = realloc(s->elemS, s->allocLength * s->elemSize);
    }

    void *target = (char *)s->elemS + s->logLength * s->elemSize;
    memcpy(target, elemAddr, s->elemSize);
    s->logLength++;
}

void stack_pop(Stack *s, void *elemAddr)
{
    if (s == NULL || elemAddr == NULL)
    {
        printf("invalid parameters!\n");
        return ;
    }

    void *source = (char *)s->elemS + (s->logLength - 1) * s->elemSize;
    memcpy(elemAddr, source, s->elemSize);
    s->logLength--;
}