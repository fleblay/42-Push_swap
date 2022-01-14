/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_qsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:44:09 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/10 16:43:53 by fred             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

//working but swap not opti
void	p_sort2(t_data *data, int begin, int end)
{
	int	pivot;
	int	save_begin;
	int	save_end;

	if (begin >= end || is_sorted(data->l1))
		return ;
	save_begin = begin;
	save_end = end;
	pivot = get_value(data->l1, begin + (end - begin) / 2);
	while (begin <= end)
	{
		while (begin <= end && get_value(data->l1, begin) < pivot)
			begin++;
		while (end >= begin && get_value(data->l1, end) > pivot)
			end--;
		if (begin <= end)
		{
			swap(data, get_value(data->l1, begin), get_value(data->l1, end));
			begin++;
			end--;
		}
	}
	p_sort2(data, save_begin, begin - 1);
	p_sort2(data, begin, save_end);
}	

//idem p_sort2 pour la stack b
//changement du swap notamment
//Utile uniquement pour la version a 2 stacks
//Inversion des < et > pour les while pour
//ordre invers avant de repousser)
void	p_sort2b(t_data *data, int begin, int end)
{
	int	pivot;
	int	save_begin;
	int	save_end;

	if (begin >= end || is_sorted(data->l2))
		return ;
	save_begin = begin;
	save_end = end;
	pivot = get_value(data->l2, begin + (end - begin) / 2);
	while (begin <= end)
	{
		while (begin <= end && get_value(data->l2, begin) > pivot)
			begin++;
		while (end >= begin && get_value(data->l2, end) < pivot)
			end--;
		if (begin <= end)
		{
			swapb(data, get_value(data->l2, begin), get_value(data->l2, end));
			begin++;
			end--;
		}
	}
	p_sort2b(data, save_begin, begin - 1);
	p_sort2b(data, begin, save_end);
}	

//idem p_sort2 mas avec tableau pour pouvoir utiliser swap2 qui n'a pas besoin
//de liste ordonee
void	p_sort_tab(t_data *data, long *tab, int begin, int end)
{
	int		pivot;
	int		save_begin;
	int		save_end;
	long	tmp;

	if (begin >= end)
		return ;
	save_begin = begin;
	save_end = end;
	pivot = get_mediane(tab, begin, end);
	while (begin <= end)
	{
		while (begin <= end && tab[begin] < pivot)
			begin++;
		while (end >= begin && tab[end] > pivot)
			end--;
		if (begin <= end)
		{
			if (begin != end)
			{
				swap2(data, tab[begin], tab[end]);
				tmp = tab[begin];
				tab[begin] = tab[end];
				tab[end] = tmp;
			}
			begin++;
			end--;
		}
	}
	p_sort_tab(data, tab, save_begin, begin - 1);
	p_sort_tab(data, tab, begin, save_end);
}

//try avec 2 stacks

void	p_sort_tab2(t_data *data, long *tab, int begin, int end)
{
	int		pivot;
	//int		save_begin;
	//int		save_end;
	long	tmp;

	if (begin >= end)
		return ;
	if (is_sorted(data->l1))
		return ;
	//save_begin = begin;
	//save_end = end;
	pivot = get_mediane(tab, begin, end);
	while (begin <= end && !is_sorted(data->l1))
	{
		while (begin <= end && tab[begin] < pivot)
			begin++;
		while (end >= begin && tab[end] > pivot)
			end--;
		if (begin <= end)
		{
			if (begin != end)
			{
				swap(data, tab[begin], tab[end]);
				tmp = tab[begin];
				tab[begin] = tab[end];
				tab[end] = tmp;
			}
			begin++;
			end--;
		}
	}
	move_top_to_other(data, begin, pb);
	p_sort2(data, 0, data->l1size - 1);
	p_sort2b(data, 0, data->l2size - 1);
	move_top_to_other(data, begin, pa);
}
