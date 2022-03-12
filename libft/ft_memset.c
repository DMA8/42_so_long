/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:20:31 by syolando          #+#    #+#             */
/*   Updated: 2021/10/27 12:20:31 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	ind;

	ind = 0;
	while (ind < n)
	{
		*(unsigned char *)(s + ind) = (unsigned char)c;
		ind++;
	}
	return (s);
}
