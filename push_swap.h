/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 23:29:29 by austunso          #+#    #+#             */
/*   Updated: 2025/02/17 23:31:03 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				index;
	int				number;
	struct s_stack	*next;
}				t_stack;

void	print_error(void);

void	ft_control(int argc, char *argv[]);

void	ft_control3(int is_num_flag, int is_exist_flag, char **args);
void	free_args(char **args);
void	free_stack(t_stack **stack_a, t_stack **stack_b);

long	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);

char	**ft_split(char const *s, char c);

void	create_stack(t_stack **stack_a, char **args);

int		is_sorted(t_stack **stack);

t_stack	*ft_lstnew(int content);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_a);
void	ss(t_stack **a, t_stack **b);

void	ra(t_stack **stack_a);
void	ra(t_stack **stack_a);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	basic_sort(t_stack **a, t_stack **b);

void	ft_sort(t_stack **a, t_stack **b, int size);

char	**join_args(int argc, char **argv);
int		get_minimum_index(t_stack **stack, int value);
int		get_position(t_stack **stack, int inx);

#endif