// List ADT

// Written by Riyasat Saber

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

link newNode(int data){
  link n = malloc(sizeof(struct _link));
  n->next = NULL;
  n->data = data;
  return n;
}

link append(link head, link node){
	if(head==NULL) return node;
	link curr = head;
	while(curr->next!=NULL) curr = curr->next;
	curr->next = node;
	return head;
}

link createListWithKeys(int * keys, int n){
	if(n==0) return NULL;
	int i;
	link head = NULL;
	for(i=0; i<n; i++){
		head = append(head, newNode(keys[i]));
	}
	return head;
}

void freeList(link head){
	if(head==NULL) return;
	link prev;
	link curr = head;
	while(curr!=NULL){
		prev = curr;
		curr = curr->next;
		free(prev);
	}
}

void printList(link head){
	if(head==NULL){
		printf("[X]\n");
		return;
	}
	printf("[%d]->",head->data);
	printList(head->next);
}



