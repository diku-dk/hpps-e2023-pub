// list.h

struct list;

// Creates new empty list.
struct list* list_empty();

// Frees list.
void list_free(struct list*);

// Returns 1 if empty, otherwise 0.
int list_is_empty(struct list*);

// Removes first element from list.
// Writes removed element to *out.
//
// returns 0 on success.
int list_remove_first(struct list* l, int* out);

// Inserts new element at head of list.
//
// returns 0 on success.
int list_insert(int x, struct list* l);

typedef int (*map_fn)(int);

void list_map(struct list* l, map_fn f);
