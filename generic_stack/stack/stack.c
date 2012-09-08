#include "stack.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void StackNew(Stack* s, int elemSize, void (*pFunc)(void*))
{
	assert(s);
	assert(elemSize != 0);

	s->allocLength = 8;
	s->logLength = 0;
	s->elemSize = elemSize;
	s->elemS = malloc(4*elemSize);
	assert(s->elemS != NULL);
	s->freefunc = pFunc;
}

void StackDispose(Stack* s)
{
	assert(s);

	if(s->freefunc != NULL)
	{
		int i = 0;
		for (i = 0; i < s->logLength; i++)
		{
			s->freefunc((char*)s->elemS + i*s->elemSize);
		}
	}

	free(s->elemS);
}

void StackPush(Stack* s, void* elemAddr)
{
	assert(s);
	assert(elemAddr);

	if (s->logLength == s->allocLength)
	{
		s->allocLength *= 2;
		s->elemS = realloc(s->elemS, s->allocLength*s->elemSize);
	}

	void* target = (char*)s->elemS + s->logLength*s->elemSize;
	memcpy(target, elemAddr, s->elemSize);
	s->logLength++;
}

void StackPop(Stack* s, void* elemAddr)
{
	assert(s);
	assert(elemAddr);

	void* source = (char*)s->elemS + (s->logLength-1)*s->elemSize;
	memcpy(elemAddr, source, s->elemSize);
	s->logLength--;
}