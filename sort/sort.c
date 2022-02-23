/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 05:04:29 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/23 05:07:18 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_list **a, t_list **b)
{
	t_list	*tmp;

	sort_index(a);
	tmp = max_index(a);
	push_b(a, b, tmp);
	mix_stack(a, b);
}

void	range_stack(t_list **a, t_list **b, t_list *min)
{
	void	(*fa)(t_list**, char*);
	void	(*fb)(t_list**, char*);
	char	*msga;
	char	*msgb;

	fa = best_function(min->place->i, lst_size(*a), &msga, 1);
	fb = best_function(min->i, lst_size(*b), &msgb, 0);
	while (1)
	{
		range_stack_utils(a, b, min, fa, fb);
		while (*a != min->place)
		{
			(*fa)(a, msga);
		}
		while (*b != min)
		{
			(*fb)(b, msgb);
		}
		if (*a == min->place && *b == min)
			break ;
	}
	push_stack(b, a, "pa\n");
}

void	mix_stack(t_list **a, t_list **b)
{
	t_list	*send;
	t_list	*tmp;
	t_list	*markup;

	tmp = *b;
	calculate_steps(a, b, max_index(a));
	while (1)
	{
		send = min_steps(*b);
		range_stack(a, b, send);
		if (!lst_size(*b))
			break ;
		markup = min_data(*a);
		calculate_steps(a, b, markup);
	}
	min_on_top(a);
}

void	calculate_steps(t_list **a, t_list **b, t_list *markup)
{
	t_list	*tmp;

	if (!lst_size(*b))
		return ;
	tmp = *b;
	while (tmp != (*b)->prev)
	{
		check_place(a, b, tmp, markup);
		tmp = tmp->next;
	}
	check_place(a, b, tmp, markup);
}

void	check_place(t_list **a, t_list **b, t_list *node_p, t_list *markup)
{
	t_list	*tmp;
	int		num;

	num = node_p->data;
	tmp = *a;
	while (tmp != (*a)->prev)
	{
		if ((tmp->data < num && num < tmp->next->data))
			write_steps(tmp->next, node_p, *a, *b);
		else if ((num < markup->data && tmp == markup))
			write_steps(tmp, node_p, *a, *b);
		tmp = tmp->next;
	}
	if ((tmp->data < num && num < tmp->next->data))
		write_steps(tmp->next, node_p, *a, *b);
	else if ((num < markup->data && tmp == markup))
		write_steps(tmp, node_p, *a, *b);
}
