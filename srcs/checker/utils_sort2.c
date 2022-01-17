/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:42:34 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/17 10:25:25 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	is_sorted(t_list *lst)
{
	int	curr_value;
	int	ncurr_value;

	while (lst && lst->next)
	{
		curr_value = *((int *)(lst->content));
		ncurr_value = *((int *)(lst->next->content));
		if (curr_value > ncurr_value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_rsorted(t_list *lst)
{
	int	curr_value;
	int	ncurr_value;

	while (lst && lst->next)
	{
		curr_value = *((int *)(lst->content));
		ncurr_value = *((int *)(lst->next->content));
		if (curr_value < ncurr_value)
			return (0);
		lst = lst->next;
	}
	return (1);
}
