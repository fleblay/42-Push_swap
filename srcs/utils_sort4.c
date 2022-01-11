/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:16:37 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/11 11:55:40 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
