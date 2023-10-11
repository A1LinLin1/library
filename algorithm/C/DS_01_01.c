// C program to insert a node in the sorted linked list
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void insert(struct Node **head, int data)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;

	if (*head == NULL || (*head)->data >= data)
	{
		newNode->next = *head;
		*head = newNode;
	}
	else
	{
		struct Node *current = *head;
		while (current->next != NULL && current->next->data < data)
		{
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

void printList(struct Node *head)
{
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	struct Node *head = NULL;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		insert(&head, x);
	}
	printf("List: ");
	printList(head);
	return 0;
}
