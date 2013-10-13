#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	struct Node *next;
	char name[128];
	int num;
};

#define LIST_HEAD(name)	\
	struct Node *name = (struct Node *) malloc(sizeof(struct Node))




void changeVal(int *);
void addNode(struct Node **head, int num, char *name);
void showAllNodes(struct Node *head);
int getListNum(struct Node *head);


int main(int argc, char *argv)
{
	struct Node *head = NULL;
	int var = 0;

	var = 100;
	changeVal(&var);
	printf("var = %d\n", var);

	addNode(&head, 100, "first");
	printf("head @ %#x, name = %s, num = %d\n", 
		head, head->name, head->num);

	addNode(&head, 20, "peter");
	addNode(&head, 1, "jack");

	showAllNodes(head);

	printf("Total elements in list is %d\n", getListNum(head));

	showAllNodes(head);

	return 0;
}


void changeVal(int *var)
{
	*var = *var + 100;
}


int getListNum(struct Node *head)
{
	int ret = 0;
	
	while(head != NULL)
	{
		ret += 1;
		head = head->next;
	}
	

	return ret;
}

void addNode(struct Node **head, int num, char *name)
{
	struct Node *node = NULL;

	if(*head == NULL)
	{
		printf("%s(): create first head\n", __func__);

		*head = (struct Node *) malloc(sizeof(struct Node));

		(*head)->next = NULL;
		(*head)->num = num;
		strcpy((*head)->name, name);
	}
	else
	{
		node = (*head);

		/* find the last node */
		while(node->next != NULL)
		{
			node = node->next;
		}

		printf("find last node %s\n", node->name);

		node->next = (struct Node *) malloc(sizeof(struct Node));
		node->next->num = num;
		strcpy(node->next->name, name);

		printf("Creating node %s, num %d\n", 
			node->next->name, node->next->num);
	}
}

void showAllNodes(struct Node *head)
{
	struct Node *node = NULL;

	printf("\nDisplay all nodes\n");

	if(head != NULL)
	{
		node = head;

		while(1)
		{
			printf("Node: %s\nnum: %d\n\n",
				node->name, node->num);

			if(node->next != NULL)
			{
				node = node->next;
			}
			else
			{
				printf("No nodes \n");
				break;
			}
		}
	}
	else
	{
		printf("List is empty.\n");
	}
}


