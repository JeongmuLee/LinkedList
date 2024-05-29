#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int element;

typedef struct LinkedList
{
	element data;
	element subdata;
	struct linkedlist* link;
}linkedlist;

linkedlist* Insertion(linkedlist* head, linkedlist* pre, element value);

linkedlist* makeGameSet(int stage);

linkedlist* makeUserSet(int stage);

bool compareEachSet(linkedlist* game, linkedlist* user);
#endif // !LINKEDLIST_H_
