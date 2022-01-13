/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:41:30 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/13 16:17:20 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	get_index(t_list *start, int value)
{
	int	i;

	i = 0;
	while (start && *((int *)(start->content)) != value)
	{
		i++;
		start = start->next;
	}
	if (!start)
		return (-1);
	return (i);
}

int	get_index_first_g(t_list *start, int value)
{
	int	i;

	i = 0;
	while (start && *((int *)(start->content)) <= value)
	{
		i++;
		start = start->next;
	}
	if (!start)
		return (-1);
	return (i);
}

int	get_index_first_l(t_list *start, int value)
{
	int	i;

	i = 0;
	while (start && *((int *)(start->content)) >= value)
	{
		i++;
		start = start->next;
	}
	if (!start)
		return (-1);
	return (i);
}

int	get_index_first_ge(t_list *start, int value)
{
	int	i;

	i = 0;
	while (start && *((int *)(start->content)) < value)
	{
		i++;
		start = start->next;
	}
	if (!start)
		return (-1);
	return (i);
}

int	get_index_first_le(t_list *start, int value)
{
	int	i;

	i = 0;
	while (start && *((int *)(start->content)) > value)
	{
		i++;
		start = start->next;
	}
	if (!start)
		return (-1);
	return (i);
}

int	get_value(t_list *start, int index)
{
	while (index--)
		start = start->next;
	return (*((int *)(start->content)));
}

void	custom_swap(int *a, int *b, int *index)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	*index = 0;
}

int	get_mediane(long *tab, int begin, int end)
{
	int	i;
	int	*tmp_tab;
	int	med;

	if (begin >= end)
		return (-1);
	tmp_tab = (int *)malloc((end - begin + 1) * sizeof(int));
	if (!tmp_tab)
		return (-1);
	i = -1;
	while ((++i) < end - begin + 1)
		tmp_tab[i] = tab[i + begin];
	i = 0;
	while (i < end - begin)
	{
		if (tmp_tab[i] > tmp_tab[i + 1])
			custom_swap(&(tmp_tab[i]), &(tmp_tab[i + 1]), &i);
		else
			i++;
	}
	med = tmp_tab[(end - begin) / 2];
	free(tmp_tab);
	return (med);
}
