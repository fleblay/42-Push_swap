/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_custom_sort2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:56:59 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/14 09:51:52 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void	opti_sort2(t_data *data)
{
	int	pivot;
	int	save_pivot[50] = {};
	int	old_l1size;
//	int	old_l2size;
	int	i;
	int j;


	//printf("nb misfit : %d\n", spot_misfits(data->l1));
	j = 0;
	pivot = 0;
	/*
	while (data->l1size > data->ml_size)
	{
		if (!is_in_loop_max_sorted(data, *(int *)(data->l1->content)))
			pb(data);
		else
			ra(data);
	}
	*/

	while (/*data->l1size > 3 ||*/ data->l1size > data->ml_size)
	{
		printf("data_l1_size : %d\n", data->l1size);
		//Mediane impossible
		//pivot = get_mediane_stack(data->l1, data->l1size);
		// a adapter avec quartiles
		pivot += 20;
		printf("pivot : %d\n", pivot);
	//	if (pivot > 50)
	//		break ;
		old_l1size = data->l1size;
		i = 0;
		while (i < old_l1size && get_index_first_l(data->l1, pivot) != -1 && data->l1size > data->ml_size)
		{
			//fx PUSH_LESS_EXPENSIVE !!!!
			if (*(int *)(data->l1->content) < pivot && !is_in_loop_max_sorted(data, *(int *)(data->l1->content)))
				pb(data);
			else
				ra(data);
			i++;
		}
		save_pivot[j] = pivot;
		j++;
	}
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
//	return ;

	j--;
	printf("nb instruct : %d\n", ft_lstsize(data->start));
	printf("doing b\n");
	
	
	while (data->l2size)// > data->s1size / 2)
	{
		//printf("size l2 : %d\n", data->l2size);
		move_top(data, get_smallest_sup_in_a(data, *(int *)(data->l2->content)));
		pa(data);
		//push_biggest_valueb(data);
	}

	
	//print_lst(*data);
	printf("nb instruct : %d\n", ft_lstsize(data->start));
	
	printf("doing b part 2\n");
	/*
	while (data->l2size)
	{
		move_topb(data, get_biggest_inf_in_b(data, *(int *)(data->l1->content)));
		pa(data);
	}
	*/

	//while (data->l2size)
	//	push_biggest_valueb(data);


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
