/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:17:26 by syolando          #+#    #+#             */
/*   Updated: 2021/10/27 12:17:26 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ans;

	if (size && SIZE_MAX / size < nmemb)
		return (NULL);
	ans = (void *)malloc(nmemb * size);
	if (!ans)
		return (NULL);
	ft_bzero(ans, nmemb * size);
	return (ans);
}
