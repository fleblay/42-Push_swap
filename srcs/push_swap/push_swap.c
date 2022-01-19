/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:36:29 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/19 19:19:47 by fred             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>

static void	initialize(t_data *data)
{
	data->s1 = NULL;
	data->sorted_s1 = NULL;
	data->max_loop = NULL;
	data->ml_size = 0;
	data->s1size = 0;
	data->l1 = NULL;
	data->l1size = 0;
	data->l2 = NULL;
	data->l2size = 0;
	data->start = 0;
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac == 1)
		return (0);
	/*
	data.start = NULL;
	data.max_loop = NULL;
	*/
	initialize(&data);
	data.s1 = get_int_tab(av, &(data.s1size));
	data.sorted_s1 = get_sorted_array(data.s1, 0, data.s1size - 1);
	data.l1 = listify(data.s1, data.s1size);
	//data.l2 = listify(data.s1, 0);
	update_size(&data);
	if (data.s1size < 2 || !data.l1)
		custom_exit(0, &data);
	data.max_loop = make_tab_max_sorted(&data);
	if (data.s1size == 3)
		sort_3a(&data);
	else if (data.s1size < 6)
		iterator_bf(&data);
	else if (data.s1size <= 101)
		opti_sort5(&data);
	else
		opti_sort6(&data);
	print_opti_instruct(data.start);
	custom_exit(0, &data);
	return (0);
}
