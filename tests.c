#include "push_swap.h"
void	test_print(t_stack *first)
{
	t_stack *temp;

	temp = first;
	printf(" A\n");
	while(temp->next && temp->next != first)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	if(temp)
		printf("%d\n", temp->data);
}
void test_print(t_stack *stack, const char *name)
{
    t_stack *current;
    int count = 0;

    printf("Stack %s:\n", name);
    if (!stack)
    {
        printf("  [Empty]\n\n");
        return;
    }

    current = stack;
    do
    {//stack = %c, current = %p, previous = %p, next = %p
        printf("  Node %d: data = %d, ss = %d\n",
               count++, current->data, current->sub_stack/* current->stack, (void *)current,
			   (void *)current->previous, (void *)current->next */);
        current = current->next;
    } while (current && current->data != stack->data);

    printf("\n");
}
/* void	test_print(t_stack *first)
{
	t_stack *temp;

	if (!first)
	{
		ft_printf("stack is empty\n");
		return ;
	}
	temp = first;
	printf(" %c\n", first->stack);
	while(temp->next && temp->next != first)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	if(temp->data)
		printf("%d\n", temp->data);
} */
void test_print(t_stack *stack, const char *name)
{
    t_stack *current;
    int count = 1;

    printf("Stack %s:\n", name);
    if (!stack)
    {
        printf("  [Empty]\n\n");
        return;
    }

    current = stack;
    do
    {//stack = %c, current = %p, previous = %p, next = %p
        printf("  Node %d: data = %d, size = %d\n",
               count++, current->data, current->size/* current->stack, (void *)current,
			   (void *)current->previous, (void *)current->next */);
        current = current->next;
    } while (current && current->data != stack->data);

    printf("\n");
}