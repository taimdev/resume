// Taimur Azhar z5116684
// 20/05/2016
// Extra Functions List Actities

// a concrete linked list

// list is a pointer to a struct - containing the head ptr
// 18 may 2014 tests expanded. includes tests on append to 
// explicitly detect non-null "next" in the appended node.

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list3-extfunc.h"

static void testList (void);

int main (int argc, char *argv[])  {
    printf ("Testing list3-core...\n");
    testList();
    printf ("All list3-core tests passed!  You are awesome\n");

    return EXIT_SUCCESS;
}

list newList() {
    link curr = malloc(sizeof(node));
    list newl = malloc(sizeof(struct _list));

    curr = NULL;

    newl->head = curr;

    return newl;
}

void deleteHead(list l) {
    link first = l->head;
    link second = first->next;
    l->head = second;
    free(first);     
}

void deleteLast(list l) {
    link curr;
    link prev;
    curr = l->head;

    if (curr == NULL) {

    } else if (curr->next == NULL) {
        l->head = NULL;

    } else {
        while (curr->next != NULL) {
            prev = curr;
            curr= curr->next;
        }

        prev->next = NULL;
        free(curr);
    }

}

void concatenate (list to, list from) {
    link last = to->head;
    link connector = from->head;


    if ((last == NULL) && (connector == NULL)) {

    } else if (last == NULL) {
        to->head = connector;
    } else if (connector == NULL) {

    } else {
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = connector;
    }
    from->head = NULL;


}

int count42s (list l) {
    int num = 0;
    int val;
    link curr = l->head;
    if (l == NULL) {
        num = 0;
    } else if (curr == NULL) {
        num = 0;
    } else {
        while (curr != NULL) {
            val = curr->value;
            if (val == 42) {
                num++;
            }
            curr = curr->next;
        }
    }

    return num;
}


static void testList (void) {
    printf ("testing newList()\n");
    list testList = newList();
   // assert (testList->head == NULL);
 
 
    printf ("testing deleteHead()\n");
    // create a 3 element list
    testList->head = malloc (sizeof (node));
    testList->head->value = 3;
    testList->head->next  = malloc (sizeof (node));
    testList->head->next->value = 1;
    testList->head->next->next  = malloc (sizeof (node));
    testList->head->next->next->value = 4;
    testList->head->next->next->next  = NULL;
 
    deleteHead (testList);
 
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 1);
    assert (testList->head->next != NULL);
    assert (testList->head->next->value == 4);
    assert (testList->head->next->next == NULL);
 
    deleteHead (testList);
 
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 4);
    assert (testList->head->next == NULL);
 
    deleteHead (testList);
 
    assert (testList != NULL);
    assert (testList->head == NULL);
 
 
    printf ("testing deleteLast()\n");
    // create a 3 element list
    testList->head = malloc (sizeof (node));
    testList->head->value = 3;
    testList->head->next  = malloc (sizeof (node));
    testList->head->next->value = 1;
    testList->head->next->next  = malloc (sizeof (node));
    testList->head->next->next->value = 4;
    testList->head->next->next->next  = NULL;
 
    deleteLast (testList);
 
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 3);
    assert (testList->head->next != NULL);
    assert (testList->head->next->value == 1);
    assert (testList->head->next->next == NULL);
 
    deleteLast (testList);
 
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 3);
    assert (testList->head->next == NULL);
 
    deleteLast (testList);
 
    assert (testList != NULL);
    assert (testList->head == NULL);
 
 
    printf ("testing concatenate()\n");
 
    // (3,2) -> (5,0)
    // create a 3 element list
    testList->head = malloc (sizeof (node));
    testList->head->value = 3;
    testList->head->next  = malloc (sizeof (node));
    testList->head->next->value = 1;
    testList->head->next->next  = malloc (sizeof (node));
    testList->head->next->next->value = 4;
    testList->head->next->next->next  = NULL;
 
    // create a two element list
    list testListB = newList();
 
    testListB->head = malloc (sizeof (node));
    testListB->head->value = 1;
    testListB->head->next  = malloc (sizeof (node));
    testListB->head->next->value = 5;
    testListB->head->next->next  = NULL;
 
    concatenate (testList, testListB);
    assert (testListB != NULL);
    assert (testListB->head == NULL);
 
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 3);
    assert (testList->head->next != NULL);
    assert (testList->head->next->value == 1);
    assert (testList->head->next->next != NULL);
    assert (testList->head->next->next->value == 4);
    assert (testList->head->next->next->next != NULL);
    assert (testList->head->next->next->next->value == 1);
    assert (testList->head->next->next->next->next != NULL);
    assert (testList->head->next->next->next->next->value == 5);
    assert (testList->head->next->next->next->next->next == NULL);
 
 
    // (5,0) -> (5,0)
    concatenate (testList, testListB);
    assert (testListB != NULL);
    assert (testListB->head == NULL);
 
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 3);
    assert (testList->head->next != NULL);
    assert (testList->head->next->value == 1);
    assert (testList->head->next->next != NULL);
    assert (testList->head->next->next->value == 4);
    assert (testList->head->next->next->next != NULL);
    assert (testList->head->next->next->next->value == 1);
    assert (testList->head->next->next->next->next != NULL);
    assert (testList->head->next->next->next->next->value == 5);
    assert (testList->head->next->next->next->next->next == NULL);
 
    // (0,5) -> (5,0)
    concatenate (testListB, testList);
    assert (testList != NULL);
    assert (testList->head == NULL);
 
    assert (testListB != NULL);
    assert (testListB->head != NULL);
    assert (testListB->head->value == 3);
    assert (testListB->head->next != NULL);
    assert (testListB->head->next->value == 1);
    assert (testListB->head->next->next != NULL);
    assert (testListB->head->next->next->value == 4);
    assert (testListB->head->next->next->next != NULL);
    assert (testListB->head->next->next->next->value == 1);
    assert (testListB->head->next->next->next->next != NULL);
    assert (testListB->head->next->next->next->next->value == 5);
    assert (testListB->head->next->next->next->next->next == NULL);
 
    printf ("testing count42s()\n");
    assert (count42s (testList) == 0);
    assert (count42s (testListB) == 0);
 
    testListB->head->value = 42;
    assert (count42s (testListB) == 1);
 
    testListB->head->next->value = 42;
    assert (count42s (testListB) == 2);
 
    testListB->head->next->next->value = 42;
    assert (count42s (testListB) == 3);
 
    testListB->head->next->next->next->value = 42;
    assert (count42s (testListB) == 4);
 
    testListB->head->next->next->next->next->value = 42;
    assert (count42s (testListB) == 5);
 
 
}