/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:36:29 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/06 17:06:46 by fle-blay         ###   ########.fr       */
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
	data.l1 = listify(data.s1, data.s1size);
	data.l2 = listify(data.s1, 0);
	update_size(&data);
	printf("val mediane : %d\n", get_mediane(data.s1, 0, data.s1size -1));
	printf("val mediane_stack : %d\n", get_mediane_stack(data.l1, data.l1size));
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
	print_lst(data);
	printf("\n");
//	print_lst(data);

	char	*sol[20] = {0};
	sort_bf(&data, sol, 0);
	print_instruct(data.start);

	//printf("res checker : %d\n", checker(data.start, data.s1, data.s1size));
	char	*solution[] = {"sa", NULL};
	printf("res checker_array : %d\n", checker_array(solution, data.s1, data.s1size));

	custom_exit(0, &data);
	return (0);
}
