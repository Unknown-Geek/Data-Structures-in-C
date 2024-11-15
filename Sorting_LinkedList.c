#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
} *temp, *cursor1, *cursor2;

struct Node *insert(int data, struct Node *head)
{
	struct Node *cursor;
	temp = malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	if (head == NULL)
	{
		return temp;
	}

	cursor = head;
	while (cursor->next != NULL)
	{
		cursor = cursor->next;
	}
	cursor->next = temp;
	return head;
}

void display(struct Node *head)
{
	if (head == NULL)
		return;

	cursor1 = head;
	while (cursor1 != NULL)
	{
		printf("%d ", cursor1->data);
		cursor1 = cursor1->next;
	}
	printf("\n");
}

int main()
{
	struct Node *list1 = NULL, *list2 = NULL, *result = NULL;
	struct Node *current, *prev, *cursor1, *cursor2;
	int ch = 0;
	struct Node *min;
	int temp;
	printf("List 1 : Enter -1 to stop.\n");
	while (ch != -1)
	{
		scanf("%d", &ch);
		if (ch != -1)
			list1 = insert(ch, list1);
	}
	printf("\nList 1 : ");
	display(list1);

	cursor1 = list1;
	while (cursor1 != NULL)
	{
		cursor2 = cursor1->next;
		min = cursor1;
		while (cursor2 != NULL)
		{
			if (cursor2->data < min->data)
				min = cursor2;
			cursor2 = cursor2->next;
		}
		int temp = min->data;
		min->data = cursor1->data;
		cursor1->data = temp;
		cursor1 = cursor1->next;
	}
	display(list1);
}
