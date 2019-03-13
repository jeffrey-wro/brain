#ifndef BRAIN_H_
#define BRAIN_H_

typedef void* (*StateFunc)(int*);

void* startedState(int* count);
void* stoppedState(int* count);




#endif