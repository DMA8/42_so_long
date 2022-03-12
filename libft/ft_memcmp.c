/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:20:14 by syolando          #+#    #+#             */
/*   Updated: 2021/10/27 12:20:14 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned int	ind;

	ind = 0;
	while (ind < n)
	{
		if (*((unsigned char *)str1 + ind) != *((unsigned char *)str2 + ind))
			return ((int)((*((unsigned char *)str1 + ind) - \
			*((unsigned char *)str2 + ind))));
		ind++;
	}
	return (0);
}
