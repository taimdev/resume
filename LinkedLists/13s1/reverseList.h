/*
 *  reverseList.h
 *  2013s1 Practice Prac Exam #1
 *  UNSW comp1917
 *
 *  Created by Richard Buckland
 *  Share freely CC-BY-3.0
 *
 */

typedef struct _node *link;    // a link points ot a node

typedef struct _node {
	int value;
	link next;
} node;

// a list is represented by a pointer to a struct containing 
// a pointer to the first node in it
typedef struct _list {
    link head;
} *list;     


// reverse a linked list by pointer manipulation
// return pointer to head of the (now reversed) list
// (which was previously the last node in the list)
// you must do this by rearranging pointers stored in
// the nodes, not by altering the integer values in the
// nodes.
//
// probably the best way to do this is to repeatedly
// remove the first element from the input list and
// insert it at the front of the output list.
// dont forget to draw pictures
list reverseList (list inputList);
void printList(list l);

