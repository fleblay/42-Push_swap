/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:49:23 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/14 11:06:44 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	sort_3a(t_data *data)
{
	int	tab[3];
	int	i;

	i = -1;
	while (++i < 3)
		tab[i] = get_value(data->l1, i);
	if (tab[0] < tab[1] && tab[1] < tab[2] && tab[2] > tab[0])
		return ;
	if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] < tab[0])
		rra(data);
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] < tab[0])
		ra(data);
	if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] > tab[0])
	{
		sa(data);
		ra(data);
	}
	if (tab[0] > tab[1] && tab[1] > tab[2] && tab[2] < tab[0])
	{
		sa(data);
		rra(data);
	}
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] > tab[0])
		sa(data);
}

void	sort_3b(t_data *data)
{
	int	tab[3];
	int	i;

	i = -1;
	while (++i < 3)
		tab[i] = get_value(data->l2, i);
	if (tab[0] < tab[1] && tab[1] < tab[2] && tab[2] > tab[0])
	{
		rrb(data);
		rrb(data);
	}
	if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] < tab[0])
		sb(data);
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] < tab[0])
	{
		sb(data);
		rb(data);
	}
	if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] > tab[0])
		rb(data);
	if (tab[0] > tab[1] && tab[1] > tab[2] && tab[2] < tab[0])
		return ;
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] > tab[0])
		rrb(data);
}
