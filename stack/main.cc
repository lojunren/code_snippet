#include "stack/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void string_free(void *elem)
{
    free(*(char **)elem);
}

int main(int argc, char const *argv[])
{
    Stack stk;
    const char *friends[] = {"AI", "Bob", "Cindy"};

    stack_init(&stk, sizeof(char *), string_free);
    for (int i = 0; i < 3; i++)
    {
        char *copy = strdup(friends[i]);
        stack_push(&stk, &copy);
    }

    char *name = '';
    for (i = 0; i < 3; i++)
    {
        stack_pop(&stk, &name);
        printf("%s\n", name);
    }
    free(name);

    stack_dispose(&stk);

    return 0;
}
