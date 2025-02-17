/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:39:19 by austunso          #+#    #+#             */
/*   Updated: 2025/02/17 21:22:22 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_num(char *arg)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0 ;
	if (arg[i] == '-')
		i++;
	if (arg[i] == '\0')
		flag = 1;
	while (arg[i] != '\0')
	{
		if ((arg[i] < '0' || arg[i] > '9') || (ft_strlen(arg) > 12))
			flag = 1;
		i++;
	}
	return (flag);
}

static int	is_exist(char **args)
{
	int	temp1;
	int	temp2;
	int	i;
	int	j;

	temp1 = 0;
	temp2 = 0;
	i = 0;
	j = 0;
	while (args[i] != NULL)
	{
		temp1 = ft_atoi(args[i]);
		j = i + 1;
		while (args[j] != NULL)
		{
			temp2 = ft_atoi(args[j]);
			if (temp1 == temp2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	ft_control2(char *str)
{
	char	**args;
	int		is_num_flag;
	int		is_exist_flag;
	int		i;

	args = ft_split(str, ' ');
	is_num_flag = 0;
	is_exist_flag = 0;
	i = 0;
	while (args[i] != NULL)
	{
		if (is_num(args[i]) == 1)
			is_num_flag = 1;
		i++;
	}
	is_exist_flag = is_exist(args);
	free(str);
	ft_control3(is_num_flag, is_exist_flag, args);
}

static void	ft_join1(int argc, char **argv, int total_size)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	str = (char *)malloc(sizeof(char) * total_size + 1 +(argc -1 -1));
	if (str == NULL)
		exit (0);
	i = 1;
	j = 0;
	while (i < argc)
	{
		k = 0;
		while (argv[i] != NULL && argv[i][k] != '\0')
		{
			str[j] = argv[i][k++];
			j++;
		}
		if (i != argc - 1)
			str[j++] = ' ';
		i++;
	}
	str[j] = '\0';
	ft_control2(str);
}

void	ft_control(int argc, char **argv)
	{
	int	i;
	int	j;
	int	flag;
	int	size;

	i = 1;
	size = 0;
	while (i < argc)
	{
		j = 0;
		flag = 0;
		while (argv[i] != NULL && argv[i][j] != '\0')
		{
			if ((argv[i][j] != 32) && (argv[i][j] != '\t'))
				flag = 1;
			size++;
			j++;
		}
		if (flag == 0)
			print_error();
		i++;
	}
	ft_join1(argc, argv, size);
}
