/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:41:14 by austunso          #+#    #+#             */
/*   Updated: 2025/02/17 23:02:00 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*join_with_space(char *joined, char *arg)
{
	char	*temp;
	char	*new_joined_str;

	temp = ft_strjoin(joined, " ");
	if (temp == NULL)
	{
		free(joined);
		print_error();
	}
	new_joined_str = ft_strjoin (temp, arg);
	free(temp);
	free(joined);
	if (new_joined_str == NULL)
		print_error();
	return (new_joined_str);
}

char	**join_args(int argc, char **argv)
{
	char	**args;
	char	*joined_str;
	int		i;

	joined_str = ft_strdup("");
	if (joined_str == NULL)
		print_error();
	i = 1;
	while (i < argc)
	{
		joined_str = join_with_space(joined_str, argv[i]);
		i++;
	}
	args = ft_split(joined_str, ' ');
	free(joined_str);
	if (args == NULL)
		print_error();
	return (args);
}

int	get_minimum_index(t_stack **stack, int value)
{
	t_stack	*temp;
	int		min_index_value;

	temp = *stack;
	min_index_value = temp -> index;
	while (temp -> next != NULL )
	{
		temp = temp->next;
		if ((temp->index < min_index_value) && (temp->index != value))
			min_index_value = temp->index;
	}
	return (min_index_value);
}

int	get_position(t_stack **stack, int inx)
{
	t_stack	*temp;
	int		position;

	temp = *stack;
	position = 0;
	while (temp != NULL)
	{
		if (temp->index == inx)
			break ;
		position++;
		temp = temp->next;
	}
	return (position);
}
