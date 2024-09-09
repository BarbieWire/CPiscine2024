/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbondare <kbondare@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:49:23 by kbondare          #+#    #+#             */
/*   Updated: 2024/09/05 10:57:58 by kbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	statement1;
	int	statement2;	
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		statement1 = str[i] >= 'A' && str[i] <= 'Z';
		statement2 = str[i] >= 'a' && str[i] <= 'z';
		if (!(statement1 || statement2))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
