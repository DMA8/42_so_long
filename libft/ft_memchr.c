/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:20:09 by syolando          #+#    #+#             */
/*   Updated: 2021/10/27 12:20:09 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned int	ind;

	ind = 0;
	while (ind < n)
	{
		if (*((unsigned char *)str + ind) == (unsigned char)c)
			return ((void *)(str + ind));
		ind++;
	}
	return (NULL);
}
