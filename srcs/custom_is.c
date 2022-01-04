/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_is.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:15:19 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/04 12:35:21 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	move_top(t_data *data, int value)
{
	int	pos_of_value;

	pos_of_value = get_index(data->l1, value);
	if (pos_of_value == -1)
		return (-1);
	if (pos_of_value <= (data->l1size / 2))
		while (get_index(data->l1, value))
			ra(data);
	else
		while (get_index(data->l1, value))
			rra(data);
	return (1);
}

int	mem_move_top(t_data *data, int value, int *n_iter, int (**f_inv)())
{
	int	n;
	int	pos_of_value;

	n = 0;
	pos_of_value = get_index(data->l1, value);
	if (pos_of_value == -1)
		return (-1);
	if (pos_of_value <= (data->l1size / 2))
	{
		*f_inv = &rra;
		while (get_index(data->l1, value))
		{
			n++;
			ra(data);
		}
	}
	else
	{
		*f_inv = &ra;
		while (get_index(data->l1, value))
		{
			n++;
			rra(data);
		}
	}
	*n_iter = n;
	return (1);
}
