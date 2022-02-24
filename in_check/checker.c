/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:57:01 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/24 01:34:48 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_num(char *str)
{
	int	i;

	i = -1;
	if ((str[0] == '-' || str[0] == '+') && str[1])
		i++;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

void	ft_exit(t_list **a)
{
	(void)a;
	clr_list(a);
	ft_putstr("Eroor\n");
	exit(0);
}

int	hash(unsigned int x)
{
	static char	map[MX];

	if (!(map[x / 8] >> (7 - (x % 8)) & 1))
		map[x / 8] = map[x / 8] | 1 << (7 - (x % 8));
	else
		return (0);
	return (1);
}

void	check_in(int ac, char **av, t_list **a)
{
	int		i;
	char	**str;

	i = 0;
	while (++i < ac)
	{
		str = ft_split(av[i]);
		if (!*str)
			ft_exit(a);
		while (*str)
		{
			if (!check_num(*str) || !hash(ft_atoi(*str)))
				ft_exit(a);
			else
				add_back(new_node(ft_atoi(*str)), a);
			str++;
		}
	}
}
