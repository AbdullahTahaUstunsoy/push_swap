/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:38:16 by austunso          #+#    #+#             */
/*   Updated: 2025/02/17 20:38:33 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **data)
{
	t_stack	*first;
	t_stack	*second;

	if (ft_lstsize(*data) < 2)
		return ;
	first = (*data);
	second = (*data)->next;
	first->next = second->next;
	second->next = first;
	*data = second;
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
	write(1, "ss\n", 3);
}
