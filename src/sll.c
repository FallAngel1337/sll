#include <stdio.h>
#include <stdlib.h>

#include <sll.h>

linked_t* linkCreate(nodes_list *fl, linked_t *node, int data) {
	int index = (*fl->index)++;
	linked_t *new_node = (linked_t*)malloc(sizeof(linked_t));

	*new_node = (linked_t){
		.data = data,
		.node = node,
	};

	fl->nodes[index] = new_node;
	return new_node;
}

void linkAppend(nodes_list *fl, int new_data) {
	fl->last->node = linkCreate(fl, NULL, new_data);
	fl->last = fl->last->node
}

void linkPush(nodes_list *fl, int new_data) {
	fl->first = linkCreate(fl, fl->first, new_data);
}

void linkDestroy(nodes_list *fl) {
	int index = *fl->index;
	for (int i=0; i < index; i++) {
		// printf("Freed: %p\n", (fl->nodes)[i]);
		free((fl->nodes)[i]);
	}
}

void showList(nodes_list *fl) {
	linked_t *first = fl->first;

	while (first != NULL) {
		printf("%d\n", first->data);
		first = first->node;
	}
}

void setup(nodes_list *fl) {
	fl->first = fl->nodes[0];
	fl->last = fl->nodes[--*(fl->index)];
}
