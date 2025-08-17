/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicsort1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:39:06 by austunso          #+#    #+#             */
/*   Updated: 2025/02/17 21:47:16 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_2(t_stack **a)
{
	t_stack	*current;

	current = *a;
	if (current->number > current->next->number)
		sa(a);
}

static void	sort_3(t_stack **a)
{
	t_stack	*current;
	int		min;
	int		second_min;

	current = *a;
	min = get_minimum_index (a, -1);
	second_min = get_minimum_index(a, min);
	if ((current->index == min) && (current->next->index != second_min))
	{
		rra(a);
		sa(a);
	}
	else if ((current->index == second_min) && (current->next->index == min))
		sa(a);
	else if ((current->index == second_min) && (current->next->index != min))
		rra(a);
	else if ((current->index != min) && (current->next->index == second_min))
	{
		sa(a);
		rra(a);
	}
	else if ((current->index != second_min) && (current->next->index == min))
		ra(a);
}

static void	sort_4(t_stack **a, t_stack **b)
{
	int	position;

	position = get_position(a, get_minimum_index(a, -1));
	if (position == 1)
		sa(a);
	else if (position == 2)
	{
		rra(a);
		rra(a);
	}
	else if (position == 3)
		rra(a);
	if (is_sorted(a))
		return ;
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

static void	sort_5(t_stack **a, t_stack **b)
{
	int	position;

	position = get_position(a, get_minimum_index(a, -1));
	if (position == 1)
		sa(a);
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
		return ;
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
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}
