//Linked Lists

//sumList
typedef struct_list*List;

struct_list{
	link first;
};

typedef struct_node node;
typedef node*link;

struct_node{
	int value;
	link next;

};

int sumList(List list) {
	int sum = 0;
	link current;
	current = list -> first;
	while (current != NULL) {
		sum += current->value;
		current = current->next;
	}

	return sum;
}



//deleting lists

int deleteFront(List list) {
	assert(list != NULL)
	assert(list->first != NULL);

	link firstNode = list->first;
	int value = firstNode->value;

	list->first = firstNode->next;

	free(firstNode);

	return value;
}

int deletelast(List list) {
	assert(list != NULL);

	link curr = list-> first;
	link prev = NULL;

	while(curr->next != NULL) {
		prev = curr;
		curr = curr->next;
	}

	int value = curr->value;
	if (prev != NULL) {
		prev->next = curr->next;
	} else {
		list->first = NULL;
	}

	free(curr);

	return EXIT_SUCCESS;
}

int copy(List olist) {

	List copylist = malloc(sizeof(olist));

	link curro = olist->first;
	link currc = copylist->first;

	while(curro != NULL) {
		currc->value = curro->value;
		curro = curro->next;
		currc = currc->next;
	}

}



int copy(List l) {
	List copiedList = malloc(sizeof(struct_list));
	copiedList->first = NULL;

	link endList = NULL;

	//for every node in teh original list
	//make a copy and connect it to end of the new list
	link curr = l->first;

	while(curr != NULL) {
		//craete a copy of the cur node
		n = malloc(sizeof(struct_node));
		n->value = curr->value;
		n->next = NULL;

		// connecting the new node to the copiedList
		if (copiedList->first == NULL) {
			copiedList->first = n;
			endList = n;
		} else {
			endList->next = n;
			endList = n;
		}
		//moves it along to teh next node
		curr = curr->next;
	}
}