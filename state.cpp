#include <stdio.h>

#include "Motor_Controller.h"
#include "jeffrey.h"
#include "state.h"

void* startedState(Jeffrey* jeffrey, int* count){

	jeffrey->moveForwardCM(10, 50);

	return (void *)outOfBox;
}

void* outOfBox(Jeffrey* jeffrey, int* count){

	if(false){
		return NULL; //Next state
	}

	if(false){
		return NULL; //Next state
	}

	return (void *)startedState;
}

void* stoppedState(Jeffrey* jeffrey, int* count){

	if(false){
		return NULL; //Next state
	}

	if(false){
		return NULL; //Next state
	}

	return (void *)startedState;
}