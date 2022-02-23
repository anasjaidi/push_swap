/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:57:01 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/23 18:36:21 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_num(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-' || str[0] == '+')
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
			if (!check_num(*str))
				ft_exit(a);
			else
				add_back(new_node(ft_atoi(*str)), a);
			str++;
		}
	}
}
