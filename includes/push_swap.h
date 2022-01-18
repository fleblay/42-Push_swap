/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 10:29:50 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/18 10:10:14 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define BUFFER_SIZE 1

typedef struct s_data {
	long	*s1;
	int		*sorted_s1;
	int		*max_loop;
	int		ml_size;
	int		s1size;
	t_list	*l1;
	int		l1size;
	t_list	*l2;
	int		l2size;
	t_list	*start;
}			t_data;

long	ft_atol(const char *nptr, int *error);
char	**get_char_tab(char *av[]);
int		is_atoiable(char **tab);
int		is_uniq(long tab[], int size);
long	*make_it_int(char **tab, int *size_tab, int *error);
void	custom_exit(int error, t_data *data);
void	destroy_tab(char **tab);
long	*get_int_tab(char **av, int *size_tab);
int		sa(t_data *data);
int		pb(t_data *data);
int		ra(t_data *data);
int		rra(t_data *data);
int		sb(t_data *data);
int		pa(t_data *data);
int		rb(t_data *data);
int		rrb(t_data *data);
int		ss(t_data *data);
int		rr(t_data *data);
int		rrr(t_data *data);
int		update_size(t_data *data);
void	printer(void *content);
void	print_instruct(t_list *start);
void	print_stack(void *content);
void	print_size(t_data data);
void	print_lst(t_data start);
int		get_index(t_list *start, int value);
int		move_top(t_data *data, int value);
int		mem_move_top(t_data *data, int value, int *n_iter, int (**f_inv)());
int		swap(t_data *data, int val1, int val2);
int		get_value(t_list *start, int index);
int		gnvap(t_data *data, int pivot, int start, int size);
int		gnvbp(t_data *data, int pivot, int start, int size);
int		is_p_sorted(t_data *data, int pivot, int start, int size);
void	p_sort2(t_data *data, int begin, int end);
void	p_sort2b(t_data *data, int begin, int end);
void	p_sort_tab(t_data *data, long *tab, int begin, int end);
void	p_sort_tab2(t_data *data, long *tab, int begin, int end);
int		swap2(t_data *data, int val1, int val2);
int		get_mediane(long *tab, int begin, int end);
int		move_top_to_other(t_data *data, int index, int (*f)());
int		move_topb(t_data *data, int value);
int		swapb(t_data *data, int val1, int val2);
int		is_sorted(t_list *lst);
int		is_rsorted(t_list *lst);
int		move_topb(t_data *data, int value);
int		mem_move_topb(t_data *data, int value, int *n_iter, int (**f_inv)());
t_list	*listify(long *tab_int, int size);
int		get_index_first_ge(t_list *start, int value);
int		get_index(t_list *start, int value);
void	custom_swap(int *a, int *b, int *index);
int		get_mediane_stack(t_list *start, int stack_size);
void	sort_3a(t_data *data);
void	do_instruct(void *content, t_data *test_data);
int		checker(t_list *instruct, long *input, int input_size);
int		sort_bf(t_data *data, char **sol, int depth, int max_depth);
int		checker_array(char **tab, long *input, int input_size);
void	opti_sort(t_data *data);
int		get_index_first_le(t_list *start, int value);
int		get_index_first_g(t_list *start, int value);
int		get_index_first_l(t_list *start, int value);
void	sort_3b(t_data *data);
int		*get_sorted_array(long *tab, int begin, int end);
int		get_biggest_valuea(t_data *data);
int		get_biggest_valueb(t_data *data);
int		get_final_index(t_data *data, int value);
int		get_nb_sorted(t_data *data, int start_value);
int		get_start_max_sorted(t_data *data);
int		is_in_loop_max_sorted(t_data *data, int value);
void	opti_sort2(t_data *data);
int		*make_tab_max_sorted(t_data *data);
int		get_biggest_inf_in_a(t_data *data, int value);
int		get_smallest_sup_in_a(t_data *data, int value);
int		get_smallest_valuea(t_data *data);
int		get_smallest_valueb(t_data *data);
int		get_biggest_inf_in_b(t_data *data, int value);
void	opti_sort3(t_data *data);
int		r_get_index_first_g(t_list *start, int value);
int		r_get_index_first_ge(t_list *start, int value);
int		r_get_index_first_l(t_list *start, int value);
int		r_get_index_first_le(t_list *start, int value);
int		calculate_cheapest_move(t_data *data, int index_a, int index_b);
void	opti_sort4(t_data *data);
int		calculate_cheapest_move_b(t_data *data, int index_big, int index_low);
void	opti_sort5(t_data *data);
int		cost_mvtop(t_data *data, int value);
int		cost_mvtopb(t_data *data, int value);
void	print_opti_instruct(t_list *start);
int		printer2(void *content1, void *conten2);
void	opti_sort6(t_data *data);
int		iterator_bf(t_data *data);
int		print_infob(t_data *data, int *to_mvtopa, int *to_mvtopb, t_list *strt);
char	*get_next_line(int fd);
void	do_instruct_gnl(void *content, t_data *test_data);
void	custom_exit_checker(int error, t_data *data, char *curr_instruct);
int		check_input(t_list *start);

#endif

/*
int		print_infob(t_data *data, int *to_mvtopa, int *to_mvtopb);
int		spot_misfits(t_list *lst);
*/
