#include "stack/stack.h"
#include <stdio.h>

void StringFree(void *elem)
{
    free(*(char **)elem);
}

int main(int argc, char const *argv[])
{
    int i = 0;
    Stack stk;
    const char *friends[] = {"AI", "Bob", "Cindy"};
    
    StackNew(&stk, sizeof(char *), StringFree);
    for (i = 0; i < 3; i++)
    {
        char *copy = strdup(friends[i]);
        StackPush(&stk, &copy);
    }

    char *name = " ";
    for (i = 0; i < 3; i++)
    {
        StackPop(&stk, &name);
        printf("%s\n", name);
    }
    free(name);

    StackDispose(&stk);

    return 0;
}
