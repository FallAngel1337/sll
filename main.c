/*
# Single Linked List(SLL) simple implementation
# Coded by: FallAngel
# Coded at: 04/2021 
*/

#include <stddef.h>
#include <sll.h>

int main(void) {
	int index = 0;
	nodes_list fl;
	fl.index = &index;

	linkCreate(&fl, NULL, 4);
	setup(&fl);

	linkPush(&fl, 3);
	linkPush(&fl, 2);
	linkPush(&fl, 1);
	linkPush(&fl, 0);
	linkPush(&fl, -1);
	linkAppend(&fl, 5);
	linkAppend(&fl, 6);
	linkAppend(&fl, 7);
	linkAppend(&fl, 8);
	
	showList(&fl);

    linkDestroy(&fl);

	return 0;
}