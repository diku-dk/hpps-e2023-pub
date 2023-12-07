// list.c

#include <stdlib.h>
#include "list.h"

struct node {
  int data;
  struct node* tail;
};

struct list {
  struct node* head; // NULL if empty
};

struct list* list_empty() {
  struct list* l = malloc(sizeof(struct list));
  l->head = NULL;
  return l;
}

void list_free(struct list* l) {
  while (!list_is_empty(l)) {
    int x;
    list_remove_first(l, &x);
  }
  free(l);
}

int list_is_empty(struct list* l) {
  return l->head == NULL;
}

int list_remove_first(struct list* l, int* out) {
  if (l->head == NULL) {
    return 1;
  }
  *out = l->head->data;
  struct node* old_head = l->head;
  l->head = l->head->tail;
  free(old_head);
  return 0;
}

int list_insert(int x, struct list* l) {
  struct node* n = malloc(sizeof(struct node));
  if (n == NULL) {
    return 1;
  }
  n->data = x;
  n->tail = l->head;
  l->head = n;
  return 0;
}

void list_map(struct list* l, map_fn f) {
  struct node* n = l->head;
  while (n != NULL) {
    n->data = f(n->data);
    n = n->tail;
  }
}
