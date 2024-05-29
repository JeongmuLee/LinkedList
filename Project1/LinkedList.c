#include "LinkedList.h"

linkedlist* Insertion(linkedlist* head, linkedlist* pre, element value)
{
	linkedlist* next = (linkedlist*)malloc(sizeof(linkedlist));
	next->data = value;
	next->link = pre->link;
	pre->link = next;
	return head;
}

linkedlist* makeGameSet(int stage)
{
	linkedlist* head = NULL;

	head = (linkedlist*)malloc(sizeof(linkedlist));
	
	head->data = rand() % 10;
	head->link = NULL;

	for (int i = 0; i < stage + 1; i++)
	{
		linkedlist* search = head;
		linkedlist* pre = NULL;
		int rdata = rand() % 10;

		do 
		{
			pre = search;
			search = search->link;
		} while (pre->link != NULL);

		Insertion(head, pre, rdata);
	}
	return head;
}

linkedlist* makeUserSet(int stage)
{
	linkedlist* head = NULL;
	int userinput = 0;
	head = (linkedlist*)malloc(sizeof(linkedlist));

	head->link = NULL;

	scanf_s("%d", &userinput);
	head->data = userinput;
	for (int i = 0; i < stage + 1; i++)
	{
		linkedlist* input = head;
		linkedlist* pre = NULL;
		scanf_s("%d", &userinput);
		{
			do
			{
				pre = input;
				input = input->link;
			} while (pre->link != NULL);

			Insertion(head, pre, userinput);
		}
	}
	return head;
}

bool compareEachSet(linkedlist* game, linkedlist* user)
{
	do
	{
		if (game->data != user->data)
		{
			return false;
			break;
		}
		game = game->link;
		user = user->link;
	} while (game!= NULL);
	return true;
}