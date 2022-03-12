/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:21:45 by syolando          #+#    #+#             */
/*   Updated: 2021/11/10 17:58:59 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	ind;

	if (!s)
		return ;
	ind = 0;
	while (s[ind])
	{
		f(ind, &s[ind]);
		ind++;
	}
}
