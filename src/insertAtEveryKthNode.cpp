/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	
	struct node *main = head;
	if (head==NULL)
	return NULL;

	if (K <= 0)
		return NULL;

	if (K == 1)
	{
		while (head != NULL)
		{
			struct node *temp1 = head->next;
			struct node *temp = (struct node*)malloc(sizeof(struct node));
			temp->num = K;
			head->next = temp;
			temp->next = temp1;
			head = temp->next;
		}
		return main;

	}

	int i = 1;

	while (head != NULL)
	{
		if (i%K == 0)
		{
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			temp->num = K;
			struct node *temp1 = head->next;
			head->next = temp;
			temp->next = temp1;
			head = head->next;
		}
		i++;
		head = head->next;
	}


	return main;


}
