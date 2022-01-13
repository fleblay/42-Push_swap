/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_custom_sort5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 09:22:52 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/13 15:24:43 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void	opti_sort5(t_data *data)
{
	int to_moveinb;
	int	to_moveina;

	while (data->l1size > data->ml_size)
	{
		if (!is_in_loop_max_sorted(data, *(int *)(data->l1->content)))
			pb(data);
		else
			ra(data);
	}
	print_lst(*data);
	printf("nb instruct no opti: %d\n", ft_lstsize(data->start));
	while (data->l2size)
	{
		print_infob(data, &to_moveina, &to_moveinb);
		move_top(data, to_moveina);
		move_topb(data, to_moveinb);
		pa(data);
	}
	move_top(data, get_smallest_valuea(data));
	print_lst(*data);
	printf("nb instruct no opti: %d\n", ft_lstsize(data->start));
}
