#include <stdio.h>
#include <stdlib.h>

#include <sll.h>

linked_t* linkCreate(free_links *fl, linked_t *node, int data) {
	int index = (*fl->index)++;
	linked_t *new_node = (linked_t*)malloc(sizeof(linked_t));

	*new_node = (linked_t){
		.data = data,
		.node = node,
	};

	fl->free_later[index] = new_node;
	return new_node;
}

void linkAppend(free_links *fl, linked_t **node, int new_data) {
	linked_t *new_node = linkCreate(fl, NULL, new_data);
	(*node)->node = new_node;
}

void linkPush(free_links *fl, linked_t *node, int new_data) {
	linked_t *new_node = linkCreate(fl, node, new_data);
	fl->first = new_node;
}

void linkDestroy(free_links *fl) {
	int index = *fl->index;
	for (int i=0; i < index; i++) {
		// printf("Freed: %p\n", (fl->free_later)[i]);
		free((fl->free_later)[i]);
	}
}

void linkDelete(linked_t **node, linked_t *next) 
{

	(*node)->node = next;
}

void showList(free_links *fl) {
	linked_t *node = fl->first;
	
	while (node != NULL) {
		printf("%d\n", node->data);
		node = node->node;
	}
	
}