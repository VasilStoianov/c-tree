#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  void *value;
  struct Node *left;
  struct Node *right;
  __uint8_t isRoot;
} Node;

typedef struct Tree {
  Node *root;
} Tree;

int compareValues(size_t left, size_t right) { return left >= right; }

void put_(Tree *tree, Node *toPut, Node **toCheck, int (*f)(size_t, size_t));
void put(Tree *tree, Node *toPut, int (*f)(size_t, size_t)) {
  put_(tree, toPut, &(tree->root), (*f));
}

void put_(Tree *tree, Node *toPut, Node **toCheck, int (*f)(size_t, size_t)) {
  if (tree->root == NULL) {
    tree->root = malloc(sizeof(Node));
    tree->root->value = malloc(strlen((char *)toPut->value) + 1);
    strcpy(tree->root->value, toPut->value);
    tree->root->isRoot = 1;
    return;
  }
  if ((*toCheck) == NULL) {
    (*toCheck) = malloc(sizeof(Node));
    (*toCheck)->value = malloc(strlen((char *)toPut->value) + 1);
    strcpy((*toCheck)->value, toPut->value);
    (*toCheck)->left = NULL;
    (*toCheck)->right = NULL;
  } else {
    if ((*f)(strlen((char *)(*toCheck)->value), strlen((char *)toPut->value))) {
      put_(tree, toPut, &(*toCheck)->left, f);
    } else {

      put_(tree, toPut, &(*toCheck)->right, f);
    }
  }
}
