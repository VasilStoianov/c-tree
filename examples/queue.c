#include "../queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Test{
    int val;
    int val2;
} Test;


void printQueue(Queue * queue){
    QNode * current = queue->head;
    while(current->value != NULL){
        QNode * next = current->next;
        Test* t = (Test*)current->value;
        printf("%d \n",t->val);
        current = next;
    }
    printf("\n");
}


int main(void) {

      Queue* queue = malloc(sizeof(Queue));
    Test* t = malloc(sizeof(Test));
      t->val = 15;

    QNode* toPut = malloc(sizeof(QNode));
    toPut->value = malloc(sizeof(Test));
     memcpy(toPut->value, t, sizeof(Test));
 
    QNode* tp = malloc(sizeof(QNode));
    tp->value = malloc(sizeof(Test));
     memcpy(tp->value, t, sizeof(Test));
    QNode* tt = malloc(sizeof(QNode));
    tt->value = malloc(sizeof(Test));
     memcpy(tt->value, t, sizeof(Test));
     push(&queue->head,*toPut,&queue);
     push(&queue->head,*tp,&queue);
     push(&queue->head,*tt,&queue);
     QNode * head = pop(queue);
     printf("Head %d \n",((Test*) head->value)->val);
   printQueue(queue);
    freeQueue(queue);
  return 1;
}