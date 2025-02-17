/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:38:55 by austunso          #+#    #+#             */
/*   Updated: 2025/02/17 20:39:52 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
