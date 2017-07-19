#include <stdio.h>
#include <stdlib.h>

enum choice {
	CREATE_LIST = 1,
	DISPLAY,
	ADD_BEG,
	ADD_AFTER_ITEM,
};

struct doubleList {
	struct doubleList *prev;
	int data;
	struct doubleList *next;
};
/***************Macro*******************************/
#define size_of(type) (char *)(&type + 1) - (char *)(&type)

/****************Function prototype******************/
void create_double_list(struct doubleList **start);
void add_to_empty(struct doubleList **, int);
struct doubleList* add_at_beg(struct doubleList *, int);
void add_at_end(struct doubleList *, int);
void add_after_item(struct doubleList *, int, int);
void display_doubly_list(struct doubleList *);

int main()
{
	int choice, data, item;
	struct doubleList *start = NULL;

	while (1){
		printf("1 for Create Double LinkList\n");
		printf("2 for Display Double LinkList\n");
		printf("3 to add at beginning\n");
		printf("4 to add after item\n");

		scanf("%d", &choice);

		switch (choice){
		
		case CREATE_LIST:
			create_double_list(&start);
		break;
		case DISPLAY:
			display_doubly_list(start);
		break;
		case ADD_BEG:
			printf("Enter the data for the node\n");
			scanf("%d", &data);
			start = add_at_beg(start, data);
		break;
		case ADD_AFTER_ITEM:
			printf("Enter the item after new node is inserted\n");
			scanf("%d", &item);
			printf("Enter the data for the node\n");
			scanf("%d", &data);
			add_after_item(start, data, item);
		break;
		default:
			printf("Wrong Choice\n");
		}
	}
	return 0;
}

/********************Function to Create***********************/
void create_double_list(struct doubleList **start)
{
	unsigned int len;
	int data, var;
	printf("Enter the length of the list\n");
	scanf("%d", &len);

	if (!len)
		return ;
	printf("Enter the data for the node\n");
	scanf("%d", &data);
	add_to_empty(start, data);

	for(var = 1; var < len; var++){
		printf("Enter the data for the node\n");
		scanf("%d", &data);
		add_at_end((*start), data);
	}
}

/*********************Function to add in Empty List***********/
void add_to_empty(struct doubleList **start, int data)
{
	struct doubleList *temp;
	temp = (struct doubleList *)malloc(size_of(temp));

	temp->prev = NULL;
	temp->next = NULL;
	temp->data = data;
	(*start) = temp;
}

/******************Function to add at beginning*************/
struct doubleList* add_at_beg(struct doubleList *start, int data)
{
	struct doubleList *temp = NULL;
	temp = (struct doubleList *)malloc(size_of(*temp));
	temp->data = data;
	temp->prev = NULL;
	temp->next = start;
	start->prev = temp;

	return temp;
	
}
/******************Function to add at the end****************/
void add_at_end(struct doubleList *start, int data)
{
	struct doubleList *temp;
	temp = (struct doubleList *)malloc(size_of(temp));
	while (start->next != NULL)
		start = start->next;
	start->next = temp;
	temp->prev = start;
	temp->data = data;
	temp->next = NULL;
}
/*******************Function to add after item************/
void add_after_item(struct doubleList *start, int data, int item)
{
	struct doubleList *temp;
	if (start == NULL){
		printf("List is empty\n");
		return ;
	}
	temp = (struct doubleList *)malloc(size_of(temp));
	temp->data = data;
	while (start != NULL){
		if (start->data == item){
			temp->prev = start;
			temp->next = start->next;
			if (start->next != NULL)
				start->next->prev = temp;
			start->next = temp;
			return ;
		}
		start = start->next;
	}
		printf("%d item is not found in list\n", item);
}

/*******************Function to display*******************/
void display_doubly_list(struct doubleList *start)
{
	if (start == NULL){
		printf("List is empty\n");
		return ;
	}
	printf("Elemenists in the list are\n");

	while((start) != NULL){
		printf("%d ", (start)->data);
		(start) = (start)->next;
	}
	printf("\n");
}
