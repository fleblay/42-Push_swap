/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_custom_sort6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:51:28 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/14 11:02:22 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

static void	opti_sort6_a_to_b(t_data *data)
{
	int	pivot;
	int	old_l1size;
	int	i;

	while (data->l1size > data->ml_size)
	{
		if (get_mediane_stack(data->l1, data->l1size) == pivot)
			break ;
		pivot = get_mediane_stack(data->l1, data->l1size);
		i = 0;
		old_l1size = data->l1size;
		while (i < old_l1size && get_index_first_le(data->l1, pivot) != -1)
		{
			if (!is_in_loop_max_sorted(data, *(int *)(data->l1->content))
				&& *(int *)(data->l1->content) <= pivot)
				pb(data);
			else
				ra(data);
			i++;
		}
	}
}

void	opti_sort6(t_data *data)
{
	int	to_moveinb;
	int	to_moveina;

	opti_sort6_a_to_b(data);
	while (data->l1size > data->ml_size)
	{
		if (!is_in_loop_max_sorted(data, *(int *)(data->l1->content)))
			pb(data);
		else
			ra(data);
	}
	while (data->l2size)
	{
		print_infob(data, &to_moveina, &to_moveinb, data->l2);
		move_top(data, to_moveina);
		move_topb(data, to_moveinb);
		pa(data);
	}
	move_top(data, get_smallest_valuea(data));
}
