# Simple C generic Data Structures header files. 
Data structures implelemted:Queue,Tree
Only header files, download and include

## Queue


Example:

``` 
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

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
```

Result: ```15```

## Tree

### TODO add Set/List/LinkedList/Stack
