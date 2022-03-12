/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:32:30 by syolando          #+#    #+#             */
/*   Updated: 2021/11/24 18:45:21 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static char	to_hex_digit(unsigned int n, char size)
{
	char	*hex_small;
	char	*hex_big;

	hex_small = "abcdef\0";
	hex_big = "ABCDEF\0";
	if (n > 9)
	{	
		if (size == 'x')
			return (hex_small[n - 10]);
		else if (size == 'X')
			return (hex_big[n - 10]);
	}
	return (n + '0');
}

static void	print_in_hex(unsigned int n, int *n_printed, char size, int fd)
{
	int		remainder;
	char	converted;

	if (n < 16)
	{
		converted = to_hex_digit(n, size);
		write(fd, &converted, 1);
		*n_printed += 1;
	}
	else
	{
		remainder = n % 16;
		converted = to_hex_digit(remainder, size);
		print_in_hex(n / 16, n_printed, size, fd);
		write(fd, &converted, 1);
		*n_printed += 1;
	}
}

int	ft_putnbr_hex_fd(unsigned int n, char size, int fd)
{
	int	n_printed;

	n_printed = 0;
	print_in_hex(n, &n_printed, size, fd);
	return (n_printed);
}
