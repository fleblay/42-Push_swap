/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:36:29 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/13 17:01:48 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac == 1)
		return (0);
	data.start = NULL;
	data.s1 = get_int_tab(av, &(data.s1size));
	data.sorted_s1 = get_sorted_array(data.s1, 0, data.s1size - 1);
	data.l1 = listify(data.s1, data.s1size);
	data.l2 = listify(data.s1, 0);
	update_size(&data);
	data.max_loop = make_tab_max_sorted(&data);
	if (data.s1size == 3)
		sort_3a(&data);
	if (data.s1size <= 80)
		opti_sort5(&data);
	else
		opti_sort6(&data);
// BF ALGO
/*
	char	*sol[10] = {0};
	int max_depth = 1;
	while (max_depth < 8)
	{
		if (sort_bf(&data, sol, 0, max_depth))
			break ;
		//printf("No solution for max_depth : %d\n", max_depth);
		max_depth++;
	}
	print_instruct(data.start);
	//printf("res checker : %d\n", checker(data.start, data.s1, data.s1size));
	//char	*solution[] = {"sa", NULL};
	//printf("res checker_array : %d\n", checker_array(sol, data.s1, data.s1size));
	int i = 0;
	while (sol[i])
	{
		ft_putstr_fd(sol[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
*/
	//print_instruct(data.start);
	print_opti_instruct(data.start);
	custom_exit(0, &data);
	return (0);
}
