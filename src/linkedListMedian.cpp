/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {

	if (head == NULL)return -1;

	int len = 0;
	struct node *temp = head;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	temp = head;
	if (len % 2 == 0)
	{
		len = len / 2;
		int i = 0;
		while (i != len - 1)
		{
			temp = temp->next;
			i++;
		}
		int sum=0;
		sum = sum + temp->num;
		temp = temp->next;
		sum = sum + temp->num;

		return sum / 2;

	}
	else
	{
		len = len / 2;
		int i = 0;
		while (i!=len)
		{
			temp = temp->next;
			i++;

		}
		
	}
	return temp->num;
}
