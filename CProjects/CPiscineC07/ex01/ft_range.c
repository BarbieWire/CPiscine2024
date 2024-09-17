/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbondare <kbondare@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:20:55 by kbondare          #+#    #+#             */
/*   Updated: 2024/09/16 12:57:11 by kbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*ptr;

	if (min >= max)
		return (NULL);
	ptr = (int *)malloc(sizeof(int) * (max - min));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (min < max)
	{
		ptr[i] = min;
		min++;
		i++;
	}
	return (ptr);
}

/*
#include <stdio.h>
int	main(void)
{
	int min = 20;
	int max = 40;
	int *result;
	int i;
	result = ft_range(min, max);
	if (result == NULL)
	{
		printf("Range is empty or memory allocation failed.\n");
		return (1);
	}
	printf("Range from %d to %d:\n", min, max);
	for (i = 0; i < max - min; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");
	free(result);
	return (0);
}*/
