/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:16:37 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/13 16:25:51 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

int	*get_sorted_array(long *tab, int begin, int end)
{
	int	i;
	int	*tmp_tab;

	if (begin >= end)
		return (NULL);
	tmp_tab = (int *)malloc((end - begin + 1) * sizeof(int));
	if (!tmp_tab)
		return (NULL);
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
	return (tmp_tab);
}

int	get_final_index(t_data *data, int value)
{
	int i;

	i = 0;
	while (i < data->s1size)
	{
		if (data->sorted_s1[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	get_nb_sorted(t_data *data, int start_value)
{
	int nb_sorted;
	int	i;
	int	j;

	nb_sorted = 0;
	i = 0;
	while (i < data->s1size && data->s1[i] != start_value)
		i++;
	j = 1;
	while (j < data->s1size)
	{
		if (data->s1[(i + j) % data->s1size] > data->s1[(i + j - 1) % data->s1size])
			nb_sorted++;
		else
			break ;
		j++;
	}
	return (nb_sorted);
}

int	get_start_max_sorted(t_data *data)
{
	int i;
	int	ret;
	int	nb_sorted;
	int	max_nb_sorted;

	i = 0;
	ret = data->sorted_s1[0];
	max_nb_sorted = get_nb_sorted(data, data->sorted_s1[0]);
	while (i < data->s1size)
	{
		nb_sorted = get_nb_sorted(data, data->sorted_s1[i]);
		if (nb_sorted > max_nb_sorted)
		{
			max_nb_sorted = nb_sorted;
			ret = data->sorted_s1[i];
		}
		i++;
	}
	return (ret);
}

int	*make_tab_max_sorted(t_data *data)
{
	int start_max_sorted;
	int	nb_sorted;
	int	i;
	int	*tab;
														
	start_max_sorted = get_start_max_sorted(data);
//	printf("start max sorted : %d\n", start_max_sorted);
	nb_sorted = get_nb_sorted(data, start_max_sorted);
//	printf("nb sorted : %d\n", nb_sorted);
	i = 0;
	tab = malloc(sizeof(int) * (nb_sorted + 1));
	if (!tab)
		return (NULL);
	data->ml_size = nb_sorted + 1;
	while (i < nb_sorted + 1)
	{
		tab[i] = data->s1[(get_index(data->l1, start_max_sorted) + i) % data->s1size];
//		printf("tab_max[%d] : %d\n", i, tab[i]);
		i++;
	}
	return (tab);
}

int	is_in_loop_max_sorted(t_data *data, int value)
{
	int	i;

	i = 0;
	while (i < data->ml_size)
	{
		if (data->max_loop[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	get_biggest_inf_in_a(t_data *data, int value)
{
	t_list	*start;
	int		max_min;

	start = data->l1;
	if (!start)
		return (value);
	max_min = get_smallest_valuea(data);
	if (max_min > value)
		return (value);
	while (start)
	{
		if (*((int *)(start->content)) > max_min && *((int *)(start->content)) < value)
			max_min = *((int *)(start->content));
		start = start->next;
	}
	return (max_min);
}

int	get_smallest_sup_in_a(t_data *data, int value)
{
	t_list	*start;
	int		min_max;

	start = data->l1;
	if (!start)
		return (value);
	min_max = get_biggest_valuea(data);
	if (min_max < value)
		return (value);
	while (start)
	{
		if (*((int *)(start->content)) < min_max && *((int *)(start->content)) > value)
			min_max = *((int *)(start->content));
		start = start->next;
	}
	return (min_max);
}

int	get_smallest_sup_in_b(t_data *data, int value)
{
	t_list	*start;
	int		min_max;

	start = data->l2;
	if (!start)
		return (value);
	min_max = get_biggest_valueb(data);
	if (min_max < value)
		return (value);
	while (start)
	{
		if (*((int *)(start->content)) < min_max && *((int *)(start->content)) > value)
			min_max = *((int *)(start->content));
		start = start->next;
	}
	return (min_max);
}

int	get_biggest_inf_in_b(t_data *data, int value)
{
	t_list	*start;
	int		max_min;

	start = data->l2;
	if (!start)
		return (value);
	max_min = get_smallest_valueb(data);
	if (max_min > value)
		return (value);
	while (start)
	{
		if (*((int *)(start->content)) > max_min && *((int *)(start->content)) < value)
			max_min = *((int *)(start->content));
		start = start->next;
	}
	return (max_min);
}
