/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:40:54 by austunso          #+#    #+#             */
/*   Updated: 2025/02/17 23:21:07 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	if (current == NULL)
	{
		return (1);
	}
	while (current->next)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}

static t_stack	*get_next_min(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last_found_min;

	temp = *stack_a;
	last_found_min = NULL;
	while (temp != NULL)
	{
		if ((temp->index == -1)
			&& (last_found_min == NULL
				|| last_found_min ->number > temp->number))
			last_found_min = temp;
		temp = temp -> next;
	}
	return (last_found_min);
}

static void	index_assignment(t_stack **stack_a)
{
	t_stack	*current_min;
	int		index;

	index = 0;
	current_min = get_next_min(stack_a);
	while (current_min != NULL)
	{
		current_min ->index = index;
		index++;
		current_min = get_next_min(stack_a);
	}
}

void	create_stack(t_stack **stack_a, char **args)
{
	t_stack	*new;
	int		i;

	i = 0;
	while (args[i] != NULL)
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack_a, new);
		i++;
	}
	index_assignment(stack_a);
}
