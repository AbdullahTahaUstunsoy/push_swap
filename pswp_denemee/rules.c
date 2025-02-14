#include "push_swap.h"

void	rotate(t_stack **list)
{
	t_stack	*first;
	t_stack	*end;

	if (ft_lstsize(*list) < 2)
		return ;
	first = *list;
	end = ft_lstlast(*list);
	*list = (*list)->next;
	end->next = first;
	first->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*add;

	if (*b != NULL)
	{
		add = *b;
		*b = (*b)->next;
		add->next = *a;
		*a = add;
		write(1, "pa\n", 3);
	}
	return ;
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*add;

	if (*a != NULL)
	{
		add = *a;
		*a = (*a)->next;
		add->next = *b;
		*b = add;
		write(1, "pb\n", 3);
	}
	return ;
}


void	swap(t_stack **data)
{
	int	tmp;

	if (ft_lstsize(*data) < 2)
		return ;
	tmp = (*data)->next->number;
	(*data)->next->number = (*data)->number;
	(*data)->number = tmp;
}

void	sa(t_stack **a)
{
	swap((a));
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap((b));
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap((a));
	swap((b));
	write(1, "sb\n", 3);
}

void	rrotate(t_stack **list)
{
	t_stack	*beforelast;
	t_stack	*last;

	beforelast = *list;
	while (beforelast->next->next)
		beforelast = beforelast->next;
	last = ft_lstlast(*list);
	last->next = *list;
	*list = last;
	beforelast->next = NULL;
}

void	rra(t_stack **a)
{
	rrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rrotate(b);
	write(1, "rra\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rrotate(a);
	rrotate(b);
	write(1, "rrr\n", 4);
}

