#include "tree.h"
#include "queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

typedef struct Test{
    int val;
    int val2;
} Test;

int main(void) {

      Queue* queue = malloc(sizeof(Queue));
  Test* t = malloc(sizeof(Test));
  t->val = 15;

    QNode* toPut = malloc(sizeof(char));
    toPut->value = malloc(sizeof(char));
     memcpy(toPut->value, t, sizeof(Test));
    pop(&queue->head,*toPut);
    Test *t2 = (Test*) queue->head.value;
    printf("%d\n",t2->val);
  return 1;
}