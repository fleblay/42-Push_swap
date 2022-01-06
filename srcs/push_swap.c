/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:36:29 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/06 11:11:20 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>

int	main(int ac, char *av[])
{
	(void)ac;
	t_data data;
	data.start = NULL;
	data.s1 = get_int_tab(av, &(data.s1size));
	data.l1 = listify(data.s1, data.s1size);
	data.l2 = listify(data.s1, 0);

	printf("val mediane : %d\n", get_mediane(data.s1, 0, data.s1size -1));
//	Attention : free du tableau de la mediane a faire !

//	long	*tab2 = get_int_tab(av, &(data.s1size));
//	p_sort_tab(&data, tab2, 0, data.s1size - 1);
//	p_sort_tab2(&data, tab2, 0, data.s1size - 1);
//	p_sort2(&data, 0, data.s1size - 1);

	update_size(&data);
	print_lst(data);
	printf("\n");

//	print_lst(data);
//	print_instruct(data.start);
	
	custom_exit(0, &data);
	return (0);
}
