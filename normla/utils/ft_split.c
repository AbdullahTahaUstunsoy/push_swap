/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austunso <austunso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:40:29 by austunso          #+#    #+#             */
/*   Updated: 2025/02/17 21:56:44 by austunso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	*del(char **ptr, int len)
{
	int	a;

	if (!ptr)
		return (NULL);
	a = 0;
	while (a < len)
	{
		free(ptr[a]);
		a++;
	}
	free(ptr);
	return (NULL);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		ptr = (char *)malloc(sizeof(char));
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (ft_strlen(s) < len)
		len = ft_strlen(s) - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}

static int	ft_count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s == '\0')
			return (count);
		while (*s != '\0' && *s != c)
			s++;
		count++;
	}
	return (count);
}

static int	ft_count_chars(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		len;

	len = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		str[len] = ft_substr(s, 0, ft_count_chars(s, c));
		if (str[len] == NULL)
			return (del(str, len));
		s += ft_count_chars(s, c);
		len++;
	}
	str[len] = NULL;
	return (str);
}
