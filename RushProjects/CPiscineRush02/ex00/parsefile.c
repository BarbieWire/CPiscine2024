/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsefile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthoffma <sthoffma@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:54:38 by sthoffma          #+#    #+#             */
/*   Updated: 2024/09/15 19:40:55 by sthoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == ('+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	read_file(char *filename, char *buf, int buf_size)
{
	int	fd;
	int	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (-1);
	}
	bytes_read = read(fd, buf, buf_size);
	buf[bytes_read] = '\0';
	close(fd);
	return (bytes_read);
}

int	main(void)
{
	char	buf[BUFFER_SIZE];
	int		red;

	red = read_file("numbers.dict", buf, BUFFER_SIZE);
	if (red == -1)
		return (1);
	write(1, buf, red);
	return (0);
}
