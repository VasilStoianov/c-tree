#pragma once
#include <stdlib.h>
#include <stdio.h>
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


int push(QNode **head, QNode  toPut,Queue ** queue){
    if( toPut.value == NULL ){
        printf("ERROR: Empty value to put");
        return 0;
    }
    if((*head) == NULL ){
        (*head) = malloc(sizeof(QNode));
        (*head)->next = NULL;
        (*head)->value = malloc(sizeof((char*)toPut.value));
       memcpy((char*)(*head)->value,(char*)toPut.value,sizeof((char*)toPut.value));
        if((*queue)->size == 0){
       (*queue)->tail = *head;
      (*queue)->head = *head;
    }
    else {
        //(*head)->previous = (*queue)->tail;
        (*head)->previous = malloc(sizeof(QNode));
        (*queue)->tail->next = malloc(sizeof(QNode));
        (*head)->previous = (*queue)->tail;
        (*queue)->tail->next = (*head);
        (*queue)->tail = (*head);
    }
      (*queue)->size++;
    return 1;
    }
   else {
        push(&(*head)->next,toPut,queue);
    }

    return 0;  
}

QNode* pop(Queue* queue){
   if(queue->head == NULL){
    return NULL;
   }
   QNode* res = queue->head;
   queue->head = queue->head->next;
   if(queue->head != NULL){

   queue->head->previous = NULL;
   }else {

   queue->tail = queue->head;
   }
   --queue->size;
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

