/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbondare <kbondare@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:10:03 by kbondare          #+#    #+#             */
/*   Updated: 2024/09/05 14:32:39 by kbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 'a' - 'A');
	return (c);
}

int	ft_isalnum(char c)
{
	return ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z') 
		|| (c >= 'A' && c <= 'Z'));
}

char	*ft_strcapitalize(char *str)
{
	int	in_word;
	int	i;

	i = 0;
	in_word = 0;
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]))
		{
			if (!in_word)
			{
				str[i] = ft_toupper(str[i]);
				in_word = 1;
			}
			else
				str[i] = ft_tolower(str[i]);
		}
		else
			in_word = 0;
		i++;
	}
	return (str);
}
