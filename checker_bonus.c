/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:08:02 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/24 02:25:07 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_rest(char *msg, t_list **a, t_list **b)
{
	if (!ft_strncmp(msg, "rr\n"))
	{
		rotate_stack(a, NULL);
		rotate_stack(b, NULL);
	}
	else if (!ft_strncmp(msg, "rrr\n"))
	{
		reverse_rotate_stack(a, NULL);
		reverse_rotate_stack(b, NULL);
	}
	else if (!ft_strncmp(msg, "ss\n"))
	{
		swap_stack(*b, NULL);
		swap_stack(*a, NULL);
	}
	else
		ft_exit(0);
}

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	check_function(char *msg, t_list **a, t_list **b)
{
	if (!ft_strncmp(msg, "ra\n"))
		rotate_stack(a, NULL);
	else if (!ft_strncmp(msg, "rb\n"))
		rotate_stack(b, NULL);
	else if (!ft_strncmp(msg, "sa\n"))
		swap_stack(*a, NULL);
	else if (!ft_strncmp(msg, "sb\n"))
		swap_stack(*b, NULL);
	else if (!ft_strncmp(msg, "rra\n"))
		reverse_rotate_stack(a, NULL);
	else if (!ft_strncmp(msg, "rrb\n"))
		reverse_rotate_stack(b, NULL);
	else if (!ft_strncmp(msg, "pa\n"))
		push_stack(b, a, NULL);
	else if (!ft_strncmp(msg, "pb\n"))
		push_stack(a, b, NULL);
	else
		check_rest(msg, a, b);
}

int	sorted(t_list *a)
{
	t_list	*tmp;

	if (!a)
		return (0);
	tmp = a;
	while (tmp != a->prev)
	{
		if (tmp->data >= tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	*str;

	if (ac == 1)
		return (0);
	check_in(ac, av, &a);
	str = get_next_line(0);
	while (str)
	{
		check_function(str, &a, &b);
		str = get_next_line(0);
	}
	if (sorted(a))
		ft_putstr("ok\n");
	else
		ft_putstr("ko\n");
}
