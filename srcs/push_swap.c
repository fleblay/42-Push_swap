/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:36:29 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/12 18:33:23 by fle-blay         ###   ########.fr       */
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

	(void)ac;
	data.start = NULL;
	data.s1 = get_int_tab(av, &(data.s1size));
	data.sorted_s1 = get_sorted_array(data.s1, 0, data.s1size - 1);
	/*
	int i = 0;
	while (i < data.s1size)
	{
		printf("sorted s[%d] : %d\n", i, data.sorted_s1[i]);
		i++;
	}
	*/
	//printf("index de 50 : %d\n", get_final_index(&data, 50));
//	printf("nb sorted pour 50 start : %d\n", get_nb_sorted(&data, 50));
	data.l1 = listify(data.s1, data.s1size);
	data.l2 = listify(data.s1, 0);
	update_size(&data);
	printf("nb depart max sorted loop : %d\n", get_start_max_sorted(&data));
	printf("dans max sorted loop ? : %d\n", is_in_loop_max_sorted(&data, 80));
	data.max_loop = make_tab_max_sorted(&data);

//	printf("val mediane : %d\n", get_mediane(data.s1, 0, data.s1size -1));
//	printf("val mediane_stack : %d\n", get_mediane_stack(data.l1, data.l1size));
	//printf("res checker : %d\n", checker(data.start, data.s1, data.s1size));
	/*
	if (data.l1size == 3)
		sort_3a(&data);
	else
		p_sort2(&data, 0, data.s1size - 1);
	*/
//	long	*tab2 = get_int_tab(av, &(data.s1size));
//	p_sort_tab(&data, tab2, 0, data.s1size - 1);
//	p_sort_tab2(&data, tab2, 0, data.s1size - 1);
//	p_sort2(&data, 0, data.s1size - 1);
	update_size(&data);
//	print_lst(data);
//	printf("\n");
//	opti_sort(&data);
	opti_sort3(&data);
//	opti_sort4(&data);
//	print_lst(data);
// BF ALGO
/*
	char	*sol[10] = {0};
	int max_depth = 1;
	while (max_depth < 8)
	{
		if (sort_bf(&data, sol, 0, max_depth))
			break ;
		printf("No solution for max_depth : %d\n", max_depth);
		max_depth++;
	}
	print_instruct(data.start);

	//printf("res checker : %d\n", checker(data.start, data.s1, data.s1size));
	//char	*solution[] = {"sa", NULL};
	printf("res checker_array : %d\n", checker_array(sol, data.s1, data.s1size));
	*/
	/*
	int i = 0;
	while (sol[i])
	{
		printf("sol[%d] : %s\n", i, sol[i]);
		i++;
	}
	*/
	printf("biggest value a:%d\n", get_biggest_valuea(&data));
	printf("biggest value b:%d\n", get_biggest_valueb(&data));
	print_instruct(data.start);
	custom_exit(0, &data);
	return (0);
}
