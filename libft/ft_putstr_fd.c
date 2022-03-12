/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:21:09 by syolando          #+#    #+#             */
/*   Updated: 2022/03/06 14:36:48 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	int	output_len;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	output_len = ft_strlen(s);
	write(fd, s, output_len);
	return (output_len);
}
