/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if ((head1 == NULL) && (head2==NULL))
	return NULL;
	if (head1 == NULL)
		return head2;

	if (head2 == NULL)
		return head1;

	struct node *res = head1;
	struct node *temp1, *temp2;
	temp1 = head1;
	temp2 = head2;

	if (head1->num < head2->num)
	{
		res = head1;
		head1 = head1->next;
	}
	else
	{
		res = head2;
		head2 = head2->next;
	}
	temp1 = res;
	while ((head1 != NULL) && (head2 != NULL))
	{
		if (head1->num < head2->num)
		{
			res->next = head1;
			res = res->next;
			head1 = head1->next;
		}
		else
		{
			res->next = head2;
			res = res->next;
			head2 = head2->next;
		}
	}

	if (head1 != NULL)
	{
		res->next = head1;
	}
	if (head2 != NULL)
	{
		res->next = head2;
	}
	return temp1;
}
