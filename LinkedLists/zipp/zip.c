/*
 *  zip.c
 *  
 *  2013 s1 Practice Prac Exam #2
 *  UNSW comp1917
 *
 *  Created by INSERT YOUR NAME HERE
 *  Share freely CC-BY-3.0
 *
 */

// Complete this function and submit this file ONLY
// for the prac exam.  Do not change the other supplied
// as you will not be submitting them.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "zip.h"

list append(list zipped, link node);
void zip (list listA, list listB, list zipped) {
	link curra = listA->head;
	link currb = listB->head;
	link storea;
	link storeb;
	zipped->head = NULL;

	while ((curra != NULL) || (currb != NULL)) {
		if (curra != NULL) {
			storea = curra->next;
			zipped = append(zipped, curra);
			printf("First if ran\n");
		}
		curra = storea;
		
		if (currb != NULL) {
			storeb = currb->next;
			zipped = append(zipped, currb);
			printf("Second if ran\n");
		}
		currb = storeb;
	}
}


list append(list zipped, link node) {
	link curr = zipped->head;
	node->next = NULL;
	if (curr == NULL) {
		zipped->head = node;
	} else {
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = node;
	}

	return zipped;
}


