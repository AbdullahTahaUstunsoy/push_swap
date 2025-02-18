/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:38:41 by austunso          #+#    #+#             */
/*   Updated: 2025/02/17 23:03:03 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_free(t_stack **a, t_stack **b)
{
	free_stack(a, b);
	print_error();
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;
	char	**args;

	if (argc < 2)
		return (0);
	ft_control(argc, argv);
	args = join_args(argc, argv);
	a = (t_stack **)malloc(sizeof(t_stack *));
	b = (t_stack **)malloc(sizeof(t_stack *));
	if (a == NULL || b == NULL)
		stack_free(a, b);
	*a = NULL;
	*b = NULL;
	create_stack(a, args);
	if (is_sorted(a))
	{
		free_args(args);
		free_stack(a, b);
		return (0);
	}
	ft_sort(a, b, ft_lstsize(*a));
	free_stack(a, b);
	free_args(args);
	return (0);
}
