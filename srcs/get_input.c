/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 10:16:12 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/30 16:23:36 by fle-blay         ###   ########.fr       */
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
	j = 0;
	while (tab[i])
	{
		sign = 0;
		j = 0;
		while (tab[i][j])
		{
		//	printf("tab[%d][%d] : %c\n", i, j, tab[i][j]);
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

long	*make_it_int(char **tab, int *size_tab)
{
	long	*tab_int;
	int		i;
	int		error;

	error = 0;
	i = 0;
	if (!is_atoiable(tab))
	{
		printf("not atoiable\n");
		return (NULL);
	}
	while (tab[i])
		i++;
	*size_tab = i;
	tab_int = (long *)malloc((*size_tab) * sizeof(long));
	if (!tab_int)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		tab_int[i] = ft_atol(tab[i], &error);
		if (error)
		{
			printf("under ou overflow int\n");
			return (NULL);
		}
		i++;
	}
	return (tab_int);
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

int	main(int ac, char *av[])
{
	(void)ac;
	char **tab;
	int	size_tab = 0;
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

	tab_int = make_it_int(tab, &size_tab);
	if (!tab_int)
	{
		printf("error making int tab");
		return (0);
	}
	i = 0;
	while (i < size_tab)
	{
		printf("tab_int : %ld\n", tab_int[i]);
		i++;
	}
	printf("isuniq and int %d\n", is_uniq(tab_int, size_tab));
	return (0);
}
