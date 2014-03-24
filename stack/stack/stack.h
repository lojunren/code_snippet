#ifndef STACK_H
#define STACK_H

typedef struct 
{
	void* elemS;	//the dynamic data structure whichi holds the element
	int elemSize;
	int logLength;
	int allocLength;
	void (*freefunc)(void*);
}Stack;

void StackNew(Stack* s, int elemSize, void (*pFunc)(void*));
void StackDispose(Stack* s);
void StackPush(Stack* s, void* elemAddr);
void StackPop(Stack* s, void* elemAddr);

#endif