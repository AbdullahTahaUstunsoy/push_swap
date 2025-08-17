/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:39:01 by austunso          #+#    #+#             */
/*   Updated: 2025/02/16 22:06:37 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rrotate(t_stack **list)
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
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rrotate(a);
	rrotate(b);
	write(1, "rrr\n", 4);
}
