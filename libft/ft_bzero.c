/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:17:18 by syolando          #+#    #+#             */
/*   Updated: 2021/10/27 12:17:18 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	ft_bzero(void *dest, size_t nbytes)
{
	size_t	ind;

	ind = 0;
	while (ind < nbytes)
	{
		*(unsigned char *)(dest + ind) = (unsigned char) '\0';
		ind++;
	}
}
