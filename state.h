#ifndef BRAIN_H_
#define BRAIN_H_

#include "jeffrey.h"

typedef void* (*StateFunc)(Jeffrey* jeffrey, int*);

void* startedState(Jeffrey* jeffrey, int* count);
void* outOfBox(Jeffrey* jeffrey, int* count);
void* stoppedState(Jeffrey* jeffrey, int* count);




#endif