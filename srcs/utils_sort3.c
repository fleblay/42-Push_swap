/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:33:12 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/06 11:43:41 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	get_mediane_stack(t_list *start, int stack_size)
{
	int	i;
	int	*tmp_tab;
	int	med;

	if (!stack_size)
		return (-1);
	tmp_tab = (int *)malloc(stack_size * sizeof(int));
	if (!tmp_tab)
		return (-1);
	i = -1;
	while (++i < stack_size)
	{
		tmp_tab[i] = *((int *)(start->content));
		start = start->next;
	}
	i = 0;
	while (i < stack_size - 1)
	{
		if (tmp_tab[i] > tmp_tab[i + 1])
			custom_swap(&(tmp_tab[i]), &(tmp_tab[i + 1]), &i);
		else
			i++;
	}
	med = tmp_tab[(stack_size - 1) / 2];
	free(tmp_tab);
	return (med);
}
