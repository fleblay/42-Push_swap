/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 10:29:50 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/03 18:57:29 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef	struct s_data {
	long	*s1;
	t_list	*l1;
	t_list	*l2;
	int		size;
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
void	printer(void *content);
void	print_instruct(t_list *start);
void	print_stack(void *content);
void	print_lst(t_data start);

#endif
