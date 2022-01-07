/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:42:34 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/07 17:07:14 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

int	spot_misfits(t_list *lst)
{
	int	prev_value;
	int	curr_value;
	int	ncurr_value;
	int nb;

	nb = 0;
	prev_value = *((int *)(lst->content));
	lst = lst->next;
	while (lst && lst->next)
	{
		curr_value = *((int *)(lst->content));
		ncurr_value = *((int *)(lst->next->content));
		if (curr_value > ncurr_value)
		{
			printf("misfit : %d\n", curr_value);
			nb++;
		}
		prev_value = curr_value;
		lst = lst->next;
	}
	return (nb);
}

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

int	is_p_sorted(t_data *data, int pivot, int start, int size)
{
	int	i;

	i = start;
	while (i < size && get_value(data->l1, i) < pivot)
		i++;
	while (i < size)
	{
		if (get_value(data->l1, i) < pivot)
			return (0);
		i++;
	}
	return (1);
}

int	gnvap(t_data *data, int pivot, int start, int size)
{
	int	i;
	int	curr_val;

	i = start;
	while (i < size)
	{
		curr_val = get_value(data->l1, i);
		if (curr_val >= pivot)
			return (curr_val);
		i++;
	}
	return (pivot);
}

int	gnvbp(t_data *data, int pivot, int start, int size)
{
	int	i;
	int	curr_val;

	i = size - 1;
	while (i > start)
	{
		curr_val = get_value(data->l1, i);
		if (curr_val < pivot)
			return (curr_val);
		i--;
	}
	return (pivot);
}
