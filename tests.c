#include "push_swap.h"
void	test_print(t_stack *first)
{
	t_stack *temp;

	temp = first;
	printf(" A\n");
	while(temp->next != first)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	printf("%d\n", temp->data);
}