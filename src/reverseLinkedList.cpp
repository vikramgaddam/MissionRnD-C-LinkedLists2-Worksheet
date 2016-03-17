/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {

	if (head == NULL)return NULL;

	struct node *temp1, *temp2;

	if (head->next == NULL)return head;

	if(head->next->next == NULL)
	{
		temp1 = head->next;
		temp1->next = head;
		head->next = NULL;
		return temp1;
	}

	temp1 = head;

	

	head = head->next;

	temp1->next = NULL;

	while (head != NULL)
	{
		temp2 = head->next;
		head->next = temp1;
		temp1 = head;
		head = temp2;
	}
	
	return temp1;
}
