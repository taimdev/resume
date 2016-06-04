// Tests File
// Write all of your tests in here

// Any questions email riyasat.saber@student.unsw.edu.au
// but ask your tutor first

// compile with gcc -Wall -Werror -O -o tests tests.c questions.c  list.c
#include <stdio.h>
#include "list.h"
#include <assert.h>

void testQ1(){
	printf("Tests for Q1\n");
	int keys[] = {1,2,3,4,5,6,7,8};
	link list1 = createListWithKeys(keys, sizeof(keys)/sizeof(int));
	printList(list1);
	printf("And the sum of every %d node(s) is ..... %d!\n",2,sumEveryN(list1,2));
	freeList(list1);
}

int main(){

	// Quick way to make a linked list
	int keys1[] = {1,2,3,4,5,6,7,8,9};
	link list1 = createListWithKeys(keys1, sizeof(keys1)/sizeof(int));

	// Or if you would rather...
	int i,size,temp;
	link list2 = NULL;
	printf("Enter a number: ");
	scanf("%d", &size);

	for(i=0; i<size; i++){
		scanf("%d", &temp);
		list2 = append(list2, newNode(temp));
	}

	printList(list1);
	printList(list2);

	freeList(list1);
	freeList(list2);

	testQ1();

	printf("Wow well done you passed all of your tests!\n");

	return 0;
}