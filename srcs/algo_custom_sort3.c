/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_custom_sort3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:17:33 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/12 13:21:16 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void	opti_sort3(t_data *data)
{
	int	pivot;
	int	save_pivot[50] = {};
	int	old_l1size;
//	int	old_l2size;
	int	i;
	int j;


	//printf("nb misfit : %d\n", spot_misfits(data->l1));
	j = 0;
	//pivot = 0;
	/*
	while (data->l1size > data->ml_size)
	{
		if (!is_in_loop_max_sorted(data, *(int *)(data->l1->content)))
			pb(data);
		else
			ra(data);
	}
	*/

	while (data->l1size > 3)// || data->l1size > data->ml_size)
	{
		printf("data_l1_size : %d\n", data->l1size);
		//Mediane impossible avec loop
		pivot = get_mediane_stack(data->l1, data->l1size);
		// a adapter avec quartiles
		//pivot += 20;
		printf("pivot : %d\n", pivot);
		//if (pivot > 50)
		//	break ;
		old_l1size = data->l1size;
		i = 0;
// OPTION 1 : ON POUSSE EN BOUCLANT TANT EN RA TANT QU'IL Y A UNE VAL INF AU PIVOT DANS A
		///*
		while (i < old_l1size && get_index_first_l(data->l1, pivot) != -1 && data->l1size > 3)// && data->l1size > data->ml_size)
		{
			if (*(int *)(data->l1->content) < pivot)// && !is_in_loop_max_sorted(data, *(int *)(data->l1->content)))
				pb(data);
			else
				ra(data);
			i++;
		}
		//*/
		/*
// OPTION 2 : ON POUSSE LE MOINS CHER VERS LE HAUT TANT QU'IL Y A UNE VAL INF AU PIVOT DANS A
		while (get_index_first_l(data->l1, pivot) != -1 && data->l1size > 3)
		{
			if (data->l1size - r_get_index_first_l(data->l1, pivot) >
				get_index_first_l(data->l1, pivot))
			{
				printf("from TOP\n");
				move_top(data, get_value(data->l1, get_index_first_l(data->l1, pivot)));
			}
			else
			{
				printf("from BOTTOM\n");
				move_top(data, get_value(data->l1, r_get_index_first_l(data->l1, pivot)));
			}
			pb(data);
		}
		*/

		save_pivot[j] = pivot;
		j++;
	}

	//print_lst(*data);
	printf("nb instruct : %d\n", ft_lstsize(data->start));
	sort_3a(data);
	//print_lst(*data);
	
	/*
	printf("smallest sup in a : %d\n", get_smallest_sup_in_a(data, 40));
	move_top(data, get_biggest_inf_in_a(data, *(int *)(data->l2->content)));
	pa(data);
	print_lst(*data);
	*/
	//return ;

	j--;
	printf("nb instruct : %d\n", ft_lstsize(data->start));
	printf("doing b\n");

// ALGO 1 : POUSSER LE PLUS GRAND A CHAQUE FOIS
	/*	
	while (data->l2size > data->s1size / 2)
	{
		push_biggest_valueb(data);
	}
	*/

	
// ALGO 2 : POUSSER LE PLUS PETIT SUP DE STACK A PAR RAPPORT AU TOP DE B VERS LE HAUT
	/*	
	while (data->l2size > data->s1size / 2)
	{
		printf("index qui va etre move_top : %d\n", get_index(data->l1, get_smallest_sup_in_a(data, *(int *)(data->l2->content))));
		move_top(data, get_smallest_sup_in_a(data, *(int *)(data->l2->content)));
		pa(data);
	}
	*/

	
	print_lst(*data);
	printf("nb instruct : %d\n", ft_lstsize(data->start));
	
	printf("doing b part 2\n");

// ALGO 3 : POUSSER LE PLUS PETIT SUP DE STACK B PAR RAPPORT AU TOP DE A VERS LE HAUT
	/*
	while (data->l2size > data->s1size /2)
	{
		printf("index qui va etre move_top : %d\n", get_index(data->l2, get_biggest_inf_in_b(data, *(int *)(data->l1->content))));
		move_topb(data, get_biggest_inf_in_b(data, *(int *)(data->l1->content)));
		pa(data);
	}
	*/
// ALGO 4 : regarder cout de 2 et cout de 3 et faire le moins cher
//
	///*
	int index_try_a;
	int index_try_b;
	int k = 0 ;
	while (data->l2size)// && k < 2)// > data->s1size / 2)
	{
		index_try_a = get_index(data->l1, get_smallest_sup_in_a(data, *(int *)(data->l2->content)));
		index_try_b = get_index(data->l2, get_biggest_inf_in_b(data, *(int *)(data->l1->content)));
		printf("index algo 2 : %d", index_try_a);
		printf("|| index algo 3: %d", index_try_b);
		printf("cheapest move : %c\n", calculate_cheapest_move(data, index_try_a, index_try_b));

		/*
		if (index_try_b == -1)
		{
			printf("doing push biggest\n");
			push_biggest_valueb(data);
		}
		else
		*/
		{
			if (calculate_cheapest_move(data, index_try_a, index_try_b) == 'a')
			{
				move_top(data, get_smallest_sup_in_a(data, *(int *)(data->l2->content)));
				pa(data);
			}
			else
			{
				//push_biggest_valueb(data);
				move_topb(data, get_biggest_inf_in_b(data, *(int *)(data->l1->content)));
				pa(data);
			}
		}
		k++;
	}
	//*/
	


	//sort_3b(data);
	/*
	while (data->l2size)
		pa(data);
		*/
	print_lst(*data);
	printf("nb instruct : %d\n", ft_lstsize(data->start));
//	printf("nb misfit : %d\n", spot_misfits(data->l1));
	
}
