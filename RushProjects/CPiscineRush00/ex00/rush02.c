/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovarute <ovarute@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:44:49 by chsantos          #+#    #+#             */
/*   Updated: 2024/09/01 16:19:08 by ovarute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char	g_body = 'B';
const char	g_top = 'A';
const char	g_bottom = 'C';

void	ft_putchar(char ch);

void	ft_putrow(int len, char leftcorner, char rightcorner)
{
	int	current;

	current = 1;
	while (current <= len) 
	{
		if (current == 1)
		{
			ft_putchar(leftcorner);
			current++;
			continue ;
		}
		else if (current == len)
		{
			ft_putchar(rightcorner);
			break ;
		}
		ft_putchar(g_body);
		current++;
	}
	ft_putchar('\n');
}

void	ft_putbody(int len)
{
	int	current;

	current = 1;
	while (current <= len)
	{
		if (current == 1 || current == len)
		{
			ft_putchar(g_body);
			current++;
			continue ;
		}
		ft_putchar(' ');
		current++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	count;

	if (x <= 0 || y <= 0)
		return ;
	count = y - 2;
	ft_putrow(x, g_top, g_top);
	while (count > 0)
	{
		ft_putbody(x);
		count--;
	}
	if (y > 1) 
	{
		ft_putrow(x, g_bottom, g_bottom); 
	}
}
