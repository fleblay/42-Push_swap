/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_custom_sort3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:17:33 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/12 10:53:11 by fle-blay         ###   ########.fr       */
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
		/*
		while (i < old_l1size && get_index_first_l(data->l1, pivot) != -1 && data->l1size > 3)// && data->l1size > data->ml_size)
		{
			if (*(int *)(data->l1->content) < pivot)// && !is_in_loop_max_sorted(data, *(int *)(data->l1->content)))
				pb(data);
			else
				ra(data);
			i++;
		}
		*/
		///*
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
		//*/

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

	
	//print_lst(*data);
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
	while (data->l2size > data->s1size / 2)
	{
		printf("index qui va etre move_top algo 2 : %d\n", get_index(data->l1, get_smallest_sup_in_a(data, *(int *)(data->l2->content))));
		printf("index qui va etre move_top algo 3: %d\n", get_index(data->l2, get_biggest_inf_in_b(data, *(int *)(data->l1->content))));
		move_top(data, get_smallest_sup_in_a(data, *(int *)(data->l2->content)));
		pa(data);
	}


//	
//	{
//		if (j >= 0)
//			pivot = save_pivot[j];
//		else
//		{
//			pivot = get_mediane_stack(data->l2, data->l2size);
//		}	
//		printf("pivot : %d\n", pivot);
//		old_l2size = data->l2size;
//	//	if (pivot < 50)
//	//		break ;
//		i = 0;
//		while (i < old_l2size && get_index_first_g(data->l2, pivot) != -1)
//		{
//			//faire avec 2eme aussi !
//			push_biggest_valueb(data);
//			/*
////			printf("Doing something. value : %d, pivot : %d", *(int *)(data->l2->content), pivot);
//			if (*(int *)(data->l2->content) >= pivot)
//			{
////				printf(" : PA\n");
//				pa(data);
//				if (*(int *)(data->l1->content) == pivot)
//				{
////					printf("THIS IS THE PIVOT\n");
//					ra(data);
//				}
//			}
//			else
//			{
////				printf(" : RB\n");
//				rb(data);
//			}
//			i++;
//			if (get_index_first_ge(data->l2, pivot) == -1)
//			{
////				printf(" : RRA for pivot\n");
//				rra(data);
//			}
//			*/
//		}
//
//		j--;
//	}
	//sort_3b(data);
	/*
	while (data->l2size)
		pa(data);
		*/
	print_lst(*data);
	printf("nb instruct : %d\n", ft_lstsize(data->start));
//	printf("nb misfit : %d\n", spot_misfits(data->l1));
	
}
