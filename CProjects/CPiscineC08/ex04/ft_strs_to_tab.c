/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbondare <kbondare@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:35:34 by kbondare          #+#    #+#             */
/*   Updated: 2024/09/18 16:27:12 by kbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		src_len;
	int		i	;

	src_len = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (src_len + 1));
	i = 0;
	if (str == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_free_stock_str_array(struct s_stock_str *res, int count)
{
	while (count > 0)
	{
		count--;
		free(res[count].copy);
	}
	free(res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*res;

	res = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		res[i].size = ft_strlen(av[i]);
		res[i].str = av[i];
		res[i].copy = ft_strdup(av[i]);
		if (res[i].copy == NULL)
		{
			ft_free_stock_str_array(res, i);
			return (NULL);
		}
		i++;
	}
	res[i].str = NULL;
	return (res);
}

/*
#include <stdio.h>

typedef struct s_stock_str
{
	int size;
	char *str;
	char *copy;
} t_stock_str;

int main(void)
{
	char *test_strings[] = {
		"Hello",
		"42Berlin",
		"C Piscine",
		"Hello world!",
	};
	int num_strings = 4;
	struct s_stock_str *result = ft_strs_to_tab(num_strings, test_strings);
	if (result == NULL)
	{
		printf("Error: Memory allocation failed.\n");
		return (1);
	}
	for (int i = 0; result[i].str != NULL; i++)
	{
		printf("String %d:\n", i + 1);
		printf("  Original: %s\n", result[i].str);
		printf("  Copy:     %s\n", result[i].copy);
		printf("  Length:   %d\n\n", result[i].size);
	}
    return (0);
}
*/
