/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:36:29 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/26 09:34:09 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac == 1)
		return (0);
	initialize(&data);
	data.s1 = get_int_tab(av, &(data.s1size));
	data.sorted_s1 = get_sorted_array(data.s1, 0, data.s1size - 1);
	data.l1 = listify(data.s1, data.s1size);
	update_size(&data);
	if (data.s1size == 1)
		custom_exit(0, &data);
	if (data.s1size == 0 || !data.l1 || !data.sorted_s1)
		custom_exit(1, &data);
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
