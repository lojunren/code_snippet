#ifndef STACK_H
#define STACK_H

typedef struct
{
    void *elemS;    //the dynamic data structure whichi holds the element
    int elemSize;
    int logLength;
    int allocLength;
    void (*freefunc)(void *);
} Stack;

void stack_init(Stack *s, int elemSize, void (*pFunc)(void *));
void stack_dispose(Stack *s);
void stack_push(Stack *s, void *elemAddr);
void stack_pop(Stack *s, void *elemAddr);

#endif