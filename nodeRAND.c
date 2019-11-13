#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    srand(time(0));
    int size = 5;
    scanf("%d", &size);
    struct node *first, *current, *last, *tmp, *e;
    first = (struct node *)malloc(sizeof(struct node));
    
    
    
    last = first;
    for (int i = 2; i <= size; i++)
    {
        current = (struct node *)malloc(sizeof(struct node));
        current->next = NULL;
        last->next = current;
        last = current;
    }
    
    int min = 999, devider = min, index = 1, count = 1, prelastind = 1;
    current = first;
    while (current){
        current->data = rand() % devider - 500;
        if (current->data <= min) {
            min = current->data;
            index = count;
        }
        count++;
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n%d %d\n", min, index);

    current = first;
    while (prelastind < size - 1)
    {
        current = current->next;
        prelastind++;
    }
    tmp = current;
    e = tmp->next;

    current = first;
    if (index != size && index != 1)
	{
		count = 1;
		while (count < index - 1)
		{
			current = current->next;
			count++;
		}
		last = current;
        current = current->next;
        if (min != tmp->data){
            e->next = current->next;
            last->next = tmp->next;
            tmp->next = current;
            current->next = NULL;
        }
        else{
            e->next = last->next;
            last->next = current->next;
            current->next = NULL;
        }
	}
    if (index == 1){
        first = tmp->next;
        e->next = current->next;
        tmp->next = current;
        current->next = NULL;
    }

    current = first;
    while (current)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");

    current = first;
    while (current)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    free(current);
    return 0;
}
