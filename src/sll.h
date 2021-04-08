#ifndef _SLL_H
#define _SLL_H

#define MAX_NODES 10 // Max number of nodes tha can be freed

typedef struct linked_t {
	int data;
	struct linked_t *node;
} linked_t;

typedef struct free_links {
	int *index;
	linked_t *free_later[MAX_NODES];
	linked_t *first;
} free_links;

linked_t* linkCreate(free_links *fl, linked_t *node, int data);
void linkAppend(free_links *fl, linked_t **node, int new_data);
void linkPush(free_links *fl, linked_t *node, int new_data);
void linkDestroy(free_links *fl);
void linkDelete(linked_t **node, linked_t *next);
void showList(free_links *fl);

#endif