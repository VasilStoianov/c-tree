#pragma once
#include "stdlib.h"
#include <string.h>
int MAX_SIZE = 25;

typedef struct QNode
{
 void * value;
 struct QNode * previous;
 struct QNode * next;
} QNode;


typedef struct Queue {
   int size;
   QNode *head;
   QNode *tail;
} Queue;


int push(QNode *head, QNode  toPut,Queue * queue){
    if(head == NULL){
        head = malloc(sizeof(QNode));
       head->next = malloc(sizeof(sizeof(QNode)));
       head->previous = malloc(sizeof(sizeof(QNode)));
       head->value = malloc(sizeof((char*)toPut.value));
       memcpy((char*)head->value,(char*)toPut.value,sizeof((char*)toPut.value));
       queue->tail = head->next;
      queue->head = head;
    return 1;
    }
    if(head->next->value ==NULL){
        head->next->next = malloc(sizeof(sizeof(QNode)));
        head->next->previous = head;
       head->next->value = malloc(sizeof((char*)toPut.value));
       memcpy((char*)head->next->value,(char*)toPut.value,sizeof((char*)toPut.value));
       queue->tail = head->next;
       return 1;
    }else {
        push(head->next,toPut,queue);
    }

    return 0;  
}

QNode* pop(Queue* queue){
   if(queue->head == NULL){
    return NULL;
   }
   QNode* res = queue->head;
   queue->head = queue->head->next;
   queue->head->previous = NULL;
return res;
}


void freeQueue(Queue * queue){
    QNode * current = queue->head;
    while(current != NULL){
        QNode * next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
    free(queue);
}

