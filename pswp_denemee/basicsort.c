#include "push_swap.h"


void	sort_3else(t_stack **a, t_stack *current, int min)
{
	if (current->next->index == min)
		ra(a);
	else
	{
		sa(a);
		rra(a);
	}
}

void	sort_3(t_stack **a)
{
	t_stack	*current;
	int		min;
	int		second_min;

	current = *a;
	min = get_min(a, -1);
	second_min = get_min(a, min);
	if (is_sorted(a))
		return ;
	if (current->index == min && current->next->index != second_min)
	{
		ra(a);
		sa(a);
		rra(a);
	}
	else if (current->index == second_min)
	{
		if (current->next->index == min)
			sa(a);
		else
			rra(a);
	}
	else
		sort_3else(a, current, min);
}

void	sort_4(t_stack **a, t_stack **b)
{
	int	position;

	if (is_sorted(a))
		return ;
	position = get_position(a, get_min(a, -1));
	if (position == 1)
		ra(a);
	else if (position == 2)
	{
		ra(a);
		ra(a);
	}
	else if (position == 3)
		rra(a);
	if (is_sorted(a))
		return ;
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	position;

	position = get_position(a, get_min(a, -1));
	if (position == 1)
		ra(a);
	else if (position == 2)
	{
		ra(a);
		ra(a);
	}
	else if (position == 3)
	{
		rra(a);
		rra(a);
	}
	else if (position == 4)
		rra(a);
	if (is_sorted(a))
	{
		return ;
	}
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
}

void	basic_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (is_sorted(a) != 0 || size <= 1)
		return ;
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}
int	get_min(t_stack **stack, int val)
{
	t_stack	*current;
	int		min;

	current = *stack;
	min = current->index;
	while (current->next != NULL)
	{
		current = current->next;
		if ((current->index < min) && current->index != val)
			min = current->index;
	}
	return (min);
}

int	get_position(t_stack **stack, int inx)
{
	t_stack	*current;
	int		position;

	position = 0;
	current = *stack;
	while (current)
	{
		if (current->index == inx)
			break ;
		position++;
		current = current->next;
	}
	return (position);
}