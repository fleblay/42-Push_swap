/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:51:36 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/20 17:10:33 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
	*error += (nptr[i] != '\0');
	return (sign * nbr);
}
