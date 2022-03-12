/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:19:21 by syolando          #+#    #+#             */
/*   Updated: 2021/11/10 14:42:55 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*test;

	if (lst)
	{
		if (*lst)
		{
			test = ft_lstlast(*lst);
			test->next = new;
		}
		else
			*lst = new;
	}
}
