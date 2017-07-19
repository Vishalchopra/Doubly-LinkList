#include <stdio.h>

enum choice {
	CREATE_LIST,
};

struct doubleList {
	struct doubleList *prev;
	int data;
	struct doubleList *next;
};
/****************Function prototype******************/
void create_double_list(struct doubleList **start)

int main()
{
	int choice;
	struct doubleList *start = NULL;

	while (1){
		printf("1 for Create Double LinkList\n");

		scanf("%d", &choice);

		switch (choice){
		
		case CREATE_LIST:
			create_double_list(&start);
		}
	}
	return 0;
}

void create_double_list(struct doubleList **start)
{
	unsigned int len;
	int data;
	printf("Enter the length of the list\n");
	scanf("%d", &len);

	if (!len)
		return ;
	printf("Enter the data for the node\n");
	scanf("%d", &data);
	add_at_beg(&start, data);
}
