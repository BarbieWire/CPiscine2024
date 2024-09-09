/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbondare <kbondare@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:46:55 by kbondare          #+#    #+#             */
/*   Updated: 2024/09/04 14:06:23 by kbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	const char		*s_current;
	char			*d_current;

	src_len = 0;
	s_current = src;
	d_current = dest;
	while (*s_current != '\0')
	{
		src_len++;
		s_current++;
	}
	s_current = src;
	while (*s_current != '\0' && size > 1)
	{
		*d_current++ = *s_current++;
		size--;
	}
	*d_current = '\0';
	return (src_len);
}
