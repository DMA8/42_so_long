/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:22:23 by syolando          #+#    #+#             */
/*   Updated: 2021/10/27 12:22:23 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	be_zero_3(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

static void	set_0_0_incr(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c += 1;
}

char	*ft_strnstr(const char *src_str, const char *goal_str, size_t len)
{
	int	len_ss;
	int	ind_src;
	int	ind_goal;
	int	cl;

	if (*goal_str == 0)
		return ((char *)src_str);
	len_ss = ft_strlen(src_str);
	be_zero_3(&ind_src, &ind_goal, &cl);
	if ((int)len > len_ss)
		len = (size_t)len_ss;
	if ((int)len < 0)
		len = (size_t)ft_strlen(src_str);
	while (ind_src < (int)len)
	{
		while (src_str[ind_src + ind_goal] == goal_str[ind_goal])
		{
			cl++;
			ind_goal++;
			if (cl == ft_strlen(goal_str) && ind_src + ind_goal <= (int)len)
				return ((void *)src_str + ind_src);
		}
		set_0_0_incr(&ind_goal, &cl, &ind_src);
	}
	return (NULL);
}
