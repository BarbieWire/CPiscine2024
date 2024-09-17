/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbondare <kbondare@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:58:17 by kbondare          #+#    #+#             */
/*   Updated: 2024/09/16 13:28:47 by kbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*ptr;
	int	size;

	size = max - min;
	if (min >= max)
		return (0);
	ptr = (int *)malloc(sizeof(int) * size);
	if (ptr == NULL)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (min < max)
	{
		ptr[i] = min;
		min++;
		i++;
	}
	*range = ptr;
	return (size);
}

/*
#include <stdio.h>
int main(void)
{
	int *range;
	int size;
	int i;
	size = ft_ultimate_range(&range, 5, 10);
	if (size == 0)
	{
		printf("Min is greater than or equal to max.\n");
	}
	else if (size == -1)
	{
		printf("Memory allocation failed.\n");
	}
	else
	{
		printf("Range size: %d\n", size);
		printf("Range: ");
		for (i = 0; i < size; i++)
		{
			printf("%d ", range[i]);
		}
		printf("\n");
		free(range);
	}
	return 0;
}*/
