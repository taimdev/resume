// List ADT
// 1917 16s1 Linked List Sample Prac
// Read the question sheet first

typedef struct _link *link;

struct _link{
	int data;
	link next;
};

link newNode(int data);
link append(link head, link node);
link createListWithKeys(int * keys, int n);
void freeList(link head);
void printList(link head);

// -------------------------------
// Functions you need to implement
// -------------------------------
// q1
int sumEveryN(link head, int n);

// q2
link nodeFromEnd(link head, int n);

// q3
link newReverseList(link head);

// q4
int findOrder(link head);

// q5
link deleteEveryNNode(link head, int n);

// q6
link zip(link a, link b);

// q7
link intersection(link a, link b);

// q8
link sublink(link a, link b);

// q9
int isPalindrome(link head);
// -------------------------------
