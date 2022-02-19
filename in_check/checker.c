/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:57:01 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/19 15:39:25 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sep(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

int	check_num(int ac, char **av)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
			if (!ft_sep(av[i][j]) && ft_sep(av[i][j + 1]))
				c++;
	}
	return (c);
}
// void	check_in(int ac, char **av)
// {
// 	int	i;
// 	int	*arr;
// 	i = 0;
// 	arr = malloc(check_num(ac, av) * sizeof(int));
// 	while (++i < ac)
// 		check_val(av[i], arr, i);
// }
// int main(int argc, char **argv)
// {
// 	check_num(argc, argv);
// 	return 0;
// }
