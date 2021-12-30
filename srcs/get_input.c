/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 10:16:12 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/30 18:09:36 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdio.h>

static int	ft_isspace(int c)
{
	if (c == '\f' || c == '\t' || c == '\n' || c == '\r' || c == '\v' \
		|| c == ' ')
		return (1);
	return (0);
}

long	ft_atol(const char *nptr, int *error)
{
	int		i;
	long	nbr;
	int		sign;

	i = 0;
	sign = 1;
	nbr = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (! ft_isdigit(nptr[i]))
	{
		if (nptr[i] != '-' && nptr[i] != '+')
			return (nbr);
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nbr = 10 * nbr + nptr[i++] - 48;
		if ((sign == -1 && nbr > 2147483648) || (sign == 1 && nbr > 2147483647))
			*error = 1;
	}
	return (sign * nbr);
}

char	**get_char_tab(char *av[])
{
	char	*ret;
	char	*tmp;
	int		i;

	ret = ft_strdup("");
	if (!ret)
		return (NULL);
	i = 0;
	while (av[i])
	{
		tmp = ret;
		ret = ft_strjoin(ret, " ");
		free(tmp);
		if (!ret)
			return (NULL);
		tmp = ret;
		ret = ft_strjoin(ret, av[i++]);
		free(tmp);
		if (!ret)
			return (NULL);
	}
	return (ft_split(ret, ' '));
}

int	is_atoiable(char **tab)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	while (tab[i])
	{
		sign = 0;
		j = 0;
		if (ft_strlen(tab[i]) == 1 && (tab[i][0] == '-' || tab[i][0] == '+'))
			return (0);
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]) && tab[i][j] != '-' && tab[i][j] != '+')
				return (0);
			if (tab[i][j] == '-' || tab[i][j] == '+')
				sign++;
			j++;
		}
		if (sign > 1)
			return (0);
		i++;
	}
	return (1);
}

int	is_uniq(long tab[], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	*make_it_int(char **tab, int *size_tab, int *error)
{
	long	*tab_int;
	int		i;

	i = 0;
	if (!is_atoiable(tab))
	{
		*error = 1;
		return (NULL);
	}
	while (tab[i])
		i++;
	*size_tab = i;
	tab_int = (long *)malloc((*size_tab) * sizeof(long));
	if (!tab_int)
		return (NULL);
	i = -1;
	while (tab[++i] && !(*error))
		tab_int[i] = ft_atol(tab[i], error);
	if (!(*error) && !is_uniq(tab_int, *size_tab))
		*error = 1;
	return (tab_int);
}

void	custom_exit(int error)
{
	if (error)
		ft_putstr_fd("Error\n",2);
	exit(0);
}

void	destroy_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

long	*get_int_tab(char **av, int *size_tab)
{
	char	**tab;
	long	*tab_int;
	int		error;

	tab_int = NULL;
	error = 0;
	tab = get_char_tab(++av);
	if (!tab)
		return (NULL);
	tab_int = make_it_int(tab, size_tab, &error);
	destroy_tab(tab);
	if (error || !tab)
	{
		free(tab_int);
		custom_exit(error);
	}
	return (tab_int);
}

#include <stdlib.h>
int	main(int ac, char *av[])
{
	(void)ac;
/*	char **tab;
	int	size_tab = 0;
	int	error = 0;
	long	*tab_int = 0;

	tab = get_char_tab(++av);
	int i = 0;
	while (tab[i])
	{
		printf("ret : %s\n", tab[i]);
		//free(tab[i]);
		i++;
	}
	//free(tab);

	tab_int = make_it_int(tab, &size_tab, &error);
	if (!tab_int)
	{
		printf("error making int tab");
		return (0);
	}*/
	long *tab_int;
	int	size_tab;
	int	i;

	tab_int = get_int_tab(av, &size_tab);
	i = 0;
	while (i < size_tab)
	{
		printf("tab_int : %ld\n", tab_int[i]);
		i++;
	}
	printf("isuniq and int %d\n", is_uniq(tab_int, size_tab));
	//printf("error : %d\n", error);
	printf("atoi de + %d\n", atoi("-"));
	return (0);
}
