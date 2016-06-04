// Taimur Azhar z5116684
// 24/05/2016
// Linked Lists Practice

#include <stdio.h>
#include <stdlib.h>
typedef struct _node *link;

typedef struct _node {
    int value;
    Node next;
} node;
 
typedef struct _list {
    Node head;
} list;


list createList(void);
void addToEnd(list l, link n);

list zip (list lista, list listb) {
	list result = createList();
	link curr1 = lista->head;
	link curr2 - listb->head;

	while ((curr1 != NULL) && (curr2 != NULL)) {
		if (curr1 != NULL) {
			link store1 = curr1->next;
			addToEnd(store1);
			curr1->next = store1;

		if (curr2 != NULL) {
			link store2 = curr2->next;
			addToEnd(store2);
			curr2->next = store2;
		}
	}

}

list createList(void) {
	list newList = malloc(sizeof(struct _list));

	return newList;
}













/*
void test();

list zipperCons(list li1, list l2);
 
int main (int argc, char const *argv[]) {
	test();


   return EXIT_SUCCESS;
}

void test() {
	// set up data
	list l1 = newList();
	list l2 = newList();

	// test both null
	list listContstruct = zipperCons(l1, l2);
	assert(listContstruct->head == NULL);

	// test list 1 is null, list 2 is not
	append(l2, 2);
	append(l2, 4);

	listContstruct = zipperCons(l1, l2);
	assert(numItems(listContstruct) == 2);

	// test neither null, same size
	append(l1, 1);
	append(l2, 3);

	listContstruct = zipperCons(l1, l2);
	assert(numItems(listContstruct) == 4);
	assert(listContstruct->head->value == 1);
	assert(listContstruct->head->next->value == 2);
}

list zipperCons(list l1, list l2) {
	list result = malloc(sizeof)

	return result;
}


*/