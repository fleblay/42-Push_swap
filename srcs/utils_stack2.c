/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:57:09 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/05 13:03:09 by fle-blay         ###   ########.fr       */
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

int	get_value(t_list *start, int index)
{
	while (index--)
		start = start->next;
	return (*((int *)(start->content)));
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

#include <stdio.h>

void	p_sort(t_data *data, int start, int size)
{
	int	middle;
	int	nxt_abv;
	int	nxt_blw;
	int	index_first_ge;

	if (size <= 2 || size - start < 2)
		return;
	middle = get_value(data->l1, size / 2);
	printf("pivot : %d\n", middle);
	printf("index pivot : %d\n", size / 2); 
	while (!is_p_sorted(data, middle, start, size))
	{
		nxt_abv = gnvap(data, middle, start, size);
		nxt_blw = gnvbp(data, middle, start, size);
		swap(data, nxt_abv, nxt_blw);
	}
	print_lst(*data);
	index_first_ge = get_index_first_ge(data->l1, middle);
	printf("index first ge pivot : %d\n", index_first_ge);
	//p_sort(data, 0, size - index_first_ge + 1);
	//p_sort(data, index_first_ge, size);
}


void	p_sort2(t_data *data, int begin, int end)
{
	int	pivot;
	int save_begin;
	int save_end;

	if (begin >= end)
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

void	p_sort_tab(t_data *data, long *tab, int begin, int end)
{
	int	pivot;
	int save_begin;
	int save_end;
	long	tmp;

	if (begin >= end)
		return ;
	save_begin = begin;
	save_end = end;
	pivot = tab[begin + (end - begin) / 2];
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
				swap2(data,	tab[begin], tab[end]);
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

int	get_mediane(t_data *data, long *tab, int begin, int end)
{

