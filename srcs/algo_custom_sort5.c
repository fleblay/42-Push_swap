/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_custom_sort5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 09:22:52 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/13 12:18:18 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void	opti_sort5(t_data *data)
{
//	int	old_l2size;
	int j;


	//printf("nb misfit : %d\n", spot_misfits(data->l1));
	j = 0;
	while (data->l1size > data->ml_size)
	{
		if (!is_in_loop_max_sorted(data, *(int *)(data->l1->content)))
			pb(data);
		else
			ra(data);
	}

//	int	i;
//	int	old_l1size;
//	int	pivot;
//	int	save_pivot[50] = {};
//	while (data->l1size > 3)// || data->l1size > data->ml_size)
//	{
//		//printf("data_l1_size : %d\n", data->l1size);
//		//Mediane impossible avec loop
//		pivot = get_mediane_stack(data->l1, data->l1size);
//		// a adapter avec quartiles
//	//	pivot += 49;
//		printf("pivot : %d\n", pivot);
//		//if (pivot > 50)
//		//	break ;
//		old_l1size = data->l1size;
//		i = 0;
//// OPTION 1 : ON POUSSE EN BOUCLANT TANT EN RA TANT QU'IL Y A UNE VAL INF AU PIVOT DANS A
//		///*
//		while (i < old_l1size && get_index_first_le(data->l1, pivot) != -1 && data->l1size > 3)// && data->l1size > data->ml_size)
//		{
//			if (*(int *)(data->l1->content) <= pivot)// && !is_in_loop_max_sorted(data, *(int *)(data->l1->content)))
//				pb(data);
//			else
//				ra(data);
//			i++;
//		}
//		//*/
//		/*
//// OPTION 2 : ON POUSSE LE MOINS CHER VERS LE HAUT TANT QU'IL Y A UNE VAL INF AU PIVOT DANS A
//		while (get_index_first_l(data->l1, pivot) != -1 && data->l1size > 3)
//		{
//			if (data->l1size - r_get_index_first_l(data->l1, pivot) >
//				get_index_first_l(data->l1, pivot))
//			{
//				printf("from TOP\n");
//				move_top(data, get_value(data->l1, get_index_first_l(data->l1, pivot)));
//			}
//			else
//			{
//				printf("from BOTTOM\n");
//				move_top(data, get_value(data->l1, r_get_index_first_l(data->l1, pivot)));
//			}
//			pb(data);
//		}
//		*/
//
//		save_pivot[j] = pivot;
//		j++;
//	}

	print_lst(*data);
	printf("nb instruct : %d\n", ft_lstsize(data->start));
	//sort_3a(data);
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

	int to_moveinb;
	int	to_moveina;

	while (data->l2size)
	{
		print_infob(data, &to_moveina, &to_moveinb);
		//printf("tomovein a : %d , tomovein b : %d\n", to_moveina, to_moveinb);
		move_top(data, to_moveina);
		move_topb(data, to_moveinb);
		pa(data);
	}

// ALGO 1 : POUSSER LE PLUS GRAND A CHAQUE FOIS
	/*	
	int ret ;
	while (data->l2size)
	{
		
		ret = calculate_cheapest_move_b(data, get_index(data->l2, get_biggest_valueb(data)), get_index(data->l2, get_smallest_valueb(data)));
		if (ret == 1)
		{
			printf("big\n");
			push_biggest_valueb(data);
		}
		else
		{
			printf("low\n");
			move_topb(data, get_smallest_valueb(data));
			pa(data);
			ra(data);
		}
	}

	while (data->l2size)
	{
		push_biggest_valueb(data);
	}
	print_lst(*data);
	*/

	
// ALGO 2 : POUSSER LE PLUS PETIT SUP DE STACK A PAR RAPPORT AU TOP DE B VERS LE HAUT
	/*	
	while (data->l2size > data->s1size / 2)
	{
		printf("index qui va etre move_topa : %d sizea : %d\n", get_index(data->l1, get_smallest_sup_in_a(data, *(int *)(data->l2->content))), data->l1size);
		move_top(data, get_smallest_sup_in_a(data, *(int *)(data->l2->content)));
		pa(data);
	}
	int k = 9;
	while (k--)
		rra(data);
	*/
	
	//print_lst(*data);
	printf("nb instruct : %d\n", ft_lstsize(data->start));
	
	printf("doing b part 2\n");

// ALGO 3 : POUSSER LE PLUS PETIT SUP DE STACK B PAR RAPPORT AU TOP DE A VERS LE HAUT
	/*
	while (data->l2size)// > data->s1size / 2)
	{
		printf("index qui va etre move_topb : %d sizeb : %d\n", get_index(data->l2, get_biggest_inf_in_b(data, *(int *)(data->l1->content))), data->l2size);
		move_topb(data, get_biggest_inf_in_b(data, *(int *)(data->l1->content)));
		pa(data);
	}
	*/
	/*
// ALGO 2+3:
	while (data->l2size > data->s1size / 2)
	{
		printf("index qui va etre move_topa : %d sizea : %d\n", get_index(data->l1, get_smallest_sup_in_a(data, *(int *)(data->l2->content))), data->l1size);
		move_top(data, get_smallest_sup_in_a(data, *(int *)(data->l2->content)));
		pa(data);
	}
	//TO implement nicely
	int k = 9;
	while (k--)
		rra(data);
	
	//print_lst(*data);
	printf("nb instruct : %d\n", ft_lstsize(data->start));
	
	printf("doing b part 2\n");

	while (data->l2size)// > data->s1size / 2)
	{
		printf("index qui va etre move_topb : %d sizeb : %d\n", get_index(data->l2, get_biggest_inf_in_b(data, *(int *)(data->l1->content))), data->l2size);
		move_topb(data, get_biggest_inf_in_b(data, *(int *)(data->l1->content)));
		pa(data);
	}
	*/
// ALGO 4 : regarder cout de 2 et cout de 3 et faire le moins cher
// PB quand switch algo
//
	/*
	int index_try_a;
	int index_try_b;
	int k = 0 ;
	while (data->l2size && k != 1)// && k < 2)// > data->s1size / 2)
	{
		index_try_a = get_index(data->l1, get_smallest_sup_in_a(data, *(int *)(data->l2->content)));
		index_try_b = get_index(data->l2, get_biggest_inf_in_b(data, *(int *)(data->l1->content)));
		printf("nb top b : %d", *(int *)(data->l2->content));
		printf("||index algo 2 : %d", index_try_a);
		printf("|| index algo 3: %d", index_try_b);
		printf("cheapest move : %c\n", calculate_cheapest_move(data, index_try_a, index_try_b));
		//if (index_try_b == -1)// || *(int *)(data->l2->content) == 92)
			//k = 1;
			//break ;
		{
			if (index_try_a != -1 && calculate_cheapest_move(data, index_try_a, index_try_b) == 'a')
			{
				printf("doing algo 2 on : %d\n", *(int *)(data->l2->content));
				move_top(data, get_smallest_sup_in_a(data, *(int *)(data->l2->content)));
				pa(data);
			}
			else if (index_try_b != -1)
			{
				//push_biggest_valueb(data);
				printf("doing algo 3 on : %d\n",get_biggest_inf_in_b(data, *(int *)(data->l1->content)));
				move_topb(data, get_biggest_inf_in_b(data, *(int *)(data->l1->content)));
				pa(data);
			}
			else 
			{
				printf("Default, pushing biggest %d\n", get_biggest_valueb(data));
				push_biggest_valueb(data);
				
				//printf("error at some point : doing algo 2\n");
				//move_top(data, get_smallest_sup_in_a(data, *(int *)(data->l2->content)));
				//pa(data);

			}
		}
	}
	*/

	//sort_3b(data);
	/*
	while (data->l2size)
		pa(data);
		*/
	print_lst(*data);
	printf("nb instruct : %d\n", ft_lstsize(data->start));
//	printf("nb misfit : %d\n", spot_misfits(data->l1));
	
}
