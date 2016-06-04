// Taimur Azhar z5116684
// 23/05/2016
// Given a number make a list of its factorial expansion
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct _node *link;

typedef struct _node {
	int value;
	link next;
} node;

typedef struct _list {
	link head;
} *list;


list factorial (int x);
static list createList(void);
static link createNode(int fact);
static void addToEnd(list ls, link newNode);
static void printList(list ls);


int main (int argc, char *argv[])  {
    int input;

    scanf("Enter a Number: %d", &input);

    factorial(input);

	return EXIT_SUCCESS;
}


list factorial (int x) {
	list ls = createList();
	link newNode = NULL;
	int counter = 1;
	int fact = 1;

	while (counter <= x) {
		fact = fact*counter;
		newNode = createNode(fact);
		addToEnd(ls, newNode);
		printList(ls);
		counter ++;
	}
	return ls;
}

static list createList(void) {
	list l = malloc(sizeof(struct _list));
	l->head = NULL;
	return l;
}

static link createNode(int fact) {
	link n = malloc(sizeof(node));
	n->value = fact;
	n->next = NULL;

	return n;
}

static void addToEnd(list ls, link newNode) {
	if (ls->head == NULL) {
		ls->head = newNode;

	} else {
		link curr = ls->head;

		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = newNode;
	}
}

static void printList(list ls) {
	//int counter = 0;
	link curr = ls->head;
	int val;
	while (curr != NULL) {
		val = curr->value;
		printf("%d\n", val);
		curr = curr->next;
	}
}
