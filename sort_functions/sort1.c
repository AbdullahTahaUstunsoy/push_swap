/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:40:44 by austunso          #+#    #+#             */
/*   Updated: 2025/02/17 21:53:30 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_max_bits(t_stack **stack)
{
	t_stack	*current;
	int		max;
	int		max_bits;

	current = *stack;
	max = 0;
	max_bits = 0;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	while (max)
	{
		max >>= 1;
		max_bits++;
	}
	return (max_bits);
}

static void	bit_iteration(t_stack **a, t_stack **b, int bit_position, int size)
{
	t_stack	*node;
	int		j;

	j = 0;
	while (j < size)
	{
		node = *a;
		if (((node->index >> bit_position) & 1) == 1)
			ra(a);
		else
			pb(a, b);
		j++;
	}
	while (*b)
		pa(a, b);
}

static void	radix_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	max_bits;
	int	bit_position;

	size = ft_lstsize(*a);
	max_bits = get_max_bits(a);
	bit_position = 0;
	while (bit_position < max_bits)
	{
		bit_iteration(a, b, bit_position, size);
		bit_position++;
	}
}

void	ft_sort(t_stack **a, t_stack **b, int size)
{
	if (is_sorted(a) || size <= 1)
		return ;
	if (size <= 5)
		basic_sort(a, b);
	else
		radix_sort(a, b);
}
