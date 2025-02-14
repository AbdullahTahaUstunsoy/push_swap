#include "push_swap.h"


 int	get_max_bits(t_stack **stack)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int		size;
	int		max_bits;
	int		i;
	int		j;
	t_stack	*node;

	size = ft_lstsize(*a);
	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			node = *a;
			if (((node->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

void	ft_sort(t_stack **a, t_stack **b, int size)
{
	if (is_sorted(a) || size <= 1)
		return ;
	if (size <= 5)
		return (basic_sort(a, b));
	else
		radix_sort(a, b);
}
