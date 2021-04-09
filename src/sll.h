#ifndef _SLL_H
#define _SLL_H

#define MAX_NODES 10 // Max number of nodes tha can be freed

typedef struct linked_t {
	int data;
	struct linked_t *node;
} linked_t;

typedef struct nodes_list {
	int *index;
	linked_t *nodes[MAX_NODES];
	linked_t *first, *last;
} nodes_list;

linked_t* linkCreate(nodes_list *fl, linked_t *node, int data);
void linkAppend(nodes_list *fl, int new_data);
void linkPush(nodes_list *fl, int new_data);
void linkDestroy(nodes_list *fl);
void linkDelete(linked_t **node, linked_t *next);
void showList(nodes_list *fl);
void setup(nodes_list *fl);

#endif