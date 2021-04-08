/*
# Single Linked List(SLL) simple implementation
# Coded by: FallAngel
# Coded at: 04/2021 
*/

#include <stddef.h>
#include <sll.h>

int main(void) {
	int index = 0;
	free_links fl;
	fl.index = &index;

	linked_t *a = linkCreate(&fl, NULL, 1);
	linked_t *b = linkCreate(&fl, a, 2);
	linked_t *c = linkCreate(&fl, b, 3);
	linked_t *d = linkCreate(&fl, c, 4);

	linkPush(&fl, d, 6);
	linkAppend(&fl, &a, 5);
    linkDelete(&d, b);
	
	showList(&fl);

    linkDestroy(&fl);

	return 0;
}