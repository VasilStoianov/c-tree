#pragma once
#include "stdlib.h"
int MAX_SIZE = 25;

typedef struct QNode
{
 void * value;
 struct QNode * previous;
 struct QNode * next;
} QNode;


typedef struct Queue {
   int size;
   QNode head;
   QNode tail;
} Queue;


int pop(QNode *head, QNode  toPut){
    printf("Value %s\n",toPut.value);
    if(head->value == NULL){
       head->next = NULL;
       head->previous = NULL;
       head->value = malloc(sizeof((char*)toPut.value));
       memcpy((char*)head->value,(char*)toPut.value,sizeof((char*)toPut.value));
    }

     printf("VAlue %s\n",(char*)head->value);
    return 1;
  
}

