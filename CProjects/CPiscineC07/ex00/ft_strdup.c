/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbondare <kbondare@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:54:23 by kbondare          #+#    #+#             */
/*   Updated: 2024/09/16 12:16:58 by kbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

/*
#include <stdio.h>
int	main(void)
{
	char	*original = "Hello, world!";
	char	*duplicate;

	duplicate = ft_strdup(original);
	if (duplicate == NULL)
	{
		printf("Memory allocation failed.\n");
		return 1;
	}
	printf("Original: %s\n", original);
	printf("Duplicate: %s\n", duplicate);
	free(duplicate);
	return (0);
}*/
